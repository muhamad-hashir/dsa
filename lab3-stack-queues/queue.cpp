// Learning Data Structure Queue For DSA...

#include<iostream>
using namespace std;

/*class QueryUsingArray {
    private:
        int list[5];
        int front;
        int rear;
        int nitems;
    public:
        QueryUsingArray() {
            front = 0;
            rear = -1;
            nitems = 0;
        }
    
    void insert(int val) {
        if(nitems < 5) {
            if (rear == 4)
            {
                rear = -1;
            }
            list[++rear] = val;
            nitems++;
            cout << val << " Inserted into Queue\n"; 
            }else {
                cout << "Overflow! Queue is full.\n";
            }
    }

    int remove() {
        if (nitems > 0)
        {
            nitems--;
            int temp = list[front++];

            if (front > 4)
            {
                front = 0;
            }
            return temp;
        } else {
            cout << "Underflow! List is empty.\n";
            return -1;
        }
        
    }
};

int main() {
    QueryUsingArray q;

    q.insert(8);
    q.insert(5);

    cout << "Removed value: " << q.remove() << endl;
    cout << "Removed value: " << q.remove() << endl;

    return 0;
} */

// Example 2

class SimpleQueue{
    private:
        int list[3];
        int rear;
        int front;
        int nitems;

    public:
        SimpleQueue() {
            front = 0;
            rear = -1;
            nitems = 0;
        }

        void insert(int val){
            if (nitems < 3)
            {
                if (rear == 2)
                {
                    rear = -1;
                }
                list[++rear] = val;
                nitems++;
                cout << val << " Inserted into the queue!\n";
            }else{
                cout << "Queue is full.\n";
            }
            
        }

        int remove() {

        if (nitems > 0)
        {
            nitems--;
            int temp = list[front++];

            if (front > 2)
            {
                front = 0;
            }
            return temp;
        } else {
            cout << "Underflow! List is empty.\n";
            return -1;
        }
        
    }
};

int main() {
    SimpleQueue s;
    s.insert(10);
    s.insert(12);
    s.insert(25);

    cout << "Removed Value : "<< s.remove() << endl;

    s.insert(20);

    return 0;
}