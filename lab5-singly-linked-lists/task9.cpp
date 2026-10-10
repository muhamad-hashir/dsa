// Task 9 - complete menu-driven singly linked list program.
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
            while(temp->next->next != NULL) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
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
    int choice, val;

    do {
        cout << endl;
        cout << "===== SINGLY LINKED LIST =====" << endl << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Head" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Delete a Specific Value" << endl;
        cout << "6. Display List" << endl;
        cout << "7. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertathead(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertatend(val);
                break;
            case 3:
                list.deleteathead();
                break;
            case 4:
                list.deleteatend();
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deletevalue(val);
                break;
            case 6:
                list.display();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
        }
    } while(choice != 7);

    return 0;
}