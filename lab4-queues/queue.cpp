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
            for(int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(nitems == 0){
                cout << "Queue is Empty."<<endl;
                return true;
            }
            else {
                cout << "Queue is not empty."<<endl;
                return false;
            }
        }

        bool isFull() {
            if(nitems == 5){
                cout << "Queue is Full."<<endl;
                return true;
            }
            else{
                cout << "Queue is not Full."<<endl;
                return false;
            }
        }

        void enqueue(int x) {
            if(isFull()){
                cout << "Queue is full!"<<endl;
                return;
            }
            rear++;
            arr[rear] = x;
            nitems++;
            cout << arr[rear] << " Inserted into the array!"<< endl;
        }

        void dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << arr[front] << " removed from the array";
            front++;
            nitems--;
            
        }

        void display() {
            if(isEmpty()) {
                cout << "Queue is empty!"<<endl;
                return;
            }
            for(int i = 0; i < nitems; i++) {
                cout << arr[front + i] << " ";
            }
        }

};

int main() {

    Queue q1;
    int option;
    int value;
    do
    {
        cout << "\n\nWhat operation do u want to perfrom? Select Option Number, ENter 0 to exit."<<endl;
        cout <<"1. Enqueue()"<<endl;
        cout <<"2. Dequeue()"<<endl;
        cout <<"3. isEmpty()"<<endl;
        cout <<"4. isFull()"<<endl;
        cout <<"5. display()"<<endl;
        cout <<"6. Clear Screen"<<endl;

        cout << "Enter your choice: ";
        cin>>option;

        switch (option)
        {
        case 0:
            cout << "Exiting...."<<endl;
            return 0;

        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            q1.dequeue();
            break;

        case 3:
            q1.isEmpty();
            break;

        case 4:
            q1.isFull();
            break;

        case 5:
            q1.display();
            break;

        case 6:
            system("clear");
            break;
        
        default:
            cout << "Select number from 0-6"<<endl;
        }
    } while (true);

    return 0;
    
}