#include <gtest/gtest.h>
#include "../book_list.h"

TEST(BookList, push) {
	BookList list;
	list.push(Book{"0"});
	EXPECT_EQ(*list[0].value(), Book{"0"});
	EXPECT_FALSE(list[1].has_value());
	
	list.push(Book{"1"});
	EXPECT_EQ(*list[0].value(), Book{"0"});
	EXPECT_EQ(*list[1].value(), Book{"1"});
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
		EXPECT_EQ(*list[0].value(), Book{"title"});
	}
}

TEST(BookList, remove) {
	BookList list;
	EXPECT_FALSE(list.remove(0).has_value());
	
	list.push(Book{"title"});
	EXPECT_EQ(list.remove(0).value(), Book{"title"});
	EXPECT_EQ(list.size(), 0);
	
	// Removing first item
	list.push(Book{"0"});
	list.push(Book{"1"});
	EXPECT_EQ(list.remove(0).value(), Book{"0"});
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(*list[0].value(), Book{"1"});

	EXPECT_EQ(list.remove(0).value(), Book{"1"});
	EXPECT_EQ(list.size(), 0);

	// Removing last item
	list.push(Book{"0"});
	list.push(Book{"1"});
	EXPECT_EQ(list.remove(1).value(), Book{"1"});
	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.capacity(), 2);
	EXPECT_EQ(*list[0].value(), Book{"0"});
}

TEST(BookList, get) {
	BookList list;
	EXPECT_FALSE(list[0].has_value());
	
	list.push(Book{"0"});
	EXPECT_EQ(*list[0].value(), Book{"0"});
}