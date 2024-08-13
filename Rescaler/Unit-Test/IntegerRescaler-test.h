#ifndef COMMON_LIB_GTEST_INTEGER_RESCALER_TEST_H
#define COMMON_LIB_GTEST_INTEGER_RESCALER_TEST_H

#include <gtest/gtest.h>
#include "IntegerRescaler.h"

namespace COMMON_LIB
{

namespace GTEST
{

class IntegerRescalerTest : public testing::Test
{
public:

  bool createIntegerRescaler(int inputMin, int inputMax, int outputMin, int outputMax);
  int  scale(int input);

protected:

  IntegerRescalerTest();
  ~IntegerRescalerTest() override;

  void TearDown() override;

private:

  IntegerRescaler * integerRescaler;

};

}

}

#endif // COMMON_LIB_GTEST_INTEGER_RESCALER_TEST_H
