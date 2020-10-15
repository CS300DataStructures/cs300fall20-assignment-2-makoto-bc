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
	size_t index = findISBN(book.isbn);
	_list.insert(std::move(book), index);
}

void BookstoreManager::remove(Book book) { // NOLINT(performance-unnecessary-value-param)
	size_t index = findISBN(book.isbn);
	if (_list.get(index).value()->isbn == book.isbn) {
		_list.remove(index);
	} else {
		std::cout << "Not Found" << std::endl;
	}
}

void BookstoreManager::removePublisher(std::string publisher) { // NOLINT(performance-unnecessary-value-param)
	BookList newList;
	size_t newListIndex = 0;
	for (size_t i = 0; i < _list.size(); ++i) {
		if (_list.get(i).value()->publisher != publisher) {
			newList.insert(std::move(*_list.get(i).value()), newListIndex);
			++newListIndex;
		}
	}

	if (newList.size() == _list.size()) {
		std::cout << "Not Found" << std::endl;
	}

	_list = std::move(newList);
}

void BookstoreManager::search(Book book) const { // NOLINT(performance-unnecessary-value-param)
	size_t index = findISBN(book.isbn);
	if (_list.get(index).value()->isbn == book.isbn) {
		_list.get(index).value()->output(std::cout);
		std::cout << "\n\n" << std::flush;
	} else {
		std::cout << "Not Found" << std::endl;
	}
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
		if (_list.get(middle).value()->isbn < isbn) {
			left = middle + 1;
		} else if (_list.get(middle).value()->isbn > isbn) {
			if (middle == 0) {
				return 0;
			}
			right = middle - 1;
		} else {
			return middle;
		}
	}

	if (_list.get(middle).value()->isbn < isbn) {
		return middle + 1;
	}

	return middle;
}
