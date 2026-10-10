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

class SinglyLinkedList{
    private:
        Node* head;
    public:
        SinglyLinkedList() {
            head = NULL;
        }

    void insertAtTheHead(int val) {
        Node* newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
    }

    void insertAtTheTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }

    void insertAtAnyPosition(int val, int pos) {
        Node* newNode = new Node(val);
        if(pos == 0) {
            newNode -> next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for(int i=0; temp != NULL && i<pos-1; i++) {
            temp = temp -> next;
        }
        if(temp == NULL) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void deleteAtTheHead() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head -> next;
        delete temp;
    }

    void deleteAtTheTail() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if(head -> next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp -> next -> next != NULL) { // CONIDITION LOOKS TWO NODES AHEAD AND TEMP MOVES ONLY ONE NODE
            temp = temp -> next;   // delete the last node & finds the second laast node
        }
        delete temp -> next;
        temp -> next = NULL;
    }

    void deleteAtAnyPosition(int pos) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        if(pos == 0) {
            head = head -> next;
            delete temp;
            return;
        }
        for(int i=0; temp != NULL && i<pos-1; i++) {
            temp = temp -> next;
        }
        if(temp == NULL || temp -> next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }
        Node* next = temp -> next -> next;
        delete temp -> next;
        temp -> next = next;
    }

    void Display() {
        Node* temp = head;
        while(temp!= NULL) {
            cout << temp->data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" <<endl;
    }
};

int main() {
    SinglyLinkedList list;

    list.insertAtTheHead(5);
    list.insertAtTheHead(10);
    list.insertAtTheHead(15);
    list.Display();

    list.insertAtTheTail(20);
    list.insertAtTheTail(25);
    list.Display();

    list.insertAtAnyPosition(30, 2);
    list.Display();

    list.deleteAtTheHead();
    list.Display();

    list.deleteAtTheTail();
    list.Display();

    list.deleteAtAnyPosition(1);
    list.Display();
    
    return 0;
}