#include <gtest.h>
#include "TList.h"

TEST(TList, can_create_)
{
	EXPECT_NO_THROW(TList<int> res);
}

TEST(TList, can_get_ListLength)
{
	TList<int> res;
	EXPECT_EQ(0, res.GetListLenght());
}

TEST(TList, true_can_IsEmpty_with_empty_TList)
{
	TList<int> res;
	EXPECT_TRUE(res.IsEmpty());
}

TEST(TList, false_can_IsEmpty_with_NOempty_TList)
{
	TList<int> res;
	res.InsFirst(10);
	EXPECT_FALSE(res.IsEmpty());
}

TEST(TList, can_put_InsFirst)
{
	TList<int> res;
	EXPECT_NO_THROW(res.InsFirst(10));
}

TEST(TList, can_put_InsLast)
{
	TList<int> res;
	EXPECT_NO_THROW(res.InsLast(10));
}

TEST(TList, can_InsLast_plus_lislen)
{
	TList<int> res;
	int tmp = res.GetListLenght();
	res.InsLast(2);
	int tmp2 = res.GetListLenght();
	EXPECT_TRUE(tmp + 1 == tmp2);
}

TEST(TList, can_delete_first)
{
	TList<int> res;
	res.InsFirst(1);
	EXPECT_NO_THROW(res.DelFirst());
}

TEST(TList, can_delete_last)
{
	TList<int> res;
	res.InsFirst(1);
	EXPECT_NO_THROW(res.DelLast());
}

TEST(TList, DelFirst_can_work_is_empty_list)
{
	TList<int> res;
	EXPECT_NO_THROW(res.DelFirst());
}

TEST(TList, DelLast_can_work_is_empty_list)
{
	TList<int> res;
	EXPECT_NO_THROW(res.DelLast());
}

TEST(TList, can_delete_for_DelList)
{
	TList<int> res;
	for (int i = 0; i < 10; i++)
	{
		res.InsFirst(i);
	}
	res.DelList();
	EXPECT_EQ(0, res.GetListLenght());
}

TEST(TList, can_put_value_in_InsValue)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i + 1);
	}

	EXPECT_NO_THROW(res.InsValue(0, 2));
}

TEST(TList, can_DelValue_is_work)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i);
	}
	EXPECT_NO_THROW(res.DelValue(0));
}

TEST(TList, can_search_is_work)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i);
	}
	EXPECT_NO_THROW(res.search(0));
}

TEST(TList, true_can_search)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i);
	}
	EXPECT_TRUE(res.search(0));
}

TEST(TList, false_can_search)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i);
	}
	EXPECT_FALSE(res.search(10));
}

TEST(TList, can_reverse_is_work)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsFirst(i);
	}
	EXPECT_NO_THROW(res.Reverse());
}

TEST(TList, can_get)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsLast(i);
	}
	EXPECT_EQ(0, res.get(0));
}

TEST(TList, can_merge_is_work)
{
	TList<int> res;
	TList<int> res1;
	TList<int> res2;
	for (int i = 0; i < 5; i++)
	{
		res1.InsLast(i);
		res2.InsLast(i + 5);
	}

	EXPECT_NO_THROW(res.Merge(res1, res2));
}

TEST(TList, exception_NOsort)
{
	TList<int> res;
	TList<int> res1;
	TList<int> res2;
	for (int i = 0, j = 5; i < 2; i++, j--)
	{
		res1.InsLast(i);
		res2.InsLast(j);
	}
	EXPECT_ANY_THROW(res.Merge(res1, res2));
}

TEST(TList, can_swap_is_work)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsLast(i);
	}
	EXPECT_NO_THROW(res.swap(0, 2));
}

TEST(TList, swap_is_work)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsLast(i);
	}
	res.swap(0, 2);
	EXPECT_EQ(2, res.get(0));
}

TEST(TList, exception_swap_negative_value)
{
	TList<int> res;
	for (int i = 0; i < 5; i++)
	{
		res.InsLast(i);
	}

	EXPECT_ANY_THROW(res.swap(0, -1));
}
