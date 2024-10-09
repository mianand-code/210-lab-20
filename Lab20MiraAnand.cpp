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
    int getLegs() { return legs; }
    
    double getAveragePrices() 
    {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }
    
    void print() 
    {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: ";
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() 
{
    cout << fixed << setprecision(2);
    
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();
    
    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    
    delete livingChair;
    livingChair = nullptr;
    
    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}