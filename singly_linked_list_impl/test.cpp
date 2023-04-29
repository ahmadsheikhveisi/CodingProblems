/* COPYRIGHT
 */

#include <gtest/gtest.h>

#include <forward_list>
#include <iostream>
#include <list>
#include <memory>

#include "singly_linked_list.hpp"

TEST(LinkedListTest, PushTest) {
  LinkedList<int> m_list;
  m_list.insert(m_list.front, 1);
  m_list.insert(m_list.front, 2);

  EXPECT_EQ(m_list.front->data, 2);
  EXPECT_EQ(m_list.front->next->data, 1);
  EXPECT_EQ(m_list.front->next->next, nullptr);
}

TEST(LinkedListTest, RecReverse) {
  LinkedList<int> m_list({0, 1, 2, 3});

  m_list.rec_reverse();

  EXPECT_EQ(m_list.front->data, 3);
}

TEST(LinkedListTest, OnReverse) {
  LinkedList<int> m_list({0, 1, 2, 3});

  m_list.On_reverse();

  EXPECT_EQ(m_list.front->data, 3);
}
