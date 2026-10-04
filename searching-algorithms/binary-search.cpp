#include<iostream>
using namespace std;


int binarySearch(int arr[], int left, int right, int x) {
    while(left <= right) {
        
        int mid = left + (right - left)/2;
        if(arr[mid] == x) {
            return mid;
        } else if(arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int num;
    int myarr[10];
    int output;

    cout << "Enter Elements Of Array In Ascending Order: "<<endl;
    for(int i = 0; i < 10; i++) {
        cin >> myarr[i];
    }

    cout << "Enter One Element You Want To Search: ";
    cin >> num;

    output = binarySearch(myarr,0,9,num);
    if(output == -1) {
        cout << "Match Not Found"<<endl;
    } else {
    cout << "Element "<<num<< " Founded At Position: "<< output + 1<< endl;
    }
    return 0;
}