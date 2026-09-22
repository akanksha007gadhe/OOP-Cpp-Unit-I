#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    double price;
    int stockQuantity;
    static int totalProducts;

public:
    Product(int id, string name, double p, int stock)
        : productId(id), productName(name), price(p), stockQuantity(stock) {
        totalProducts++;
    }

    inline int getId() const { return productId; }
    inline string getName() const { return productName; }
    inline double getPrice() const { return price; }

    void updateStock(int quantity) {
        stockQuantity = quantity;
    }

    static int getTotalProducts() {
        return totalProducts;
    }

    void display() const {
        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;
    }

    ~Product() {
        totalProducts--;
    }
};

int Product::totalProducts = 0;

int main() {
    Product p1(2001, "Smartphone", 32000, 20);
    Product p2(2002, "Headphones", 1800, 35);
    Product p3(2003, "Smartwatch", 4500, 25);

    cout << "=== Product Catalog ===" << endl;
    p1.display();
    p2.display();
    p3.display();

    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;
}
