//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
			     //SOURCE CODE
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		   //including header files//
#include<GRAPHICS.H>
#include<IOSTREAM.H>
#include<FSTREAM.H>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<ctype.h>
//***************************************************************************
#include"C:\TC\BIN\ADMIN.CPP"
//***************************************************************************
		    //GLOBAL FUNCTIONS//
void screen();           //welcome screen
void modemmenu();        //mode selection menu page
void dispmenu();         //game menu page
void wordwrap();         //for playing word wrap game
void jumble();           //for playing jumbled words game
void wrong();            //for the failure of the user
void congrats();         //for the success of the user
int sort();              //to sort score for jumble up game
int sort1();             //to sort score for word wrap game
void password();         //for password encryption
//***************************************************************************
		    //GLOBAL OBJECTS & CLASSES~~~
int iff=0;
char wstr[50][50];
int score=0;
class hscorew        //for high score of word wrap
{
 public:
 int h[5];
}ss;
class hscorej       //for high score of jumbled words
{
 public:
 int h[5];
}rr;
class num
{
 public:
 char ch[10];
 char chh[4];
 void num1();
}s;
void num::num1()
{
 ifstream fp1;
 char str[50];
 fp1.open("C:/TC/BIN/QDICT.TXT");
 if(!fp1)
 {
  cout<<"ERROR in opening...";
  getch();
 }
 do
 {
  fp1.getline(str,50);
  strcpy(wstr[iff],str);
  iff++;
 }while(fp1);
 fp1.close();
}
//****************************************************************************
void dispmenu()
{
 clrscr();
 char ch;
 do
 {
  cleardevice();
  setbkcolor(15);
  settextstyle(7,0,5);
  setcolor(12);
  outtextxy(50,50,"--MENU PAGE--");
  outtextxy(70,150,"A.PLAY WORD WRAP.");
  outtextxy(70,250,"B.PLAY JUMBLE UP.");
  outtextxy(70,350,"C.EXIT");
  settextstyle(8,0,3);
  setcolor(2);
  outtextxy(70,400,"ENTER YOUR CHOICE(A--C):");
  cin>>ch;
  ch=getch();
  ch=toupper(ch);
  switch(ch)
  {
   case 'A': settextstyle(7,0,5);
	     for(int i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,150,"A.PLAY WORD WRAP.");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,150,"A.PLAY WORD WRAP.");
	      delay(800);
	     }
	     wordwrap();
	     break;
   case 'B': settextstyle(7,0,5);
	     for(i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,250,"B.PLAY JUMBLE UP.");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,250,"B.PLAY JUMBLE UP.");
	      delay(800);
	     }
	     jumble();
	     break;
   case 'C': settextstyle(7,0,5);
	     for(i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,350,"C.EXIT");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,350,"C.EXIT");
	      delay(800);
	     }
	     closegraph();
	     exit(0);
   default : cout<<"\nENTER A VALID OPTION.";
	     getch();
	     break;
  }
 }while(ch!='C');
}
//***************************************************************************
void screen()
{
 setcolor(1);
 for(int i=0;i<200;i++)
 {
  circle(300,250,i);
  delay(10);
 }
 delay(1000);
 setcolor(3);
 settextstyle(1,0,4);
 outtextxy(155,142,"By:Radhika Singla");
 outtextxy(320,155,"         XII-CCA");
 delay(1000);
 settextstyle(7,0,4);
 for(i=0;i<=6;i++)
 {
  if(i%2==0)
  {
   setcolor(2);
   outtextxy(220,200,"JUMBLED WORDS");
   delay(400);
   setcolor(1);
   outtextxy(220,200,"JUMBLED WORDS");
  }
  else
  {
   setcolor(2);
   outtextxy(220,300,"WORD WRAP");
   delay(800);
   setcolor(1);
   outtextxy(220,300,"WORD WRAP");
  }
 }
 setcolor(5);
 outtextxy(220,200,"JUMBLED WORDS");
 outtextxy(220,300,"WORD WRAP");
 getch();
}
//*****************************************************************************
void modemenu()
{
 char ch;
 do
 {
  cleardevice();
  setbkcolor(15);
  settextstyle(7,0,5);
  setcolor(12);
  outtextxy(50,50,"--MAIN MENU PAGE--");
  outtextxy(70,150,"A.ADMIN MODE.");
  outtextxy(70,250,"B.GAME MODE.");
  outtextxy(70,350,"C.EXIT");
  settextstyle(8,0,3);
  setcolor(2);
  outtextxy(70,400,"ENTER YOUR CHOICE(A--C):");
  cin>>ch;
  ch=getch();
  ch=toupper(ch);
  switch(ch)
  {
   case 'A': settextstyle(7,0,5);
	     for(int i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,150,"A.ADMIN MODE.");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,150,"A.ADMIN MODE.");
	      delay(800);
	     }
	     clrscr();
	     cleardevice();
	     rectangle(10,10,630,470);
	     password();
	     break;
   case 'B': settextstyle(7,0,5);
	     for(i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,250,"B.GAME MODE.");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,250,"B.GAME MODE.");
	      delay(800);
	     }
	     dispmenu();
	     break;
   case 'C': settextstyle(7,0,5);
	     for(i=0;i<3;i++)
	     {
	      setcolor(1);
	      outtextxy(70,350,"C.EXIT");
	      delay(800);
	      setcolor(4);
	      outtextxy(70,350,"C.EXIT");
	      delay(800);
	     }
	     closegraph();
	     exit(0);
   default : cout<<"\nENTER A VALID OPTION.";
	     getch();
	     break;
  }
 }while(ch!='C');
}
//*****************************************************************************
void wrong()
{
 cleardevice();
 setcolor(4);
 setbkcolor(15);
 settextstyle(3,0,3);
 for(int i=0;i<5;i++)
 {
  for(int j=0;j<10;j++)
  {
   outtextxy(i*150,j*48,"WRONG WORD!!");
  }
  delay(100);
 }
 getch();
 cleardevice();
}
//****************************************************************************
void congrats()
{
 cleardevice();
 setbkcolor(5);
 setcolor(7);
 settextstyle(5,0,1);
 outtextxy(20,200,"CONGRATS! YOU HAVE COMPLETED THIS LEVEL.");
 outtextxy(20,250,"LET'S MOVE ON TO THE NEXT STAIR OF SUCCESS");
 outtextxy(20,300,"IN THE GAME.");
 getch();
}
//****************************************************************************
int sort()
{
 for(int i=0;i<5;i++)
 {
  if(score>=rr.h[i])
  {
   for(int j=4;j>i;j--)
   {
    rr.h[j]=rr.h[j-1];
   }
   rr.h[i]=score;
   return 1;
  }
 }
 return 0;
}
//****************************************************************************
void jumble()
{
 char rep;
 char str[15][3];
 int ctr=0;
 int r;
 do
 {
  cleardevice();
  getch();
  setbkcolor(3);
  setcolor(4);
  settextstyle(3,0,3);
  outtextxy(75,115,"In the game, you will be");
  outtextxy(75,155,"provided with a jumbled word ");
  outtextxy(75,195,"which you are supposed to unscramble.");
  outtextxy(75,235,"On each correct word,100 points will ");
  outtextxy(75,275,"be added to your score.");
  outtextxy(75,315,"GOOD LUCK!!");
  outtextxy(75,355,"HERE WE GO-> -> ->....");
  getch();
  cleardevice();
  r=rand()%40;
  ctr=strlen(wstr[r]);
  for(int i=0;i<ctr;i++)
  {
   str[i][0]=wstr[r][i];
   str[i][1]='\0';
  }
  setbkcolor(3);
  setcolor(5);
  settextstyle(3,0,3);
  for(i=0;i<ctr;i++)
  {
   rectangle(100+40*i,150,140+40*i,190);
   delay(300);
  }
  int f,flag=0;
  f=rand()%ctr;
  if(f%2==0)
  {
   for(int o=0;o<ctr;o+=2)
   {
    outtextxy(110+20*o,158,str[o]);
    delay(100);
    flag+=2;
   }
   for(o=1;o<ctr;o+=2)
   {
    outtextxy(90+20*(o+flag),158,str[o]);
    delay(100);
   }
  }
  if(f%2==1)
  {
   for(int o=1;o<ctr;o+=2)
   {
    outtextxy(90+20*o,158,str[o]);
    flag+=2;
    delay(100);
   }
   flag+=1;
   for(o=0;o<ctr;o+=2)
   {
    outtextxy(90+20*(o+flag),158,str[o]);
    delay(100);
   }
  }



  for(i=0;i<ctr;i++)
  {
   rectangle(100+40*i,350,140+40*i,390);
   delay(300);
  }
  char ans[50];
  char ans1[15][3];
  int temp=0;
  setcolor(1);
  outtextxy(10,500,"ENTER YOUR ANSWER:");
  for(i=0;i<ctr;i++)
  {
   cin>>ans[i];
   ans1[i][0]=toupper(ans[i]);
   ans1[i][1]='\0';
   outtextxy(110+40*i,358,ans1[i]);
  }
  ans[i]='\0';
  getch();
  for(i=0;i<iff;i++)
  {
   if(strcmp(wstr[i],ans)==0)
   {
    temp++;
   }
  }
  if(temp!=0)
  {
   score+=100;
   congrats();
  }
  else
  {
   wrong();
  }
  cleardevice();
  settextstyle(3,0,2);
  outtextxy(200,200,"DO YOU WANT TO CONTINUE");
  outtextxy(200,250,"WITH THE GAME?");
  outtextxy(160,300,"Y FOR YES N FOR NO:");
  cin>>rep;
  rep=toupper(rep);
  if(rep=='N')
  {
   fstream sc;
   sc.open("C:/TC/BIN/SCORE.DAT",ios::in|ios::app|ios::binary);
   char sas[5],saa[5],sab[5],sac[5],sad[5],sae[5];
   cleardevice();
   sc.seekg(0,ios::beg);
   sc.read((char*)&rr,sizeof(rr));
   int p=sort();
   sc.seekp(0,ios::beg);
   sc.write((char*)&rr,sizeof(rr));
   if(p==1)
   {
    outtextxy(10,50,"CONGRATS! YOU HAVE MADE IT");
    outtextxy(10,80,"TO THE BOARD OF ELITES.");
    delay(1000);
   }
   outtextxy(220,120,"SCORECARD:");
   itoa(rr.h[0],saa,10);
   itoa(rr.h[1],sab,10);
   itoa(rr.h[2],sac,10);
   itoa(rr.h[3],sad,10);
   itoa(rr.h[4],sae,10);
   itoa(score,sas,10);
   outtextxy(220,150,"I");
   outtextxy(280,150,saa);
   outtextxy(220,180,"II");
   outtextxy(280,180,sab);
   outtextxy(220,210,"III");
   outtextxy(280,210,sac);
   outtextxy(220,240,"IV");
   outtextxy(280,240,sad);
   outtextxy(220,270,"V");
   outtextxy(280,270,sae);
   outtextxy(220,400,"YOUR SCORE:");
   outtextxy(350,400,sas);
   getch();
   sc.close();
   getch();
  }
  cleardevice();
 }while(rep=='Y');
 cleardevice();
}
//***************************************************************************
int sort1()
{
 for(int i=0;i<5;i++)
 {
  if(score>=ss.h[i])
  {
   for(int j=4;j>i;j--)
   {
    ss.h[j]=ss.h[j-i];
   }
   ss.h[i]=score;
   return 1;
  }
 }
 return 0;
}
//****************************************************************************
void wordwrap()
{
 cleardevice();
 setbkcolor(15);
 setcolor(12);
 settextstyle(6,0,3);
 getch();
 outtextxy(75,75,"WELCOME TO THE WORLD OF ALPHABETS");
 outtextxy(75,115,"IN THE GAME, YOU WILL HAVE TO MAKE");
 outtextxy(75,155,"THREE LETTER WORDS FROM THE WORD GIVEN.");
 outtextxy(75,195,"NO REPITITION IS ALLOWED.");
 outtextxy(75,235,"TYPE THE ALPHABET YOU WANT TO USE & PRESS ENTER.");
 outtextxy(75,275,"BEST OF LUCK TO COMPLETE THE TWENTY ROUNDS");
 outtextxy(75,315,"HERE, WE START OUR JOURNEY");
 getch();
 clrscr();
 cleardevice();
 char rep;
 char ch1,ch2,ch3;
 int flag=0;
 char arr[4];
 ifstream fp;
 int ctr=0;
 char str[20][3];
 do
 {
  cleardevice();
  int r=rand()%40;
  for(int i=0;wstr[r][i]!='\0';i++)
  {
   str[i][0]=wstr[r][i];
   str[i][1]='\0';
  }
  ctr=strlen(wstr[r]);
  setbkcolor(9);
  setcolor(12);
  settextstyle(5,0,3);
//****************************************************************************
	 //**Making boxes for selected words
//****************************************************************************
  for(i=0;i<ctr;i++)
  {
   rectangle(100+40*i,150,140+40*i,190);
   delay(300);
  }
//****************************************************************************
	   //**Writing selected words in boxes**//
//****************************************************************************
  for(i=0;i<ctr;i++)
  {
   outtextxy(110+40*i,158,str[i]);
   delay(300);
  }
  settextstyle(5,0,2);
  outtextxy(10,430,"ENTER THE LETTER AT FIRST POSITION:");
  cin>>ch1;
  int temp1=0;
//****************************************************************************
	      //Checking the inputted char in the string//
//****************************************************************************
  for(int k=0;str[k][0]!=ch1;k++)
  {
   temp1++;
  }
  settextstyle(5,0,3);
  int f;
  flag=0;
  for(i=0;i<ctr&&flag==0;i++)
  {
   if(str[i][0]==ch1)
   {
    flag=1;
    f=140+40*i;
//****************************************************************************
		//Making 3 boxes for 3 letter word//
//*****************************************************************************
    for(int j=0;j<3;j++)
    {
     rectangle(140+40*i+40*j,350,180+40*j+40*i,390);
     delay(10);
    }
    for(j=0;j<40;j++)
    {
     setcolor(1);
     outtextxy(110+40*i+j,158+5*j,str[i]);
     delay(10);
     setcolor(0);
     outtextxy(110+40*i+j,158+5*j,str[i]);
     delay(10);
    }
    setcolor(1);
    outtextxy(110+40*i+j,158+5*j,str[i]);
    delay(10);
   }
   if(flag==1)
    break;
  }
//********************************************************************************
	       //Drawing boxes in different colour//
//****************************************************************************
  for(int j=0;j<3;j++)
  {
   rectangle(f+40*j,350,f+40*(j+1),390);
  }
  for(i=0;i<ctr;i++)
  {
   rectangle(100+40*i,150,140+40*i,190);
   delay(300);
  }
  if(flag==0)
  {
   wrong();
  }
  flag=0;
  int temp=0,l;
  settextstyle(5,0,2);
  setcolor(0);
  outtextxy(10,430,"ENTER THE LETTER AT FIRST POSITION:");
  setcolor(12);
  outtextxy(10,430,"ENTER THE LETTER AT SECOND POSITION:");
  cin>>ch2;
  settextstyle(5,0,3);
  for(i=0;i<10;i++)
  {
   if(str[i][0]==ch2)
   {
    flag=1;
    for(k=0;str[k][0]!=ch2;k++)
    {
     temp++;
    }
    if(temp>temp1)
    {
     for(int j=0;j<80;j++)
     {
      setcolor(1);
      outtextxy(110+40*i+j-j*(temp-temp1)/2,158+5*j/2,str[i]);
      delay(10);
      setcolor(0);
      outtextxy(110+40*i+j-j*(temp-temp1)/2,158+5*j/2,str[i]);
      delay(10);
     }
     setcolor(1);
     outtextxy(110+40*i+j-j*(temp-temp1)/2,158+5*j/2,str[i]);
     delay(10);
    }
    else if(temp<temp1)
    {
     for(int j=0;j<80;j++)
     {
      setcolor(1);
      outtextxy(110+40*i+j+j*(temp1-temp)/2,158+5*j/2,str[i]);
      delay(10);
      setcolor(0);
      outtextxy(110+40*i+j+j*(temp1-temp)/2,158+5*j/2,str[i]);
      delay(10);
     }
     setcolor(1);
     outtextxy(110+40*i+j+j*(temp1-temp)/2,158+5*j/2,str[i]);
     delay(10);
     flag=1;
    }
   }
   if(flag==1)
    break;
  }
  setcolor(GREEN);
  for(i=ctr;i>0;i--)
  {
   rectangle(100+40*(ctr-i),150,140+40*(ctr-i),190);
   delay(300);
  }
  setcolor(1);
  for(j=0;j<3;j++)
  {
   setcolor(i+2);
   rectangle(f+40*j,350,f+40*(j+1),390);
  }
  setcolor(1);
  if(flag==0)
  {
   wrong();
  }
  flag=0;
  temp=0;
  settextstyle(5,0,2);
  setcolor(0);
  outtextxy(10,430,"ENTER THE LETTER AT SECOND POSITION:");
  setcolor(12);
  outtextxy(10,430,"ENTER THE LETTER AT THIRD POSITION:");
  cin>>ch3;
  settextstyle(5,0,3);
  for(i=0;i<10;i++)
  {
   if(str[i][0]==ch3)
   {
    flag=1;
    for(int k=0;str[k][0]!=str[i][0];k++);
    {
     temp++;
    }
    if(temp>=temp1)
    {
     for(int j=0;j<120;j++)
     {
      setcolor(1);
      outtextxy(110+40*i+j-j*(temp-temp1)/3,158+5*j/3,str[i]);
      delay(10);
      setcolor(0);
      outtextxy(110+40*i+j-j*(temp-temp1)/3,158+5*j/3,str[i]);
      delay(10);
     }
     setcolor(1);
     outtextxy(110+40*i+j-j*(temp-temp1)/3,158+5*j/3,str[i]);
     delay(10);
    }
    else if(temp<temp1)
    {
     for(int j=0;j<120;j++)
     {
      setcolor(1);
      outtextxy(110+40*i+j+j*(temp1-temp)/3,158+5*j/3,str[i]);
      delay(10);
      setcolor(0);
      outtextxy(110+40*i+j+j*(temp1-temp)/3,158+5*j/3,str[i]);
      delay(10);
     }
     setcolor(1);
     outtextxy(110+40*i+j+j*(temp1-temp)/3,158+5*j/3,str[i]);
     delay(10);
    }
   }
   if(flag==1)
    break;
  }
  setcolor(4);
  for(i=0;i<ctr;i++)
  {
   rectangle(100+40*i,150,140+40*i,190);
   delay(300);
  }
  setcolor(4);
  for(j=0;j<3;j++)
  {
   rectangle(f+40*j,350,f+40*(j+1),390);
  }
  setcolor(1);
  getch();
  if(flag==0)
  {
   wrong();
  }
  ifstream fp;
  fp.open("C:/TC/BIN/DICT.TXT");
  arr[0]=tolower(ch1);
  arr[1]=tolower(ch2);
  arr[2]=tolower(ch3);
  arr[3]='\0';
  int tempo=0;
  clrscr();
  fp.getline(s.chh,10);
  if(strcmp(s.chh,arr)==0)
  {
   tempo=1;
  }
  if(tempo==1)
  {
   score+=10;
   congrats();
  }
  else
  {
   wrong();
  }
  fp.close();
  cleardevice();
  settextstyle(3,0,2);
  outtextxy(200,200,"DO YOU WANT TO CONTINUE");
  outtextxy(200,250,"WITH THE GAME?");
  outtextxy(160,300,"Y FOR YES N FOR NO:");
  cin>>rep;
  rep=toupper(rep);
  if(rep=='N')
  {
   fstream sc1;
   sc1.open("c:/tc/bin/score1.dat",ios::in|ios::app|ios::binary);
   char sas[5],saa[5],sab[5],sac[5],sad[5],sae[5];
   cleardevice();
   sc1.seekg(0,ios::beg);
   sc1.read((char*)&ss,sizeof(ss));
   int p=sort1();
   sc1.seekp(0,ios::beg);
   sc1.write((char*)&ss,sizeof(ss));
   if(p==1)
   {
    outtextxy(100,50,"CONGRATS! YOU HAVE MADE IT");
    outtextxy(100,80,"TO THE BOARD OF ELITES.");
    delay(1000);
   }
   outtextxy(220,120,"SCORECARD:");
   itoa(ss.h[0],saa,10);
   itoa(ss.h[1],sab,10);
   itoa(ss.h[2],sac,10);
   itoa(ss.h[3],sad,10);
   itoa(ss.h[4],sae,10);
   itoa(score,sas,10);
   outtextxy(220,150,"I");
   outtextxy(280,150,saa);
   outtextxy(220,180,"II");
   outtextxy(280,180,sab);
   outtextxy(220,210,"III");
   outtextxy(280,210,sac);
   outtextxy(220,240,"IV");
   outtextxy(280,240,sad);
   outtextxy(220,270,"V");
   outtextxy(280,270,sae);
   outtextxy(220,400,"YOUR SCORE:");
   outtextxy(350,400,sas);
   getch();
   sc1.close();
   getch();
  }
  cleardevice();
 }while(rep=='Y');
 fp.close();
}
//****************************************************************************
void password()
{
 clrscr();
 cleardevice();
 settextstyle(6,0,3);
 setbkcolor(7); n9.5878+9-- char a[15],c[15]="Lekhini";
 outtextxy(150,75,"Enter your password");
 int b=strlen(c);
 for(int y=0;y<b;y++)
 {
  cin>>a[y];
  outtextxy(110+40*y,135,"*");
 }
 if(strcmp(a,c)==0)
 {
  setcolor(3);
  outtextxy(150,195,"Welcome Ms. Radhika");
  getch();
  admin_menu();
 }
 else
 {
  setcolor(14);
  outtextxy(150,195,"SORRY!! Incorrect password.");
  getch();
  modemenu();
 }
}
//****************************************************************************
void main()
{
 s.num1();
 int gdriver=DETECT,gmode,errorcode;
 initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
 errorcode=graphresult();
 if(errorcode!=grOk)
 {
  printf("Graphics error:%s\n",grapherrormsg(errorcode));
  printf("Press any key to halt:");
  getch();
  exit(1);
 }
 screen();
 modemenu();
 closegraph();
 getch();
}
//****************************************************************************