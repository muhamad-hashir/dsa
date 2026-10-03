#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

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

    delete[] myArr;
    
    return 0;
}