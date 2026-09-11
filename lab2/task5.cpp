// task 5
#include<iostream>
using namespace std;

int main() {
    float arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "ELements at odd poistions: ";
    float *ptr = arr;
    for (int i = 0; i < 10; i++) {
        if(i % 2 == 1) {
            cout << "Position "<< i << ": " << *(ptr + i)<< endl;
        }
    }
    return 0;

}