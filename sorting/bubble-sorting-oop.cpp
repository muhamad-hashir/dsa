#include<iostream>
using namespace std;

class BubbleSort{
    private:
        int *arr;
        int size;
    public:
        BubbleSort(int n) {
            size = n;
            arr = new int[size];
        }

        ~BubbleSort() {
            delete[] arr;
        }

        void input() {
            cout << "Enter Size " << size << endl;
            for(int i = 0; i < size; i++) {
                cin >> arr[i];
            }
        }

        void sort() {
            for(int i = 0; i < 5; i++) {

            for(int j=0; j < (5 - i - 1);j++) {

                if(arr[j] > arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp; 
                }
            }
        }
    }
        void display() {
        cout << "Sorted Array: ";
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
         cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    BubbleSort bs(n);
    bs.input();
    bs.sort();
    bs.display();

    return 0;
}