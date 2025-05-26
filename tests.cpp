#include <gtest/gtest.h>
#include "piquet.h"
#include "speed_restriction.h"
#include <sstream>

// Тесты для класса Piquet
TEST(PiquetTest, DefaultConstructor) {
    Piquet p;
    EXPECT_EQ(p.number, 0);
    EXPECT_DOUBLE_EQ(p.shift, 0.0);
    EXPECT_DOUBLE_EQ(p.length, 100.0);
    EXPECT_TRUE(p.isStandard);
}

TEST(PiquetTest, ParameterizedConstructor) {
    Piquet p(10, 25.5);
    EXPECT_EQ(p.number, 10);
    EXPECT_DOUBLE_EQ(p.shift, 25.5);
    EXPECT_DOUBLE_EQ(p.length, 100.0);
    EXPECT_TRUE(p.isStandard);
}

TEST(PiquetTest, ToString) {
    Piquet p1(5, 30.75);
    EXPECT_EQ(p1.ToString(), "ПК 5+30.75");

    Piquet p2(-3, 50.0);
    EXPECT_EQ(p2.ToString(), "ПК 03+50.00");
}

TEST(PiquetTest, ComparisonOperators) {
    Piquet p1(10, 20.0);
    Piquet p2(10, 20.0);
    Piquet p3(10, 30.0);
    Piquet p4(15, 10.0);

    EXPECT_TRUE(p1 == p2);
    EXPECT_TRUE(p1 != p3);
    EXPECT_TRUE(p1 < p3);
    EXPECT_TRUE(p3 > p1);
    EXPECT_TRUE(p1 <= p2);
    EXPECT_TRUE(p1 >= p2);
    EXPECT_TRUE(p3 <= p4);
}

TEST(PiquetTest, StreamOutput) {
    Piquet p(7, 15.25);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "ПК 7+15.25");
}

TEST(PiquetTest, StreamInput) {
    std::istringstream iss("ПК 12+34.56");
    Piquet p;
    iss >> p;
    EXPECT_EQ(p.number, 12);
    EXPECT_DOUBLE_EQ(p.shift, 34.56);
}

// Тесты для класса SpeedRestriction
TEST(SpeedRestrictionTest, Constructor) {
    Piquet start(10, 0.0);
    Piquet end(12, 50.0);
    SpeedRestriction sr(start, end, 60.0);

    EXPECT_EQ(sr.start.number, 10);
    EXPECT_EQ(sr.end.number, 12);
    EXPECT_DOUBLE_EQ(sr.speedLimit, 60.0);
}

TEST(SpeedRestrictionTest, ToString) {
    Piquet start(10, 0.0);
    Piquet end(12, 50.0);
    SpeedRestriction sr(start, end, 45.5);

    EXPECT_EQ(sr.ToString(), 
              "Ограничение скорости: ПК 10+0.00 - ПК 12+50.00, Скорость: 45.5 км/ч");
}

TEST(SpeedRestrictionTest, ReadFromStreamValid) {
    std::istringstream input(
        "ПК 10+00.00\n"
        "ПК 12+50.00\n"
        "60\n"
    );
    
    std::ostringstream output;
    auto restriction = SpeedRestriction::ReadFromStream(input);

    ASSERT_NE(restriction, nullptr);
    output << *restriction;
    EXPECT_EQ(output.str(), 
              "Ограничение скорости: ПК 10+0.00 - ПК 12+50.00, Скорость: 60.0 км/ч");
    
    delete restriction;
}

TEST(SpeedRestrictionTest, ReadFromStreamInvalidSpeed) {
    std::istringstream input(
        "ПК 10+00.00\n"
        "ПК 12+50.00\n"
        "90\n"
    );
    
    auto restriction = SpeedRestriction::ReadFromStream(input);
    EXPECT_EQ(restriction, nullptr);
}

TEST(SpeedRestrictionTest, ReadFromStreamInvalidOrder) {
    std::istringstream input(
        "ПК 12+50.00\n"
        "ПК 10+00.00\n"
        "60\n"
    );
    
    auto restriction = SpeedRestriction::ReadFromStream(input);
    EXPECT_EQ(restriction, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
