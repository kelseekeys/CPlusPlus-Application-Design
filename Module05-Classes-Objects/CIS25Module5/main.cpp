#include <iostream>
#include "Food.h"

using namespace std;

int main()
{
    Food food1(1, 5.99, "Apple", 95);

    cout << food1.toString() << endl;

    return 0;
}
