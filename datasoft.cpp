#include <iostream.h>
#include <graphics.h>
#include <fstream.h>
#include <process.h>
#include <iomanip.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <alloc.h>
#include <dos.h>

typedef char menu,msg;

int scan;
int ascii;
int hotkey;

menu mainmenu[13][40] = {

			   "Create Table            ",       //C
			   "Insert Into Table       ",       //I
			   "View / Select Table     ",       //V
			   "Update Table            ",       //U
			   "Perform Action          ",       //P
			   "Delete / Drop Table     ",       //D
			   "Truncate Table          ",       //T
			   "Rename Table            ",       //R

			   } ;

menu submenuperform[8][40] = {

				"Union                   ",        //U
				"Intersection            ",        //I
				"Get Minus               ",        //G
				"Compare Tables          ",        //C
				"Back                    "         //B

				} ;

class Main_menu
{
	private:
			int 	i,done;

	public :
			void    title();
			void    screens();                       //done
			void	datetoday();                     //done
			void    maintip(int,int);                //done
			void 	normalvideo(int,int,char*);      //done
			void 	reversevideo(int,int,char*);     //done
			void 	box(int,int,int,int);            //done
			void    hotkeys1();                      //done
			void    hotkeys2();                      //done
			void    hotkeys3();						 //done
			char 	showmenu();                      //done
			void 	controlmenu();                   //done
			char	showmenualter();                 //done
			char	showmenuperform();               //done
			char	showmenudel();                   //done
			int		endscreens();
};

class Designer
{
	public :
			void 	linehor(int,int,int,char);        //done
			void 	linever(int,int,int,char);        //done
			void 	box(int,int,int,int,char);        //done
};

class Interface :public Main_menu,public Designer
{
	private:
			int 	i,done;
			int 	searchintable();//pending

	public :
			void 	parttable();//pending             //w
			void 	partrow();//pending               //w
			void 	partcol();//pending               //w
			int 	deltab();//done
			int     createtab();//done
			int		inserttab();//done
			void 	dounion();//pending               //w
			void 	dointersect();//pending           //w
			void 	dominus();//pending               //w
			void 	docompare();//pending             //w
			int     viewtab();//done
			int		updatetab(); //pending
			int		perform();//done
			int		deletetab();//done
			int		droptab();//pending
			int		truncatetab();//done
			int 	renametab();//done
			int     help();//pending
			int 	about();//pending

};

class Backup
{
	private:
			int 	response;
			int		createfile();           //pending

	public :
			int		tableoftab();           //pending
			int		backupdata();          	//pending
			int     backuptab(); 	        //pending

};

class Subinterface : public Interface
{
	private:
			int		i,done;

	public :
			int	    msgbox(int,int,int,int,msg*);     //pending
			int		errorbox(int,int,int,int,msg*);   //pending
			int		savetofile();		              //pending

};
//CIVUAPDoTRHA
char hottykeys1[8]={'C','I','V','U','P','D','T','R'};
void Main_menu :: hotkeys1()
{
	highvideo();
	textcolor(YELLOW);
	for(int x=4,y=0;y<8;x++,y++)
	{
			gotoxy(2,x);
			cprintf("%c",hottykeys1[y]);
	}
	textcolor(BLUE);
}
//MAB
char hottykeys2[3]={'M','A','B'};
void Main_menu :: hotkeys2()
{
	textcolor(YELLOW);
	for(int x=4,y=0;y<3;x++,y++)
	{
		gotoxy(2,x);
		cprintf("%c",hottykeys2[y]);
	}
	textcolor(BLUE);
}
//SUIMJCB
char hottykeys3[5]={'U','I','G','C','B'};
void Main_menu :: hotkeys3()
{
	textcolor(YELLOW);
	for(int x=4,y=0;y<5;x++,y++)
	{
		gotoxy(2,x);
		cprintf("%c",hottykeys3[y]);
	}
	textcolor(BLUE);
}
void Main_menu :: title()
{
	highvideo();
	_setcursortype(_NOCURSOR);
	textcolor(BLACK);
	textbackground(CYAN);
	for(int i=0;i<80;i++)
	cprintf(" ");
	gotoxy(30,1);
	cprintf("ð D A T A S O F T ð");
	gotoxy(2,1);
	datetoday();
	gotoxy(71,1);
	cprintf("Esc : Exit");
}


// Main_menu			screens();
void Main_menu :: screens()
{
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
	setbkcolor(BLACK);
	setcolor(LIGHTGREEN);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	rectangle(20,20,getmaxx()-20,getmaxy()-20);
	setcolor(YELLOW);
	settextstyle(TRIPLEX_FONT,0,4);
	outtextxy(145,100,"ð D A T A S O F T ð");
	settextstyle(SANS_SERIF_FONT,0,3);
	outtextxy(125,200,"DATABASE MANAGEMENT PACKAGE");
	settextstyle(SANS_SERIF_FONT,0,1);
	outtextxy(50,380,"DEVELOPED  BY :");
	outtextxy(250,380,"P.G.K. Consultancy & Co.");
	outtextxy(50,400,"COPYRIGHT      :");
	outtextxy(250,400,"P.G.K. Consultancy & Co.");
	outtextxy(50,420,"LICENSED TO    :");
	outtextxy(250,420,"K.K.Wagh Polytechnic");
	getch();
	getch();
	closegraph();
	restorecrtmode();
	return;
}

// Main_menu           normalvideo();
void Main_menu :: normalvideo(int x,int y,char* str)
{
	gotoxy(x,y);
	cprintf("%s",str);
}

// Main_menu           reversevideo();
void Main_menu :: reversevideo(int x,int y,char* str)
{
	textcolor(WHITE);
	textbackground(LIGHTGRAY);
	gotoxy(x,y);
	cprintf("%s",str);
	textcolor(BLUE);
	textbackground(LIGHTGRAY);
}

// Main_menu			box();
void Main_menu :: box(int x1,int y1,int x2,int y2)
{
	for(int x = x1;x < x2;x++)
	for(int y = y1;y < y2;y++)
	{
		gotoxy(x,y);
		cprintf(" ");
	}
	textcolor(WHITE);
	for(int col = x1;col < x2;col++)
	{
		gotoxy(col,y1);
		cprintf("%c",205);
		gotoxy(col,y2);
		cprintf("%c",205);
	}
	for(int row = y1;row < y2;row++)
	{
		gotoxy(x1,row);
		cprintf("%c",186);
		gotoxy(x2,row);
		cprintf("%c",186);
	}
	gotoxy(x1,y1);
	cprintf("%c",201);
	gotoxy(x1,y2);
	cprintf("%c",200);
	gotoxy(x2,y1);
	cprintf("%c",187);
	gotoxy(x2,y2);
	cprintf("%c",188);
}

// Main_menu			showmenu();
char Main_menu :: showmenu()
{
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(34,2);
	cprintf(" Main Menu ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);
	textcolor(BLACK);
	cprintf("Warning:");
	gotoxy(2,20);
	cprintf("You should not move your cursor here and there.");
	textbackground(LIGHTGRAY);
	textcolor(BLUE);
	for(i = 0;i < 10;i++)
		normalvideo(2,i+4,mainmenu[i]);
	reversevideo(2,4,mainmenu[0]);
	hotkeys1();
	hotkey = 0;
	i = done = 0;
	do
	{
		textcolor(BLUE);
		int key = getch();
		switch(key)
		{
			case 0 :
					key = getch();
					switch(key)
					{
						case 72 :
									normalvideo(2,i+4,mainmenu[i]);
									i--;
									if(i == -1)
										i=7;
									reversevideo(2,i+4,mainmenu[i]);
									hotkeys1();
									break;
						case 80 :
									normalvideo(2,i+4,mainmenu[i]);
									i++;
									if(i == 8)
										i=0;
									reversevideo(2,i+4,mainmenu[i]);
									hotkeys1();
									break;
						case 46 :
									i=46;
									done=1;
									break;
						case 23 :
									i=23;
									done=1;
									break;
						case 47 :
									i=47;
									done=1;
									break;
						case 22 :
									i=22;
									done=1;
									break;
						case 25 :
									i=25;
									done=1;
									break;
						case 32 :
									i=32;
									done=1;
									break;
						case 20 :
									i=20;
									done=1;
									break;
						case 19 :
									i=19;
									done=1;
									break;
						case 35 :
									i=35;
									done=1;
									break;
						case 30 :
									i=30;
									done=1;
									break;
					}
					break;

			case 13 :
						done = 1;
						break;
			case 27 :
						char ans='y';
						gotoxy(29,24);
						textcolor(BLACK);
						cprintf("Are You Sure : [Y]  N");
						ans=getch();
						if(ans=='y' || ans=='Y' || ans==13)
						{
							clrscr();
							exit(0);
						}
						else
							gotoxy(29,24);
							cprintf("                     ");
							continue;
		}

	}while(!done);
	_setcursortype(_NOCURSOR);
	if(i>18)
		return i;
	else
		return(i+49);
}

// Main_menu			controlmenu();
void Main_menu :: controlmenu()
{
	char choice;
	Subinterface s;
	do
	{
		clrscr();
		choice = showmenu();
		clrscr();
		_setcursortype(_NORMALCURSOR);
		switch(choice)
		{
			case 46  :
			case '1' :
					s.createtab();
					break;

			case 23  :
			case '2' :
					s.inserttab();
					break;

			case 47  :
			case '3' :
					s.viewtab();
					break;

			case 22  :
			case '4' :
					s.updatetab();
					break;

			case 25  :
			case '5' :
					s.perform();
					break;

			case 32  :
			case '6' :
					s.deletetab();
					break;
										 //CIVUMPDTRHA
			case 20  :
			case '7' :
					s.truncatetab();
					break;

			case 19  :
			case '8' :
					s.renametab();
					break;

			case 35  :
			case '9' :
					s.help();
					break;

			case 30  :
			case '10':
					s.about();
					break;

			}
		controlmenu();
	}while(choice=='X'||choice==27);
}

// Main_menu			datetoday();
void Main_menu :: datetoday()
{
	struct dostime_t t;
	struct date d;
	getdate(&d);
	cprintf("%d-%d-%d",d.da_day,d.da_mon,d.da_year);
};

// Main_menu			maintip();
void Main_menu :: maintip(int x,int y)
{
	char statusmsg1[]="TIP : USE UP / DOWN ARROW KEYS TO NAVIGATE IN BETWEEN THE OPTIONS";
	textcolor(WHITE);
	gotoxy(x,y);
	textbackground(BLACK);
	cprintf("%s",statusmsg1);
	gotoxy(x,y+1);
	return;
}


// Main_menu			showmenuview();
int Interface :: viewtab()
{

	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuView Table ");

	gotoxy(1,3);
	textcolor(WHITE);
	textbackground(BLACK);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(WHITE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}
	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);

	gotoxy(2,18);
	textcolor(WHITE);
	_setcursortype(_NORMALCURSOR);
	fstream view;
	int x = 1;
	char filename[8];
	while(x==1)
	{
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars.");
		textbackground(BLACK);
		gotoxy(41,6);
		cprintf("                ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name ");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
			//	textcolor(BLACK);
				cin>>filename;
				if(strlen(filename) > 8)
				{
					textcolor(WHITE);
					gotoxy(2,23);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		view.open(filename,ios::in);
		if(view==NULL)
		{
			textcolor(WHITE);
			gotoxy(2,23);
			cprintf("Cannot View The Table,Might Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,12);
	cprintf("                                                    ");
	char colname[10];
	char colcontent[15];
	int num,normal = 0,n = 0;
	view>>num;
	textcolor(WHITE);
	linehor(1,57,7,'Í');
	linehor(1,57,9,'Í');
	gotoxy(2,12);
	if(num==0 || sizeof(view)==0)
		cprintf("Table Has No Rows To View.");
	else
	{
		int count1 = (int)(58 / num);
		int count = 2;
		while(n < num)
		{
			if(count<58)
			{
				gotoxy(count,8);
				view>>colname;
				cout<<setw(count1-2)<<setiosflags(ios::left)<<colname;
			}
			count=count+count1;
			n++;
		}
		count = 2;
		n = 0;
		int ctr = 10;
		while(view)
		{
			if(count<58)
			{
				gotoxy(count,ctr);
				view>>colcontent;
				cout<<setw(count1-2)<<setiosflags(ios::left)<<colcontent;
				count=count+count1;
			}
			else
			{
				count = 2;
				ctr++;
			}
			n++;
		}

		textcolor(WHITE);
		linehor(1,57,ctr,'Í');
	}
	textcolor(WHITE);
	textbackground(BLACK);
	_setcursortype(_NOCURSOR);
	gotoxy(2,21);
	cprintf("Total No. Of Records Viewed.: %d",(int)(n/num)-2);
	gotoxy(2,22);
	cprintf("Data Successfully Viewed From Table.");
	getch();
	getch();
	controlmenu();
	return 0;
}

int Interface :: updatetab()
{
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuUpdate Table ");

	gotoxy(1,3);
	textcolor(WHITE);
	textbackground(BLACK);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(WHITE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}
	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);

	gotoxy(2,18);
	textcolor(WHITE);
	_setcursortype(_NORMALCURSOR);
	fstream updatethis;
	int x = 1;
	char filename[8];
	while(x==1)
	{
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars.");
		textbackground(BLACK);
		gotoxy(41,6);
		cprintf("                ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name ");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
			//	textcolor(BLACK);
				cin>>filename;
				if(strlen(filename) > 8)
				{
					textcolor(WHITE);
					gotoxy(2,23);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		updatethis.open(filename,ios::in);
		if(updatethis==NULL)
		{
			textcolor(WHITE);
			gotoxy(2,23);
			cprintf("Cannot Update The Table,Might Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,23);
	cprintf("                                                    ");
	char colname[10];
	char colcontent[15];
	int num,normal = 0,n = 0;
	int ctr = 10;
	updatethis>>num;
	int count1 = (int)(58 / num);
	int count = 2;
	textcolor(WHITE);
	linehor(1,57,7,'Í');
	linehor(1,57,9,'Í');
	gotoxy(2,12);
	if(num==0 || sizeof(updatethis)==0)
		cprintf("Table Has No Rows To Update.");
	else
	{
		while(n < num)
		{
			if(count<58)
			{
				gotoxy(count,8);
				updatethis>>colname;
				cout<<setw(count1-2)<<setiosflags(ios::left)<<colname;
			}
			count=count+count1;
			n++;
		}
		count = 2;
		n = 0;

		while(updatethis)
		{
			if(count<58)
			{
				gotoxy(count,ctr);
				updatethis>>colcontent;
				cout<<setw(count1-2)<<setiosflags(ios::left)<<colcontent;
				count=count+count1;
			}
			else
			{
				count = 2;
				ctr++;
			}
			n++;
		}

		textcolor(WHITE);
		linehor(1,57,ctr,'Í');
	}
	textcolor(WHITE);
	gotoxy(2,ctr+2);
	int net = 0;
	int k=ctr+4;
	char ans='y',update1[10];
	fstream temp;
	temp.open("temp.pgk",ios::out);
	cprintf("Want To Upadate It ?(y/n) ");
	ans=getche();
	if(ans=='y')
	{
		gotoxy(2,k);
		cprintf("Enter First Column Of Row,Which Is To Be Updated :");
		cin>>update1;
		updatethis.seekg(0,ios::beg);
		updatethis>>num;
		temp<<num<<endl;
		char xcolname[4][10];
		count1 = (int)(58 / num);
		count = 2;

		while(n < num)
		{
			updatethis>>xcolname[n];
			temp<<xcolname[n]<<endl;
			n++;
		}

		while(updatethis)
		{
			updatethis>>colcontent;

			if(strcmpi(colcontent,update1)==0)
			{
				textcolor(WHITE);
				gotoxy(2,12);
				for(int i = 0;i < num;i++)
				{
					textbackground(BLACK);
					gotoxy(36,i+22);
					cprintf("              ");
					textbackground(BLACK);
				}
				for(i = 0;i < num;i++)
				{
					textcolor(WHITE);
					textbackground(BLACK);
					gotoxy(2,i+22);
					cprintf("Enter value of %s",xcolname[i]);
					gotoxy(35,i+22);
					cprintf("");
					textcolor(WHITE);
					textbackground(BLACK);
					cscanf("%s",colcontent);
					temp<<colcontent<<endl;
					getch();
				}
				net++;
			}
			else
			{
				temp<<colcontent<<endl;
			}

		}
		updatethis.close();
		temp.close();
		updatethis.open(filename,ios::out|ios::app|ios::nocreate);
		temp.open("temp.pgk",ios::in);
		n = 0;
		temp>>num;
		updatethis<<num;
		while(temp)
		{
			while(n < num)
			{
				temp>>colname;
				updatethis<<colname<<endl;
				n++;
			}
			while(temp)
			{
					temp>>colcontent;
					updatethis<<colcontent<<endl;
			}
		}
		cout<<"\n";
		cout<<"Table Updated Successfully.";
	}
	else
	{
		gotoxy(2,k);
		cout<<"Table Is Unupdated.";
	}
	textcolor(YELLOW);
	gotoxy(2,23);
	cout<<"\nNo. Of Rows Updated.:"<<net;
	getch();
	_setcursortype(_NOCURSOR);
	return 0;
}

char Main_menu :: showmenuperform()
{
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuPerform Action ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);
	textcolor(BLACK);
	cprintf("Warning:");
	gotoxy(2,20);
	cprintf("You should not move your cursor here and there.");
	textbackground(LIGHTGRAY);
	textcolor(BLUE);
	for(i = 0;i < 7;i++)
		normalvideo(2,i+4,submenuperform[i]);
	reversevideo(2,4,submenuperform[0]);
	hotkeys3();
	i=0;
	i = done = 0;
	_setcursortype(_NOCURSOR);
	do
	{
		textcolor(BLUE);
		int key = getch();
		switch(key)
		{
			case 0 :
					key = getch();
					switch(key)
					{
						case 72 :
									normalvideo(2,i+4,submenuperform[i]);
									i--;
									if(i == -1)
										i=4;
									reversevideo(2,i+4,submenuperform[i]);
									hotkeys3();
									break;
						case 80 :
									normalvideo(2,i+4,submenuperform[i]);
									i++;
									if(i == 5)
										i=0;
									reversevideo(2,i+4,submenuperform[i]);
									hotkeys3();
									break;
									//SUIMJCB
						case 22 :
									i=22;
									done=1;
									break;
						case 23 :
									i=23;
									done=1;
									break;
						case 34 :
									i=34;
									done=1;
									break;
						case 46 :
									i=46;
									done=1;
									break;
						case 48 :
									i=48;
									done=1;
									break;
						}
						break;
			case 13 :
						done = 1;
						break;
			case 27 :   char ans='y';
						textcolor(BLACK);
						gotoxy(29,24);
						cprintf("Are You Sure : [Y]  N");
						ans=getch();
						if(ans=='y' || ans=='Y' || ans==13)
							exit(0);
						else
							gotoxy(29,24);
							cprintf("                      ");
							continue;
						textcolor(BLUE);
		}
	}
	while(!done);
	_setcursortype(_NOCURSOR);
	if(i>18)
		return i;
	else
		return(i+49);
}

int Interface :: perform()
{
	char choice;
	Subinterface s;
	do
	{
		choice = showmenuperform();
		clrscr();
		_setcursortype(_NORMALCURSOR);
		switch(choice)
		{
			case 31 :
/*			case '1':                                    */
/*					    s.searchtab();                   */
						break;
			case 22 :
			case '1':
						s.dounion();
						break;
			case 23 :
			case '2':
						s.dointersect();
						break;
			case 34 :
			case '3':
						s.dominus();
						break;
			case 36 :
/*			case '5':                              */
/*					    s.join();                  */
						break;
			case 46 :
			case '4':
						s.docompare();
						break;
			case 48 :
			case '5':
						controlmenu();
		}
	}
	while(choice!=0 || choice!=27);
	return 0;
}

int Interface :: deletetab()
{
	clrscr();
	_setcursortype(_SOLIDCURSOR);
	char filename[8];
	int x=1;
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuDelete / Drop Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);
	textcolor(BLACK);
	cprintf("Warning:");
	gotoxy(2,20);
	cprintf("You should not move your cursor here and there.");
	fstream delete1;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars.");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name ");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,12);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		delete1.open(filename,ios::out | ios::nocreate);
		if(delete1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,12);
			cprintf("Cannot Delete The Table,Might Be Not existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,12);
	cprintf("                                                    ");
	gotoxy(2,12);
	cprintf("Table Is Successfully Deleted.");
	delete1.close();
	flush(delete1);
	getch();
	_setcursortype(_NOCURSOR);
	return 0;
}

void Designer :: linehor(int column1,int column2,int row,char c)
{
	for(column1;column1<=column2;column1++)
	{
		gotoxy(column1,row);
		cprintf("%c",c);
	}
}

void Designer :: linever(int row1,int row2,int column,char c)
{
	for(row1;row1<=row2;row1++)
	{
		gotoxy(column,row1);
		cout<<c;
	}
}

void Designer :: box(int column1,int row1,int column2,int row2,char c)
{
	char ch = 218;
	char c1,c2,c3,c4;
	char l1=196,l2=179;
	if(c == ch)
	{
		c1 = 218;
		c2 = 191;
		c3 = 217;
		c4 = 217;
		l1 = 196;
		l2 = 179;
	}
	else
	{
		c1 = c;
		c2 = c;
		c3 = c;
		c4 = c;
		l1 = c;
		l2 = c;
	}
	gotoxy(column1,row1);
	cout<<c1;
	gotoxy(column2,row1);
	cout<<c2;
	gotoxy(column1,row2);
	cout<<c3;
	gotoxy(column2,row2);
	cout<<c4;
	column1++;
	column2--;
	linehor(column1,column2,row1,l1);
	linehor(column1,column2,row1,l1);
	column1++;
	column2--;
	row1++;
	row2--;
	linever(row1,row2,column1,l2);
	linever(row1,row2,column2,l2);
}

int Interface :: help()
{
	return 0;
}

int Interface :: about()
{
	return 0;
}

int Interface :: truncatetab()
{
	textmode(C80);
	char filename[20];
	int x=1;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuTruncate Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	gotoxy(2,18);
	textcolor(BLACK);
	cprintf("Warning:");
	gotoxy(2,20);
	cprintf("You should not move your cursor here and there.");

	fstream truncate;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars.");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name ");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,12);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		truncate.open(filename,ios::out | ios::nocreate);
		if(truncate==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,12);
			cprintf("Cannot Truncate the Table.Might be not existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,12);
	cprintf("                                                    ");
	gotoxy(2,12);
	cprintf("Table Is Successfully Truncated.");
	truncate.close();
	getch();
	flush(truncate);

	return 0;
}

int Interface :: createtab()
{
	clrscr();
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuCreate Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	char filename[8];
	char colname[10],strnum[10],c;
	int x=1,n=0,num;
	fstream create,tab;
	_setcursortype(_SOLIDCURSOR);
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name ");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		create.open(filename,ios::out|ios::noreplace);
		tab.open("TAB.pgk",ios::app|ios::nocreate);
		tab<<filename<<endl;
		if(create==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Cannot create the Table.May already be existed.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	int y = 0;
	while(y==0)
	{
		i=0;
		gotoxy(2,8);
		textcolor(BLUE);
		cprintf("Enter the no. of Fields ");
		gotoxy(40,8);
		cprintf("");
		textcolor(BLACK);
		cscanf("%s",strnum);
		num=atoi(strnum);
		if(num < 0 || num > 4)
		{
			y = 0;
			gotoxy(2,22);
			cprintf("Invalid Entry.");
			textcolor(BLUE);
			gotoxy(40,8);
			cprintf("       ");
		}
		else
			y = 1;
		getch();

	}
	gotoxy(2,22);
	cprintf("                ");
	create<<num<<endl;
	textcolor(BLUE);
	gotoxy(2,10);
	cprintf("Enter the Field Names ");
	for(x=11,i=0;i<num;i++,x++)
	{
		strcpy(colname,"");
		textcolor(BLUE);
		gotoxy(2,x);
		cprintf("Field No. %d ",i+1);
		gotoxy(40,x);
		cprintf("");
		textcolor(BLACK);

		cscanf("%s",colname);
		create<<colname<<endl;
	}
	gotoxy(2,x+2);
	cprintf("Table created successfully !!!");
	getch();
	create.close();
	getch();
	_setcursortype(_NOCURSOR);
	return 0;
}

int Interface :: renametab()
{
	clrscr();
	textmode(C80);
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuRename Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");

	char filename1[8],filename2[8];
	char c;
	int x=1,n=0,num;
	fstream rename1;
	_setcursortype(_SOLIDCURSOR);
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,7);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,7);
		cprintf("Enter Table Name To Be Renamed");
		gotoxy(40,7);
		cprintf("");
		int key = getch();
		while(1)
		{
			gotoxy(41,7);
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename1);
				if(strlen(filename1) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename1,".pgk");
		rename1.open(filename1,ios::in);
		if(rename1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Cannot Renamed The Table May Not Be Existng.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	x=1;
	while(x==1)
	{
		textcolor(LIGHTGRAY);
		gotoxy(40,10);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,10);
		cprintf("Enter Table's New Name ");
		gotoxy(40,10);
		cprintf("");
		int key = getch();
		while(1)
		{
			gotoxy(41,10);
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename2);
				if(strlen(filename2) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename2,".pgk");
		x=0;
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	gotoxy(2,15);
	if(rename(filename1,filename2)==0)
		cprintf("Table Renamed Successfully.");
	else
		cprintf("System Error Has Occured.Sorry.");
	_setcursortype(_NOCURSOR);
	rename1.close();
	getch();
	return 0;
} //addcol

int Interface :: inserttab()
{
	clrscr();
	textmode(C80);
	char filename[8];
	char colname[4][8]={"","","",""};
	char colcontent[10];
	int num,normal = 0;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuInsert Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	fstream insert;
	int x = 1;
	_setcursortype(_NORMALCURSOR);
	while(x == 1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textbackground(BLACK);
		gotoxy(40,5);
		cprintf("               ");
		textbackground(LIGHTGRAY);
		textcolor(BLUE);
		gotoxy(2,5);
		cprintf("Enter Table Name");
		gotoxy(40,5);
		cprintf("");
		textbackground(BLACK);
		int key = getch();
		gotoxy(41,5);
		while(1)
		{
			if(key!=27)
			{
				textcolor(WHITE);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					textbackground(LIGHTGRAY);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		insert.open(filename,ios::in|ios::nocreate);
		if(insert==NULL)
		{
			textcolor(BLACK);
			textbackground(LIGHTGRAY);
			gotoxy(2,22);
			cprintf("Cannot Insert Into This Table,Might Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
		textbackground(LIGHTGRAY);
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	insert>>num;
	textcolor(BLACK);
	linehor(1,57,7,'Í');
	int count1 = (int)(58 / num);
	int count = 2,n = 0;
	while(n < num)
	{
		if(count<58)
		{
			gotoxy(count,8);
			insert>>colname[n];
			cprintf("%s",colname[n]);
		}
		count = count + count1;
		n++;
	}
	textcolor(BLACK);
	linehor(1,57,9,'Í');
	insert.close();
	insert.open(filename,ios::app|ios::nocreate);
	textcolor(BLUE);
	gotoxy(2,10);
	cprintf("These Are Fields Of Selected Table.Insert Data Into");
	gotoxy(2,11);
	cprintf("Them As Asked.Enter 'END' To Exit Inserting Data.");
	n = 0;

	while(strcmpi(colcontent,"END")!=0)
	{
		textcolor(LIGHTGRAY);
		gotoxy(2,12);
		for(int i = 0;i < num;i++)
		{
			textbackground(BLACK);
			gotoxy(36,i+12);
			cprintf("              ");
			textbackground(LIGHTGRAY);
		}
		for(i = 0;i < num;i++)
		{
			textcolor(BLUE);
			textbackground(LIGHTGRAY);
			gotoxy(2,i+12);
			cprintf("Enter value of %s",colname[i]);
			gotoxy(35,i+12);
			cprintf("");
			textcolor(WHITE);
			textbackground(BLACK);
			cscanf("%s",colcontent);
			if(strcmpi(colcontent,"END")==0)
				break;
			insert<<colcontent<<endl;
			getch();
		}
		textcolor(YELLOW);
		textbackground(LIGHTGRAY);
		gotoxy(2,19);
		cprintf("Enter Again From First.");
		n++;
	}
	textcolor(BLACK);
	textbackground(LIGHTGRAY);
	_setcursortype(_NOCURSOR);
	gotoxy(2,21);
	cprintf("Total No. Of Records Added.: %d",n);
	gotoxy(2,22);
	cprintf("Data Successfully Added In Table.");
	getch();
	getch();
	controlmenu();
	return 0;
}

void Interface :: docompare()
{
	clrscr();
	textmode(C80);
	char filename[8];
	int num1,num2,x=1;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuPerform ActionCompare Tables ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	gotoxy(60,19);
	putch(27);
	putch(26);
	putch('=');
	cprintf("Select Menu");
	gotoxy(60,20);

	putch(24);
	putch(25);
	putch('=');
	cprintf("Select Option");
	fstream compare1,compare2;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name 1");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		compare1.open(filename,ios::in|ios::nocreate);
		if(compare1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Cannot Compare This Table.Might Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	x=1;
	strcpy(filename,"");
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,9);
		cprintf("Enter Table Name 2");
		gotoxy(40,9);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename);
				if(strlen(filename) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename,".pgk");
		compare2.open(filename,ios::in|ios::nocreate);
		if(compare2==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Cannot Compare This Table.May Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	int size1=sizeof(compare1);
	int size2=sizeof(compare2);
	textcolor(BLACK);
	gotoxy(2,12);
	if(size1>size2)
		cprintf("First Table Is Greater Than Second.");
	else if(size1<size2)
			cprintf("Second Table Is Greater Than First.");
		 else
			cprintf("Both Tables Are Equal To Each Other.");
	getch();
}


void Interface :: dounion()
{
	clrscr();
	textmode(C80);
	char filename[8];
	int num1,num2,x=1;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuPerform ActionUnion ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	int num;
	char filename1[8],filename2[8];
	char colname[10];
	fstream tab1,tab2,doneunion;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name 1");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename1);
				if(strlen(filename1) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename1,".pgk");
		tab1.open(filename1,ios::in|ios::nocreate);
		if(tab1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Table Does Not Exist");
			x=1;
		}
		else
		{
			x = 0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	x = 1;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(40,8);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,8);
		cprintf("Enter Table Name 2");
		gotoxy(40,8);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename2);
				if(strlen(filename2) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename1,".pgk");
		tab2.open(filename2,ios::in|ios::nocreate);
		if(tab2==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Table Doesnot Exist.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                           ");
	tab1>>num1;
	tab2>>num2;
	doneunion.open("uniondone.pgk",ios::out);
	if(num1!=num2)
	{
		gotoxy(2,20);
		cout<<"Union Not Possible.";
		getch();
		perform();
	}
	int n=0;
	while(n < num1)
	{
		tab1>>colname[n];
		doneunion<<colname[n]<<endl;
	}

	n = 0;
	int flag=0;
	doneunion<<num;

	getch();
	perform();
}

void Interface::dointersect()
{
	clrscr();
	textmode(C80);
	char filename1[8],filename2[8];
	int num1,num2,x=1;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuPerform ActionIntersect ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	fstream tab1,tab2;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename1);
				if(strlen(filename1) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename1,".pgk");
		tab1.open(filename1,ios::in|ios::nocreate);
		if(tab1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Table Doesn't Exist.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	x = 1;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename2);
				if(strlen(filename2) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename2,".pgk");
		tab2.open(filename2,ios::in|ios::nocreate);
		if(tab2==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Table Doesn't Exist.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	gotoxy(2,18);
	cout<<"Intersection Of Tables Done.";
	getch();
	controlmenu();
}

void Interface::dominus()
{
	clrscr();
	textmode(C80);
	char filename1[8],filename2[8];
	int num1,num2,x=1;
	title();
	textbackground(BLUE);
	gotoxy(1,2);
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(LIGHTGRAY);
	gotoxy(28,2);
	cprintf(" Main MenuPerform ActionSearch Table ");

	gotoxy(1,3);
	textcolor(LIGHTGRAY);
	textbackground(LIGHTGRAY);

	for(int j=0;j<22;j++)
	for(i=0;i<80;i++)
	cprintf(" ");

	textcolor(BLUE);
	for(i=4;i<24;i++)
	{
		gotoxy(58,i);
		cprintf("³");
	}

	fstream tab1,tab2;
	while(x==1)
	{
		textcolor(BLUE);
		gotoxy(2,4);
		cprintf("Remember : Names Should Not Exceed 8 chars");
		textcolor(LIGHTGRAY);
		gotoxy(40,6);
		cprintf("               ");
		textcolor(BLUE);
		gotoxy(2,6);
		cprintf("Enter Table Name");
		gotoxy(40,6);
		cprintf("");
		int key = getch();
		while(1)
		{
			if(key!=27)
			{
				textcolor(BLACK);
				cscanf("%s",filename1);
				if(strlen(filename1) > 8)
				{
					textcolor(BLACK);
					gotoxy(2,22);
					cprintf("Table Name Too Long.");
					continue;
				}
				else
					break;
			}
			else
				controlmenu();
		}
		strcat(filename1,".pgk");
		tab1.open(filename1,ios::in|ios::nocreate);
		if(tab1==NULL)
		{
			textcolor(BLACK);
			gotoxy(2,22);
			cprintf("Cannot Search This Table.Might Not Be Existing.");
			x=1;
		}
		else
		{
			x=0;
		}
		getch();
	}
	gotoxy(2,22);
	cprintf("                                                    ");
	int num;
	gotoxy(2,18);
	cout<<"Minus Of These Tables Is Done.";
	getch();
	controlmenu();
}

int main()
{
	Main_menu m_menu;
	int gdriver=DETECT,gmode,j=1;
	char pass[10]="PGK$",newpass[10];
	textmode(C80);
	fstream install;
	install.open("c:\\Program Files\\Install.dll",ios::out|ios::nocreate);
/*	if(install==NULL)
	{
		clrscr();
		cout<<"      Welcome To..\n\n";
		cout<<"\t***************DATA********************\n\n";
		cout<<"\t***************SOFT********************\n\n";
		delay(2000);
		cout<<"     The Application Has Not Been Installed On This System.....\n";
		delay(2000);
		cout<<"     The System Does Not Contain Any Database Required For This Application....\n";
		delay(2000);
		cout<<"     If You Wish To Install It Start \"Setup\" File.";
		getch();
		getch();
		exit(0);
	}

*/	cout<<"Welcome To..\n\n";
	cout<<"\t***************DATA********************\n\n";
	cout<<"\t***************SOFT********************\n\n";

	textcolor(BLACK);
	while(j!=0)
	{
	for(int i=0;i<3;i++)
	{
	cout<<"\n\nEnter Password :";
	cscanf("%s",newpass);
	if(strcmp(newpass,pass)!=0)
	{
		cout<<"\nIncorrect Password.";
		continue;
	}
	else
		j=0;
		break;
	}
	}
	if(j==0)
	{
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		m_menu.screens();
		closegraph();
		m_menu.controlmenu();
	}
	getch();
	return 0;
}