#include<iostream>
using namespace std;

class StackUsingArray{
    private:
        int arr[10];
        int top = -1;
    public:
        void push(int x) {
            if(top == 9) {
                cout << "The Stack is Full"<<endl;
                return;
            }
            top++;
            arr[top] = x;
            cout << arr[top] << " Added to the Stack At Top Position "<<top<<endl;
        }

        void pop() {
            if(top == -1){
                cout << "Stack is empty."<<endl;
                return;
            }
            cout << arr[top] << " Removed from the stack"<<endl;
            top--;
        }

        void display() {
            if(top == -1) {
                cout << "Stack is Empty"<<endl;
                return;
            }
            for(int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();
    s.pop();

    s.display();

    s.push(50);
    s.display();

    return 0;
}