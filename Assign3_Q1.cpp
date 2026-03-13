// Q1. Write a class to find volume of a Cylinder by using following members. (volume of 
// Cylinder=3.14 * radius * radius *height) ( use static wherever needed. hint-PI) 
// Class having following member functions: 
// Cylinder() 
// Cylinder(double radius, double height) 
// getRadius() 
// setRadius() 
// getHeight() 
// setHeight() 
// calculateVolume() 
// Initialize members using constructor member initializer list.


#include<iostream>
using namespace std;
 class Cylinder
 {
    double radius;
    double height;
    static double PI;  

    public:
    Cylinder():radius(0),height(0)
    { 

        this->radius=radius;
        this->height=height;
    }

    Cylinder(double radius, double height): radius(radius),height(height)
    { 
            this->radius=radius;
            this->height=height;
    }

    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }

    double getRadius() { return radius; }
    double getHeight() { return height; }


    
    double calculateVolume() {
        return PI * radius * radius * height;
    }

 };
 double Cylinder :: PI=3.14;

 int main()
 {
    Cylinder c1;
    Cylinder c2;
    c1.setRadius(2);
    c1.setHeight(4);
    
    c2.setHeight(2);
    c2.setRadius(3);
    
    cout<<"radius: "<<c1.getRadius()<<endl;
    cout<<"height: "<<c1.getHeight()<<endl;
    
    cout<<"c1 volume: "<<c1.calculateVolume()<<endl;
     cout<<"radius: "<<c2.getRadius()<<endl;
    cout<<"height: "<<c2.getHeight()<<endl;
    
    cout<<"c2 volume: "<<c2.calculateVolume()<<endl;

 }