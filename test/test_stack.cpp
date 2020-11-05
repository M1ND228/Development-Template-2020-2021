#include <gtest.h>
#include "stack.h"

TEST(stack, can_create_stack_with_positive_length)
{
	EXPECT_NO_THROW(TStack stack(10));
}

TEST(stack, throws_when_create_matrix_with_negative_length)
{
	EXPECT_ANY_THROW(TStack stack(-10));
}

TEST(stack, true_can_IsEmpty_with_empty_stack)
{
	TStack stack(10);
	EXPECT_TRUE(stack.IsEmpty());
}

TEST(stack, false_can_IsEmpty_with_NoEmpty_stack)
{
	TStack stack(10);
	stack.Put(1);
	EXPECT_FALSE(stack.IsEmpty());
}

TEST(stack, false_can_IsFull_with_empty_stack)
{
	TStack stack(10);
	EXPECT_FALSE(stack.IsFull());
} 

TEST(stack, true_can_IsFull_with_full_stack)
{
	TStack stack(3);
	for (int i = 0; i < 3; i++)
	{
		stack.Put(i);
	}
	EXPECT_TRUE(stack.IsFull());
}

TEST(stack, can_put_number_with_stack)
{
	TStack stack(10);
	EXPECT_NO_THROW(stack.Put(1));
}

TEST(stack, can_Put_number_with_Full_stack)
{
	TStack stack(10);
	for (int i = 0; i < 10; i++)
	{
		stack.Put(i);
	}
	EXPECT_ANY_THROW(stack.Put(1));
}

TEST(stack, can_Get_number_with_stack)
{
	TStack stack(10);
	for (int i = 0; i < 10; i++)
	{
		stack.Put(i);
	}
	EXPECT_TRUE(9 == stack.Get());
}

TEST(stack, throw_can_Get_number_with_empty_stack)
{
	TStack st(10);
	EXPECT_ANY_THROW(st.Get());
}