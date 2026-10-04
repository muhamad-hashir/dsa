#include<iostream>
using namespace std;

void linearSearch(int a[], int num) {
    bool found = false;
    for(int i = 0; i < 5; i++) {
        if(a[i] == num) {
            cout << "ELement "<<num<<" Founded at Position "<<i+1<<endl;
            found = true;
            break;
        } 
    }
    if(!found) {
        cout << "Element "<<num<< " Does Not Exist in the array"<<endl;
    }
}

int main() {
    int arr[5];
    cout << "Enter the Elements of Array: ";
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    int n;
    cout << "Enter the element you want to search: ";
    cin >> n;
    linearSearch(arr, n);
    return 0;
}