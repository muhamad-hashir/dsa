/*
Implement stack using array of size 10, Add a display method which will display the current
value of the Top pointer and then just display the elements of the stack in LIFO fashion 
without popping any element of the stack. 
*/
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

        void display() {
            cout << "Current Top Pointer Value : " << top << endl;
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
    st.push(40);
    st.push(50);

    st.display();

    return 0;
}