// Q2. Implement following classes. Test all functionalities in main() of each created class. Note that 
// employee is inherited into manager and salesman.

//------------------------constructor base initializer list---------------
//for avoiding diamond problem we use virtual keyword 
//if derived class objects is created and parameters are passed through that object then it will look for an parameteried constructor
//if you want to call parameterized constructor of base class then that parameterized constructor should be in base parameter constructor initializer list
//otherwise it will look for an non parameterized by default

#include<iostream>
using namespace std;
class Employee
{
    private:
    int id;
    double salary;
    public:
    Employee(void):id(0),salary(0.0)
    {
        cout<<"Employee base constructor"<<endl;
    }
    Employee(int id, double salary):id(id),salary(salary)
    {
        cout<<"Parameterized constructor called"<<endl;
    }
    void setId(int id)
    {
        this->id=id;
    }
    int getId()
    {
        return id;
    }
    void setSalary(double salary)
    {
        this->salary=salary;
    }
    double getSalary()
    {
        return salary;
    }
    void accept(void)
    {

        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter Salary: ";
        cin>>salary;

    }
    void display(void)
    {
        cout<<"id: "<<id<<endl;
        cout<<"salary"<<salary<<endl;
    }
    ~Employee()
    {
        cout<<"Destructor of base Employee"<<endl;
    }

};
class Manager:virtual public Employee
{
    private:
    double bonus;
    public:
    Manager(void):bonus(0.0)
    {
        cout<<"derived Manager Constructor called"<<endl;
     }
    Manager(int id, double salary,double bonus):bonus(bonus),Employee(id,salary)
    { 
        cout<<"parameterized Manager Constructor called"<<endl;
    }
    void setBonus(double bonus)
    {
        this->bonus=bonus;
    }
    double getBonus()
    {
        return bonus;
    }

     void accept(void)
    {

        Employee::accept();
        

    }
    void display(void)
    {
        Employee::display();
      
    }
    protected:
    void acceptManager()
    {
        cout<<"Enter Bonus: ";
        cin>>bonus;
    }

    void displayManager()
    {
        cout<<"Bonus"<<bonus<<endl;
    }
    ~Manager()
    {
        cout<<"destructor of derived Manager called"<<endl;
    }

};
class SalesMan:virtual public Employee
{
    private:
    double commission;
    public:
    
    SalesMan(void): commission(0.0),Employee()
    { 

         cout<<"derived SalesMan Constructor called"<<endl;
    }

    SalesMan(int id,double salary,double commission):commission(commission),Employee(id,salary)
    { 
         cout<<"derived Salesman Parameterized Constructor called"<<endl;
    }
    void setCommission(double commission)
    {
        this->commission=commission;
    }
    double getCommission()
    {
        return commission;
    }
    void accept()
    {
        // cout<<"Enter Commision"<<endl;
        // cin>>commission;
        Employee::accept();
    }
    void display()
    {
        Employee::display();
    }
    protected:
    void acceptSaleman(void)
    {
        cout<<"Enter Commission"<<endl;
        cin>>commission;
    }
    void displaySalesMan(void)
    {
        cout<<"Commisssion: "<<commission;
    }
    ~SalesMan()
    {
        cout<<"Destructor of Derived SalesMan"<<endl;
    }


};
class SalesManager:public Manager,public SalesMan
{

    public:
    SalesManager(void)
    { 
        cout<<"Indirect derived SalesManager Constructor called"<<endl;
    }

    SalesManager(int id,double salary,double commission,double bonus):Manager( id,  salary, bonus),SalesMan(id, salary, commission)
    {

    }

    void accept()
    {

        
        Manager::accept();
        Manager::acceptManager();
        SalesMan::accept();
        SalesMan::acceptSaleman();
    }
    void display()
    {

        Manager::display();
        Manager::displayManager();
        SalesMan::display();
        SalesMan::displaySalesMan();

    }
   ~SalesManager(void)
    { 
        cout<<"Destructor Indirect derived SalesManager Constructor called"<<endl;
    }


};
int main()
{
    SalesManager sm(1,200,300,30);
    
    
    // sm.setSalary(3000);
    // sm.accept();
    sm.display();

}