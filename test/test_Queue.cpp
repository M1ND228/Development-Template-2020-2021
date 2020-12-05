#include "Queue.h"

#include <gtest.h>


TEST(Queue, can_create_Queue)
{
	EXPECT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_push_in_Queue)
{
	Queue<int> q;
	EXPECT_NO_THROW(q.push(5));
}

TEST(Queue, can_pop_is_NOempty_Queue)
{
	Queue<int> q;
	q.push(5);
	EXPECT_NO_THROW(q.pop());
}

TEST(Queue, can_pop_is_empty_Queue)
{
	Queue<int> q;
	EXPECT_ANY_THROW(q.pop());
}

TEST(Queue, can_empty_is_empty_Queue)
{
	Queue<int> q;
	EXPECT_TRUE(q.empty());
}

TEST(Queue, can_empty_Queue)
{
	Queue<int> q;
	q.push(5);
	EXPECT_FALSE(q.empty());
}

TEST(Queue, can_empty_after_push_and_pop_with_Queue)
{
	Queue<int> q;
	q.push(5);
	q.pop();
	EXPECT_TRUE(q.empty());
}

TEST(Queue, can_return_size_with_empty_Queue)
{
	Queue<int> q;
	EXPECT_EQ(q.size(), 0);
}

TEST(Queue, can_return_size_after_push_in_Queue)
{
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.size(), 1);
}

TEST(Queue, can_return_size_after_push_and_pop_in_Queue)
{
	Queue<int> q;
	q.push(1);
	q.pop();
	EXPECT_EQ(q.size(), 0);
}

TEST(Queue, can_front_after_push_Queue)
{
	Queue<int> q;
	q.push(1);
	EXPECT_NO_THROW(q.front());
}


TEST(Queue, can_front_return_first_element_with_Queue_filled_with_one_element)
{
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.front(), 1);
}

TEST(Queue, can_front_return_first_element_with_Queue_filled_with_several_element)
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	EXPECT_EQ(q.front(), 1);
}

TEST(Queue, can_front_with_empty_Queue)
{
	Queue<int> q;
	EXPECT_ANY_THROW(q.front());
}

TEST(Queue, can_back_after_push_Queue)
{
	Queue<int> q;
	q.push(1);
	EXPECT_NO_THROW(q.back());
}


TEST(Queue, can_back_return_first_element_with_Queue_filled_with_one_element)
{
	Queue<int> q;
	q.push(1);
	EXPECT_EQ(q.back(), 1);
}

TEST(Queue, can_back_return_first_element_with_Queue_filled_with_several_element)
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	EXPECT_EQ(q.back(), 5);
}

TEST(Queue, can_back_with_empty_Queue)
{
	Queue<int> q;
	EXPECT_ANY_THROW(q.back());
}

