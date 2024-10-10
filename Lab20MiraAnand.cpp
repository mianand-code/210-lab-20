// COMSC-210 | Lab 20 | Mira Anand
// Module 7, Lesson: Doubly-Linked Lists & Class Destructors, Assignment: Chair Maker 3000
// IDE used: Visual Studio Code for Mac

#include <cstdlib> // needed to generate a random number
#include <ctime> // needed to generate a random number
#include <iomanip> // to use setprecision()
#include <iostream>
using namespace std;

// declaration and initialization of const int variables
// these variables are used to generate random numbers for prices and # of legs and to also set an array size
// prices should be within the range of $100.00 - $999.99
// legs should be within the range of 3 - 4
const int SIZE = 3; // represents array size (prices, Chair objects)
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
    // DESCRIPTION: initializes legs and prices to random values (within specified ranges)
    // - creates a dynamic array to hold 3 random prices
    // - legs within the range 3 - 4
    // - prices within the range $100.00 - $999.99
    // ARGUMENTS: no arguments/parameters
    // RETURNS: no return type
    Chair() 
    {
        prices = new double[SIZE]; // creation and assignment of a dynamic array to the private member variable, "prices"
        legs = rand() % (LEGS_MAX - LEGS_MIN + 1) + LEGS_MIN; // random assignment of 3 or 4 legs
        for (int i = 0; i < SIZE; i++) // step through the array
            prices[i] = (rand() % (PRICE_MAX - PRICE_MIN + 1) + PRICE_MIN) / (double) 100; // assign a random price to each element of the array, between $100.00 - $999.99
    }
    // creation of a full parameter constructor, Chair(int l, double array[SIZE])
    // DESCRIPTION: initializes legs and prices by parameter
    // - creates a dynamic array to hold 3 random prices
    // ARGUMENTS: int l, represents the # of legs
    // - double array[SIZE], an array of 3 doubles/prices
    // RETURNS: no return type
    Chair(int l, double array[SIZE]) 
    {
        prices = new double[SIZE]; // creation and assignment of a dynamic array to the private member variable, "prices"
        legs = l; // initialize legs by parameter
        for (int i = 0; i < SIZE; i++) // step through the array
            prices[i] = array[i]; // initialize "prices" array by parameter
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
    // DESCRIPTION: this function will calculate the average price for each Chair object, based on the 3 prices stored in the "prices" array
    // ARGUMENTS: no arguments/parameters
    // RETURNS: the double value for average price
    // adding a trailing const, since getters do not change an object's data
    double getAveragePrices() const
    {
        double sum = 0.0;
        for (int i = 0; i < SIZE; i++) // step through the "prices" array
            sum += prices[i]; // keep a running total of the prices
        
        return sum / SIZE; // calculate and return average
    }
    
    // creation of a member print() method to print the object's data
    // void print() function header
    // DESCRIPTION: this function outputs info for each Chair object - # of legs, 3 historical prices, & historical average price
    // ARGUMENTS: no arguments/parameters
    // RETURNS: nothing, void function 
    void print() 
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++) // step through "prices" array to display 3 historical prices
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices(); // getAveragePrices() function call, to calculate historical average price
        cout << endl << endl;
    }

    // creation of a class destructor to avoid memory leaks
    ~Chair()
    {
        delete[] prices; // free memory
    }
};

// in main(), we need to exercise these items:
// - our setters
// - our revised full parameter constructor
// - our revised default constructor
// - our member print() method
// we don't need to exercise getLegs() const, since we have our print() method
// getAveragePrices() const is exercised within our print() method
// the class destructor is automatcally called when an object goes out of scope, so we don't need to call it in main()
int main() 
{
    srand(time(0)); // needed as the first line in main() to generate random numbers for # of legs and prices
    cout << fixed << setprecision(2); // setprecision() is used to ensure that prices are displayed to 2 decimal places
    
    // this 1st code block does not need to be changed since it exercises our setters
    Chair *chairPtr = new Chair;  // creating pointer to first Chair object
    chairPtr->setLegs(4); // setLegs() function call, setting legs to 4
    chairPtr->setPrices(121.21, 232.32, 414.14); // setPrices() function call, setting all 3 prices of object
    chairPtr->print(); // print() function call, to output information for this Chair object
    // free memory, for good housekeeping
    delete chairPtr;
    chairPtr = nullptr;
    
    // revising 2nd code block to exercise revised full parameter constructor
    // since one of the parameters of this constructor is an array of 3 doubles/prices, 
    // - we first have to create an array of 3 doubles/prices to use as a parameter/argument for this new Chair object
    double livingChairPrices[SIZE] = {525.25, 434.34, 252.52}; // creation and initialization of a new array with 3 specific prices
    Chair *livingChair = new Chair(3, livingChairPrices); // creating dynamic Chair object with constructor
    livingChair->print(); // print() function call, to output information for this Chair object
    // free memory, for good housekeeping
    delete livingChair;
    livingChair = nullptr;
    
    // revising 3rd code block to exercise revised default constructor
    // since the default constructor initializes legs and prices to random values (within specified ranges), we do not need to call our setters here
    Chair *collection = new Chair[SIZE]; // creating dynamic array of Chair objects
    for (int i = 0; i < SIZE; i++) // step through newly created array of Chair objects
        collection[i].print(); // print() function call, to output information for each Chair object
    // free memory, for good housekeeping
    delete[] collection;
    collection = nullptr;
    
    return 0;
}