#include <gtest/gtest.h>
#include "../book_list.h"

TEST(BookList, listConstructor) {
	{
		BookList list({});
		EXPECT_EQ(list.size(), 0);
	}
	{
		BookList list({Book{}});
		EXPECT_EQ(list.size(), 1);
	}
}

TEST(BookList, insert) {
	BookList list;
	list.insert(Book{}, 1);
	list.insert(Book{}, 2);
	EXPECT_EQ(list.size(), 0);

	list.insert(Book{"a"}, 0);
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(*list[0].value(), Book{"a"});

	list.insert(Book{"b"}, 0);
	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(*list[0].value(), Book{"b"});
	EXPECT_EQ(*list[1].value(), Book{"a"});

	list.insert(Book{"c"}, 2);
	EXPECT_EQ(list.size(), 3);
	EXPECT_EQ(*list[0].value(), Book{"b"});
	EXPECT_EQ(*list[1].value(), Book{"a"});
	EXPECT_EQ(*list[2].value(), Book{"c"});

	list.insert(Book{"d"}, 1);
	EXPECT_EQ(*list[0].value(), Book{"b"});
	EXPECT_EQ(*list[1].value(), Book{"d"});
	EXPECT_EQ(*list[2].value(), Book{"a"});
	EXPECT_EQ(*list[3].value(), Book{"c"});
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

		EXPECT_FALSE(list[0].has_value());
	}
	{
		BookList list;
		list.insert(Book{"a"}, 0);
		list.reserve(4);
		EXPECT_EQ(*list[0].value(), Book{"a"});
	}
}

TEST(BookList, remove) {
	BookList list;
	EXPECT_FALSE(list.remove(0).has_value());
	
	list.insert(Book{"a"}, 0);
	EXPECT_EQ(list.remove(0).value(), Book{"a"});
	EXPECT_EQ(list.size(), 0);
	
	// Removing first item
	list.insert(Book{"0"}, 0);
	list.insert(Book{"1"}, 1);
	EXPECT_EQ(list.remove(0).value(), Book{"0"});
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(*list[0].value(), Book{"1"});

	EXPECT_EQ(list.remove(0).value(), Book{"1"});
	EXPECT_EQ(list.size(), 0);

	// Removing last item
	list.insert(Book{"0"}, 0);
	list.insert(Book{"1"}, 1);
	EXPECT_EQ(list.remove(1).value(), Book{"1"});
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.capacity(), 2);
	EXPECT_EQ(*list[0].value(), Book{"0"});
}

TEST(BookList, get) {
	BookList list;
	EXPECT_FALSE(list[0].has_value());
	
	list.insert(Book{"0"}, 0);
	EXPECT_EQ(*list[0].value(), Book{"0"});
}

TEST(BookList, unequal) {
	EXPECT_EQ(BookList(), BookList());
	EXPECT_FALSE(BookList({{"a"}}) == BookList({}));
	EXPECT_EQ(BookList({{"a"}}), BookList({{"a"}}));
	EXPECT_FALSE(BookList({{"a"}}) == BookList({{"b"}}));
}