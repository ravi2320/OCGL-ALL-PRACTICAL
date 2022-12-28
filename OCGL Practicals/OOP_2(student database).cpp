//Develop an object oriented program in C++ to create a database of student information
//System containing the following information: Name, Roll number, Class, division, Date of
//Birth, Blood group, Contact address, telephone number, driving license no. and other.
//Construct the database with suitable member functions for initializing and destroying the
//data viz constructor, default constructor, Copy constructor, destructor, static member
//functions, friend class, this pointer, inline code and dynamic memory allocation
//operators-new and delete.
#include <iostream>
#include <string.h>
using namespace std;

class College;
class student
{
	string name, dob, bg, addr, lno, tele;
	static string adhar;
	public:
		student()
		{
			name="", dob= "",bg="",addr="",lno="",tele="";
			cout<<"\nDefault Constructor called...!"; 
		}
		student(string name, string dob, string bg, string addr, string lno, string tele)
		{
			this->name = name;
			this->dob = dob;
			this->bg = bg;
			this->addr = addr;
			this->lno = lno;
			this->tele = tele;
		}
		student(const student &stud)
		{
			this->name = stud.name;
			cout<<"\nCopy Constructor called...!";
		}
		~student()
		{
			cout<<"\nStudent Destructor called...!";
		}
		inline void accept_student()
		{
			cout<<"\nEnter Name : ";
			cin>>name;
			cout<<"\nEnter Date of birth : ";
			cin>>dob;
			cout<<"\nEnter Blood Group : ";
			cin>>bg;
			cout<<"\nEnter Address : ";
			cin>>addr;
			cout<<"\nEnter Telephone NO : ";
			cin>>tele;
			cout<<"\nEnter License No : ";
			cin>>lno;
		}
		static void setData()
		{
			cout<<"\nStatic function executed...";
			cout<<"\nYour Adhar No is : "<<adhar;
		}
		friend class college;
};
class college
{
	string class_name;
	char div;
	int roll;
	public:
		college()
		{
			roll = 0;
			cout<<"\nDefault college constructor called...!";
		}
		void acceptcollege()
		{
			cout<<"\nEnter your Roll No : ";
			cin>>roll;
			cout<<"\nEnter your class : ";
			cin>>class_name;
			cout<<"\nEnter your division : ";
			cin>>div;
		}
		void printData(student &stud)
		{
			cout<<"\n| Name : "<<stud.name;
			cout<<" | DOB : "<<stud.dob;
			cout<<" | Blood Group : "<<stud.bg;
			cout<<" | Address : "<<stud.addr;
			cout<<" | Telephone No : "<<stud.tele;
			cout<<" | License No : "<<stud.lno;
			cout<<" | Roll No : "<<roll;
			cout<<" | Class : "<<class_name;
			cout<<" | division : "<<div;
			cout<<" |"<<endl;
		}	
		~college()
		{
			cout<<"\nCollege destructor called...!";
		}
};

int main()
{
	student s1("Ravi","13/11/2001","A+","Pune","8888888888","98745612");
	student s2 = s1;
	student *s[10];
	college *c[10];
	int i = 0, ch;
	while(1)
	{
		cout<<"\n\n\n===============================================";
		cout<<"\n***************| STUDENT DATABASE |*************";
		cout<<"\n 1. Add Student";
		cout<<"\n 2. Display Students";
		cout<<"\n 0. Exit";
		cout<<"\n=================================================";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		cout<<"\n=================================================";
		switch(ch)
		{
			case 1:
				cout<<"\n**************| Accepting New Student |*****************";
				s[i] = new student();
				c[i] = new college();
				s[i]->accept_student();
				c[i]->acceptcollege();
				cout<<"\n**************| Printing Student |**********************";
				c[i]->printData(*s[i]);
				i++;
				break;
			case 2:
				cout<<"\n**************| Printing All Student Data |****************";
				for(int j=0; j<i; j++)
				{
					c[j]->printData(*s[j]);
				}
				break;
			case 0:
				exit(0);
				cout<<"\n****************| THANK YOU |*******************";
				break;
			default:
				cout<<"\nInvalid choic...Enter Valid choice.....!";
		}
		cout<<"\n================================================";
	}
	
	return 0;
}