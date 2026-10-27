#include <iostream>
using namespace std;

class Product {
public:
    int ID;
    char Category;
    float Price;
    Product* next;

    Product(int id, char cat, float pr) {
        ID = id;
        Category = cat;
        Price = pr;
        next = NULL;
    }
};

class ProductList {
private:
    Product* head;

public:
    ProductList() {
        head = NULL;
    }

    void insertAtEnd(int id, char cat, float pr) {
        Product* newProd = new Product(id, cat, pr);
        if (head == NULL) {
            head = newProd;
            return;
        }
        Product* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProd;
    }

    ProductList SearchCategory(char Category) {
        ProductList resultList;
        Product* temp = head;

        while (temp != NULL) {
            if (temp->Category == Category) {
                resultList.insertAtEnd(temp->ID, temp->Category, temp->Price);
            }
            temp = temp->next;
        }

        return resultList;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Product* temp = head;
        while (temp != NULL) {
            cout << "[ID: " << temp->ID << " | Cat: " << temp->Category 
                 << " | Price: $" << temp->Price << "] --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ProductList storeList;

    storeList.insertAtEnd(101, 'E', 299.99); // Electronics
    storeList.insertAtEnd(102, 'C', 49.99);  // Clothing
    storeList.insertAtEnd(103, 'E', 150.00); // Electronics
    storeList.insertAtEnd(104, 'G', 12.50);  // Grocery
    storeList.insertAtEnd(105, 'E', 89.99);  // Electronics

    cout << "--- Full Store Inventory ---" << endl;
    storeList.display();
    cout << endl;

    cout << "Searching for Category 'E'..." << endl;
    ProductList electronicsOnly = storeList.SearchCategory('E');

    cout << "--- Matching Products Found ---" << endl;
    electronicsOnly.display();

    return 0;
}