// Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members 
// day, month, year. Implement the following functions. 
// void initDate(struct Date* ptrDate); 
// void printDateOnConsole(struct Date* ptrDate); 
// void acceptDateFromConsole(struct Date* ptrDate); 
#include<stdio.h>
struct Date
{
    int day;
    int  month;
    int year;
};
void initDate(struct Date *ptrDate)
{
 ptrDate->day =1;
 ptrDate->month =1;
 ptrDate->year =2026;
}

void AcceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter Day , Month , Year: ");
    scanf("%d",&ptrDate->day);
    scanf("%d",&ptrDate->month);
    scanf("%d",&ptrDate->year);
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date:%d ",ptrDate->day);
    printf("Month:%d ",ptrDate->month);
    printf("Year:%d \n",ptrDate->year);
}
int menuList(void)
{
     int choice; 
    printf("0.Exit.\n");
    printf("1.Initialize Date\n");
    printf("2.Accept Date From Console.\n"); 
    printf("3.print Date On Console.\n");
    printf("Enter the choice : "); 
    scanf("%d",&choice); 
    return choice;
    
}

int main()
{
    int choice; 
    struct Date dt;
    while((choice = menuList())!=0)
    {
        switch(choice)
        {   case 1: initDate(&dt);
                    break;
            case 2:AcceptDateFromConsole(&dt);
                    break;
            case 3: printDateOnConsole(&dt);
                    break;   

        }
    }
    return 0;
}