#include<iostream>
using namespace std;

class DoubleEndedQueue{
    private:
        int *arr;
        int rear, maxSize;

    public:
        DoubleEndedQueue(int size) {
            maxSize = size;
            arr = new int [maxSize];
            rear = -1;
        }

        ~DoubleEndedQueue() {
            delete[] arr;
        }

        bool isEmpty() {
            return rear == -1;
        }

        bool isFull() {
            return rear == maxSize - 1;
        }

        void insertRear(int x) {
            if(isFull()) {
                cout << "Queue is full can not add./n"<<endl;
                return;
            }
            rear++;
            arr[rear] = x;
        }

        void insertFront(int x) {
            if(isFull()) {
                cout << "Queue is Full can not add\n";
                return;
            }
            for(int i = rear; i >= 0; i--) {
                arr[i + 1] = arr[i];
            }
            arr[0] = x;
            rear++;
        }

        int removeFront() {
            if(isEmpty()) {
                cout << "Queue is Empty!\n";
                return -1;
            }
            int temp = arr[0];

            for(int i = 0; i < rear; i++) {
                arr[i] = arr[i + 1];
            }

            rear--;
            return temp;
        }

        int removeRear() {
            if(isEmpty()) {
                cout<< "Queue is empty!\n";
                return -1;
            }

            int temp = arr[rear];
            rear--;
            return temp;
        }

        int peekFront() {
            if(isEmpty()) {
                cout << "Queue is empty!\n";
                return -1;
            }
            return arr[0];
        }

        int peekRear() {
            if(isEmpty()) {
                cout << "Queue is empty!\n";
                return -1;
            }
            return arr[rear];
        }

        void display() {
            if(isEmpty()) {
                cout << "Queue is empty!\n";
                return;
            }
            cout << "Current Queue: ";
            for(int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    DoubleEndedQueue q(5);

    q.insertRear(1);
    q.insertRear(2);
    q.insertFront(0);
    q.display();

    cout << "Front element: " << q.peekFront() << endl;
    cout << "Rear element: " << q.peekRear() << endl;

    q.removeFront();
    q.removeRear();
    q.display();

    return 0;
}