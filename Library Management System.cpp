#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string title;
    string author_name;
    bool isIssued;
    string issuedTo;
};

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is full, cannot add more books." << endl;
        return;
    }
    Book newBook;
    cout << endl << "Enter book ID: ";
    cin >> newBook.id;
    cin.ignore(); // to clear the buffer
    cout << "Enter book title: ";
    getline(cin, newBook.title);
    cout << "Enter book author name: ";
    getline(cin, newBook.author_name);
    newBook.isIssued = false;
    library[bookCount++] = newBook;
    cout << "Book added successfully." << endl;
}

void searchBook() {
    int choice;
    cout << endl << "Search by:" << endl << "1. ID" << endl << "2. Title " << endl << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        int id;
        cout <<  "Enter book ID: ";
        cin >> id;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].id == id) {
                cout << "Book found: " << library[i].title << " by " << library[i].author_name << (library[i].isIssued ? " [Issued]" : " [Available]") << endl;
                return;
            }
        }
    } else if (choice == 2) {
        string title;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        for (int i = 0; i < bookCount; i++) {
            if (library[i].title == title) {
                cout << "Book found: " << library[i].title << " by " << library[i].author_name << (library[i].isIssued ? " [Issued]" : " [Available]") << endl;
                return;
            }
        }
    } else {
        cout << endl << "Invalid choice." << endl;
        return;
    }
    cout << endl << "Book not found." << endl;
}

void issueBook() {
    int id;
    cout << endl << "Enter book ID to issue: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].isIssued) {
                cout << "Book is already issued to " << library[i].issuedTo << "." << endl;
                return;
            }
            cout << "Enter student name to issue the book to: ";
            cin.ignore();
            getline(cin, library[i].issuedTo);
            library[i].isIssued = true;
            cout << "Book issued successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void returnBook() {
    int id;
    cout << endl << "Enter book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (!library[i].isIssued) {
                cout << "Book is not issued." << endl;
                return;
            }
            library[i].isIssued = false;
            library[i].issuedTo = "";
            cout << "Book returned successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void listBooks() {
    if (bookCount == 0) {
        cout << endl << "No books in the library." << endl;
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << library[i].id << ", Title: " << library[i].title << ", Author Name: " << library[i].author_name << (library[i].isIssued ? " [Issued]" : " [Available]") << endl;
    }
}

void deleteBook() {
    int id;
    cout << endl << "Enter book ID to delete: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            cout << "Book deleted successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n***************Library Management System***************\n";
        cout << "1. Add New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Issue a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. List of All Books\n";
        cout << "6. Delete a Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: listBooks(); break;
            case 6: deleteBook(); break;
            case 7: exit(0); break;
            default: cout << "Invalid choice. Please enter a valid input." << endl;
        }
    }
    return 0;
}


/*
Code is written by Viki Kumar
Gmail : vikikumar0505@gmail.com
Github : https://github.com/vikikumar05
*/