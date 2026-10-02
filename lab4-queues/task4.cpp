#include <iostream>
using namespace std;

class Queue {
private:
    int arr[5];
    int front;
    int rear;

public:

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == 4);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << "." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << "Inserted " << value << " into the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot delete." << endl;
            return;
        }
        cout << "Removed " << arr[front] << " from the queue." << endl;
        front++;
        
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    int countElements() {
        if (isEmpty()) {
            return 0;
        }
        return (rear - front + 1);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "Initial element count: " << q.countElements() << endl;

    cout << "\nInserting Elements" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Current element count: " << q.countElements() << endl;

    cout << "\nRemoving an Element" << endl;
    q.dequeue();

    cout << "Current element count after deletion: " << q.countElements() << endl;

    cout << "\n";
    q.display();

    return 0;
}