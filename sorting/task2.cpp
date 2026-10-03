#include<iostream>
using namespace std;

void insertionSort(float arr[], int size) {
    float key;
    int j=0;
    for(int i = 0; i < 5; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int size;
    cout<<"Enter the size of array: ";
    cin >> size;

    cin.ignore();

    float myArr[size];
    cout<<"\nEnter "<<size<<" Elements for the Array: ";
    for(int i = 0; i < size; i++) {
        cin >> myArr[i];
    }

    insertionSort(myArr, size);

    cout<<"\nSORTED FORM (DESCENDING) ";
    for(int i = 0; i < size; i++) {
        cout << myArr[i] << " ";
    }

    cout << endl;

    return 0;
}