#include "IntegerRescaler.h"
#include <limits>

namespace COMMON_LIB
{

IntegerRescaler::IntegerRescaler(int inputMin, int inputMax, int outputMin, int outputMax, unsigned int precision):
  inputMax   (0),
  outputMax  (0),
  scaleFactor(0)
{
  // make sure that outputRange << PRECISION is not greater than max int
  // make sure that inputRange is not zero
  if (((outputMax - outputMin) > (std::numeric_limits<int>::max() >> PRECISION)) ||
      ((inputMax - inputMin) <= 0))
  {
    return;
  }

  this->inputMax  = inputMax;
  this->outputMax = outputMax;

  scaleFactor = ((outputMax - outputMin) << PRECISION) / (inputMax - inputMin);
    
}

IntegerRescaler::~IntegerRescaler()
{
}

int IntegerRescaler::scale(int input)
{
  int output = scaleFactor * (input - inputMax) + outputMax;
  return output >> PRECISION;
}

}
