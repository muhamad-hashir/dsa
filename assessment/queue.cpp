#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int nitems;
        int arr[5];
    public:
        Queue() {
            front = 0;
            rear = -1;
            nitems = 0;
        }

        bool isEmpty() {
            if(nitems == 0) {
                return true;
            } else {
                return false;
            }
        }

        bool isFull() {
            if(nitems == 5) {
                return true;
            } else {
                return false;
            }
        }

        void enqueue(int x) {
            if(isFull()) {
                cout << "Queue OverFLow!"<<endl;
                return;
            }
            rear++;
            arr[rear] = x;
            nitems++;
            cout << arr[rear] << " Added to the queue"<<endl;
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Queue Underflow!..."<<endl;
                return;
            }
            cout << arr[front] << " Removed from the queue." << endl;
            front++;
            nitems--;
        }

        void dipslay() {
            if(isEmpty()) {
                cout << "Queue is empty.."<<endl;
                return;
            }
            for(int i = 0; i < nitems; i++) {
                cout << arr[front + i] << " ";
            }

            cout << endl;
        }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dipslay();

    q.dequeue();
    q.dequeue();

    q.dipslay();

    q.enqueue(40);

    q.dipslay();

    return 0;
}