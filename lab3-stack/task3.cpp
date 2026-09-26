#include<iostream>
using namespace std;

class CharacterStack {
    private:
        char array[100];
        int top;
        int capacity;

    public:
        CharacterStack(int size = 100) {
            capacity = size;
            top = -1;
        }

        void push(char x) {
            if(top < capacity - 1) {
                array[++top] = x;
            } else {
                cout << "Stack Overflow! Cannot push." << endl;
            }
        }

        char pop() {
            if(top == -1) {
                cout << "Stack Underflow! Stack is empty." << endl;
                return '\0';
            }
            return array[top--];
        }

        bool isEmpty() {
            return top == -1;
        }

        int getSize() {
            return top + 1;
        }
};

void reverseString(string str) {
    CharacterStack stack(str.length());

    cout << "Original String: " << str << endl;
    cout << "\nPushing characters onto stack:" << endl;
    for(int i = 0; i < str.length(); i++) {
        cout << "Pushing: " << str[i] << endl;
        stack.push(str[i]);
    }

    cout << "\nPopping characters from stack to get reversed string:" << endl;
    string reversedStr = "";
    while(!stack.isEmpty()) {
        char ch = stack.pop();
        cout << "Popping: " << ch << endl;
        reversedStr += ch;
    }

    cout << "\nReversed String: " << reversedStr << endl;
}

int main() {
    string input;

    cout << "STRING REVERSAL USING STACK" << endl;
    cout << "Enter a string to reverse: ";
    getline(cin, input);

    reverseString(input);

    if(input.length() > 0) {
        reverseString(input);
    }

    return 0;
}