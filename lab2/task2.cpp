// task 2
#include<iostream>
using namespace std;

int main() {

    int arr[8];
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i < 8; i++) {
        cin >> arr[i];
    }

    cout<< "\nElements in reverse: \n";
    for(int i = 7; i >= 0; i--){
        cout<< arr[i] << " ";
    }

    return 0;
}