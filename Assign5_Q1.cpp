// Q1. Create a class Date with data memebrs day,month and year. 
// Create a class Person with data members name,address and birthdate. The birthdate should be of 
// type Date. 
// Create a class Student with data members id, marks, course and joining date, end date. The joining 
// date and end date should be of type date. 
// Implement above classes. Test all functionalities in main(). 
// (Note - Only Perform the Association in the above case. No need of Inheritance)


#include<iostream>
using namespace std;
class Date
{
    private:
    int day ;
    int month;
    int  year;

   public:
   Date():day(0),month(0),year(0)
   {   }
   Date(int date ,int month,int year):day(day),month(month),year(year)
   {   }

   void acceptDate()
   {
    cout<<"Enter day: "<<endl;
    cin>>day;
    cout<<"Enter month: "<<endl;
    cin>>month;
    cout<<"Enyer year: "<<endl;
    cin>>year;
   }
   void printDate()
   {
    cout<<day<<"/"<<month<<"/"<<year<<endl;
   }

};
class Person
{
    private:
    string name;
    string address;
    Date birthDate;

    public:

    Person(void):name(""),address("")
    {  }
    Person(string name,string address,int day, int month, int year):name(name),address(address),birthDate(birthDate)
    { }
    Person(string name,string address,Date birthDate):name(name),address(address),birthDate(birthDate)
    { }

    void accept( void )
    {
        cout<<"name "; 
        cin>>name; 
        cout<<"address : "; 
        cin>>address;  
        cout<<"Enter BirthDate : "; 
        this->birthDate.acceptDate( ); 
    }

    void display(void)
    {
        cout<<"name: "<<name<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"BirthDate: ";
        this->birthDate.printDate();

    }



};
class Student
{
    private:
    int id;
    int marks;
    string course;
    Date joinDate;
    Date endDate;

    public:

    Student(void):id(0),marks(0),course("")
    { }
    Student(int id,int marks,string course,Date joinDate,Date endDate):id(id),marks(marks),course(course),joinDate(joinDate),endDate(endDate)
    { }
    Student(int id,int marks,string course,int day,int month,int year):id(id),marks(marks),course(course),joinDate(day,month,year),endDate(day,month,year)
    { }
   
    void accept( void )
    {
        cout<<"id: "; 
        cin>>id; 
        cout<<"marks : "; 
        cin>>course;  
        cout<<"Enter JoinDate : "; 
        this->joinDate.acceptDate( ); 
        cout<<"Enter End Date: ";
        this->endDate.acceptDate();
    }
    void display( void )
    {
        cout<<"id : "<<id<<endl;
        cout<<"Empid : "<<marks<<endl; 
        cout<<"Salary : "<<course<<endl;
        cout<<"JoinDate : ";  
        this->joinDate.printDate( ); 
        cout<<"End Date : ";
        this->endDate.printDate();
    }


};



   int main()
{
    Person p1;

    cout<<"Enter Person Details"<<endl;
    p1.accept();

    cout<<"\nPerson Details"<<endl;
    p1.display();


    cout<<"\n----------------------\n";


    Student s1;

    cout<<"Enter Student Details"<<endl;
    s1.accept();

    cout<<"\nStudent Details"<<endl;
    s1.display();

    return 0;
}
