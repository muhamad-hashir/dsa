#include<iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    int key;
    int j=0;

    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j +1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {

        int min = i;

        for(int j = i+1; j < size; j++) {

            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min!=1) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int* a = new int[n];
    cout << "Enter the "<<n<<" Elements of the arary: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "UNSORTED ARRAY: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    insertionSort(a,n);

    cout << "SORTED ARRAY BY SELECTION SORT: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    selectionSort(a,n);

    cout << "SORTED ARRAY BY INSERTION SORT: "<<endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}