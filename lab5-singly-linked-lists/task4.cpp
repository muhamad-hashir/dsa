// Task 4 - insertatend() with empty-list handling.
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

class singlylist{
    private:
        Node* head;
    public:
        singlylist() {
            head = NULL;
        }

        void insertatend(int val) {
            Node* newNode = new Node(val);
            if(head == NULL) {          
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void display() {
            Node* temp = head;
            while(temp != NULL) {
                cout << temp->data << " --> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    singlylist list;

    list.insertatend(10); 
    list.insertatend(20);
    list.insertatend(30);
    cout << "Before: ";
    list.display();

    list.insertatend(40);
    cout << "After: ";
    list.display();

    return 0;
}