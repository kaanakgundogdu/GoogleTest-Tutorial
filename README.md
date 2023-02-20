# Google Test Tutorial with CMake
## *If you find Google's explanation complicated you can follow this example. I tried to explain very simply.*

>   ### Start with a making project folder and then create CMakeLists.txt and main.cpp. For this example I have a folder named Testing and I created that 2 files (CMakeList.txt and main.cpp).

```
touch CMakeLists.txt
touch main.cpp

```

![image](https://user-images.githubusercontent.com/62032779/220097914-05a10c5c-d21f-410d-8d36-6445b6a36659.png)

- ### After creating CMakeLists you need to fill it with some content. For this example: 

```
cmake_minimum_required(VERSION 3.14)
project(testing)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest) 

enable_testing()

add_executable(
	testing
	main.cpp
)
target_link_libraries(
  testing
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing)

```
- ### Next, I added some code into the main.cpp file. 
```
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
```
- ### If you are using any editors like Visual Studio or QT you can compile and see the test results, but for this example I use commands:
```
cmake -S . -B build
```
![image](https://user-images.githubusercontent.com/62032779/220101840-708bad20-03aa-4992-be0c-d3838001eb8e.png)

<br>

```
cmake --build build
```
![image](https://user-images.githubusercontent.com/62032779/220102360-ae1ce99c-ea66-425c-8b4f-d3a3d14b400b.png)

<br>

```
cd build && ctest
```
![image](https://user-images.githubusercontent.com/62032779/220102596-17506359-f686-4804-ae1e-2db0dc24af4b.png)


- ### Building in QT creator:
![image](https://user-images.githubusercontent.com/62032779/220103690-0efe69c3-b80e-4801-91da-463c8001a9bb.png)




