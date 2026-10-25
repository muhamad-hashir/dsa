
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = NULL;
    }

    // 1. Display the list
    void display() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while(true) {
            cout << temp->data << " ";
            temp = temp->next;

            if(temp == head)
                break;
        }

        cout << endl;
    }

    // 2. Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // 3. Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // 4. Insert after a given value
    void insertAfterValue(int target, int value) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while(temp->next != head && temp->data != target) {
            temp = temp->next;
        }

        if(temp->data != target) {
            cout << "Target not found" << endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 5. Delete at the beginning
    void deleteAtBeginning() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        Node* toDelete = head;
        head = head->next;
        temp->next = head;

        delete toDelete;
    }

    // 6. Delete at the end
    void deleteAtEnd() {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if(head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next->next != head) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = head;

        delete toDelete;
    }

    // 7. Delete by value
    void deleteByValue(int value) {
        if(head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Case 1: The value is at the head
        if(head->data == value) {
            if(head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            Node* last = head;

            while(last->next != head) {
                last = last->next;
            }

            Node* toDelete = head;
            head = head->next;
            last->next = head;

            delete toDelete;
            return;
        }

        // Case 2: The value is elsewhere
        Node* temp = head;

        while(temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }

        // Case 3: The value was not found
        if(temp->next == head) {
            cout << "Value not found" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        delete toDelete;
    }

    // 8. Search for a value
    bool search(int value) {
        if(head == NULL) {
            return false;
        }

        Node* temp = head;

        while(true) {
            if(temp->data == value) {
                return true;
            }

            temp = temp->next;

            if(temp == head) {
                break;
            }
        }

        return false;
    }

    // 9. Count the nodes
    int countNodes() {
        if(head == NULL) {
            return 0;
        }

        int count = 0;
        Node* temp = head;

        while(true) {
            count++;
            temp = temp->next;

            if(temp == head) {
                break;
            }
        }

        return count;
    }

    // 10. Destructor: free all nodes
    ~CircularLinkedList() {
        if(head == NULL) {
            return;
        }

        Node* temp = head->next;

        while(temp != head) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }

        delete head;
        head = NULL;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Original list: ";
    list.display();

    list.insertAtBeginning(5);
    cout << "After inserting at beginning: ";
    list.display();

    list.insertAfterValue(20, 25);
    cout << "After inserting 25 after 20: ";
    list.display();

    list.deleteAtBeginning();
    cout << "After deleting beginning: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleting end: ";
    list.display();

    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.display();

    cout << "Number of nodes: " << list.countNodes() << endl;

    if(list.search(25)) {
        cout << "25 found" << endl;
    }
    else {
        cout << "25 not found" << endl;
    }

    return 0;
}