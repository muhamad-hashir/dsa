/* Task 1
   This is a simple C++ program to demonstrate basic array operations.
*/

#include <iostream>
using namespace std;

int maxArr(int arr[], int size) {

    int max = arr[0];

    for(int i = 0; i < size; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minArr(int arr[], int size) {

    int min = arr[0];

    for(int i = 0; i<size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int sumArr(int arr[], int size) {

    int sum = 0;

    for(int i=0;i<size;i++){
       sum =+ sum + arr[i];
    }
    return sum;
}

int averageArr(int arr[], int size) {

    int sum = 0;

    for(int i=0;i<size;i++){
        sum =+ sum + arr[i];
    }
    return sum/size;
}

int main() {

    int size;

    int i;
    cout << "Enter Array Size: ";
    cin >> size;

    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(i=0;i < size; i++) {
        cin >> arr[i];

    }
    cout<<"Maximum Element in the array is: "<<maxArr(arr,size);

    cout<<"\nMinimum Element in the array is: "<<minArr(arr,size);

    cout<<"\nSum of all Elements is: "<<sumArr(arr,size);

    cout<<"\nAverage of the Array is: "<<averageArr(arr,size);

   return 0;

}