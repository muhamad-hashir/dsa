#include<iostream>
#include<cstdlib>
#include<ctime>
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

void insertionSort(float arr[], int size) {
    int key;
    int j = 0;
    for(int i = 0; i < size; i++) {
        key = arr[i];
        j = i -1;

        while( j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

float* initArray(int N) {

    float* arr = new float[N];

    for(int i = 0; i < N; i++) {
        arr[i] = static_cast<float>(rand() % 1001);
    }

    return arr;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int N;
    cout << "Enter the size of array: ";
    cin >> N;

    float *myArr = initArray(N);

    cout << "Randomly Initialized Array: ";
    for(int i =0; i < N; i++) {
        cout << myArr[i] << " ";
    }

    cout << endl;

    bubbleSort(myArr, N);
    cout << "Array after Bubble Sort: ";
    for(int i =0; i < N; i++) {
        cout << myArr[i] << " ";
    }

    cout << endl;

    insertionSort(myArr, N);
    cout << "Array after Insertion Sort: ";
    for(int i =0; i < N; i++) {
        cout << myArr[i] << " ";
    }
    cout << endl;

    delete[] myArr;
    
    return 0;
}