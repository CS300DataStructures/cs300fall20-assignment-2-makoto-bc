#include "book_list.h"

#include <utility>

void BookList::push(Book book) {
	if (_size == _capacity) {
		reserve(_size + 1);
	}
	
	_array[_size] = std::move(book);
	_size++;
}

void BookList::reserve(size_t capacity) {	
	size_t newCapacity = 1;
	while (newCapacity < capacity) {
		newCapacity *= 2;
	}
	
	if (newCapacity <= _capacity) {
		return;
	}

	auto newArray = std::make_unique<Book[]>(newCapacity);

	for (size_t i = 0; i < _size; i++) {
		std::swap(newArray[i], _array[i]);
	}

	_array = std::move(newArray);
	_capacity = newCapacity;
}

std::optional<Book> BookList::remove(size_t index) {
	if (index >= _size) {
		return {};
	}

	Book tmp = std::move(_array[index]);

	for (size_t i = index; i < _size - 1; ++i) {
		std::swap(_array[i], _array[i + 1]);
	}

	_size--;
	return {tmp};
}

std::optional<Book*> BookList::operator[](size_t index) const {
	if (index >= _size) {
		return {};
	}
	
	return &_array[index];
}
