#include "gtest/gtest.h"
#include "Vector.h"

TEST(VectorTest, DefaultConstructor) {
    Vector vec;
    ASSERT_TRUE(vec.isEmpty());
}

TEST(VectorTest, AddElement) {
    Vector vec;
    vec << 10;
    ASSERT_FALSE(vec.isEmpty());
    ASSERT_EQ(vec[0], 10);
}

TEST(VectorTest, InsertElement) {
    Vector vec;
    vec.insert(0, 5);
    ASSERT_EQ(vec[0], 5);
}

TEST(VectorTest, RemoveElement) {
    Vector vec = {1, 2, 3};
    vec.remove(1);
    ASSERT_EQ(vec.search(2), false);
}

TEST(VectorTest, RemoveLastElement) {
     Vector vec = {1, 2, 3};
     vec >> 1;
     ASSERT_EQ(vec.search(3),false);
}
