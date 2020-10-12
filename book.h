#ifndef ASSIGNMENT_2__BOOK_H_
#define ASSIGNMENT_2__BOOK_H_

#include <string>
#include <tuple>
#include <ostream>

class Book {
public:
	int isbn;
	std::string title;
	std::string authors;
	std::string publisher;

	Book()
		: isbn(0) {}

	explicit Book(int isbn)
		: isbn(isbn) {}

	explicit Book(std::string title, int isbn, std::string authors, std::string publisher)
		: title(std::move(title))
		  , isbn(isbn)
		  , authors(std::move(authors))
		  , publisher(std::move(publisher)) {}

	void output(std::ostream& os) const;

	bool operator==(const Book& rhs) const {
		return std::tie(title, authors, publisher, isbn)
			== std::tie(rhs.title, rhs.authors, rhs.publisher, rhs.isbn);
	}

	bool operator!=(const Book& rhs) const {
		return !(rhs == *this);
	}
};

#endif //ASSIGNMENT_2__BOOK_H_
