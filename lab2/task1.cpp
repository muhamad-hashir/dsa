#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size;
    int sum = 0;
    
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "The elements of the array are: " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "The sum of the elements of the array is: " << sum << endl;
    
    return 0;
}