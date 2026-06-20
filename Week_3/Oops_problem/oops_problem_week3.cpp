#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract Class
class Compartment
{
public:
    virtual string notice() = 0; 
    virtual ~Compartment() {}
};

// Derived Classes
class FirstClass : public Compartment
{
public:
    string notice()
    {
        return "First Class Compartment";
    }
};

class Ladies : public Compartment
{
public:
    string notice()
    {
        return "Ladies Compartment";
    }
};

class General : public Compartment
{
public:
    string notice()
    {
        return "General Compartment";
    }
};

class Luggage : public Compartment
{
public:
    string notice()
    {
        return "Luggage Compartment";
    }
};

// Test Class
class TestCompartment
{
public:
    static void mainFunction()
    {
        Compartment* c[10];

        srand(time(0));

        // random compartments
        for (int i = 0; i < 10; i++)
        {
            int num = rand() % 4 + 1; // Random number 1 to 4

            switch (num)
            {
                case 1:
                    c[i] = new FirstClass();
                    break;
                case 2:
                    c[i] = new Ladies();
                    break;
                case 3:
                    c[i] = new General();
                    break;
                case 4:
                    c[i] = new Luggage();
                    break;
            }
        }

        // Polymorphic behavior
        cout << "Compartment Notices:\n\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "Compartment " << i + 1 << ": "
                 << c[i]->notice() << endl;
        }

        // Free memory
        for (int i = 0; i < 10; i++)
        {
            delete c[i];
        }
    }
};

int main()
{
    TestCompartment::mainFunction();
    return 0;
}