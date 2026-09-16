/*
Modify the above queue class so that front is always at the index 0 while rear pointer 
changes its position with both the insertion and deletion of elements of the queue.
*/
#include<iostream>
using namespace std;

class FrontQueue {
    private:
        int list[5];
        int front;
        int rear;
    public:
        FrontQueue() {
            front = 0;
            rear = -1;
        }

        void insert(int val) {
            if (rear < 4){
                list[++rear] = val;
                cout << val << " Inserted, Rear is now at Index " << rear << endl;
            } else {
                cout << "Queue Overflow! Cannot Insert.\n";
            }
        }

        int remove() {
            if (rear >= 0)
            {
                int temp = list[0];

                for(int i = 0; i < rear; i++){
                    list[i] - list[i +1];
                }
                rear--;
                cout << "Removed Value " << temp << ". Rear moved to " << rear << endl;
                return temp;
            } else {
                cout << "Queue is Empty!"<< endl;
                return -1;
            }
        }

        void display() {
            cout << "Current Queue : ";
            if (rear < 0)
            {
                cout << "Empty\n";
            } else {
                for (int i = 0; i <= rear; i++) {
                    cout << list[i] << " ";
                }
                cout << endl;
            }
            
        }
};

int main() {
    FrontQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.remove();
    q.display();

    q.insert(40);
    q.display();

    return 0;
}