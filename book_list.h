#ifndef ASSIGNMENT_2__BOOK_LIST_H_
#define ASSIGNMENT_2__BOOK_LIST_H_

#include <memory>
#include <optional>
#include "book.h"

/**
 * Stack-based container for books.
 */
class BookList {
public:
	/**
	 * Returns an empty BookList.
	 */
	BookList()
		: _array(std::make_unique<Book[]>(0))
		  , _size(0)
		  , _capacity(0) {}

	/**
	 * Copies all books from given list to initialize BookList.
	 */
	BookList(std::initializer_list<Book> list);

	size_t size() const {
		return _size;
	}

	/**
	 * @return Max size before reallocation.
	 */
	size_t capacity() const {
		return _capacity;
	}

	/**
	 * Inserts book to given index. All books at and after index are shifted up.
	 */
	void insert(Book book, size_t index);

	/**
	 * Allocates enough space to ensure that the size can grow up to given capacity without
	 * reallocation.
	 */
	void reserve(size_t capacity);

	/**
	 * Removes book at index and shifts down all books after index, if index is valid.
	 * @return The removed book if index was valid
	 */
	std::optional<Book> remove(size_t index);

	/**
	 * @return Book at index if it exists, or nothing if it does not exist
	 */
	std::optional<Book*> get(size_t index) const;

	bool operator==(const BookList& rhs) const;

private:
	std::unique_ptr<Book[]> _array;
	size_t _size;
	size_t _capacity;
};

#endif //ASSIGNMENT_2__BOOK_LIST_H_
