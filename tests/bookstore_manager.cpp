#include <gtest/gtest.h>
#include "../bookstore_manager.h"

TEST(BookstoreManager, insert) {
	struct Test {
		BookstoreManager manager;
		Book book;
		BookstoreManager expected;
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
		tests[i].manager.insert(tests[i].book);
		EXPECT_EQ(tests[i].manager, tests[i].expected) << i;
	}
}

TEST(BookstoreManager, removePublisher) {
	struct Test {
		BookstoreManager manager;
		std::string publisher;
		BookstoreManager expected;
	};

	std::vector<Test> tests {
		{
			{},
			"",
			{},
		},
		{
			{Book("", 0, "", "a")},
			{""},
			{Book("", 0, "", "a")},
		},
		{
			{
				Book("", 0, "", "a"),
				Book("", 0, "", "b"),
			},
			{""},
			{
				Book("", 0, "", "a"),
				Book("", 0, "", "b"),
			},
		},
		{
			{Book("", 0, "", "a")},
			{"a"},
			{},
		},
		{
			{
				Book("", 0, "", "a"),
				Book("", 0, "", "a"),
			},
			{"a"},
			{},
		},
	};

	for (size_t i = 0; i < tests.size(); ++i) {
		tests[i].manager.removePublisher(tests[i].publisher);
		EXPECT_EQ(tests[i].manager, tests[i].expected) << i;
	}
}

TEST(BookstoreManager, findISBN) {
	struct Test {
		BookstoreManager manager;
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
		size_t result = tests[i].manager.findISBN(tests[i].isbn);
		EXPECT_EQ(result, tests[i].expected) << i;
	}
}