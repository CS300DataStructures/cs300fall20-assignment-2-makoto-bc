#include "book_list.h"

BookList::BookList(std::initializer_list<Book> list)
	: BookList() {
	size_t i = 0;
	for (const Book& book : list) {
		insert(book, i);
		++i;
	}
}

void BookList::insert(Book book, size_t index) {
	if (index >= _size + 1) {
		return;
	}

	if (_size == _capacity) {
		reserve(_size + 1);
	}

	// Move back of list up 1 starting with the last item to the new spot
	for (size_t i = 0; i < _size - index; ++i) {
		std::swap(_array[_size - i - 1], _array[_size - i]);
	}
	++_size;

	_array[index] = std::move(book);
}

void BookList::reserve(size_t capacity) {
	if (capacity <= _capacity) {
		return;
	}

	size_t newCapacity = _capacity * 2;
	if (newCapacity == 0) {
		newCapacity = 2;
	}

	while (newCapacity < capacity) {
		newCapacity *= 2;
	}

	auto newArray = std::make_unique<Book[]>(newCapacity);

	for (size_t i = 0; i < _size; ++i) {
		std::swap(newArray[i], _array[i]);
	}

	_array = std::move(newArray);
	_capacity = newCapacity;
}

Book BookList::remove(size_t index) {
	if (index >= _size) {
		throw std::out_of_range("index is out of range");
	}

	Book tmp = std::move(_array[index]);

	for (size_t i = 0; i < _size - index - 1; ++i) {
		std::swap(_array[i + index], _array[i + index + 1]);
	}

	--_size;
	return tmp;
}

Book& BookList::operator[](size_t index) const {
	if (index >= _size) {
		throw std::out_of_range("index is out of range");
	}

	return _array[index];
}

bool BookList::operator==(const BookList& rhs) const {
	if (_size != rhs._size) {
		return false;
	}

	for (size_t i = 0; i < _size; ++i) {
		if (_array[i] != rhs._array[i]) {
			return false;
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const BookList& rhs) {
	os << '{';
	for (size_t i = 0; i < rhs.size(); ++i) {
		os << rhs[i].isbn;
		if (i < rhs.size() - 1) {
			os << ',';
		}
	}
	return os << '}';
}

BookList& BookList::operator=(BookList&& rhs) noexcept {
	_array = std::move(rhs._array);
	_size = rhs._size;
	_capacity = rhs._capacity;
	return *this;
}
