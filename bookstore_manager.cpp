#include <cmath>
#include "bookstore_manager.h"

void BookstoreManager::print() const {
	for (size_t i = 0; i < _list.size(); ++i) {
		_list.get(i).value()->output(std::cout);
		std::cout << "\n\n";
	}
	std::cout << std::flush;
}

void BookstoreManager::insert(Book book) {
	size_t index = findISBN(book.ISBN);
	_list.insert(std::move(book), index);
}

void BookstoreManager::remove(Book book) { // NOLINT(performance-unnecessary-value-param)
	size_t index = findISBN(book.ISBN);
	if (_list.get(index).value()->ISBN == book.ISBN) {
		_list.remove(index);
	}
}

void BookstoreManager::removePublisher(std::string publisher) { // NOLINT(performance-unnecessary-value-param)
	size_t initialSize = _list.size();
	for (size_t i = 0; i < initialSize; ++i) {
		if (_list.get(initialSize - 1 - i).value()->publisher == publisher) {
			_list.remove(initialSize - 1 - i);
		}
	}
}

void BookstoreManager::search(Book book) const { // NOLINT(performance-unnecessary-value-param)
	size_t index = findISBN(book.ISBN);
	if (_list.get(index).value()->ISBN == book.ISBN) {
		_list.get(index).value()->output(std::cout);
		std::cout << "\n\n";
	}
	std::cout << std::flush;
}

size_t BookstoreManager::findISBN(int isbn) const {
	if (_list.size() == 0) {
		return 0;
	}

	size_t left = 0;
	size_t right = _list.size() - 1;
	size_t middle = 0;
	
	while (left <= right) {
		middle = (left + right) / 2;
		if (_list.get(middle).value()->ISBN < isbn) {
			left = middle + 1;
		} else if (_list.get(middle).value()->ISBN > isbn) {
			if (middle == 0) {
				return 0;
			}
			right = middle - 1;
		} else {
			return middle;
		}
	}
	
	if (_list.get(middle).value()->ISBN < isbn) {
		return middle + 1;
	}

	return middle;
}
