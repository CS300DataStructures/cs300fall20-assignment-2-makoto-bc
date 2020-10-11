#include <cmath>
#include "bookstore_manager.h"

void BookstoreManager::print() const {
	for (size_t i = 0; i < _list.size(); ++i) {
		_list[i].value()->output(std::cout);
		std::cout << "\n\n";
	}
}

void BookstoreManager::insert(Book book) {
	size_t index = findISBN(book.ISBN);
	_list.insert(std::move(book), index);
}

size_t BookstoreManager::findISBN(const std::string& isbn) const {
	if (_list.size() == 0) {
		return 0;
	}

	size_t left = 0;
	size_t right = _list.size() - 1;
	size_t middle = 0;
	
	while (left <= right) {
		middle = (left + right) / 2;
		if (_list[middle].value()->ISBN < isbn) {
			left = middle + 1;
		} else if (_list[middle].value()->ISBN > isbn) {
			if (middle == 0) {
				return 0;
			}
			right = middle - 1;
		} else {
			return middle;
		}
	}
	
	if (_list[middle].value()->ISBN < isbn) {
		return middle + 1;
	}

	return middle;
}
