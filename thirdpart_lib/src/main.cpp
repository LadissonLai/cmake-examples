#include <iostream>
#include "mymath.h"
#include <gtest/gtest.h>

/**
 * @brief Test case for the Add function in MyMathTest.
 */
TEST(MyMathTest, Add1)
{
    EXPECT_EQ(myadd(1, 2), 3);
}

TEST(MyMathTest, Add2)
{
    EXPECT_EQ(myadd(3, 2), 5);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}