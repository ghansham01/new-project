#include <iostream>
#include <vector>
#include <string>
using namespace std;

// A Library class that manages a collection of books.
class Library {
public:
    Library(vector<string> bookList) : books(bookList) {}
// Displays the list of available books in the library.
    void displayAvailableBooks() {
        cout<< "Books present in this library: " << endl;
        // for each loop
        for (const auto& book : books) {
            cout<< "* " << book << endl;
        }
    }
// Borrows a book from the library 
    bool borrowBook(const string& bookName) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (*it == bookName) {
                cout<< "You have been issued " << bookName << ". Please keep it safe and return it within 30 days" << endl;
                books.erase(it);
                return true;
            }
        }
        cout<< "Sorry, This book is either not available or has already been issued to someone else. Please wait until the book is available" <<endl;
        return false;
    }
// The name of the book to return.
    void returnBook(const std::string& bookName) {
        books.push_back(bookName);
        cout<< "Thanks for returning this book! Hope you enjoyed reading it. Have a great day ahead!" << endl;
    }

private:
    vector<std::string> books;
};
// A Student class that interacts with the Library.
class Student {
public:
    string requestBook() {
        string bookName;
        cout << "Enter the name of the book you want to borrow: ";
        cin >> bookName;
        return bookName;
    }

    string returnBook() {
        string bookName;
        cout << "Enter the name of the book you want to return: ";
        cin >> bookName;
        return bookName;
    }
};

int main() {
    Library centralLibrary({"Python Programming", "Data Science", "Machine Learning", "DSA", "Python Notes"});
    Student student;

    while (true) {
        cout<< "\n ====== Welcome to Central Library ======" << endl;
        cout<< "Please choose an option:" << endl;
        cout<< "1. List all the books" << endl;
        cout<< "2. Request a book" << endl;
        cout<< "3. Return a book" << endl;
        cout<< "4. Exit the Library" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                centralLibrary.displayAvailableBooks();
                break;
            case 2:
                centralLibrary.borrowBook(student.requestBook());
                break;
            case 3:
                centralLibrary.returnBook(student.returnBook());
                break;
            case 4:
                cout << "Thanks for using Central Library. Have a great day ahead!" <<endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose a valid option" << endl;
        }
    }

    return 0;
}