/**
 * Copyright
 */

#include "gtest/gtest.h"

#include "solution.hpp"

TEST(RouteBetweenTwoNodesTest, RouteDiscoverTest) {
  solution uut{"0", "1", "2",  "3",  "4",  "5",  "6",  "7",
               "8", "9", "10", "11", "12", "13", "14", "15"};
  EXPECT_TRUE(uut.AddEdge("0", "4"));
  EXPECT_TRUE(uut.AddEdge("1", "4"));
  EXPECT_TRUE(uut.AddEdge("2", "5"));
  EXPECT_TRUE(uut.AddEdge("3", "5"));
  EXPECT_TRUE(uut.AddEdge("4", "6"));
  EXPECT_TRUE(uut.AddEdge("5", "6"));
  EXPECT_TRUE(uut.AddEdge("6", "7"));
  EXPECT_TRUE(uut.AddEdge("7", "8"));
  EXPECT_TRUE(uut.AddEdge("8", "9"));
  EXPECT_TRUE(uut.AddEdge("8", "10"));
  EXPECT_TRUE(uut.AddEdge("9", "11"));
  EXPECT_TRUE(uut.AddEdge("9", "12"));
  EXPECT_TRUE(uut.AddEdge("10", "13"));
  EXPECT_TRUE(uut.AddEdge("10", "14"));

  EXPECT_TRUE(uut.DoesRouteExist("0", "14"));
  EXPECT_FALSE(uut.DoesRouteExist("0", "15"));
}
