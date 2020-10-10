#include "book_list.h"

#include <utility>

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
	_size++;
	
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

	for (size_t i = 0; i < _size - index - 1; ++i) {
		std::swap(_array[i + index], _array[i + index + 1]);
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
