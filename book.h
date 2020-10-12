#ifndef ASSIGNMENT_2__BOOK_H_
#define ASSIGNMENT_2__BOOK_H_

#include <string>
#include <tuple>
#include <ostream>

class Book {
public:
	int ISBN;
	std::string title;
	std::string authors;
	std::string publisher;

	Book() = default;

	explicit Book(int isbn)
		: ISBN(isbn) {}

	explicit Book(std::string title, int isbn, std::string authors, std::string publisher)
		: title(std::move(title))
		  , ISBN(isbn)
		  , authors(std::move(authors))
		  , publisher(std::move(publisher)) {}

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
