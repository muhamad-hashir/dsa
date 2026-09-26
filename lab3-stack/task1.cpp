#include<iostream>
using namespace std;

class StackUsingArray {
    private:
        int array[10];
        int top;
    public:
        StackUsingArray() {
            top = -1;
        }

        void push(int x){
            if(top < 9){
                array[++top] = x;
            } else {
                cout << "Overflow! Stack is full.\n";
            }
        }

        void pop() {
            if(top == -1){
                cout << "Underflow! Stack is empty!.\n";
                return;
            }
            cout << array[top] << " Removed from stack!"<<endl;
            top--;
        }

        void peek() {
            if(top == -1){
                cout << "Stack is empty so no peek exists"<< endl;
                return;
            }
            cout << "Current Top Pointer Value : " << array[top] << endl;
        }

        void isEmpty() {
            if(top == -1){
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack is not empty!"<<endl;
        }

        void isFull() {
            if(top == 9){
                cout << "Top is full"<<endl;
                return;
            }
            cout<<"Stack is not full!"<<endl;
        }

        void display() {
            cout << "ELements in LIFO order (Top to Bottom): "<<endl;

            if (top == -1)
            {
                cout << "Stack is empty.\n";
            }else {
                for (int i = top; i >= 0;i--)
                {
                    cout << array[i] << " ";
                }
            cout << endl;
            }
            
        }
        
};

int main() {
    StackUsingArray st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    st.pop();
    st.display();

    st.peek();

    st.isEmpty();

    st.isFull();

    return 0;
}