// Q1. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
// holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
// Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
// should be menu driven and should not cause memory leakage.
// Hint - Create class Product and inherit into Book and Tape. Also create array like Product* arr[3]

// Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
// employee is inherited into manager and salesman.

#include <iostream>
using namespace std;

class product
{
private:
    int id;
    string title;
protected:
    double price;

public:
    product(void) : id(0), title(""), price(0.0)
    {
    }
    virtual double calculate_Bill() = 0;

    virtual void acceptRecord(void)
    {
        cout << "id: ";
        cin >> id;
        cin.ignore();
        cout << "title: ";
        getline(cin, title);
        cout << "price: ";
        cin >> price;
    }
    virtual void printRecord(void)
    {
        cout << "id : " << id << endl;
        cout << "Title : " << title << endl;
        cout << "Price : " << price << endl;
    }

    virtual ~product(){};
};

class Book : public product
{
private:
    string author;

public:
    Book(void) : author("")
    {
    }
    Book(string author) : author(author)
    {
    }

    virtual void acceptRecord(void)
    {
        product::acceptRecord();
        cin.ignore();
        cout << "Author : ";
        getline(cin, author);
    }
    virtual void printRecord(void)
    {
        product::printRecord();
        cout << "Author : " << author << endl;
    }
     virtual double calculate_Bill()
    {

         return price * 0.90;
    }
};
class Tape : public product
{
private:
    string artist;

public:
    Tape(void) : artist(" ")
    {
    }
    virtual void acceptRecord(void)
    {
        product::acceptRecord();
        cin.ignore();
        cout << "Artist : ";
        getline(cin, artist);
    }
    virtual void printRecord(void)
    {
        product::printRecord();
        cout << "Artist: " << artist << endl;
    }
    virtual double calculate_Bill()
    {
        return price * 0.95;
    }
};

int MenuList()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Book" << endl;
    cout << "2.Tape" << endl;
    cout<<"3.Display"<<endl;
    cout<<"4.count Total Bill"<<endl;
    cout << "Enter Choice" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    product *arr[3];

    int choice;int n = 0;
    while ((choice = ::MenuList()) != 0)
    {
        

        switch (choice)
        {
        case 1:
        {
            if (n < 3)
            {
                arr[n] = new Book(); // upcasting
                arr[n]->acceptRecord();
                n++;
            }
        }
        break;

        case 2:
        {
            if (n < 3)
            {
                arr[n] = new Tape();
                arr[n]->acceptRecord();
                n++;
            }
        }
        break;

        case 3:
        {
            for (int i = 0; i < n; i++)
            {
                arr[i]->printRecord();
                
            }
        }
        break;

        case 4:
        {   double totalBill = 0;
            for(int i=0;i<n;i++)
            {
                cout<<"------------------"<<endl;
                arr[i]->printRecord();
                totalBill += arr[i]->calculate_Bill();
                cout<<"-------------------"<<endl;
            }
            cout<<"Total Bill: "<< totalBill <<endl;
            break;
        }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        delete arr[i];
    }


    return 0;
}
