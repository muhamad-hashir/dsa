// task 3
#include<iostream>
using namespace std;

int main() {

    int num = 42;
    int *ptr = &num;

    cout<< "Variable value: "<< num << endl;
    cout<< "Variable Address: "<< &num << endl;
    cout<< "Pointer Value: " << ptr <<endl;
    cout<< "Value using pointer: " << *ptr <<endl;

    return 0;
}