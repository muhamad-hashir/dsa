// Task 2 - singlylist class with a private head initialized to NULL.
#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = NULL;
        }
};

class singlylist{
    private:
        Node* head;
    public:
        singlylist() {
            head = NULL;
        }
};

int main() {
    singlylist list;
    cout << "Empty list created, head = NULL" << endl;
    return 0;
}