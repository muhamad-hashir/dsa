#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void bubbleSort(float arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(float arr[], int size) {
    float key;
    int j = 0;
    for(int i = 0; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] < key) {
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

void copyArray(float source[], float destination[], int size) {
    for(int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int sizes[] = {10, 100, 1000};

    cout << "PERFORMANCE BENCHMARK" << endl;

    for(int s = 0; s < 3; s++) {
        int N = sizes[s];
        cout << "\nTesting for N = " << N << ":" << endl;

        float* originalArr = initArray(N);
        float* workArr = new float[N];

        copyArray(originalArr, workArr, N);
        
        auto startBubble = chrono::high_resolution_clock::now();
        bubbleSort(workArr, N);
        auto endBubble = chrono::high_resolution_clock::now();
        
        chrono::duration<double, milli> bubbleDuration = endBubble - startBubble;
        cout << "Bubble Sort Time:    " << bubbleDuration.count() << " ms" << endl;

        copyArray(originalArr, workArr, N);
        
        auto startInsertion = chrono::high_resolution_clock::now();
        insertionSort(workArr, N);
        auto endInsertion = chrono::high_resolution_clock::now();
        
        chrono::duration<double, milli> insertionDuration = endInsertion - startInsertion;
        cout << "Insertion Sort Time: " << insertionDuration.count() << " ms" << endl;

        delete[] originalArr;
        delete[] workArr;
    }

    return 0;
}