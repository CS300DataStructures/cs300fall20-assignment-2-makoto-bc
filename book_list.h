#ifndef ASSIGNMENT_2__BOOK_LIST_H_
#define ASSIGNMENT_2__BOOK_LIST_H_

#include <memory>
#include <optional>
#include "book.h"

class BookList {
public:
	BookList()
		: _array(std::make_unique<Book[]>(0))
		  , _size(0)
		  , _capacity(0) {}

	BookList(std::initializer_list<Book> list);

	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _capacity;
	}

	void insert(Book book, size_t index);

	void reserve(size_t capacity);

	std::optional<Book> remove(size_t index);

	std::optional<Book*> get(size_t index) const;

	bool operator==(const BookList& rhs) const;

private:
	std::unique_ptr<Book[]> _array;
	size_t _size;
	size_t _capacity;
};

#endif //ASSIGNMENT_2__BOOK_LIST_H_
