// Q2. Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll.
// Mostly they do, but sometimes a car goes by without paying.
// The tollbooth keeps track of the number of cars that have gone by and of the total amount of money
// collected. Model this tollbooth with a class called tollbooth.
// The two data items are a type unsigned int to hold the total number of cars, and a type double to
// hold the total amount of money collected.
// A constructor initializes all data members to 0. A member function called payingCar() increments
// the car total and adds 0.50 to the cash total. An other function, called nopayCar()
// increments the car total but adds nothing to the cash total. Finally, a member function called
// printOnConsole() displays the two totals and number of paying as well as non paying cars total.
#include <iostream>
using namespace std;

class Toolbooth
{
private:
    unsigned int Total_car;
    double Total_amt;

public:
    Toolbooth()
    {
        Total_car = 0;
        Total_amt = 0;
    }

    int payingCar(void)
    {
        Total_car++;
        Total_amt = Total_amt + 0.50;
        return 0;
    }

    int nopayCar()
    {
        Total_car++;
        return 0;
    }

    int printOnConsole()
    {
        unsigned int paying_cars = Total_amt / 0.50;

        unsigned int non_paying_cars = Total_car - paying_cars;

        cout << "\n--- Tollbooth Statistics ---" << endl;
        cout << "Total Cars: " << Total_car << endl;
        cout << "Total Cash: $" << Total_amt << endl;
        cout << "Paying Cars: " << paying_cars << endl;
        cout << "Non-paying Cars: " << non_paying_cars << endl;
        cout << "----------------------------" << endl;
        return 0;
    }

    int MenuList()
    {
        int choice;
        cout << "1.Paying Cars Passed" << endl;
        cout << "2.Non Paying Car Passed" << endl;
        cout << "3. show Toolbooth Statistics" << endl;
        cin >> choice;
        return choice;
    }
};

int main()
{
    Toolbooth t1;

    int choice;

    while ((choice = t1.MenuList()) != 0)
    {
        switch (choice)
        {
        case 1:

            t1.payingCar();
            break;

        case 2:

            t1.nopayCar();
            break;

        case 3:

            t1.printOnConsole();
            break;
        }
    }
    return 0;
}
