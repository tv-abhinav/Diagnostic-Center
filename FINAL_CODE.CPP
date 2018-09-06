#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include<iomanip.h>
//GLOBAL FUNCTIONS
void pattern();
void load();
void center();
void menu();
void admenu();
void docmenu();
void patmenu();
//void pdisplay();
//void ddisplay(doc);
void psearch();
void dsearch();
void password();
void line();
void temp(char*,char*);
void deldoc();
void delpat();

int n,n1;
char adpass[]={"pass"};

class doc
{
	public:
	long m_no,c_id;
	char dname[20],title[40],g[7],q[10],dadd[100],email[30],cno[15];
	int dd,mm,yy;//use dname & m_no for login
	void dreg();
	void dmod();
	void dtitle();
	void dlogin(int);
	void dnamsearch();
	void dcnosearch();
	void dmlnsearch();
	void dcidsearch();
	void delpatient(long);
}d[10],d1,c;

class patient
{
	public:
	long rno,fees;
	int rd,rm,ry,dd,mm,yy,td,tm,ty;
	char pname[20],g[7],padd[100],href[20],tt[10],dname[20],pnum[15];
	void preg();
	void prnosearch();
	void pnamsearch();
	void phnosearch();
	void pmod();
	void test();
}p[50],p1;

void opage()
{
	pattern();
	cout<<"\n\nTCS PROJECT BY: \n";
	cout<<"T.V.ABHINAV\n";
	cout<<"R.KARTHIK\n";
	cout<<"R.K.MADHU BHARATHI\n";
	cout<<"REBEKHA SHIRLEY\n\n";
	load();
}
//DISPLAY PATIENT DETAILS
void pdisplay(patient p2)
{
clrscr();
	cout<<"\n"<<setw(40)<<"PATIENT DETAILS \n";
	cout<<"REGISTRATION NUMBER: "<<p2.rno<<"\n";
	cout<<"REGISTRATION DATE  : "<<p2.rd<<"/"<<p2.rm<<"/"<<p2.ry<<"\n";
	cout<<"PATIENT NAME       : "<<p2.pname<<"\n";
	cout<<"GENDER             : "<<p2.g<<"\n";
	cout<<"DATE OF BIRTH      : "<<p2.dd<<"/"<<p2.mm<<"/"<<p2.yy<<"\n";
	cout<<"PATIENT ADDRESS    : "; puts(p2.padd);
	cout<<"PHONE NUMBER       : "<<p2.pnum<<"\n";
	cout<<"REFERENCE          : ";puts(p2.href);
	cout<<"TEST DATE          : "<<p2.td<<"/"<<p2.tm<<"/"<<p2.ty<<"\n";
	cout<<"TEST TYPE          : "<<p2.tt<<"\n";
	cout<<"DOCTOR NAME        : "<<p2.dname<<"\n";
	cout<<"FEES               : "<<p2.fees;
	getch();
}
//DISPLAY DOCTOR DETAILS
void ddisplay(doc d2)
{
clrscr();
	cout<<"\n"<<setw(40)<<"DOCTOR DETAILS \n";
	cout<<"NAME                  : "<<d2.dname<<"\n";
	cout<<"TITLE                 : "<<d2.title<<"\n";
	cout<<"GENDER                : "<<d2.g<<"\n";
	cout<<"DATE OF BIRTH         : "<<d2.dd<<"/"<<d2.mm<<"/"<<d2.yy<<"\n";
	cout<<"QUALIFICATION         : "<<d2.q<<"\n";
	cout<<"MEDICAL LICENSE NUMBER: "<<d2.m_no<<"\n";
	cout<<"CENTRE ID             : "<<d2.c_id<<"\n";
	cout<<"ADDRESS               : ";puts(d2.dadd);
	cout<<"CONTACT NUMBER        : "<<d2.cno;
	cout<<"\nEMAIL ID            : "<<d2.email;
	getch();
}

void doc::dreg()
{
	pattern();
	char ch;
	int i=n;
	while(ch!='n')
	{
	 clrscr();
	 cout<<"\n                       Enter the doctor details  "<<endl;
	 cout<<"\n Name of doctor: ";
	 gets(d[i].dname);
	 cout<<"\n Title of doctor: ";
	 gets(d[i].title);
	 cout<<"\n Gender: ";
	 gets(d[i].g);
	 cout<<"\n Date of birth('dd'Enter'mm'Enter'yy'): ";
	 cin>>d[i].dd>>d[i].mm>>yy;
	 cout<<"\n Qualification: ";
	 gets(d[i].q);
	 cout<<"\n Medical license number: ";
	 cin>>d[i].m_no;
	 cout<<"\n Address of doctor: ";
	 gets(d[i].dadd);
	 cout<<"\n Contact number: ";
	 cin>>d[i].cno;
	 cout<<"\n E-mail id: ";
	 gets(d[i].email);

	 ofstream dr("docdet.dat",ios::app|ios::binary);
	 dr.write((char*)&d[i],sizeof(d[i]));
	 dr.close();

	 cout<<"Added successfully!\n";
	 i++;
	 cout<<"Do you want to continue adding?(y/n) ";
	 ch=getch();
	}
	admenu();
}
void patient::preg()
{
	pattern();
	char ch;
	int i=0;
	while(ch!='n')
	{
		cout<<setw(40)<<"ENTER THE PATIENT DETAILS\n\n\n";
		cout<<"\nEnter the Address of the Patient: ";
		gets(p[i].padd);
		cout<<"\nEnter the Reference by which you known this hospital: ";
		gets(p[i].href);
		cout<<"Enter the Registration Number: ";
		cin>>p[i].rno;
		cout<<"\nEnter the Registration Date in Date Month Year format: ";
		cin>>p[i].rd>>p[i].rm>>p[i].ry;
		cout<<"\nEnter the Patient Name: ";
		gets(p[i].pname);
		cout<<"Enter the Gender of the Patient: ";
		cin>>p[i].g;
		cout<<"Enter the date of birth of the Patient: ";
		cin>>p[i].dd>>p[i].mm>>p[i].yy;
		cout<<"Enter the contact phone number of the Patient: ";
		cin>>p[i].pnum;
		cout<<"Enter the test date in Date Month Year format: ";
		cin>>p[i].td>>p[i].tm>>p[i].ty;
		cout<<"\nEnter the test type: ";
		gets(p[i].tt);
		cout<<"Enter the doctor's name: ";
		gets(p[i].dname);
		cout<<"Enter the total fees: ";
		cin>>p[i].fees;
		 ofstream pr("patdet.dat",ios::app|ios::binary);
		 pr.write((char*)&p[i],sizeof(p[i]));
		 pr.close();
		 cout<<"Added successfully!\nDo you want to continue?(y/n) ";
		 i++;
		 ch=getch();
	}

}
//SEARCH USING MEDICAL LICENCE NO
void doc::dmlnsearch()
{
 int i=0;
 char cn[15];
  long mn;
  cout<<"Enter med lic. no: ";cin>>mn;
 ifstream dr("docdet.dat",ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
   if(d1.m_no==mn)
   {
     i++;
     ddisplay(d1);
   }
 }
  if(i==0)
  {
   cout<<"No doctor found with such medical licence number!";getch();
  }
  dr.close();

}
//SEARCH USING CONTACT NO
void doc::dcnosearch()
{
 int i=0;
 char cn[15];
 cout<<"Enter contact no: ";gets(cn);
 ifstream dr("docdet.dat",ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
   if(strcmpi(d1.cno,cn)==0)
  {
   i++;
   ddisplay(d1);
  }
 }
  if(i==0)
  {
   cout<<"No doctor found with such contact number!";getch();
  }
	 dr.close();
}
//SEARCH USING CENTER ID
void doc::dcidsearch()
{
 int i=0;
 char cn[15];
 long cid;
 cout<<"Enter center id: ";
 cin>>cid;
 ifstream dr("docdet.dat",ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
   if(d1.c_id==cid)
  {
   i++;
   ddisplay(d1);
  }
 }
  if(i==0)
  {
   cout<<"No doctor found with such Center ID!";getch();
  }
  dr.close();
}
//SEARCH USING DOCTOR NAME
void doc::dnamsearch()
{
 int i=0;
 char dnam[25];
 cout<<"Enter doctor name: ";
 gets(dnam);
 ifstream dr("docdet.dat",ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
   if(strcmpi(d1.dname,dnam)==0)
  {
   i++;
   ddisplay(d1);
  }
 }
  if(i==0)
  {
   cout<<"No doctor found with such name!";getch();
  }
  dr.close();

}


void deldoc()
{
 int i=0;
 char dnam[25],ch;
 doc d3;
 cout<<"Enter name of the doctor to be removed ";
 gets(dnam);
 ifstream dr("docdet.dat",ios::in|ios::binary);
 ofstream dr1("temp.dat",ios::out|ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
 d3=d1;
   if(strcmpi(d1.dname,dnam)==0)
  {
   ddisplay(d1);
   i++;
   cout<<"\n\nAre you sure you want to remove this doctor? (y/n)";cin>>ch;
   if(ch=='n'||ch=='N')
   {
    dr1.write((char*)&d3,sizeof(d3));
    continue;
   }
   else
   {
    continue;
   }
  }
  else
  {
    dr1.write((char*)&d3,sizeof(d3));
  }
 }
  if(i==0)
  {
   cout<<"No doctor found with such name!";getch();
  }
  dr.close();
  dr1.close();
  ifstream dr2("temp.dat",ios::in|ios::binary);
  ofstream dr3("docdet.dat",ios::out|ios::binary);
  while(dr2.read((char*)&d1,sizeof(d1)))
  {
    dr3.write((char*)&d1,sizeof(d1));
  }
  dr2.close();
  dr3.close();
  cout<<"\n\nPROCESSING SUCCESSFUL...Press any key to go to previous menu";
  getch();
}

void delpat()
{
 int i=0;
 char ch;
 long regno;
 patient p3;
 cout<<"Enter reg no of the patient to be removed ";cin>>regno;
 ifstream pat("patdet.dat",ios::in|ios::binary);
 ofstream pat1("temp.dat",ios::out|ios::binary);
 while(pat.read((char*)&p1,sizeof(p1)))
 {
 p3=p1;
   if(p1.rno==regno)
  {
   pdisplay(p1);
   i++;
   cout<<"\n\nAre you sure you want to remove this patient? (y/n)";cin>>ch;
   if(ch=='n'||ch=='N')
   {
    pat1.write((char*)&p3,sizeof(p3));
    continue;
   }
   else
   {
    continue;
   }
  }
  else
  {
    pat1.write((char*)&p3,sizeof(p3));
  }
 }
  if(i==0)
  {
   cout<<"No patient found with such registration number!";getch();
  }
  pat.close();
  pat1.close();
  ifstream pat2("temp.dat",ios::in|ios::binary);
  ofstream pat3("patdet.dat",ios::out|ios::binary);
  while(pat2.read((char*)&p1,sizeof(p1)))
  {
    pat3.write((char*)&p1,sizeof(p1));
  }
  pat2.close();
  pat3.close();
  cout<<"\n\nPROCESSING SUCCESSFUL...Press any key to go to previous menu";
  getch();
}



void assign()
{
 int i=0;
 ifstream f;
 f.open("docdet.dat",ios::binary|ios::in);
 while(f.read((char*)&c,sizeof(c)))
 {
  d[i]=c;
  i++;
 }
 n1=i;
 f.close();
}
void patient::prnosearch() //RNO
{
 int i=0;
 long rn;
  cout<<"Enter reg no: ";cin>>rn;

 ifstream pat("patdet.dat",ios::binary);
 while(pat.read((char*)&p1,sizeof(p1)))
 {
  if(p1.rno==rn)
  {
   i++;
   pdisplay(p1);
  }
 }
  if(i==0)
  {
   cout<<"No patient found with such registration number!";getch();
  }
 pat.close();
}
void patient::phnosearch() //PNUM
{
 int i=0;
 char pno[15];
 cout<<"Enter phone no: ";
 cin>>pno;

 ifstream pat("patdet.dat",ios::binary);
 while(pat.read((char*)&p1,sizeof(p1)))
 {
  if(strcmpi(p1.pnum,pno)==0)
  {
   i++;
   pdisplay(p1);
  }
 }
  if(i==0)
  {
   cout<<"No patient found with such phone number!";getch();
  }
 pat.close();
}
void patient::pnamsearch() //PHNO
{
 int i=0;
 char nam[25];
 cout<<"Enter patient name: ";
 gets(nam);

 ifstream pat("patdet.dat",ios::binary);
 while(pat.read((char*)&p1,sizeof(p1)))
 {
  if(strcmpi(p1.pname,nam)==0)
  {
   i++;
   pdisplay(p1);
  }
 }
  if(i==0)
  {
   cout<<"No patient found with such phone name!";getch();
  }
 pat.close();
}

void doc::dtitle()
{
}

void dsearch()
{
clrscr();
pattern();
cout<<"\nSEARCH BY:\n\n";
int ch;
cout<<"1.MEDICAL LICENCE NUMBER\n";
cout<<"2.CONTACT NUMBER\n";
cout<<"3.DOCTOR NAME\n";
cout<<"4.CENTER ID\n";
cout<<"5.BACK TO ADMINISTRATOR MENU\n";
cout<<"Enter Your Choice[1-5]: ";
do{
   cin>>ch;
   if(ch<1||ch>5){cout<<"\n\nEnter a Valid Choice\n\n";}
  }while((ch<1)||(ch>5));
switch(ch)
{
case 1:{d1.dmlnsearch();dsearch();break;}
case 2:{d1.dcnosearch();dsearch();break;}
case 3:{d1.dnamsearch();dsearch();break;}
case 4:{d1.dcidsearch();dsearch();break;}
case 5:{admenu();break;}
}//end of switch
}//end of function

void main()
{
opage();
menu();
}
void load()
{
    int j;
    cout << "Loading";
    cout.flush();
    for (j=0;j<3;j++) {
	for (int i = 0; i < 3; i++) {
	    cout << ".";
	    cout.flush();
	    sleep(1);
	}
	cout << "\b\b\b   \b\b\b";
    }
}
void menu()
{
	int ch;
	 pattern();
	 cout<<"\nMENU";
	 cout<<"\n1.Administrator.";
	 cout<<"\n2.Doctor.";
	 cout<<"\n3.Exit.";
	do
	{
	 cout<<"\nEnter a choice: ";
	 cin>>ch;
	 if(ch<1||ch>3)
	 {
	   cout<<"\n\nInvalid Choice! Please Try Again!\n\n";
	 }
	}while(ch<1||ch>3);
 switch(ch)
 {
  case 1:{
	   password();
	   clrscr();
	   admenu();
	   break;
	}
  case 2:{
	  //VALIDATION FOR DOCTOR NEEDS TO BE DONE
	  docmenu();
	  break;}
  case 3:{exit(0);break;}
  default:cout<<"please enter correct option!\n";
 }
}

void admenu()
{
clrscr();
pattern();
    int opt;
	cout<<"             MENU";
	cout<<"\n    1.Add doctor.";
	cout<<"\n    2.Search doctor.";
	cout<<"\n    3.Modify doctor.";
	cout<<"\n    4.Remove doctor.";
	cout<<"\n    5.Add title to a doctor.";
	cout<<"\n    6.Go to main menu.";
    do
     {
	cout<<"\n    Enter your choice: ";
	cin>>opt;
	if(opt<1||opt>6)
	{
	 cout<<"\n\nInvalid Choice! Try Again!\n\n";
	}
     }while(opt<1||opt>6);
 switch(opt)
 {
  case 1:{d1.dreg();break;}
  case 2:{dsearch();break;}
  case 3:{d[0].dmod();break;}
  case 4:{deldoc();admenu();break;}
  case 5:{d[0].dtitle();break;}
  case 6:{menu();break;}
  default:cout<<"please enter correct option!\n";
 }
}
void docmenu()
{
clrscr();
pattern();
 int ch2;
 char ch;
 cout<<"What do you want to do???\n";
 cout<<"1.Add patient\n";
 cout<<"2.Search patient\n";
 cout<<"3.Modify patient\n";
 cout<<"4.Remove patient\n";
 cout<<"5.Go to main menu\n";
 cout<<"Enter your choice: ";
 cin>>ch2;
switch(ch2)
{
 case 1:{p1.preg();docmenu();break;}
 case 2:{psearch();break;}
 case 3:{p1.pmod();break;}
 case 4:{delpat();docmenu();break;}
 case 5:{menu();break;}
 default:{}
}
}
void doc::dmod()
{
clrscr();
pattern();
char dnam[25],ch4;
int ch,c=0,i=0;
cout<<"Enter the Name of the Doctor whose details are to be modified\n";
gets(dnam);
 doc d3;
 ifstream dr("docdet.dat",ios::in|ios::binary);
 ofstream dr1("temp.dat",ios::out|ios::binary);
 while(dr.read((char*)&d1,sizeof(d1)))
 {
   if(strcmpi(d1.dname,dnam)==0)
  {
   i++;
   ddisplay(d1);
   cout<<"\n\nDo you want to modify the details of this doctor? (y/n)";cin>>ch4;
   if(ch4=='n'||ch4=='N')
   {
     dr1.write((char*)&d1,sizeof(d1));
   }
   else
   {
   d3=d1;

cout<<"\n\n 1.NAME\n";
cout<<" 2.TITLE\n";
cout<<" 3.GENDER[m/f]\n";
cout<<" 4.DATE OF BIRTH\n";
cout<<" 5.QUALIFICATION\n";
cout<<" 6.MEDICAL LICENSE NUMBER\n";
cout<<" 7.CENTRE ID\n";
cout<<" 8.ADDRESS\n";
cout<<" 9.CONTACT NUMBER\n";
cout<<"10.EMAIL ID\n";
do{
   cout<<"ENTER WHAT YOU NEED TO MODIFY[1-10]\n";
   cin>>ch;
   if(ch<1||ch>10)
   {
    cout<<"\n\nInvalid choice! Try Again!\n\n";
   }
  }while((ch<1)||(ch>10));

  switch(ch)
  {
   case 1:cout<<"\n\nEnter new name for this person:";gets(d3.dname);break;
   case 2:cout<<"\n\nEnter new title for this person:";gets(d3.title);break;
   case 3:cout<<"\n\nEnter new gender for this person:";gets(d3.g);break;
   case 4:cout<<"\n\nEnter new DOB for this person:";cin>>d3.dd>>d3.mm>>d3.yy;break;
   case 5:cout<<"\n\nEnter new qualification for this person:";gets(d3.q);break;
   case 6:cout<<"\n\nEnter new medical licence no for this person:";cin>>d3.m_no;break;
   case 7:cout<<"\n\nEnter new center ID for this person:";cin>>d3.c_id;break;
   case 8:cout<<"\n\nEnter new address for this person:";gets(d3.dadd);break;
   case 9:cout<<"\n\nEnter new contact no for this person:";cin>>d3.cno;break;
   case 10:cout<<"\n\nEnter new email for this person:";gets(d3.email);break;
   default:cout<<"\n\nINVALID CHOICE!";getch();
  }
   dr1.write((char*)&d3,sizeof(d3));
   }
  }
  else
  {
   dr1.write((char*)&d1,sizeof(d1));
  }
 }
  if(i==0)
  {
   cout<<"No doctor found with such name!";getch();admenu();
  }
  dr.close();
  dr1.close();
 ifstream dr2("temp.dat",ios::in|ios::binary);
 ofstream dr3("docdet.dat",ios::out|ios::binary);
 while(dr2.read((char*)&d1,sizeof(d1)))
 {
  dr3.write((char*)&d1,sizeof(d1));
 }
 dr2.close();
 dr3.close();
 cout<<"PROCESSING SUCCESSFUL....Press any key to go back to previous menu.";getch();
 admenu();
}

void patient::pmod()
{
clrscr();
pattern();
long rno;
char ch4;
int ch,c=0,i=0;
cout<<"Enter the Registration No of the Patient whose details are to be modified\n";
cin>>rno;
 patient p3;
 ifstream pat("patdet.dat",ios::in|ios::binary);
 ofstream pat1("temp.dat",ios::out|ios::binary);
 while(pat.read((char*)&p1,sizeof(p1)))
 {
   if(p1.rno==rno)
  {
   i++;
   pdisplay(p1);
   cout<<"\n\nDo you want to modify the details of this patient? (y/n)";cin>>ch4;
   if(ch4=='n'||ch4=='N')
   {
     pat1.write((char*)&p1,sizeof(p1));
   }
   else
   {
   p3=p1;

cout<<" 1.REGISTRATION NUMBER\n";
cout<<" 2.REGISTRATION DATE\n";
cout<<" 3.NAME\n";
cout<<" 4.GENDER[m/f]\n";
cout<<" 5.DATE OF BIRTH\n";
cout<<" 6.ADDRESS\n";
cout<<" 7.CONTACT PHONE NUMBER\n";
cout<<" 8.HOSPITAL REFERENCE BY\n";
cout<<" 9.TEST DATE\n";
cout<<"10.TEST TYPE\n";
cout<<"11.DOCTOR'S NAME\n";
cout<<"12.DOCTOR'S FEES\n";
do{
   cout<<"ENTER WHAT YOU NEED TO MODIFY[1-12]\n";
   cin>>ch;
   if(ch<1||ch>12)
   {
    cout<<"\n\nInvalid choice! Try Again!\n\n";
   }
  }while((ch<1)||(ch>12));

  switch(ch)
  {
   case 1:cout<<"\n\nEnter new registration no for this person:";cin>>p3.rno;break;
   case 2:cout<<"\n\nEnter new registration date for this person:";cin>>p3.rd>>p3.rm>>p3.ry;break;
   case 3:cout<<"\n\nEnter new name for this person:";gets(p3.pname);break;
   case 4:cout<<"\n\nEnter new gender for this person:";cin>>p3.g;break;
   case 5:cout<<"\n\nEnter new DOB for this person:";cin>>p3.dd>>p3.mm>>p3.yy;break;
   case 6:cout<<"\n\nEnter new address for this person:";gets(p3.padd);break;
   case 7:cout<<"\n\nEnter new contact no for this person:";cin>>p3.pnum;break;
   case 8:cout<<"\n\nEnter new reference for this person:";gets(p3.href);break;
   case 9:cout<<"\n\nEnter new test date for this person:";cin>>p3.td>>p3.tm>>p3.ty;break;
   case 10:cout<<"\n\nEnter new test type for this person:";gets(p3.tt);break;
   case 11:cout<<"\n\nEnter new doctor name for this person:";gets(p3.dname);break;
   case 12:cout<<"\n\nEnter new doctor fee for this person:";cin>>p3.fees;break;
   default:cout<<"\n\nINVALID CHOICE!";getch();
  }
   pat1.write((char*)&p3,sizeof(p3));
   }
  }
  else
  {
   pat1.write((char*)&p1,sizeof(p1));
  }
 }
  if(i==0)
  {
   cout<<"No patient found with such registration no!";getch();docmenu();
  }
  pat.close();
  pat1.close();
 ifstream pat2("temp.dat",ios::in|ios::binary);
 ofstream pat3("patdet.dat",ios::out|ios::binary);
 while(pat2.read((char*)&p1,sizeof(p1)))
 {
  pat3.write((char*)&p1,sizeof(p1));
 }
 pat2.close();
 pat3.close();
 cout<<"PROCESSING SUCCESSFUL....Press any key to go back to previous menu.";getch();
 docmenu();
 }

void psearch()
{
clrscr();
pattern();
	int ch;
	cout<<"\n1.REGISTRATION NUMBER\n";
	cout<<"2.PATIENT NAME\n";
	cout<<"3.PHONE NUMBER\n";
	cout<<"4.BACK TO DOCTOR's MENU\n";
	do
	{
	   cout<<"Enter Your Choice[1-4]: ";
	   cin>>ch;
	   if(ch<1||ch>4){cout<<"\n\nInvalid Choice! Try again!\n\n";}
	}while((ch<1)||(ch>4));
	switch(ch)
	{
		case 1:{p1.prnosearch();psearch();break;}
		case 2:{p1.pnamsearch();psearch();break;}
		case 3:{p1.phnosearch();psearch();break;}
		case 4:{docmenu();break;}
	}
}

void doc::dlogin(int docno)
{
	int i=0;
	char password[25],pass[25];
	char ch;
	while(1)
	{
		ch=getch();
		if(ch=='\b')
		{
			cout <<"\b \b";
			if (i>0){pass[i--]='\0';}
		}
		else if (ch=='\n'|ch=='\r')
			{
				pass[i]='\0';
				break;
			}
		else {pass[i]=ch; i++; cout <<(char)158;}
	}
}
/*
void userRegister()
{
	char username[50],password[25];
	ofstream usersFile ("userData.txt",ios::app);
	usersFile << username << " " << password << endl;
	usersFile.close();
}*/

void pattern()
{
  clrscr();
  cout<<"\n ____________________________________________________________";
  cout<<"\n|                  MODERN DIAGNOSTIC CENTRE                  |";
  cout<<"\n ------------------------------------------------------------ \n";
}
int f1=0;
void password()
{
 char a[15],b[15];
 temp(a,b);
 if(strcmp(a,"password")!=0&&strcmpi(b,"user")!=0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid ID and Password!  "<<3-f1<<" chance(s)left! Press any key to try again..";
   else
    cout<<"\n\nInvalid ID and Password!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
else
 if(strcmp(a,"password")!=0&&strcmpi(b,"user")==0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid Password!  "<<3-f1<<" chance(s) left! Press any key to try again..";
   else
    cout<<"\n\nInvalid Password!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();
     cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
else
 if(strcmpi(b,"user")!=0&&strcmp(a,"password")==0)
  {
   ++f1;
   if(3-f1!=0)
    cout<<"\n\nInvalid User ID!  "<<3-f1<<" chance(s) left! Press any key to try again..";
   else
    cout<<"\n\nInvalid User ID!  No more chances left..Press any Key!";
    getch();
   if(3-f1!=0)
    password();
   else
    {
     clrscr();
     center();
     cout<<"\t\tSorry!! Program terminating due to security reasons\a\a\a.\a\a\a.\a\a\a.\a\a";
     exit(0);
    }
  }//1 if
}//void

void center()
{
 for(int i=1;i<=25;++i)
 cout<<"\n";
}

void temp(char a[15],char b[15])
{
 clrscr();
 pattern();
 cout<<"\n\t\t\t\tLOGIN";
 line();
 cout<<"\n\nHINT:Password is Case Sensitive but User ID is not Case Sensitive\n";
 cout<<"\nPlease Enter Login ID\t";gets(b);
 cout<<"\nPlease Enter The Password\t";
 char ch;
 ch=getch();
 int r=-1;
 while(ch!=13)
  {                              //BACKSPACE
   if(ch!=8)
   {
   a[++r]=ch;
   cout<<"*";
   ch=getch();
   }
   else
   {
   a[r]=8;
   ch=getch();--r;}
  }
 a[++r]=NULL;
}//temp

void line()
{
 cout<<"\n";
 for(int i=1;i<=80;++i)
 cout<<"-";
}