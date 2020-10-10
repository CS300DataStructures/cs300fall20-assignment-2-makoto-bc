#ifndef ASSIGNMENT_2__BOOK_H_
#define ASSIGNMENT_2__BOOK_H_

#include <string>
#include <tuple>

class Book {
public:
	std::string title;
	std::string authors;
	std::string publisher;
	std::string ISBN;
	
	bool operator==(const Book& rhs) const {
		return std::tie(title, authors, publisher, ISBN)
			== std::tie(rhs.title, rhs.authors, rhs.publisher, rhs.ISBN);
	}
};

#endif //ASSIGNMENT_2__BOOK_H_
