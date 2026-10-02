#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int front;
        int rear;
        int nitems;
        int arr[5];
    public:
        CircularQueue() {
            front = -1;
            rear = -1;
            nitems = 0;
        }

        bool isFull() {
            return(nitems == 5);
        }

        bool isEmpty() {
            return(nitems == 0);
        }

        void enqueue(int x){
            if(isFull()) {
                cout << "Queue is Full can not add."<<endl;
                return;
            }

            // Its very first element (EMPTY!) ; all this code instead of rear++
            if(isEmpty()) {
                rear = 0;
                front = 0;
            } else {
                rear = (rear + 1) % 5;
            }

            arr[rear] = x;
            nitems++;
            cout << x << " Inserted into the queue."<<endl;
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Already EMpty can't dequeue!"<<endl;
                return;
            }

            cout << arr[front] << " Removed from queue."<<endl;
            nitems--;
            // This Block instead of front++ 
            if(isEmpty()) {
                rear = -1;
                front = -1;
            } else {
                front = (front + 1) % 5;
            }
        }

        void display() {
            if(isEmpty()) {
                cout << "Queue is EMPTY!"<<endl;
                return;
            }

            cout << "Current Queue: "<<endl;

            for(int i = 0; i < nitems; i++) {
                int index = (front + i) % 5;
                cout << arr[index] << " ";
            }
            cout << "\n\n";
        }
};

int main() {
    CircularQueue q1;

    cout << "Filling Queue:" <<endl;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.display();

    cout << "Removing some items: "<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.display();

    cout << "Adding two more (testing wrap around)"<<endl;
    q1.enqueue(60);
    q1.enqueue(70);
    q1.display();
}