#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> st(5)); // ��������� �������� ����� � ������ 5
}

TEST(TStack, cant_create_stack_with_negative_length)
{
    ASSERT_THROW(TStack<int> st(-1), int); // ��������� ������� ������� ���� � ������������� ������
}

TEST(TStack, cant_create_stack_with_zero_length)
{
    ASSERT_THROW(TStack<int> st(0), int); // ��������� ������� ������� ���� � ������ 0
}

TEST(TStack, can_push_elements_into_stack)
{
    TStack<int> st(5);
    ASSERT_NO_THROW(st.Push(10)); // ��������� ���������� �������� � ����
    ASSERT_NO_THROW(st.Push(20)); // ��������� ���������� ������� ��������
}

TEST(TStack, can_pop_elements_from_stack)
{
    TStack<int> st(5);
    st.Push(10);
    st.Push(20);
    int x = st.Pop();
    ASSERT_EQ(x, 20); // ���������, ��� ��������� ����������� ������� �����������
    x = st.Pop();
    ASSERT_EQ(x, 10); // ���������, ��� ������ ������� �����������
}

TEST(TStack, cant_pop_from_empty_stack)
{
    TStack<int> st(5);
    ASSERT_THROW(st.Pop(), const char*); // ���������, ��� ���������� �� ������� ����� �������� ������
}

TEST(TStack, can_check_if_stack_is_empty)
{
    TStack<int> st(5);
    ASSERT_TRUE(st.IsEmpty()); // ���������, ��� ���� ���� ��� ��������
    st.Push(10);
    ASSERT_FALSE(st.IsEmpty()); // ���������, ��� ���� �� ���� ����� ���������� ��������
}

TEST(TStack, can_check_if_stack_is_full)
{
    TStack<int> st(2);
    ASSERT_FALSE(st.IsFull()); // ���������, ��� ���� �� ������
    st.Push(10);
    ASSERT_FALSE(st.IsFull()); // ���������, ��� ���� �� ������
    st.Push(20);
    ASSERT_TRUE(st.IsFull()); // ���������, ��� ���� ������
}

TEST(TStack, cant_push_to_full_stack)
{
    TStack<int> st(2);
    st.Push(10);
    st.Push(20);
    ASSERT_THROW(st.Push(30), const char*); // ���������, ��� ���������� �������� � ������ ���� �������� ������
}

TEST(TStack, can_get_top_element)
{
    TStack<int> st(5);
    st.Push(10);
    ASSERT_EQ(st.Top(), 10); // ���������, ��� ����� Top ���������� ������� �������
}

TEST(TStack, cant_get_top_from_empty_stack)
{
    TStack<int> st(5);
    ASSERT_THROW(st.Top(), const char*); // ���������, ��� ����� ������ Top �� ������� ����� �������� ������
}

TEST(TStack, can_get_stack_size)
{
    TStack<int> st(5);
    st.Push(10);
    st.Push(20);
    ASSERT_EQ(st.GetSize(), 2); // ���������, ��� ����� GetSize ���������� ���������� ���������� ��������� � �����
}
