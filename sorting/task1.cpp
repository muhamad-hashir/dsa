#include<iostream>
using namespace std;

void bubbleSort(float arr[],int size) {
    for(int i = 0; i < size -1; i++) {
        for(int j = 0; j < size - i -1; j++) {
            if(arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j +1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    cin.ignore();
    
    float* myArr = new float[size];

    cout << "\nEnter "<<size<<" Elements of array: ";
    for(int i = 0; i < size; i++) {
        cin >> myArr[i];
    }

    bubbleSort(myArr, size);

    cout<<"\nSORTED ARRAY (DESCENDING ORDER): "<<endl;
    for(int i=0; i <size; i++){
        cout << myArr[i] << " ";
    }

    delete[] myArr;

    return 0;
}