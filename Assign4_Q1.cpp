// Q1. Write a class for Time and provide the functionality 
// Time() 
// Time(int h,int m,int s) 
// getHour() 
// getMinute() 
// getSeconds() 
// printTime() 
// setHour() 
// setMinute() 
// setSeconds() 
// In main create array of objects of Time. 
// Allocate the memory for the array and the object dynamically. 
// Write a menu driven code which provides below functionality 
// 1. Add Time 
// 2. Display All Time 
// 3. Display only hrs of all time objects



#include<iostream>
using namespace std;

class Time
{
    private:
    int h;
    int m;
    int s;
    public :
    Time():h(0),m(0),s(0)
    {

    }
    Time(int h, int m, int s): h(h),m(m),s(s)
    {

    }

    int getHour(void)
    {
        return h;
    }
    int getMin(void)
    {
        return m;
    }
    int getSec(void)
    {
        return s;
    }

    void setHour(int h)
    {
        this->h=h;
    }
    void setMin(int m)
    {
        this->m=m;
    }
    void setSec(int s)
    {
        this->s=s;
    }

    // int display()
    // {
    //     cout<<"hour: "<<h<<"min: "<<m<<"sec: "<<s<<endl;
    //     return 0;
    
    // }



    int MenuList()
    {
        int choice;
        cout<<"0.Exit"<<endl;
        cout<<"1. Add Time "<<endl;
        cout<<"2. Display All Time "<<endl;
        cout<<"3. Display only hrs of all time objects"<<endl;
        cin>>choice;
        return choice;
    }



};
int main()
{


    int choice;
    
    Time *arr= new Time[3];
    

    while((choice=arr->MenuList())!=0)
    {
        switch(choice)
        {
            case 1:
                for (int index = 0; index < 3; index++)
                {   int h ,m,s;
                    cout<<"Enter Hour Min Sec "<<index+1<<":";
                    cin>> h >> m >>s;
                    
                    arr[index].setHour(h);
                    arr[index].setMin(m);
                    arr[index].setSec(s);
                    
                }
                
                break;

            case 2:
            for(int index=0;index<3;index++)
            {
                cout<<" Time " << index+1<<": "<<
                
                arr[index].getHour()<<" :"<<
                arr[index].getMin()<<" :"<<
                arr[index].getSec()<<endl;

                
            }
                break;

            case 3:

                for(int index=0;index<3;index++)
                {
                    cout<<"Display hours"<<arr[index].getHour()<<endl;
                }
                break;

        }

        
    }
    
        delete [] arr;
        arr=NULL;


    

return 0;
}























































// if (count < size) {
//                     int hrs, mins, secs;
//                     cout << "Enter Hour, Min, Sec: ";
//                     cin >> hrs >> mins >> secs;
//                     arr[count].setHour(hrs);
//                     arr[count].setMinute(mins);
//                     arr[count].setSeconds(secs);
//                     count++;
//                     cout << "Time added successfully!" << endl;
//                 } else {
//                     cout << "Array is full!" << endl;
//                 }
//                 break;

//             case 2:
//                 cout << "\nDisplaying all times:" << endl;
//                 for (int i = 0; i < count; i++) {
//                     arr[i].printTime();
//                 }
//                 break;

//             case 3:
//                 cout << "\nDisplaying only hours:" << endl;
//                 for (int i = 0; i < count; i++) {
//                     cout << "Object " << i + 1 << " Hour: " << arr[i].getHour() << endl;
//                 }
//                 break;

//             case 0:
//                 cout << "Exiting program..." << endl;
//                 break;

//             default:
//                 cout << "Invalid choice! Try again." << endl;
//         }
//     } while (choice != 0);

//     // Clean up dynamic memory
//     delete[] arr;