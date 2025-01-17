// assignment-2
// Makoto Emura
// 10/12/2020
// Container for books with functionality for insertion, removal, binary search and text output.

#include <iostream>
#include "book.h"
#include "bookstore_manager.h"

using namespace std;

// Inputs valid ISBN.
int inputISBN() {
	std::string s;
	while (true) {
		std::cout << "Enter isbn:";
		std::getline(std::cin, s);
		try {
			return std::stoi(s);
		} catch (...) {
			continue;
		}
	}
}

int main() { 
    BookstoreManager bookstoreManager;

    //prints true if the bookstore is empty
    bookstoreManager.isEmpty();

    //insert 4 books
    string title, authors, publisher;
    int isbn;
    for(int i=0;i<4;i++){
        cout<<"Enter book title:";
        getline(std::cin, title);
        cout<<"Enter authors:";
		getline(std::cin, authors);
        isbn = inputISBN();
        cout<<"Enter publisher";
		getline(std::cin, publisher);
        Book aBook(title, isbn, authors, publisher);
        bookstoreManager.insert(aBook); 
        cout<<endl;
    }

    //print bookstore
    bookstoreManager.print();

    //search for books
    cout<<"Searching…"<<endl;
	isbn = inputISBN();
    Book b2(isbn);
    bookstoreManager.search(b2);

    //remove a book
    cout<<"Removing…"<<endl;
	isbn = inputISBN();
    Book b1(isbn);
    bookstoreManager.remove(b1);

    //print bookstore
    bookstoreManager.print();

    //remove books from a particular publisher
    cout<<"Removing publisher"<<endl;
    cout<<"Publisher:";
	getline(std::cin, publisher);
    bookstoreManager.removePublisher(publisher);

    //print bookstore
    bookstoreManager.print();


    //prints the number of books 
    bookstoreManager.listSize();

}
