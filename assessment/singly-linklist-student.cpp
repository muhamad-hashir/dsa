#include<iostream>
#include<string>
using namespace std;

class Student {
    public:
        string name;
        string regNo;
        float gpa;
        Student* next;
        Student(string n, string r, float g) {
            name = n;
            regNo = r;
            gpa = g;
            next = NULL;
        }
};

class LinkedList {
    private:
        Student* head;
    public:
    LinkedList() {
        head = NULL;
    }

    // ---------- INSERTION ----------

    void insertAtFront(string name, string regNo, float gpa) {
        Student* newStudent = new Student(name, regNo, gpa);
        newStudent->next = head;
        head = newStudent;
    }

    void insertAtEnd(string name, string regNo, float gpa) {
        Student* newStudent = new Student(name, regNo, gpa);
        if(head == NULL) {
            head = newStudent;
            return;
        }
        Student* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }

    void insertAtPosition(string name, string regNo, float gpa, int pos) {
        if(pos == 0) {
            insertAtFront(name, regNo, gpa);
            return;
        }
        Student* temp = head;
        for(int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if(temp == NULL) {
            cout << "Out of bounds" << endl;
            return;
        }
        Student* newStudent = new Student(name, regNo, gpa);
        newStudent->next = temp->next;
        temp->next = newStudent;
    }

    // ---------- DELETION ----------

    void deleteAtHead() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Student* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Student* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteAtPosition(int pos) {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        if(pos == 0) {
            deleteAtHead();
            return;
        }
        Student* temp = head;
        for(int i = 0; temp->next != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if(temp->next == NULL) {
            cout << "Out of bounds" << endl;
            return;
        }
        Student* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void deleteByRegNo(string regNo) {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        if(head->regNo == regNo) {
            deleteAtHead();
            return;
        }
        Student* temp = head;
        while(temp->next != NULL && temp->next->regNo != regNo) {
            temp = temp->next;
        }
        if(temp->next == NULL) {
            cout << "Student not found" << endl;
            return;
        }
        Student* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // ---------- SEARCHING ----------

    void searchByRegNo(string regNo) {
        Student* temp = head;
        while(temp != NULL) {
            if(temp->regNo == regNo) {
                cout << "Name: " << temp->name << endl;
                cout << "Registration No: " << temp->regNo << endl;
                cout << "GPA: " << temp->gpa << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found" << endl;
    }

    void searchByName(string name) {
        Student* temp = head;
        bool found = false;
        while(temp != NULL) {
            if(temp->name == name) {
                cout << temp->name << " | " << temp->regNo << " | " << temp->gpa << endl;
                found = true;
            }
            temp = temp->next;
        }
        if(!found) {
            cout << "Student not found" << endl;
        }
    }

    // ---------- UPDATE ----------

    void updateGPA(string regNo, float newGpa) {
        Student* temp = head;
        while(temp != NULL) {
            if(temp->regNo == regNo) {
                temp->gpa = newGpa;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found" << endl;
    }

    // ---------- STATISTICS ----------

    void findHighestGPA() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Student* temp = head;
        Student* best = head;
        while(temp != NULL) {
            if(temp->gpa > best->gpa) {
                best = temp;
            }
            temp = temp->next;
        }
        cout << "Highest GPA Student: " << best->name << " | " << best->regNo << " | " << best->gpa << endl;
    }

    void findLowestGPA() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Student* temp = head;
        Student* worst = head;
        while(temp != NULL) {
            if(temp->gpa < worst->gpa) {
                worst = temp;
            }
            temp = temp->next;
        }
        cout << "Lowest GPA Student: " << worst->name << " | " << worst->regNo << " | " << worst->gpa << endl;
    }

    int countStudents() {
        int count = 0;
        Student* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    float averageGPA() {
        if(head == NULL) {
            return 0;
        }
        float sum = 0;
        int count = 0;
        Student* temp = head;
        while(temp != NULL) {
            sum += temp->gpa;
            count++;
            temp = temp->next;
        }
        return sum / count;
    }

    // ---------- OTHER OPERATIONS ----------

    bool isEmpty() {
        return head == NULL;
    }

    void reverse() {
        Student* prev = NULL;
        Student* curr = head;
        Student* nextStudent = NULL;
        while(curr != NULL) {
            nextStudent = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextStudent;
        }
        head = prev;
    }

    void display() {
        if(head == NULL) {
            cout << "NULL" << endl;
            return;
        }
        Student* temp = head;
        while(temp != NULL) {
            cout << temp->name << " (" << temp->regNo << ", " << temp->gpa << ") --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LinkedList() {
        while(head != NULL) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }
};