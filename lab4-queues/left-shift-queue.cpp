// Queue with Pointers (Fixed Front, Left Shift)

#include<iostream>
using namespace std;

class PointerQueue {
    private:
        int* arr;
        int capacity;
        int nitems;
    public:

        PointerQueue(int size) {
            capacity = size;
            arr = new int[capacity];
            nitems = 0;
        }

        ~PointerQueue() {
            delete[] arr;
        }

        void enqueue(int x) {
            if(nitems == capacity){
                cout << "Queue Overflow!"<< endl;
                return;
            }
            *(arr + nitems) = x;
            nitems++;
            cout << x << " Added into the Queue!"<<endl;
        }

        void dequeue() {
            if(nitems == 0){
                cout << "Queue Underflow!"<<endl;
                return;
            }
            // Front is ALWAYS at index 0 *(arr + 0)
            cout << *arr << " removed from queue.\n";
            
            // SHIFT LEFT using pointer arithmetic: arr[i] = arr[i+1]
            for (int i = 0; i < nitems - 1; i++) {
                *(arr + i) = *(arr + i + 1);
            }

            nitems--;
        }

        void displayFront() {
            if(nitems == 0) {
                cout << "Queue is empty.\n";
                return;
            }
            cout << "Front ELement: "<< *arr << endl;
        }
};    

int main() {

    PointerQueue q(3); 

    q.enqueue(100);
    q.enqueue(200);
    q.displayFront();

    q.dequeue();
    q.displayFront(); 

    return 0;
}