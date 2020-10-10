#include "book_list.h"

#include <utility>

void BookList::push(Book book) {
	if (_size == _capacity) {
		reserve(_size + 1);
	}
	
	_array[_size] = std::move(book);
	_size++;
}

void BookList::reserve(size_t size) {	
	size_t newSize = 1;
	while (newSize < size) {
		newSize *= 2;
	}
	
	if (newSize <= _capacity) {
		return;
	}

	auto newArray = std::make_unique<Book[]>(newSize);

	for (size_t i = 0; i < _size; i++) {
		std::swap(newArray[i], _array[i]);
	}

	_array = std::move(newArray);
	_capacity = newSize;
}

std::optional<Book*> BookList::operator[](size_t i) const {
	if (i >= _size) {
		return {};
	}
	
	return &_array[i];
}
