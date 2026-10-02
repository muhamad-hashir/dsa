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
            cout << "Queue Overflow! Cannot insert " << value << ". The queue is FULL." << endl;
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
            cout << "Queue Underflow! Cannot delete. The queue is EMPTY." << endl;
            return;
        }
        
        cout << "Removed " << arr[front] << " from the queue." << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
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

    cout << "Testing Deletion on Empty Queue" << endl;
    q.dequeue();

    cout << "\nTesting Insertions" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "\nTesting Insertion on Full Queue" << endl;
    q.enqueue(60);

    cout << "\n";
    q.display();

    return 0;
}