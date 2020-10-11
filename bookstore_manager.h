#ifndef ASSIGNMENT_2__BOOKSTORE_MANAGER_H_
#define ASSIGNMENT_2__BOOKSTORE_MANAGER_H_

#include <iostream>
#include "book.h"
#include "book_list.h"

class BookstoreManager {
public:
	BookstoreManager() = default;
	
	explicit BookstoreManager(std::initializer_list<Book> list)
		: _list(list)
	{}
	
	/**
	 * @return true if the list is empty
	 */
	bool isEmpty() const {
		return _list.size() == 0;
	}
	
	/**
	 * @return true if the size equals the capacity of the underlying array
	 */
	bool isFull() const {
		return _list.size() == _list.capacity();
	}
	
	/**
	 * Prints the number of books in this list.
	 */
	void listSize() const {
		std::cout << _list.size();
	}
	
	/**
	 * Prints list.
	 */
	void print() const;
	
	/**
	 * Adds book to this list.
	 * @param book 
	 */
	void insert(Book book);
	
	/**
	 * Removes a book with the same ISBN as given book if it exists.
	 * @param book 
	 */
	void remove(Book book);
	
	/**
	 * Removes all books with the given publisher.
	 * @param publisher 
	 */
	void removePublisher(std::string publisher);
	
	/**
	 * Prints the contents of book that matches the given book's ISBN.
	 * @param book 
	 */
	void search(Book book) const;

	size_t findISBN(const std::string& isbn) const;

	bool operator==(const BookstoreManager& rhs) const {
		return _list == rhs._list;
	}

private:
	BookList _list;
};

#endif //ASSIGNMENT_2__BOOKSTORE_MANAGER_H_
