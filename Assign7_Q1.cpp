#include<iostream>
using namespace std;




// . Provide menu driven code for the functionalities:
// 1. Add Manager
// 2. Add Salesman
// 3. Add Salesmanager
// 4. Display the count of all employees with respect to designation
// 5. Display All Managers
// 6. Display All Salesman
// 7. Display All SalesManagers

#include <iostream>

using namespace std;

class Employee
{
private:
    int id;
    double salary;

public:
    Employee(void) : id(0), salary(0.0)
    {
    }
    Employee(int id, double salary) : id(id), salary(salary)
    {
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setsalary(int salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
    virtual ~Employee()
    { }
};

class Manager : virtual public Employee
{
private:
    double bonus;

public:
    Manager(void) : bonus(bonus)
    {
    }
    Manager(int id, double salary, double bonus) : bonus(bonus), Employee(id, salary)
    {
    }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus()
    {
        return bonus;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptManager();
    }
    virtual void display()
    {
        Employee::display();
        displayManager();
    }

protected:
    void acceptManager()
    {
        cout << "Enter Bonus for Manager: ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus Of Manager: " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{

private:
    double commission;

public:
    Salesman(void) : commission(commission)
    {
    }
    Salesman(int id, double salary, double commission) : commission(commission), Employee(id, salary)
    {
    }
    void setCommission(double commission)
    {
        this->commission = commission;
    }
    double getCommission()
    {
        return commission;
    }
    virtual void accept()
    {
        Employee::accept();
        acceptSalesMan();
    }
    virtual void display()
    {
        Employee::display();
        displaySalesMan();
    }

protected:
    void acceptSalesMan()

    {
        cout << "Enter Sales Man commission: ";
        cin >> commission;
    }
    void displaySalesMan()
    {
        cout << "Commission of SalesMan: " << commission << endl;
    }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager(void)
    {
    }
    Salesmanager(int id, double salary, double commission, double bonus) : Manager(id, salary, bonus), Salesman(id, salary, commission), Employee(id, salary)
    {
    }
    void accept()
    {
         Employee::accept();
         
        Salesman :: acceptSalesMan();
        Manager :: acceptManager();
        
    }

     void display()
    {
        Employee::display();

        Salesman :: displaySalesMan();
        Manager:: displayManager();

        
    }
};

int MenuList()
{
    int choice;
    cout << "1. Add Manager " << endl;
    cout << "2. Add Salesman " << endl;
    cout << "3. Add Salesmanager " << endl;
    cout << "4. Display the count of all employees with respect to designation " << endl;
    cout << "5. Display All Managers " << endl;
    cout << "6. Display All Salesman " << endl;
    cout << "7. Display All SalesManagers" << endl;
    cout << "Enter Choice" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    int n=0;
    Employee *ptr[10];
   

    int m=0;
    int m1=0;
    int sm=0;
    int sm1=0;
    while((choice=::MenuList())!=0)
    {
        switch(choice)
        {
            case 1:
            if(n<10)
            {
                ptr[n]=new Manager;
                ptr[n]->accept();
                n++;
                m++;
            }
            break;
            case 2:
            if(n<10)
            {
                ptr[n]=new Salesman;
                ptr[n]->accept();
                n++;
            }
            break;
            case 3:
            if(n<10)
            {
                ptr[n]=new Salesmanager;
                ptr[n]->accept();
                n++;
            }
            break;
            case 4:

            for(int i=0;i<n;i++)
            {
                if(typeid(*ptr[i])==typeid(Manager))
                {
                    m1++;
                }
                else if(typeid(*ptr[i])==typeid(Salesman))
                {
                    sm++;
                }
                else if(typeid(*ptr[i])==typeid(Salesmanager))
                {
                    sm1++;
                }
                cout << "Total manager: " << m1 << endl;
                cout << "Total Salesman: " << sm << endl;
                cout << "Total Sales-Manager: " << sm1<< endl;
            }
            break;

            case 5:
            for(int i=0; i<n;i++)
            {
                 if (typeid(*ptr[i])==typeid(Manager))
                 {
                    ptr[i]->display();
                 }
            }
            break;
            case 6:
            for(int i=0; i<n;i++)
            {
                if(typeid(*ptr[i])==typeid(Salesman))
                {
                    ptr[i]->display();
                }
            }
            break;

            case 7:
            for(int i=0;i<n;i++)
            {
                if (typeid(*ptr[i])==typeid(Salesmanager))
                {
                    ptr[i]->display();
                }
            }
            break;
            

            

        }
    }

}

