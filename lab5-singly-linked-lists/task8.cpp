// Task 8 - deletevalue(int val) searches and removes a matching node.
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

        void deletevalue(int val) {
            if(head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            if(head->data == val) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* prev = head;
            Node* curr = head->next;
            while(curr != NULL && curr->data != val) {
                prev = curr;
                curr = curr->next;
            }
            if(curr == NULL) {
                cout << "Value not found" << endl;
                return;
            }
            prev->next = curr->next;  
            delete curr;
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

    list.deletevalue(30);
    cout << "After: ";
    list.display();

    list.deletevalue(99);

    return 0;
}