// Q1. Write a menu driven program to calculate volume of the box(length * width * height).
// Provide parameterless, parameterized(with 3 parameters) and single paramaterized constructor.
// Create the local objects in respective case and call the function to caluclate area.
// Menu options ->
// 1. Calculate Volume with default values
// 2. Calculate Volume with length,breadth and height with same value
// 3. Calculate Volume with different length,breadth and height values.

#include <iostream>
using namespace std;

class Rectangle
{
private:
    float l;
    float b;
    float h;

public:
    Rectangle(void) // parameterless constructor
    {
        l = 2;
        b = 4;
        h = 6;
    }
    

    Rectangle(int S)
    {

        l = b = h = S;
    }

    Rectangle(int l, int b, int h)
    {

        this->l = l;
        this->b = b;
        this->h = h;
    }

    int CalculateVolume()
    {
        cout << "The Volume is: " << l * b * h << endl;
        return 0;
    }

    int MenuList()
    {
        int choice;
        cout << "0.Exit" << endl;
        cout << "1. Enter Side of rectangle" << endl;
        cout << "2.Enter length Breadth And height" << endl;
        cout << "3.Print Volume of default values" << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{

    Rectangle r1;
    int choice;
    while ((choice = r1.MenuList()) != 0)
    {

        switch (choice)
        {
        case 1:
        {
            float S;
            cout << "Enter Side: " << endl;
            cin >> S;
            Rectangle r2(S);
            r2.CalculateVolume();
            break;
        }
        case 2:
        {
            float l, b, h;
            cout << "Enter Length Breadth and Height" << endl;
            cin >> l;
            cin >> b;
            cin >> h;

            Rectangle r3(l, b, h);
            r3.CalculateVolume();
            break;
        }
        case 3:
        {
            r1.CalculateVolume();
            break;
        }
        }
    }
    return 0;
}