/*
Create a DEqueue class based on the discussion of deques (double-ended queues) theory class. 
With space for 10 items, it should include insertRear(), insertFront(), removeRear(), 
removeFront(), isEmpty(), and isFull() methods. It will need to support wraparound at 
the end of the array, as queues do.
*/
#include<iostream>
using namespace std;

class Dequeue {
    private:
        int list[10];
        int front;
        int rear;
        int nitems;

    public:
        Dequeue() {
            front = 0;
            rear = -1;
            nitems = 0;
        }

        bool isEmpty() {
            return (nitems == 0);
        }

        bool isFull() {
            return (nitems == 10);
        }

        void insertRear(int x) {
            if(!isFull()){
                if(rear == 9) {
                    rear = -1;
                }
                list[++rear] = x;
                nitems++;
                cout << x << " Inserted at right side of the queue. Rear = " << rear << endl;
            } else {
                cout << "Queue Overflow!\n";
            }
        }

        void insertFront(int x){
            if(!isFull()) {
                if(front == 0) {
                    front = 9;
                } else {
                    front--;
                }
                list[front] = x;
                nitems++;
                cout << x << " Inserted at left side of the queue. Front = " << front << endl;
            } else {
                cout << "Queue Overflow! Deque is full.\n";
            }
        }

        void removeRear() {
        if (!isEmpty()) {
            int val = list[rear];
            if (rear == 0) {
                rear = 9;
            } else {
                rear--;
            }
            nitems--;
            cout << "Removed " << val << " from Rear side. Rear=" << rear << " \t Front=" << front << endl;
        } else {
            cout << "Queue Underflow! Deque is empty.\n";
        }
    }

    void removeFront() {
        if (!isEmpty()) {
            int val = list[front];
            if (front == 9) {
                front = 0;
            } else {
                front++;
            }
            nitems--;
            cout << "Removed " << val << " from Front side. Rear=" << rear << " \t Front=" << front << endl;
        } else {
            cout << "Queue Underflow! Deque is empty.\n";
        }
    }

    void display() {
        cout << "Index\t\tvalue\t\tPointer\n";
        for (int i = 0; i < 10; i++) {
            cout << i << "\t\t";
        
            bool hasData = false;
            
            if (nitems > 0) {
                if (i == rear && i == front) {
                    cout << list[i] << "\t\tRear & Front";
                } else if (i == rear) {
                    cout << list[i] << "\t\tRear";
                } else if (i == front) {
                    cout << list[i] << "\t\tFront";
                } else {
                
                    cout << "empty\t\t";
                }
            } else {
                cout << "empty\t\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Dequeue dq;
    int choice, val;

    do {
        cout << "\nPlease enter a number representing an operation in the following list (-1 to quit):\n";
        cout << "1. InsertRear()\n";
        cout << "2. InsertFront()\n";
        cout << "3. RemoveRear()\n";
        cout << "4. RemoveFront()\n";
        cout << "5. Display()\n";
        cout << "User enters >> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value that you want to insert at Rear side: ";
                cin >> val;
                dq.insertRear(val);
                break;
            case 2:
                cout << "Enter a value that you want to insert at left side: ";
                cin >> val;
                dq.insertFront(val);
                break;
            case 3:
                dq.removeRear();
                break;
            case 4:
                dq.removeFront();
                break;
            case 5:
                dq.display();
                break;
            case -1:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != -1);

    return 0;
}