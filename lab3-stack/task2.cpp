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
                cout << x << " pushed to stack successfully!" << endl;
            } else {
                cout << "Overflow! Stack is full.\n";
            }
        }

        void pop() {
            if(top == -1){
                cout << "Underflow! Stack is empty!.\n";
                return;
            }
            cout << array[top] << " Removed from stack!" << endl;
            top--;
        }

        void peek() {
            if(top == -1){
                cout << "Stack is empty so no peek exists" << endl;
                return;
            }
            cout << "Current Top Pointer Value : " << array[top] << endl;
        }

        void isEmpty() {
            if(top == -1){
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack is not empty!" << endl;
        }

        void isFull() {
            if(top == 9){
                cout << "Stack is full" << endl;
                return;
            }
            cout << "Stack is not full!" << endl;
        }

        void display() {
            cout << "Elements in LIFO order (Top to Bottom): " << endl;

            if (top == -1)
            {
                cout << "Stack is empty.\n";
            }else {
                for (int i = top; i >= 0; i--)
                {
                    cout << array[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    StackUsingArray stack;
    int choice;
    int value;

    while(true) {
        cout << "\n     STACK MENU     " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check Empty" << endl;
        cout << "6. Check Full" << endl;
        cout << "7. Exit" << endl;
        cout << "=====================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;

            case 4:
                stack.display();
                break;

            case 5:
                stack.isEmpty();
                break;

            case 6:
                stack.isFull();
                break;

            case 7:
                cout << "Closing..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please enter 1-7" << endl;
        }
    }

    return 0;
}