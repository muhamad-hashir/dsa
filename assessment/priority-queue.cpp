#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 100 

struct Student {
    int studentID;
    string name;
    float cgpa;
};

class PriorityQueue {
private:
    Student arr[MAX_SIZE];
    int count; 

public:
    PriorityQueue() {
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int id, string n, float gpa) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add student." << endl;
            return;
        }

        Student newStudent;
        newStudent.studentID = id;
        newStudent.name = n;
        newStudent.cgpa = gpa;

        int i = count - 1;

        while (i >= 0) {
            // Condition 1: New student has HIGHER CGPA -> New student has higher priority
            // Condition 2: Equal CGPA, but new student has SMALLER ID -> New student has higher priority
            if (gpa > arr[i].cgpa || (gpa == arr[i].cgpa && id < arr[i].studentID)) {
                arr[i + 1] = arr[i]; // Shift right
                i--;
            } else {
                break;
            }
        }

        arr[i + 1] = newStudent;
        count++;
        cout << "Enqueued: " << n << " (CGPA: " << gpa << ", ID: " << id << ")" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! No students to serve." << endl;
            return;
        }

        cout << "Serving Student: " << arr[0].name 
             << " [ID: " << arr[0].studentID 
             << " | CGPA: " << arr[0].cgpa << "]" << endl;

        for (int i = 0; i < count - 1; i++) {
            arr[i] = arr[i + 1];
        }

        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        cout << "\nCurrent Advising Priority Queue:" << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". Name: " << arr[i].name 
                 << " | ID: " << arr[i].studentID 
                 << " | CGPA: " << arr[i].cgpa << endl;
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(105, "Ali", 3.2);
    pq.enqueue(102, "Sara", 3.8);
    pq.enqueue(101, "Usman", 3.8);
    pq.enqueue(108, "Zain", 2.9);

    pq.display();

    pq.dequeue();
    pq.dequeue();

    pq.display();

    return 0;
}