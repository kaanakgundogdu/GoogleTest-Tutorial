#include <iostream>
#include <gtest/gtest.h>

int factorial(int n);

TEST(HelloTest, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}


TEST(FactorialTest, HandlesSomeInput) {
    EXPECT_EQ(factorial(5),120);
    EXPECT_EQ(factorial(0),1);
    EXPECT_EQ(factorial(1),1);
    EXPECT_EQ(factorial(3),6);
}
TEST(FactorialTest, SomeLargeInput) {
    EXPECT_EQ(factorial(11),39916800);
    EXPECT_EQ(factorial(10),3628800);
    EXPECT_EQ(factorial(7),5040);
    //EXPECT_EQ(factorial(20),2432902008176640000);
}


int factorial(int n){
    if(n<2)
        return 1;

    return n * factorial(n-1);
}

int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

