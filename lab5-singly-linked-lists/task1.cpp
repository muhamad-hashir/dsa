// Task 1 - Node class with data, next pointer, and constructor.
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
};

int main() {
    Node* node = new Node(10);
    cout << "Data: " << node->data << endl;
    if(node->next == NULL) {
        cout << "Next: NULL" << endl;
    }
    delete node;
    return 0;
}