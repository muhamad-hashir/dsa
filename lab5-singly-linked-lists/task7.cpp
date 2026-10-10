// Task 7 - deleteatend() handles empty, one-node, and multi-node lists.
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

        void deleteatend() {
            if(head == NULL) {
                cout << "List is empty" << endl;
                return;
            }
            if(head->next == NULL) {
                delete head;
                head = NULL;
                return;
            }
            Node* temp = head;
            while(temp->next->next != NULL) {   // stops at the second last node
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
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

    list.deleteatend();

    list.insertatend(10);
    list.deleteatend();
    list.display();

    list.insertatend(10);
    list.insertatend(20);
    list.insertatend(30);
    cout << "Before: ";
    list.display();

    list.deleteatend();
    cout << "After: ";
    list.display();

    return 0;
}