#include "IntegerRescaler-test.h"
#include <new>

namespace COMMON_LIB
{

namespace GTEST
{

IntegerRescalerTest::IntegerRescalerTest():
  integerRescaler(nullptr)
{
}

IntegerRescalerTest::~IntegerRescalerTest()
{
  delete(integerRescaler);
  integerRescaler = nullptr;
}

void IntegerRescalerTest::TearDown()
{
  delete(integerRescaler);
  integerRescaler = nullptr;
}

bool IntegerRescalerTest::createIntegerRescaler(int inputMin, int inputMax, int outputMin, int outputMax)
{
  integerRescaler = new (std::nothrow) IntegerRescaler(inputMin, inputMax, outputMin, outputMax);
  
  return (nullptr == integerRescaler) ? false : true;
}

int IntegerRescalerTest::scale(int input)
{
  if (nullptr == integerRescaler)
  {
    return 0;
  }

  return integerRescaler->scale(input);
}

TEST_F(IntegerRescalerTest, scale_1) 
{
  int inputMin  = 1;
  int inputMax  = 5;
  int outputMin = 2;
  int outputMax = 10;

  ASSERT_TRUE(createIntegerRescaler(inputMin, inputMax, outputMin, outputMax));

  EXPECT_EQ(outputMin, scale(inputMin));
  EXPECT_EQ(outputMax, scale(inputMax));

  int inputMedian  = ((inputMax - inputMin) / 2) + inputMin;
  int outputMedian = ((outputMax - outputMin) / 2) + outputMin;

  EXPECT_EQ(outputMedian, scale(inputMedian));
}

TEST_F(IntegerRescalerTest, scale_2) 
{
  int inputMin  = 4;
  int inputMax  = 13;
  int outputMin = 1;
  int outputMax = 43;

  ASSERT_TRUE(createIntegerRescaler(inputMin, inputMax, outputMin, outputMax));

  EXPECT_EQ(outputMin, scale(inputMin));
  EXPECT_EQ(outputMax, scale(inputMax));

  int inputMedian  = ((inputMax - inputMin) / 2) + inputMin;
  int outputMedian = ((outputMax - outputMin) / 2) + outputMin;

  EXPECT_EQ(outputMedian, scale(inputMedian));
}

}

}
