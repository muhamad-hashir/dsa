#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

            void insertAtFront(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deleteAtHead() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtTail() {
        if(tail == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete temp;
    }

    void displayBackward() {
        Node* temp = tail;
        while(temp != NULL) {
            cout << temp->data << " <--> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};
