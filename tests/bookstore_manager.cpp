#include <gtest/gtest.h>
#include "../bookstore_manager.h"

TEST(BookstoreManager, insert) {
	struct Test {
		std::initializer_list<Book> list;
		Book book;
		std::initializer_list<Book> expectedList;
	};
	
	std::vector<Test> tests {
		{
			{},
			Book(0),
			{Book(0)},
		},
		{
			{Book(0)},
			Book(1),
			{Book(0), Book(1)},
		},
		{
			{Book(1)},
			Book(0),
			{Book(0), Book(1)},
		},
		{
			{Book(0), Book(2)},
			Book(1),
			{Book(0), Book(1), Book(2)},
		},
		{
			{Book(0), Book(2)},
			Book(2),
			{Book(0), Book(2), Book(2)},
		},
		{
			{Book(1), Book(2)},
			Book(0),
			{Book(0), Book(1), Book(2)},
		},
	};
	
	for (size_t i = 0; i < tests.size(); ++i) {
		BookstoreManager result(tests[i].list);
		result.insert(tests[i].book);
		EXPECT_EQ(result, BookstoreManager(tests[i].expectedList)) << i;
	}
}

TEST(BookstoreManager, findISBN) {
	struct Test {
		std::initializer_list<Book> list;
		int isbn;
		size_t expected;
	};

	std::vector<Test> tests {
		{
			{},
			0,
			0,
		},
		{
			{Book(1)},
			0,
			0,
		},
		{
			{Book(1)},
			1,
			0,
		},
		{
			{Book(1)},
			2,
			1,
		},
		{
			{Book(0), Book(1)},
			0,
			0,
		},
		{
			{Book(0), Book(1)},
			1,
			1,
		},
		{
			{Book(0), Book(1)},
			2,
			2,
		},
		{
			{Book(0), Book(2)},
			1,
			1,
		},
		{
			{Book(1), Book(2)},
			0,
			0,
		},
		{
			{Book(0), Book(0), Book(1)},
			0,
			1,
		},
		{
			{Book(0), Book(1), Book(1)},
			1,
			1,
		},
		{
			{Book(0), Book(1), Book(2)},
			1,
			1,
		},
		{
			{Book(0), Book(2), Book(4)},
			1,
			1,
		},
		{
			{Book(0), Book(2), Book(4)},
			3,
			2,
		},
	};

	for (size_t i = 0; i < tests.size(); ++i) {
		BookstoreManager manager(tests[i].list);
		size_t result = manager.findISBN(tests[i].isbn);
		EXPECT_EQ(result, tests[i].expected) << i;
	}
}