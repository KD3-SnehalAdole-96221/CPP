// Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
// Date is having data members day, month, year. Implement the following functions. 
// void initDate(); 
// void printDateOnConsole(); 
// void acceptDateFromConsole(); 
// bool isLeapYear();
#include<iostream>
using namespace std;
class Date
{
    private:
    int day;
    int month;
    int year;



    public:
    void initDate()
    {
         day =01;
         month =01;
         year = 2000;
    }

    
    public:
    void acceptDateFromConsole()
    {
        cout<<"Enter Day Month Year" <<endl;
        cin>>  day >>month >> year;
    }

    bool isLeapYear()
    {
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
   }


    void printDateOnConsole()
    {
        cout<<" day "<<day<<" month "<<" year "<<year <<endl;
    }

    int menuList(void)
    {
        int choice;
        cout<<"0. Exit"<<endl;
        cout<<"1. Initialize Date"<<endl;
        cout <<"2. Accept Date" <<endl;
        cout <<"3. Print Date" <<endl;
        cout <<"4. Is it leap year" <<endl;
        cin >> choice;
        return choice;
    }

int getYear()
{return year;}

};


int main()
{
    int choice;
    Date dt;
    while ((choice =dt.menuList())!=0)
    {
        switch(choice)
        {   case 1: dt.initDate();
                    break;
            case 2:dt.acceptDateFromConsole();
                    break;
            case 3:dt.printDateOnConsole();
                    break; 
            case 4:
            if (dt.isLeapYear()) 
            {
                cout << dt.getYear() << " is a Leap Year!" << endl;
            }
            else 
            {
                cout << dt.getYear() << " is NOT a Leap Year." << endl;
            }
            break;  

        }
     }
    return 0;
    }

