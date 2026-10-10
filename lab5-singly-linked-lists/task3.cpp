// Task 3 - insertathead() and display() demonstration.
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

        void insertathead(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
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

    list.insertathead(30);
    list.insertathead(20);
    list.insertathead(10);

    list.display();

    return 0;
}