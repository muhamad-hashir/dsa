#include<iostream>
using namespace std;

class Stack {
    private:
        char array[100];
        int top;
    public:
        Stack() {
            top = -1;
        }

        void push(char x) {
            if(top < 99) {
                array[++top] = x;
            }
        }

        char pop() {
            if(top == -1) {
                return '\0';
            }
            return array[top--];
        }

        bool isEmpty() {
            return top == -1;
        }
};

bool isBalanced(string expression) {
    Stack stack;

    for(int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }

        if(ch == ')' || ch == '}' || ch == ']') {
            if(stack.isEmpty()) {
                return false; 
            }

            char opening = stack.pop();

            if((ch == ')' && opening != '(') ||
               (ch == '}' && opening != '{') ||
               (ch == ']' && opening != '[')) {
                return false;
            }
        }
    }

    if(!stack.isEmpty()) {
        return false;
    }

    return true;
}

int main() {
    string expression;

    cout << "Enter expression to check: ";
    getline(cin, expression);

    if(isBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}