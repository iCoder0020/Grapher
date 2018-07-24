/*header files*/
#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<dos.h>

typedef long double ld;

/*global variables*/
ld s,l,len,p,xmax,ymax;
int i,j,m;
char ch,chg[20];

/*function for typing slow*/
void slowtype(char a[])
{
	for(i=0;a[i]!='\0';i++)
	{
		cout<<a[i];
		delay(16);
	}
}

/*function for typing faster*/
void slowtype2(char a[])
{
	for(i=0;a[i]!='\0';i++)
	{
		cout<<a[i];
		delay(8);
	}
}

/*structure for linked list*/
struct term
{
	ld c;
	term *next;
	term *prev;
};

term *top,*rear,*tmp;

/*function to push coefficients into linked list*/
void push(int j, int n)
{
	tmp = new term;

	slowtype2("Enter the co-efficient of x^");
	cout<<j<<": ";
	cin>>tmp->c;

	if(top==NULL)
	{
		top=tmp;
		rear=tmp;
	}
	else
	{
		rear->next=tmp;
		rear=tmp;
	}
	if(j==n)
	{
		rear->next=top;
	}
	else
	{
		rear->next=NULL;
	}
}

/*function to pop coefficients out of linked list*/
ld pop(int n)
{
	ld p;
	tmp=top;

	for(int i=0;i<n;i++)
	{
		tmp=tmp->next;
	}

	p=tmp->c;
	return p;
}

/*function to clear the screen completely*/
void cd()
{
	clrscr();
	cleardevice();
}

/*function to get values of y for each x in polynomial function*/
ld get_y_poly_function(ld x,int n)
{
	ld y=0;
	int k=0;
	for(int i=0;i<=n;i++)
	{
		k=pop(i);
		y+=k*pow(x,i);
	}
	return y;
}

/*function to get +ve values of y for each x in conic section*/
ld get_y_conic_section_pos(ld x,ld a, ld h, ld b, ld g, ld f, ld c)
{
	ld y=0;
	if((((h/2)*(h/2)-a*b)*(x*x)+2*((h/2)*(f/2)-b*(g/2))*x+((f/2)*(f/2)-b*c))>=0&&b!=0)
	{
		y=(-(((h/2)*x)+(f/2))+sqrt(((h/2)*(h/2)-a*b)*(x*x)+2*((h/2)*(f/2)-b*(g/2))*x+((f/2)*(f/2)-b*c)))/b;
	}
	else if(b==0)
	{
		y = -(a*x*x+g*x+c)/(h*x+f);
	}
	else
	{
		return 2016.2017; //treated as a garbage value
	}
	return y;
}

/*function to get -ve values of y for each x in conic section*/
ld get_y_conic_section_neg(ld x,ld a, ld h, ld b, ld g, ld f, ld c)
{
	ld y=0;
	if((((h/2)*(h/2)-a*b)*(x*x)+2*((h/2)*(f/2)-b*(g/2))*x+((f/2)*(f/2)-b*c))>=0&&b!=0)
	{
		y=(-(((h/2)*x)+(f/2))-sqrt(((h/2)*(h/2)-a*b)*(x*x)+2*((h/2)*(f/2)-b*(g/2))*x+((f/2)*(f/2)-b*c)))/b;
	}
	else if(b==0)
	{
		y = -(a*x*x+g*x+c)/(h*x+f);
	}
	else
	{
		return 2016.2017;
	}
	return y;
}

/*function to show the start screen*/
void start_screen()
{
	setcolor(GREEN);
	settextstyle(0,0,8);
	outtextxy(xmax/2-216,ymax/2-30,"GRAPHER");

	int i;

	rectangle(xmax/2-250,ymax/2+150,xmax/2+250,ymax/2+160);
	setcolor(GREEN);

	for(i=-250;i<=250;i++)
	{
		delay(5);
		rectangle(xmax/2-250,ymax/2+150,xmax/2+i,ymax/2+160);
		setfillstyle(1,GREEN);
		if(i!=-250)
		{
			floodfill(xmax/2-249,ymax/2+151,GREEN);
		}
		if(i==250)
		{
			settextstyle(2,0,5);
			setcolor(BLACK);
			outtextxy(xmax/2-90,ymax/2+146,"Press any key to continue...");
			getch();
			cd();
		}
	}
}

/*function to show the base of the graph*/
void graph()
{
	settextstyle(2,0,6);
	setcolor(WHITE);
	outtextxy(xmax/2-3,ymax/2-10,"O");

	for(i=ymax/2;i<=ymax;i+=s)		//vertical line divisions(M-B)
	{
		setcolor(CYAN);
		setlinestyle(1,1,1);
		line(0,i,xmax,i);
		setlinestyle(0,1,1);
		line(xmax/2-l,i,xmax/2+l,i);
		for(m=1;m<=ymax/(2*s);m++)
		{
			setcolor(WHITE);
			settextstyle(2,0,3);
			sprintf(chg,"%d",m*-1);
			outtextxy(xmax/2-l-10,ymax/2+m*s,chg);
		}
	}
	for(i=ymax/2;i>=0;i-=s)			//vertical line divisions(M-T)
	{
		setcolor(CYAN);
		setlinestyle(1,1,1);
		line(0,i,xmax,i);
		setlinestyle(0,1,1);
		line(xmax/2-l,i,xmax/2+l,i);
		for(m=-1;m>=-ymax/(2*s);m--)
		{
			setcolor(WHITE);
			settextstyle(2,0,3);
			sprintf(chg,"%d",m*-1);
			outtextxy(xmax/2-l-5,ymax/2+m*s,chg);
		}
	}
	for(j=xmax/2;j<=xmax;j+=s)		//horizontal line divisions(M-R)
	{
		setcolor(CYAN);
		setlinestyle(1,1,1);
		line(j,0,j,ymax);
		setlinestyle(0,1,1);
		line(j,ymax/2-l,j,ymax/2+l);
		for(m=1;m<=xmax/(2*s);m++)
		{
			setcolor(WHITE);
			settextstyle(2,0,3);
			sprintf(chg,"%d",m);
			outtextxy(xmax/2+m*s,ymax/2+l+5,chg);
		}
	}
	for(j=xmax/2;j>=0;j-=s)			//horizontal line divisions(M-L)
	{
		setcolor(CYAN);
		setlinestyle(1,1,1);
		line(j,0,j,ymax);
		setlinestyle(0,1,1);
		line(j,ymax/2-l,j,ymax/2+l);
		for(m=-1;m>=-xmax/(2*s);m--)
		{
			setcolor(WHITE);
			settextstyle(2,0,3);
			sprintf(chg,"%d",m);
			outtextxy(xmax/2+m*s-5,ymax/2+l+5,chg);
		}
	}

	setcolor(GREEN);
	setlinestyle(0,1,1);

	line(xmax/2,0,xmax/2,ymax); 		//vertical line
	line(0,ymax/2,xmax,ymax/2);   		//horizontal line

	setcolor(YELLOW);
	settextstyle(2,0,6);
	outtextxy(10,10,"Graph is: ");
	outtextxy(xmax-200,5,"Press '+' to zoom in");
	outtextxy(xmax-200,25,"Press '-' to zoom out");
	outtextxy(xmax-215,ymax-20,"Press key 'e' to exit...");
}

/*function to take values regarding graph plotting*/
void graphinput()
{
	cout<<"\n";

	slowtype2("Enter the scale(recommended15-60): ");
	cin>>s;
	//s is the distance between each division

	cout<<"\n";
	slowtype2("Enter the length(recommended6-12): ");
	cin>>len;
	//len is the length of each division

	l=len/2;

	cout<<"\n";

	slowtype2("Enter the precision level(recommended0.0001-0.01): ");
	cin>>p;

	cd();
	graph();
}

void menu();

/*function to ask the user to run program again*/
void again()
{
	settextstyle(0,0,2);
	setcolor(GREEN);
	outtextxy(xmax/2-240,ymax/2-10,"Press any key to go to main menu");
	getch();
	cd();
	menu();
}

/*function to plot some special graphs*/
void special_graphs()
{
	int r=0,z=0;
	ld x,y,a;

	slowtype("Select the graph you want to plot: ");
	cout<<"\n\n";
	slowtype2("01. sin(x)");
	cout<<"\n";
	slowtype2("02. cos(x)");
	cout<<"\n";
	slowtype2("03. tan(x)");
	cout<<"\n";
	slowtype2("04. cosec(x)");
	cout<<"\n";
	slowtype2("05. sec(x)");
	cout<<"\n";
	slowtype2("06. cot(x)");
	cout<<"\n";
	slowtype2("07. modulus (|x|)");
	cout<<"\n";
	slowtype2("08. greatest integer ([x])");
	cout<<"\n";
	slowtype2("09. fractional part ({x})");
	cout<<"\n";
	slowtype2("10. logarithmic (log(a)(x))");
	cout<<"\n";
	slowtype2("11. exponential (a^x)");
	cout<<"\n\n";

	slowtype2("Enter your choice: ");
	cin>>r;

	if(r==10)
	{
		cout<<"\n";
		slowtype2("Enter the base(greater than 0 and not equal to 1): ");
		cin>>a;
	}
	else if(r==11)
	{
		cout<<"\n";
		slowtype2("Enter the base(greater than 0): ");
		cin>>a;
	}
	if(r>=1&&r<=11)
	{
		graphinput();
	}
	while(z==0)
	{
		for(x=-xmax/(2*s);x<=xmax/(2*s)&&z==0;x+=p)
		{

			switch(r)
			{
				case 1:
				{
					y=sin(x);
					break;
				}
				case 2:
				{
					y=cos(x);
					break;
				}
				case 3:
				{
					y=tan(x);
					break;
				}
				case 4:
				{
					y=1/sin(x);
					break;
				}
				case 5:
				{
					y=1/cos(x);
					break;
				}
				case 6:
				{
					y=1/tan(x);
					break;
				}
				case 7:
				{
					if(x>=0)
					{
						y=x;
					}
					else
					{
						y=-1*x;
					}
					break;
				}
				case 8:
				{
					y=floor(x);
					break;
				}
				case 9:
				{
					y=x-floor(x);
					break;
				}
				case 10:
				{
					if(x<0)
					{
						y=2016.2017;
					}
					if(x>0)
					{
						y=log10(x)/log10(a);
					}
					break;
				}
				case 11:
				{
					y=pow(a,x);
					break;
				}
				default:
				{
					cd();
					slowtype("Invalid choice...");
					getch();
					cd();
					z=1;
				}
			}
			if(xmax/2+(x*s)>xmax||xmax/2+(x*s)<0||ymax/2-(y*s)>ymax||ymax/2-(y*s)<0)
			{
				continue;
			}
			putpixel(xmax/2+(x*s),ymax/2-(y*s),LIGHTRED);
		}
		if(z==0)
		{
			ch=getch();
			if(ch=='-')
			{
				s--;
				cd();
				graph();
			}
			else if(ch=='+')
			{
				s++;
				cd();
				graph();
			}
			else if(ch=='e')
			{
				break;
			}
		}
	}
}

/*function to display help page*/
void help()
{
	//Page 1
	cd();
	setcolor(CYAN);
	settextstyle(0,0,3);
	outtextxy(xmax/2-60,20,"HELP");
	settextstyle(6,0,1);
	outtextxy(0,60,"*The main menu icons perform the following tasks: ");
	outtextxy(20,90,"1. 'Let's Plot' starts the grapher");
	outtextxy(20,120,"2. 'Help' helps to understand the functioning of program");
	outtextxy(20,150,"3. 'About' gives the information about the programmers");
	outtextxy(20,180,"4. 'Exit' exits the program");
	outtextxy(0,210,"*The program's main motive is to plot a graph");
	outtextxy(0,240,"*It can make graphs of polynomial functions,conic sections and some special");
	outtextxy(8,270,"graphs");
	outtextxy(0,300,"*For making the graphs the program takes following as input: ");
	outtextxy(20,330,"1. Scale i.e. the number of pixels/unit");
	outtextxy(20,360,"2. Length i.e. the size of each division on the x and y axes");
	outtextxy(20,390,"3. Precision level i.e. the number of pixels to be skipped in each iteration");
	outtextxy(0,420,"*For best results,enter the recommended values (given in brackets) of the above");
	settextstyle(0,0,1);
	outtextxy(xmax/2+30,470,"Press any key to go to next page...");
	getch();
	cd();

	//Page 2
	settextstyle(0,0,3);
	outtextxy(xmax/2-60,20,"HELP");
	settextstyle(6,0,1);
	outtextxy(0,60,"*If it takes too much time to plot the graph then the problems could be: ");
	outtextxy(20,90,"1. Precision is very low");
	outtextxy(20,120,"2. No graph is possible for the entered equation");
	outtextxy(20,150,"3. Graph is plotted but is not visible at the present scale");
	outtextxy(0,180,"*If the graph pixels become scattered then the problems could be: ");
	outtextxy(20,210,"1. Precision is very high");
	outtextxy(20,240,"2. The change in values of y with change in x is too much -- in this case");
	outtextxy(45,270,"the correct graph formation is out of scope for the program");
	outtextxy(0,300,"*After plotting is done,pressing '+' will zoom in and pressing '-' will zoom out");
	outtextxy(0,390,"*Enjoy graphing!!");
	settextstyle(0,0,1);
	outtextxy(xmax/2+30,470,"Press any key to go to main menu...");
	getch();
	cd();

	menu();
}

/*function to display about page*/
void about()
{
	cd();
	setcolor(MAGENTA);
	settextstyle(0,0,3);
	outtextxy(xmax/2-60,20,"ABOUT");
	settextstyle(6,0,1);
	outtextxy(0,60,"*The project has been developed by: ");
	outtextxy(10,90,"1. Ishan Sang");
	outtextxy(10,120,"2. Neepam Goel");
	outtextxy(8,150,"Class XII");
	outtextxy(8,180,"Delhi Public School,Ranipur");

	settextstyle(0,0,1);
	outtextxy(xmax/2+30,470,"Press any key to go to main menu...");
	getch();
	cd();
	menu();
}

void menu()
{
	int num;
	setcolor(GREEN);
	settextstyle(0,0,4);
	outtextxy(xmax/2-110,50,"GRAPHER");

	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(xmax/2-110,150,"1. Let's Plot");

	setcolor(CYAN);
	settextstyle(0,0,2);
	outtextxy(xmax/2-110,200,"2. Help");

	setcolor(MAGENTA);
	settextstyle(0,0,2);
	outtextxy(xmax/2-110,250,"3. About");

	setcolor(YELLOW);
	settextstyle(0,0,2);
	outtextxy(xmax/2-110,300,"4. Exit");

	setcolor(GREEN);
	settextstyle(0,0,2);
	settextstyle(0,0,1);
	outtextxy(xmax-50,450,"v2.0");

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    ";
	outtextxy(xmax/2-110,388,"Enter your choice: ");

	cin>>num;
	switch(num)
	{
		case 1:
		{
			break;
		}
		case 2:
		{
			help();
			break;
		}
		case 3:
		{
			about();
			break;
		}
		case 4:
		{
			cd();
			exit(0);
		}
		default:
		{
			cd();
			outtextxy(10,50,"Well, you have to press-> ");
			outtextxy(10,90,"1 to start the program");
			outtextxy(10,120,"2 to open help page");
			outtextxy(10,150,"3 to open about page");
			outtextxy(10,180,"4 to exit the program");
			outtextxy(10,240,"Try Again!!");
			outtextxy(xmax/2+30,470,"Press any key to go to main menu...");
			getch();
			cd();
			menu();
			break;
		}
	}
}

void main()
{
	int gdriver=DETECT, gmode, errorcode;
	int n,choice;
	ld x,y;
	ld a,b,h,g,f,c;

	srand(time(NULL));

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	xmax=getmaxx();    			//xmax=639
	ymax=getmaxy();				//ymax=479

	cd();

	start_screen();

	menu();

	cd();

	char go_ahead='y';
	while(go_ahead=='y')
	{
		cd();

		slowtype("Press 1 to plot a polynomial function");
		cout<<"\n\n";
		slowtype("Press 2 to plot a conic section");
		cout<<"\n\n";
		slowtype("Press 3 to plot some special graphs");
		cout<<"\n\n";
		slowtype("Enter your choice: ");
		cin>>choice;

		cd();

		switch(choice)
		{
			case 1:
			{
				slowtype("Polynomial Function");
				cout<<"\n\n";
				slowtype2("Enter the degree of polynomial function (an integer greater than 0): ");
				cin>>n;
				cout<<"\n";

				for(int j=0;j<=n;j++)
				{
					push(j,n);
				}

				graphinput();

				while(1)
				{
					//loop1 to plot the points
					for(x=-xmax/(2*s);x<=xmax/(2*s);x+=p)
					{
						y=get_y_poly_function(x,n);
						if(xmax/2+(x*s)>xmax||xmax/2+(x*s)<0||ymax/2-(y*s)>ymax||ymax/2-(y*s)<0)
						{
							continue;
						}
						putpixel(xmax/2+(x*s),ymax/2-(y*s),LIGHTRED);
					}
					ch=getch();
					if(ch=='-')
					{
						s--;
						cd();
						graph();
					}
					else if(ch=='+')
					{
						s++;
						cd();
						graph();
					}
					else if(ch=='e')
					{
						break;
					}
				}
				top=NULL;
				break;
			}
			case 2:
			{
				slowtype("Conic Section");
				cout<<"\n\n";
				slowtype2("Enter the coefficient of x^2: ");
				cin>>a;
				slowtype2("Enter the coefficient of xy: ");
				cin>>h;
				slowtype2("Enter the coefficient of y^2: ");
				cin>>b;
				slowtype2("Enter the coefficient of x: ");
				cin>>g;
				slowtype2("Enter the coefficient of y: ");
				cin>>f;
				slowtype2("Enter the constant: ");
				cin>>c;

				graphinput();

				//loop2 to plot the points
				while(1)
				{
					for(x=-xmax/(2*s);x<=xmax/(2*s);x+=p)
					{
						y=get_y_conic_section_pos(x,a,h,b,g,f,c);
						putpixel(xmax/2+(x*s),ymax/2-(y*s),LIGHTRED);

						y=get_y_conic_section_neg(x,a,h,b,g,f,c);
						putpixel(xmax/2+(x*s),ymax/2-(y*s),LIGHTRED);
					}
					ch=getch();
					if(ch=='-')
					{
						s--;
						cd();
						graph();
					}
					else if(ch=='+')
					{
						s++;
						cd();
						graph();
					}
					else if(ch=='e')
					{
						break;
					}
				}
				break;
			}
			case 3:
			{
				slowtype("Special Graphs");
				cout<<"\n\n";
				special_graphs();
				break;
			}
			default:
			{
				slowtype("Invalid choice...");
				getch();
			}
		}

		cd();

		again();
	}
}