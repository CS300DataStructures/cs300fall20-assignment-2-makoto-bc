#ifndef ASSIGNMENT_2__BOOK_LIST_H_
#define ASSIGNMENT_2__BOOK_LIST_H_

#include <memory>
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

	BookList(const BookList& list) : BookList() {
		reserve(list._size);
		for (size_t i = 0; i < list._size; ++i) {
			insert(list[i], i);
		}
	}

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
	 * Removes book at index and shifts down all books after index.
	 * @return The removed book
	 * @throw index is out of range
	 */
	Book remove(size_t index);

	/**
	 * @return Book at index
	 * @throw index is out of range
	 */
	Book& operator[](size_t index) const;

	bool operator==(const BookList& rhs) const;

	friend std::ostream& operator<<(std::ostream& os, const BookList& rhs);

	BookList& operator=(BookList&& rhs) noexcept;

private:
	std::unique_ptr<Book[]> _array;
	size_t _size;
	size_t _capacity;
};

#endif //ASSIGNMENT_2__BOOK_LIST_H_
