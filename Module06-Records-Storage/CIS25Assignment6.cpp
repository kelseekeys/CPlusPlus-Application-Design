// Name: Kelsee Keys
// Course: CIS 25
// Date: 10/12/2026
// Assignment: 6

#include <iostream>
#include <string>

using namespace std;

class Product {
private:
    string name;
    int id;
    double price;
    int quantity;

public:
    // Constructor
    Product(string productName, int productId,
            double productPrice, int productQuantity) {
        name = productName;
        id = productId;
        price = productPrice;
        quantity = productQuantity;
    }

    // Member function to display product information
    void displayProduct() {
        cout << "Product Name: " << name << endl;
        cout << "Product ID: " << id << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    // Getter
    string getName() {
        return name;
    }

    // Setter
    void setPrice(double newPrice) {
        if (newPrice >= 0) {
            price = newPrice;
        }
    }

    // Member function to calculate inventory value
    double calculateValue() {
        return price * quantity;
    }
};

int main() {
    // Create two Product objects
    Product product1("Laptop", 101, 899.99, 5);
    Product product2("Headphones", 102, 49.99, 10);

    // Display the first product
    cout << "Product 1 Information" << endl;
    product1.displayProduct();
    cout << "Inventory Value: $"
         << product1.calculateValue() << endl;

    cout << endl;

    // Display the second product
    cout << "Product 2 Information" << endl;
    product2.displayProduct();
    cout << "Inventory Value: $"
         << product2.calculateValue() << endl;

    cout << endl;

    // Demonstrate the getter and setter
    cout << "Product Name: " << product1.getName() << endl;

    product2.setPrice(44.99);
    cout << "Updated Headphones Price: $"
         << product2.calculateValue() / 10 << endl;

    return 0;
}
