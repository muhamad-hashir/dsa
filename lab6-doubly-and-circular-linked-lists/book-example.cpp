#include<iostream>
#include<string>
using namespace std;

class Book {
    public:
        string title;
        string isbn;
        float price;
        Book* next;
        Book* prev;
        Book(string t, string i, float p) {
            title = t;
            isbn = i;
            price = p;
            next = NULL;
            prev = NULL;
        }
};

class BookList {
    private:
        Book* head;
        Book* tail;
    public:
    BookList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtFront(string title, string isbn, float price) {
        Book* newBook = new Book(title, isbn, price);
        if(head == NULL) {
            head = tail = newBook;
            return;
        }
        newBook->next = head;
        head->prev = newBook;
        head = newBook;
    }

    void insertAtEnd(string title, string isbn, float price) {
        Book* newBook = new Book(title, isbn, price);
        if(tail == NULL) {
            head = tail = newBook;
            return;
        }
        tail->next = newBook;
        newBook->prev = tail;
        tail = newBook;
    }

    void deleteAtHead() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Book* temp = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
        } else {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtTail() {
        if(tail == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Book* temp = tail;
        tail = tail->prev;
        if(tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete temp;
    }

    void displayForward() {
        Book* temp = head;
        while(temp != NULL) {
            cout << temp->title << " (" << temp->isbn << ", " << temp->price << ") <--> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        Book* temp = tail;
        while(temp != NULL) {
            cout << temp->title << " (" << temp->isbn << ", " << temp->price << ") <--> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    void searchByIsbn(string isbn) {
        Book* temp = head;
        while(temp != NULL) {
            if(temp->isbn == isbn) {
                cout << "Title: " << temp->title << endl;
                cout << "ISBN: " << temp->isbn << endl;
                cout << "Price: " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found" << endl;
    }

    void findMostExpensive() {
        if(head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Book* temp = head;
        Book* best = head;
        while(temp != NULL) {
            if(temp->price > best->price) {
                best = temp;
            }
            temp = temp->next;
        }
        cout << "Most expensive: " << best->title << " | " << best->isbn << " | " << best->price << endl;
    }

    void deleteByIsbn(string isbn) {
        Book* temp = head;
        while(temp != NULL && temp->isbn != isbn) {
            temp = temp->next;
        }
        if(temp == NULL) {
            cout << "Book not found" << endl;
            return;
        }
        if(temp == head) {               // case 1: first book
            deleteAtHead();
            return;
        }
        if(temp == tail) {               // case 2: last book
            deleteAtTail();
            return;
        }
        temp->prev->next = temp->next;   // case 3: middle book
        temp->next->prev = temp->prev;
        delete temp;
    }
};

int main() {
    BookList list;
    list.insertAtFront("Book A", "12345", 10.5);
    list.insertAtFront("Book B", "67890", 15.0);
    list.insertAtEnd("Book C", "54321", 20.0);

    cout << "Books in forward order:" << endl;
    list.displayForward();

    cout << "Books in backward order:" << endl;
    list.displayBackward();

    cout << "Searching for book with ISBN: 67890" << endl;
    list.searchByIsbn("67890");

    cout << "Finding the most expensive book:" << endl;
    list.findMostExpensive();

    cout << "Deleting book with ISBN: 67890" << endl;
    list.deleteByIsbn("67890");
    
    cout << "Books in forward order after deletion:" << endl;
    list.displayForward();

    return 0;
}