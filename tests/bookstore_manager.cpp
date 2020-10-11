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
			{"a"},
			{{"a"}},
		},
		{
			{{"a"}},
			{"b"},
			{{"a"}, {"b"}},
		},
		{
			{{"b"}},
			{"a"},
			{{"a"}, {"b"}},
		},
		{
			{{"a"}, {"c"}},
			{"b"},
			{{"a"}, {"b"}, {"c"}},
		},
		{
			{{"a"}, {"c"}},
			{"c"},
			{{"a"}, {"c"}, {"c"}},
		},
		{
			{{"b"}, {"c"}},
			{"a"},
			{{"a"}, {"b"}, {"c"}},
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
		std::string isbn;
		size_t expected;
	};

	std::vector<Test> tests {
		{
			{},
			"",
			0,
		},
		{
			{{"b"}},
			"a",
			0,
		},
		{
			{{"b"}},
			"b",
			0,
		},
		{
			{{"b"}},
			"c",
			1,
		},
		{
			{{"a"}, {"b"}},
			"a",
			0,
		},
		{
			{{"a"}, {"b"}},
			"b",
			1,
		},
		{
			{{"a"}, {"b"}},
			"c",
			2,
		},
		{
			{{"a"}, {"c"}},
			"b",
			1,
		},
		{
			{{"b"}, {"c"}},
			"a",
			0,
		},
		{
			{{"a"}, {"a"},{"b"}},
			"a",
			1,
		},
		{
			{{"a"}, {"b"},{"b"}},
			"b",
			1,
		},
		{
			{{"a"}, {"b"},{"c"}},
			"b",
			1,
		},
		{
			{{"a"}, {"c"},{"e"}},
			"b",
			1,
		},
		{
			{{"a"}, {"c"},{"e"}},
			"d",
			2,
		},
	};

	for (size_t i = 0; i < tests.size(); ++i) {
		BookstoreManager manager(tests[i].list);
		size_t result = manager.findISBN(tests[i].isbn);
		EXPECT_EQ(result, tests[i].expected) << i;
	}
}