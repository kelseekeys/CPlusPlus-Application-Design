// Name: Kelsee Keys
// Course: CIS 25
// Date: 10/12/2026
// Assignment: 7

#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 10;

// Product record
class Product {
private:
    int id;
    string name;
    double price;

public:
    Product() {
        id = 0;
        name = "";
        price = 0.0;
    }

    Product(int productId, string productName, double productPrice) {
        id = productId;
        name = productName;
        price = productPrice;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    void displayProduct() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: $" << price << endl;
    }
};

// Base User class
class User {
protected:
    string username;

public:
    User(string name) {
        username = name;
    }

    string getUsername() const {
        return username;
    }
};

// Product Inventory System
class Inventory {
private:
    Product products[MAX_PRODUCTS];
    int count;

    // Find a product by ID using binary search
    int binarySearch(int target) const {
        int left = 0;
        int right = count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (products[mid].getId() == target) {
                return mid;
            }

            if (products[mid].getId() < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

public:
    Inventory() {
        count = 0;

        // Initial records, already sorted by ID
        products[count++] = Product(101, "Laptop", 899.99);
        products[count++] = Product(102, "Headphones", 49.99);
        products[count++] = Product(103, "Keyboard", 29.99);
    }

    // Available to both roles
    void viewProducts() const {
        cout << "\n--- Product Inventory ---\n";

        if (count == 0) {
            cout << "No products available.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            products[i].displayProduct();
        }
    }

    // Available to both roles
    void searchProduct(int id) const {
        int index = binarySearch(id);

        if (index != -1) {
            cout << "\nProduct found:\n";
            products[index].displayProduct();
        } else {
            cout << "\nProduct ID " << id
                 << " was not found.\n";
        }
    }

    // Available to Admin only
    void addProduct(int id, string name, double price) {
        if (count >= MAX_PRODUCTS) {
            cout << "Inventory is full.\n";
            return;
        }

        if (id <= 0 || price < 0) {
            cout << "Invalid product ID or price.\n";
            return;
        }

        if (binarySearch(id) != -1) {
            cout << "Product ID already exists.\n";
            return;
        }

        // Find the correct position to keep IDs sorted
        int position = 0;

        while (position < count &&
               products[position].getId() < id) {
            position++;
        }

        // Shift products to make room
        for (int i = count; i > position; i--) {
            products[i] = products[i - 1];
        }

        products[position] = Product(id, name, price);
        count++;

        cout << "Product added successfully.\n";
    }

    // Available to Admin only
    void deleteProduct(int id) {
        int index = binarySearch(id);

        if (index == -1) {
            cout << "Product not found.\n";
            return;
        }

        for (int i = index; i < count - 1; i++) {
            products[i] = products[i + 1];
        }

        count--;
        cout << "Product deleted successfully.\n";
    }
};

// Admin role
class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void addRecord(Inventory& inventory,
                   int id, string name, double price) {
        cout << "\nAdmin " << username << ": ";
        inventory.addProduct(id, name, price);
    }

    void viewRecords(const Inventory& inventory) {
        cout << "\nAdmin " << username
             << " is viewing records.\n";
        inventory.viewProducts();
    }

    void deleteRecord(Inventory& inventory, int id) {
        cout << "\nAdmin " << username << ": ";
        inventory.deleteProduct(id);
    }

    void searchRecord(const Inventory& inventory, int id) {
        inventory.searchProduct(id);
    }
};

// Regular User role
class RegularUser : public User {
public:
    RegularUser(string name) : User(name) {}

    void viewRecords(const Inventory& inventory) {
        cout << "\nUser " << username
             << " is viewing records.\n";
        inventory.viewProducts();
    }

    void searchRecord(const Inventory& inventory, int id) {
        inventory.searchProduct(id);
    }
};

int main() {
    Inventory inventory;

    Admin admin("Alex");
    RegularUser user("Jordan");

    // Admin can view, add, search, and delete
    cout << "=== ADMIN ACCESS ===\n";

    admin.viewRecords(inventory);

    admin.addRecord(inventory, 104, "Mouse", 19.99);

    admin.searchRecord(inventory, 104);

    admin.deleteRecord(inventory, 102);

    admin.viewRecords(inventory);

    // Regular user can only view and search
    cout << "\n=== REGULAR USER ACCESS ===\n";

    user.viewRecords(inventory);

    user.searchRecord(inventory, 103);

    cout << "\nRegular users cannot add or delete products.\n";

    return 0;
}
