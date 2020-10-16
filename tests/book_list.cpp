#include <gtest/gtest.h>
#include "../book_list.h"

TEST(BookList, listConstructor) {
	{
		BookList list({});
		EXPECT_EQ(list.size(), 0);
	}
	{
		BookList list({Book()});
		EXPECT_EQ(list.size(), 1);
	}
}

TEST(BookList, insert) {
	BookList list;
	list.insert(Book(), 1);
	list.insert(Book(), 2);
	EXPECT_EQ(list.size(), 0);

	list.insert(Book(0), 0);
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list[0], Book(0));

	list.insert(Book(1), 0);
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list[0], Book(1));
	EXPECT_EQ(list[1], Book(0));

	list.insert(Book(2), 2);
	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(list[0], Book(1));
	EXPECT_EQ(list[1], Book(0));
	EXPECT_EQ(list[2], Book(2));

	list.insert(Book(3), 1);
	EXPECT_EQ(list[0], Book(1));
	EXPECT_EQ(list[1], Book(3));
	EXPECT_EQ(list[2], Book(0));
	EXPECT_EQ(list[3], Book(2));
}

TEST(BookList, reserve) {
	{
		BookList list;
		list.reserve(0);
		EXPECT_EQ(list.capacity(), 0);

		list.reserve(1);
		EXPECT_EQ(list.capacity(), 2);
		EXPECT_EQ(list.size(), 0);

		list.reserve(3);
		EXPECT_EQ(list.capacity(), 4);

		list.reserve(0);
		EXPECT_EQ(list.capacity(), 4);

		EXPECT_EQ(list.size(), 0);
	}
	{
		BookList list;
		list.insert(Book(0), 0);
		list.reserve(4);
		EXPECT_EQ(list[0], Book(0));
	}
}

TEST(BookList, remove) {
	BookList list;
	EXPECT_THROW(list.remove(0), std::out_of_range);

	list.insert(Book(0), 0);
	EXPECT_EQ(list.remove(0), Book(0));
	EXPECT_EQ(list.size(), 0);

	// Removing first item
	list.insert(Book(0), 0);
	list.insert(Book(1), 1);
	EXPECT_EQ(list.remove(0), Book(0));
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list[0], Book(1));

	EXPECT_EQ(list.remove(0), Book(1));
	EXPECT_EQ(list.size(), 0);

	// Removing last item
	list.insert(Book(0), 0);
	list.insert(Book(1), 1);
	EXPECT_EQ(list.remove(1), Book(1));
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.capacity(), 2);
	EXPECT_EQ(list[0], Book(0));
}

TEST(BookList, get) {
	BookList list;
	EXPECT_THROW(list[0], std::out_of_range);

	list.insert(Book(0), 0);
	EXPECT_EQ(list[0], Book(0));
}

TEST(BookList, unequal) {
	EXPECT_EQ(BookList(), BookList());
	EXPECT_FALSE(BookList({Book(0)}) == BookList({}));
	EXPECT_EQ(BookList({Book(0)}), BookList({Book(0)}));
	EXPECT_FALSE(BookList({Book(0)}) == BookList({Book(1)}));
}