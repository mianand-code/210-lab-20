// COMSC-210 | Lab 20 | Mira Anand
// Module 7, Lesson: Doubly-Linked Lists & Class Destructors, Assignment: Chair Maker 3000
// IDE used: Visual Studio Code for Mac

#include <cstdlib> // needed to generate a random number
#include <ctime> // needed to generate a random number
#include <iomanip>
#include <iostream>
using namespace std;

// declaration and initialization of const int variables
// these variables are used to generate random numbers for prices and # of legs
// prices should be within the range of $100.00 - $999.99
// legs should be within the range of 3 - 4
const int SIZE = 3; // represents the size of the array (prices, Chair objects)
const int PRICE_MIN = 10000; // represents the minimum price of a chair, will be used to generate a random price
const int PRICE_MAX = 99999; // represents the maximum price of a chair, will be used to generate a random price
const int LEGS_MIN = 3; // represents the minimum # of legs for a chair, will be used to generate a random # of legs
const int LEGS_MAX = 4; // represents the maximum # of legs for a chair, will be used to generate a random # of legs

// creation of Chair class
class Chair {
// private member variables
private:
    int legs; // holds # of legs for a chair
    double * prices; // pointer to a double array that holds historical prices of a chair
// public member functions
public:
    // creation of a default constructor, Chair()
    // DESCRIPTION: initializes legs and prices to randomly selected values
    // - legs within the range 3 -4
    // prices within the range $100.00 - $999.99
    // ARGUMENTS: no arguments/parameters
    // RETURNS: no return type
    Chair() 
    {
        srand(time(0)); // needed as the first line in the constructor to generate random numbers for # of legs and prices
        prices = new double[SIZE]; // creation and assignment of a dynamic array to the private member variable, "prices"
        legs = rand() % (LEGS_MAX - LEGS_MIN + 1) + LEGS_MIN; // randomly assigning 3 or 4 legs
        for (int i = 0; i < SIZE; i++) // step through the array
            prices[i] = (rand() % (PRICE_MAX - PRICE_MIN + 1) + PRICE_MIN) / (double) 100; // assign a random price to each element of the array, between $100.00 - $999.99
    }
    // creation of a full parameter constructor, Chair(int l, double array[SIZE])
    // DESCRIPTION: initializes legs and prices by parameter
    // ARGUMENTS: int l, represents the # of legs
    // - double array[SIZE], an array of 3 doubles/prices
    // RETURNS: no return type
    Chair(int l, double array[SIZE]) 
    {
        prices = new double[SIZE]; // creation and assignment of a dynamic array to the private member variable, "prices"
        legs = l; // initialize legs by parameter
        for (int i = 0; i < SIZE; i++) // step through the array
            prices[i] = array[i]; // initialize prices array by parameter
    }
    
    // creating all setters together, to keep it organized
    // void setLegs(int l) function header
    // DESCRIPTION: this function will "set" the # of legs for each Chair object
    // ARGUMENTS: int l, which represents the # of legs
    // RETURNS: nothing, void function
    void setLegs(int l)     { legs = l; }
    // void setPrices(double p1, double p2, double p3) function header
    // DESCRIPTION: this function will "set" the prices for each element of the "prices" array, for each Chair object
    // ARGUMENTS: double p1, which represents 1st price assigned to the first element
    // - double p2, which represents the 2nd price assigned to the second element
    // - double p3, which represents the 3rd price assigned to the third element
    // RETURNS: nothing, void function
    void setPrices(double p1, double p2, double p3) 
    {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }
    
    // creating all getters together, to keep it organized
    // int getLegs() const function header
    // DESCRIPTION: this function will "get" the # of legs for each Chair object
    // ARGUMENTS: no arguments/parameters
    // RETURNS: the int value for # of legs
    // adding a trailing const, since getters do not change an object's data
    int getLegs() const     { return legs; }
    
    // double getAveragePrices() const function header
    // DESCRIPTION: this function will calculate the average price for each Chair object, based on the 3 prices stored in the "prices array"
    // ARGUMENTS: no arguments/parameters
    // RETURNS: the double value for average price
    // adding a trailing const, since getters do not change an object's data
    double getAveragePrices() const
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    
    // a member print() method to print the object's data
    // void print() function header
    // DESCRIPTION: this function outputs info for each Chair object - # of legs, 3 historical prices, & average historical price
    // ARGUMENTS: no arguments/parameters
    // RETURNS: nothing, void function 
    void print() 
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++) // step through "prices" array to display 3 historical prices
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices(); // getAveragePrices() function call, to calculate average historical price
        cout << endl << endl;
    }
};

// in main(), we need to exercise 3 things
// - our setters
// - our revised full parameter constructor
// - our revised default constructor
int main() 
{
    cout << fixed << setprecision(2); // setprecision() used to ensure prices are displayed to 2 decimal places
    
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    
    // revising 2nd code block to exercise new full parameter constructor
    // since one of the parameters of the partial constructor is an array of 3 doubles/prices, 
    // - we first have to create an array of 3 doubles/prices to use as a parameter/argument for the new Chair object
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52}; // creation and initialization of a new array that holds 3 prices
    Chair *livingChair = new Chair(3, livingChairPrices); // creating dynamic chair object with constructor
    livingChair->print();
    
    delete livingChair;
    livingChair = nullptr;
    
    // revising 3rd code block to exercise new default constructor
    // since the default constructor initializes legs and prices to randomly selected values, we do not need to call our setters
    Chair *collection = new Chair[SIZE]; // creating dynamic array of chair objects

    for (int i = 0; i < SIZE; i++) // step through array
        collection[i].print(); // print() function call, to output information for each Chair object
    
    // free memory, for good housekeeping
    delete [] collection;
    collection = nullptr;
    
    return 0;
}