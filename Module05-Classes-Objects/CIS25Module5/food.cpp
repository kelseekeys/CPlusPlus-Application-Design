#include <iostream>
#include <string>
#include "Food.h"

using namespace std;

// Default constructor
Food::Food()
{
}

// Constructor
Food::Food(int inputId, double inputPrice, string inputDescription, int inputCalories)
{
    id = inputId;
    price = inputPrice;
    description = inputDescription;
    calories = inputCalories;
}

// Destructor
Food::~Food()
{
}

// Method used to display the food details
string Food::toString()
{
    string result = "Category: Food, Description: " + description +
                    ", Price: " + to_string(price) +
                    ", Calories: " + to_string(calories);

    return result;
}
