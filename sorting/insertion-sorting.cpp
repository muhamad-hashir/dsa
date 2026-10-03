#include<iostream>
using namespace std;

void insertionSort(int arr[]) {
    int key;
    int j=0;

    for(int i = 1; i < 5; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j +1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    int myArr[5];
    cout << "Enter 5 Integers in any order" << endl;

    for (int i = 0; i < 5; i++) {
        cin >> myArr[i];
    }

    cout << "UNSORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << myArr[i] << " ";
    }
    cout << endl;

    insertionSort(myArr);

    cout << "SORTED ARRAY: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << myArr[i] << " ";
    }
    cout << endl;

    return 0;
}