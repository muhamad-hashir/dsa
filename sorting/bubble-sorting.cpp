#include<iostream>
using namespace std;

void bubbleSort(int a[]) {

    for(int i = 0; i < 5; i++) {

        for(int j=0; j < (5 - i - 1);j++) {

            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 
            }
        }
    }
}

int main() {

    int myArr[5];

    cout << "Enter the array elements in random order: ";
    for(int i =0; i<5; i++){
        cin >> myArr[i];
    }

    cout << endl;

    cout<< "UNSORTED ARRAY: ";
    for(int i =0; i<5; i++){
        cout << myArr[i] << " ";
    }

    cout << endl;

    bubbleSort(myArr);

    cout<< "SORTED ARRAY: ";
    cout << "Enter the array elements in random order: ";
    for(int i =0; i<5; i++){
        cout << myArr[i] << " ";
    }

    cout << endl;
    return 0;
}