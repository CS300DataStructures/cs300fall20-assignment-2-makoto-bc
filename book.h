#ifndef ASSIGNMENT_2__BOOK_H_
#define ASSIGNMENT_2__BOOK_H_

#include <string>
#include <tuple>
#include <ostream>

class Book {
public:
	std::string ISBN;
	std::string title;
	std::string authors;
	std::string publisher;
	
	void output(std::ostream& os) const;

	bool operator==(const Book& rhs) const {
		return std::tie(title, authors, publisher, ISBN)
			== std::tie(rhs.title, rhs.authors, rhs.publisher, rhs.ISBN);
	}

	bool operator!=(const Book& rhs) const {
		return !(rhs == *this);
	}
};

#endif //ASSIGNMENT_2__BOOK_H_
