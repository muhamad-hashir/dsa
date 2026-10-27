#include <iostream>
using namespace std;

class ProductNode {
public:
    int ID;
    char Category;
    float Price;
    ProductNode* next;
    ProductNode* prev;

    ProductNode(int id, char cat, float pr) {
        ID = id;
        Category = cat;
        Price = pr;
        next = NULL;
        prev = NULL;
    }
};

class DoublyQueue {
private:
    ProductNode* head;
    ProductNode* tail;

public:
    DoublyQueue() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int id, char cat, float pr) {
        ProductNode* newNode = new ProductNode(id, cat, pr);
        
        if (head == NULL) { 
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void dequeue() {
        if (head == NULL) { 
            cout << "Queue is Empty!" << endl;
            return;
        }

        ProductNode* temp = head;
        cout << "Dequeued Product ID: " << temp->ID << endl;

        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
    }

    ~DoublyQueue() {
        while (head != NULL) {
            ProductNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyQueue dq;

    dq.enqueue(101, 'A', 29.99);
    dq.enqueue(102, 'B', 19.99);
    dq.enqueue(103, 'C', 39.99);

    dq.dequeue();
    dq.dequeue();
    dq.dequeue();
    dq.dequeue(); 

    return 0;
}