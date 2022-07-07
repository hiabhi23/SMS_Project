#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class student
{
	
	
	char nm[30];
	float perc;
	
	public:
	long roll_no; 	
	void input();
	void display();
	//void search();
};	

void student ::input()
{
	cout<<endl<<"ENTER STUDENT NAME \n";
	cin>>nm;
	
	cout<<"\n ENTER ROLL NO \n";
	cin>>roll_no;
	
	cout<<"\n ENTER PERCENTAGE \n";
	cin>>perc;
}
void student ::display()
{
		cout<<nm<<"\t\t";
	cout<<roll_no<<"\t\t";
	cout<<perc<<endl;
}

void add_stud()
{
	student s1;
	fstream fout;//this will help to open a file ex studnet.dat
fout.open("student.dat",ios::app|ios::binary);
  s1.input();
  fout.write((char *)&s1,sizeof(s1));//
  fout.close();
}

void stud_display()
{
 student s1;
	fstream fin;
	fin.open("student.dat",ios::in|ios::binary);
	
	if(!fin)
	{
		cout<<"FILE NOT FIND";
		exit;
	}
	else
	{
	while(fin.read((char *)&s1,sizeof(s1)))
	{
		s1.display();
	}
}
	fin.close();
}

void search_stud()
{
	 long R,found=0;
	cout<<"enter the student roll no which you want to search";
	cin>>R;

	student s1;
fstream fin;
fin.open("student.dat",ios::in|ios::binary);
while(fin.read((char *)&s1,sizeof(s1)))
	{
	if(s1.roll_no==R)
	{
		found=1;
		cout<<"NAME          ROLL NO.          PERCENTAGE"<<endl;

		s1.display();
		break;
		
	}
}

if(found==0)
{
	cout<<"\nRecord not found";
}
}
void modify_stud()
{
	 long R,found=0;
	cout<<"enter the student roll no which you want to update";
	cin>>R;

	student s1;
fstream fin;
fin.open("student.dat",ios::in|ios::binary);
while(fin.read((char *)&s1,sizeof(s1)))
	{
	if(s1.roll_no==R)
	{
		found=1;
		add_stud();
		   
		break; 
		
	}
	if(found==0)
{
	cout<<"\nRecord not found";
}
}
}
void intro()
{
	cout<<"\n\n\n\t  STUDENT ";
	cout<<"\n\n\tMANAGEMENT";
	cout<<"\n\n\t  SYSTEM";
	cout<<"\n\n\n\nMADE BY : ABHINAV AGGARWAL";
	cout<<"\n\nCOLLEGE : ADGITM";
	cin.get();
}
int main()
{
	intro();
int n;
student s1;
while(1)
{
	
	
	cout<<endl<<"\t\t\t\t*********************************************************"<<endl;
	cout<<endl<<"\t\t\t\t\tSTUDENT_________MANAGEMENT_________SYSTEM"<<endl;
	cout<<endl<<"\t\t\t\t*********************************************************\n\n"<<endl;

cout<<endl<<"\t01:ADD STUDENT "<<endl;
cout<<endl<<"\t02:DISPLAY STUDENT"<<endl;
cout<<endl<<"\t03:EXITING......."<<endl;
cout<<endl<<"\t04:SEARCH STUDENT"<<endl;
cout<<endl<<"\t05:MODIFY THE RECORD"<<endl;

cout<<endl<<"\t\t\t\t*********************************************************"<<endl;
cout<<endl<<"\t\t\t\tSELECT OPTION FROM ABOVE <0-3>"<<endl;
cout<<endl<<"\t\t\t\t*********************************************************"<<endl;

cin>>n;
 switch(n)
{
case 1:

add_stud();
break;	
	
case 2:
	cout<<"\n\nRecord of Students "<<endl;
	cout<<"Name      Roll Number     Percentage"<<endl;
		stud_display();
	   break;
	

case 3:
	
		cout<<".........EXITING ..........";
	break;
case 4:
 search_stud();	
	break;

case 5:
	modify_stud();
	break;
default:
	
		cout<<"*****INVALID_______ CHOICE*****";
		break;	

 
} 

if(n==3)
{
	break;
}

}

	return 0;
}

