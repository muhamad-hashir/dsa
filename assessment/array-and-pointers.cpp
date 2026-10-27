#include<iostream>
using namespace std;

int findSecondMax(int *array, int size) {
    int max = *array;
    int second = -1;

    for(int i = 0; i < size; i++) {
        int val = *(array + i);
        if(val > max) {
            second =  max;
            max = val;
        } else if(val > second && val != max) {
            second = val;
        }
    }
    return second;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *a = new int[n];

    cout << "Enter "<<n<<" Elements to Enter...";
    for(int i = 0; i < n; i++) {
        cin >> *(a+i);
    }
    cout << "Second Largest ELement of the array is : " << findSecondMax(a,5) <<endl;

    delete[] a;
    return 0;
}