#include <gtest.h>
#include "multistack.h"

TEST(multistack, can_create_MultiStack)
{
	EXPECT_NO_THROW(TMultistack MStack);
}

TEST(multistack, true_can_IsEmpty_with_empty_MultiStack)
{
	TMultistack MStack;
	EXPECT_TRUE(MStack.IsEmpty(1));
}

TEST(multistack, false_can_IsEmpty_with_empty_MultiStack)
{
	TMultistack MStack;
	MStack.Put(1, 1);
	EXPECT_FALSE(MStack.IsEmpty(1));
}

TEST(multistack, true_can_IsFull_with_full_MultiStack)
{
	TMultistack MStack;
	for (int i = 0; i < 10; i++)
	{
		MStack.Put(1, i);
	}
	EXPECT_FALSE(MStack.IsFull(1));
}

TEST(multistack, false_can_IsFull_with_empty_MultiStack)
{
	TMultistack MStack;
	EXPECT_FALSE(MStack.IsFull(1));
}

TEST(multistack, can_Put_number_with_MultiStack)
{
	TMultistack MStack;
	EXPECT_NO_THROW(MStack.Put(3, 10));
}

TEST(multistack, test_Relocation_can_Put_number_with_Full_MultiStack)
{
	TMultistack MStack;
	for (int i = 0; i < 10; i++)
	{
		MStack.Put(1, i);
	}
	EXPECT_NO_THROW(MStack.Put(3, 10));
}

TEST(multistack, can_Get_with_MultiStack)
{
	TMultistack MStack;
	MStack.Put(1, 1);
	EXPECT_NO_THROW(MStack.Get(1));
}

TEST(multistack, can_Get_with_empty_MultiStack)
{
	TMultistack MStack;
	EXPECT_ANY_THROW(MStack.Get(1));
}

TEST(multistack, can_GetRelocationCount_with_MultiStack)
{
	TMultistack MStack;
	for (int i = 0; i < 10; i++)
	{
		MStack.Put(1, i);
	}
	MStack.Put(3, 10);
	EXPECT_TRUE(MStack.GetRelocationCount() == 1);
}