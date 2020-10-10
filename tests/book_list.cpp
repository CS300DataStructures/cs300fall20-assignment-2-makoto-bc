#include <gtest/gtest.h>
#include "../book_list.h"

TEST(BookList, push) {
	BookList list;
	list.push(Book{"0"});
	EXPECT_EQ(list[0].value()->title, "0");
	EXPECT_FALSE(list[1].has_value());
	
	list.push(Book{"1"});
	EXPECT_EQ(list[0].value()->title, "0");
	EXPECT_EQ(list[1].value()->title, "1");
}

TEST(BookList, reserve) {
	{
		BookList list;
		list.reserve(0);
		EXPECT_EQ(list.capacity(), 1);

		list.reserve(1);
		EXPECT_EQ(list.capacity(), 1);

		list.reserve(3);
		EXPECT_EQ(list.capacity(), 4);

		list.reserve(0);
		EXPECT_EQ(list.capacity(), 4);

		EXPECT_FALSE(list[0].has_value());
	}
	{
		BookList list;
		list.push(Book{"title"});
		list.reserve(4);
		EXPECT_EQ(list[0].value()->title, "title");
	}
}

TEST(BookList, get) {
	BookList list;
	EXPECT_FALSE(list[0].has_value());
	
	list.push(Book{});
	EXPECT_TRUE(list[0].has_value());
}