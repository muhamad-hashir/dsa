// Task 4
#include<iostream>
using namespace std;

int main() {
    int num;
    int *ptr = &num;

    cout<< "Enter an Integer: ";
    cin >> num;

    cout << "\nYou Entered: "<< num <<endl;
    cout << "Variable Address: "<< &num <<endl;
    cout<< "Value using Pointer: "<< *ptr <<endl;
}