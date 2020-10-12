#include "book.h"

void Book::output(std::ostream& os) const {
	os << title << '\n' << authors << '\n' << isbn << '\n' << publisher;
}