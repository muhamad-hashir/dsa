/*  Task 2
    This is a simple C++ program to demonstrate inheritance in object-oriented programming.
    It creates a base class 'Employee' and two derived classes 'Salaried_Emp' and 'Hourly_Emp'.
*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected: 

    string Name;
    string Address;

public:
    Employee(string name, string address) {
        Name = name;
        Address = address;
    }

    void display() {
        cout << "Name: " << Name << " | Address: " << Address << endl;
    }
};

class Salaried_Emp : public Employee {
private:
    double monthly_salary; 

public:
    Salaried_Emp(string name, string address, double salary) 
        : Employee(name, address) { 
        monthly_salary = salary;
    }

    double Calculate_salary() {
        return monthly_salary; 
    }
};

class Hourly_Emp : public Employee {
private:
    double hourly_rate;
    int hours_worked;

public:
    Hourly_Emp(string name, string address, double rate, int hours) 
        : Employee(name, address) { 
        hourly_rate = rate;
        hours_worked = hours;
    }

    double Calculate_salary() {
        return hourly_rate * hours_worked;
    }
};

int main() {

    cout << "--- Base Employees ---" << endl;
    Employee emp1("Ali", "House 1, Street 2, Lahore");
    Employee emp2("Sara", "Apartment 5, Karachi");
    Employee emp3("Usman", "Sector F, Islamabad");

    emp1.display();
    emp2.display();
    emp3.display();
    
    cout << endl;

    cout << "--- Derived Employees ---" << endl;
    Salaried_Emp manager("Ayesha", "DHA, Lahore", 150000);
    Hourly_Emp worker("Bilal", "Clifton, Karachi", 500, 40);

    manager.display();
    cout << "Salary: Rs. " << manager.Calculate_salary() << "\n\n";

    worker.display();
    cout << "Salary: Rs. " << worker.Calculate_salary() << endl;

    return 0;
}