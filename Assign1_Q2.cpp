// Q2. Write a menu driven program for Date in a CPP language using structure and also using class. 
// Date is having data members day, month, year. Implement the following functions. 
// void initDate(); 
// void printDateOnConsole(); 
// void acceptDateFromConsole(); 
// bool isLeapYear();


#include<iostream>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
void initDate(struct Date *ptr)
{
    ptr->day = 01;
    ptr->month =01;
    ptr-> year =2000;
}

void acceptDateFromConsole(struct Date *ptr)
{
    cout << "Enter Day, Month, Year: " << endl;
    cin >> ptr->day >> ptr->month >> ptr->year;
}


void printDateOnConsole(struct Date *ptr)
{
cout << "Day: "<<ptr->day << " Month: "<< ptr->month <<" Year: "<<ptr->year<< endl;
}


int menuList(void)
{
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1.Initialize Date"<<endl;
    cout<<"2.Accept Date"<<endl;
    cout<<"3.Print Date"<<endl;
    cin>> choice;
    return choice ;

}
 
int main()
{
    int  choice;
    struct Date dt;
    while((choice = menuList())!=0)
    {
        switch(choice)
        {   case 1: initDate(&dt);
                    break;
            case 2:acceptDateFromConsole(&dt);
                    break;
            case 3: printDateOnConsole(&dt);
                    break;   

        }
    }
    return 0;
}




