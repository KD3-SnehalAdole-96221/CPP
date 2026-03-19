//  Write a class Distance to hold feet and inches. Overload operator + as member function. Also, 
// overload ++ operator (to increment inches) as member function and -- operator as friend function. 
// Overload << and >> operators to accept and display distance.
#include<iostream>
using namespace std;
class Distance
{
private:
double feet;
double inches;
public:
Distance(void):feet(0.0),inches(0.0)
{

}
Distance(double feet,double inch):feet(feet),inches(inch)
{ }
void printRecord(void)
{
    cout<<"feet: "<<this->feet<<endl;
}

};
int main()
{
    Distance d1(10,20);
    

}