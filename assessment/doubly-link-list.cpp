#include<iostream>
using namespace std;

class Student{
    public:
        string name;
        string regNo;
        float gpa;
        Student* next;
        Student* prev;

        Student(string n, string r, float g) {
            name =  n;
            regNo = r;
            gpa = g;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkList{
    private:
        Student* head;
        Student* tail;
    public:
        DoublyLinkList() {
            head = NULL;
            tail = NULL;
        }

        void insertAtFront(string name, string regNo, float gpa) {
            Student* newStudent = new Student(name, regNo, gpa);
            newStudent->next =  head;
            if(head != NULL) {
                head -> prev = newStudent;
            }
            head = newStudent;
        }

        void searchByRegNo(string regNo) {
            Student* temp = head;
            while(temp != NULL) {
            if(temp->regNo == regNo) {
                cout << "Registration Number: "<< temp->regNo << endl;
                cout << "Name of Student: "<< temp->name << endl;
                cout << "GPA of Student: "<< temp->gpa << endl;
            }
            temp =  temp->next;
        }
        cout << "Not Found... No such Student by this Reg No..."<<endl;
    }
};

int main() {
    DoublyLinkList list;
    list.insertAtFront("M Hashir", "12345", 3.5);
    list.insertAtFront("Hassan", "67890", 3.8);
    list.insertAtFront("Zarak", "54321", 3.9);

    cout << "Searching for student with Reg No: 67890" << endl;
    list.searchByRegNo("67890");

    cout << "\nSearching for student with Reg No: 11111" << endl;
    list.searchByRegNo("11111");

    return 0;
}