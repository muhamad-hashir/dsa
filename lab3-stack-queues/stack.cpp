// Learning Data Structure Stack fro my DSA... 
#include<iostream>
#include<stack>

using namespace std;
/*
int main() {

    stack<string> browserHistory;

    browserHistory.push("google.com");
    browserHistory.push("github.com");
    browserHistory.push("stackoverflow.com");

    cout<< "Current Page: "<< browserHistory.top() <<endl;

    browserHistory.pop();

    cout << "After clicking back: "<< browserHistory.top() <<endl;

    cout << "Total pages in history: " <<browserHistory.size() << endl;

    cout << "Is history empty? " << (browserHistory.size() ? "Yes" : "No") << endl;

    return 0;

}*/
/*
int main() {
    int stack[5];
    int top = -1;

    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;
    stack[++top] = 40;
    stack[++top] = 50;
    stack[++top] = 60;

    cout << "Top Items: " << stack[top] << endl;
    
    cout << "Stack Elements from bottom to top: " << endl;

    for ( int i = 0; i <= top; i++)
    {
        cout << stack[i] << " " <<endl;
    }
    
    top--;

    cout << "Top item after pop: " << stack[top] << endl;

    return 0;
}*/


/*int main() {
    int* stack = new int[3];
    int top = -1;

    stack[++top] = 100;
    stack[++top] = 200;

    cout << "Top via pointer array: " << stack[top] << endl;

    delete[] stack; 
    return 0;
}*/