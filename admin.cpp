//************************************************************
          //ADMIN.CPP//
//************************************************************
void admin_menu()
{
 menu:
 clrscr();
 cleardevice();
 char opt;
 setbkcolor(1);
 setcolor(6);
 settextstyle(6,0,3);
 {
  outtextxy(150,75,"ADMINISTRATOR MENU");
  outtextxy(150,115,"Please choose an option:");
  outtextxy(150,195,"<A>Add a word");
  outtextxy(150,235,"<B>Delete a word");
  outtextxy(150,275,"<C>Show all words");
  outtextxy(150,315,"<D>Back");
  cin>>opt;
  outtextxy(150,355," -->>");
 }
 opt=toupper(opt);
 switch(opt)
 {
  case 'A':
           clrscr();
	   cleardevice();
	   setbkcolor(0);
           setcolor(6);
	   outtextxy(50,75,"The files 'QDICT.TXT' & 'DICT.TXT' are ");
	   outtextxy(50,115,"ever expandable files. You can add words ");
           outtextxy(50,155,"directly into them from the (C:) drive itself...");
           getch();
           goto menu;
           break;
  case 'B':
           clrscr();
           cleardevice();
	   setbkcolor(0);
	   setcolor(6);
	   outtextxy(50,75,"Words from the files 'QDICT.TXT' & 'DICT.TXT'");
	   outtextxy(50,115,"can be deleted from them from the(C:) drive...");
           getch();
	   goto menu;
	   break;
  case 'C':
	   clrscr();
	   cleardevice();
           int r;
	   setbkcolor(7);
	   setcolor(9);
	   settextstyle(6,0,3);
	   outtextxy(100,75,"Which dictionary would you like to operate upon....");
	   outtextxy(150,115,"<1> Main dictionary");
	   outtextxy(150,155,"<2> 3-Letter dictionary");
	   outtextxy(150,195,"<3> Back");
           cin>>r;
	   switch(r)
	   {
	    case 1: clrscr();
		    cleardevice();
		    char dic[80];
		    fstream fin;
		    fin.open("qdict.txt",ios::in);
		    while(fin.getline(dic,80))
		    {
		     cout<<dic<<endl;
		    }
		    delay(1000);
		    fin.close();
		    getch();
	  	    goto menu;
		    break;
	    case 2: clrscr();
		    cleardevice();
		    char dic1[80];
		    fstream fin1;
		    fin1.open("dict.txt",ios::in);
		    while(fin1.getline(dic1,80))
		    {
		     cout<<dic1<<endl;
		    }
	            delay(1000);
		    fin1.close();
		    getch();
		    goto menu;
		    break;
	    case 3: break;
       	   }
           break;
  case 'D':
           break;
 }
}
//*************************************************************************
              //END OF THE CODE//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~