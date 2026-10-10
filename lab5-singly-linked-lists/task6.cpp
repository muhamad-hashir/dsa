// Task 6 - deleteathead() with empty-list handling.
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

        void deleteathead() {
            if(head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void display() {
            if(head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
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
    list.insertatend(40);
    cout << "Before: ";
    list.display();

    list.deleteathead();
    cout << "After: ";
    list.display();

    list.deleteathead();
    list.deleteathead();
    list.deleteathead();
    list.deleteathead();

    return 0;
}