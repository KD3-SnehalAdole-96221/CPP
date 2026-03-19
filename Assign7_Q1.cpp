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
        cout << "--------Employee --------" << endl;
        cout << "Enter Employee Id: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "--------Employee --------" << endl;
        cout << "Id: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "--------------------------" << endl;
    }
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
    void accept()
    {
        cout << "-----------Manager----------" << endl;
        Employee::accept();
        acceptManager();
    }
    virtual void display()
    {
        cout << "-----------Manager----------" << endl;
        Employee::display();
        displayManager();
    }

protected:
    void acceptManager()
    {
        cout << "-----------Manager----------" << endl;
        cout << "Enter Bonus for Manager: ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "-----------Manager----------" << endl;
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
    void accept()
    {
        cout << "-----------SalesMan----------" << endl;
        Employee::accept();
        acceptSalesMan();
    }
    void display()
    {
        cout << "-----------SalesMan----------" << endl;
        Employee::display();
        displaySalesMan();
    }

protected:
    void acceptSalesMan()

    {
        cout << "-----------SalesMan----------" << endl;
        cout << "Enter Sales Man commission";
        cin >> commission;
    }
    void displaySalesMan()
    {
        cout << "-----------SalesMan----------" << endl;
        cout << "Commission of SalesMan: " << commission << endl;
        ;
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

        // Manager::accept();

        // Salesman::accept();
    }
    void display()
    {
        Employee::display();

        // Manager::display();

        // Salesman::display();
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
    // Salesmanager sm;
    // sm.accept();
    // sm.display();
    int i=0,t;
    cout<<"Enter size"; cin>>t;
    Employee *ptr[t];

    

    int choice;
    int m1 = 0;
            int s1 = 0;
            int sm = 0;

    while ((choice = ::MenuList()) != 0)
    {

        switch (choice)
        {

        case 1:
            
            
                ptr[i] = new Manager();
                ptr[i]->accept();
                
                i++;
                break;
            
        case 2:
            
                ptr[i] = new Salesman();
                ptr[i]->accept();
                i++;
            
        case 3:
            
                ptr[i] = new Salesmanager();
                ptr[i]->accept();
                i++;
                break;
            

        case 4:
        {
            
            for (int j = 0; j < i; j++)
            {
                if (typeid(*ptr[j]) == typeid(Manager))
                {
                    m1++;
                }
                else if (typeid(*ptr[j]) == typeid(Salesman))
                {
                    s1++;
                }
                else
                {
                    sm++;
                }
            }
            cout << "Total manager: " << m1 << endl;
            cout << "Total Salesman: " << s1 << endl;
            cout << "Total Sales-Manager: " << sm << endl;
        }

        break;

        case 5:
            // for(int i; i<n; i++)
            // {
            //     ptr[i]->display();
            // }

            
            
                if (typeid(*ptr[i]) == typeid(Manager))
                    ptr[i]->display();
            
            break;

        case 6:
            
            
                if (typeid(*ptr[i]) == typeid(Salesman))
                    ptr[i]->display();
         

            break;

        case 7:
            
                if (typeid(*ptr[i]) == typeid(Salesmanager))
                    ptr[i]->display();
           
            break;
        }
    }
}