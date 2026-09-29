#pragma once

#include <string>

using namespace std;

class Food
{
private:
    int id;
    double price;
    string description;
    int calories;

public:
    Food(); // default constructor
    Food(int inputId, double inputPrice, string inputDescription, int inputCalories); // constructor
    ~Food(); // destructor

    string toString(); // displays food details
};
