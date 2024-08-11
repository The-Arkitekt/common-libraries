#include "IntegerNormalizer.h"

namespace COMMON_LIB
{

IntegerNormalizer::IntegerNormalizer(int inputMin, int inputMax, int outputMin, int outputMax):
  inputMin (inputMin),
  inputMax (inputMax),
  outputMin(outputMin),
  outputMax(outputMax)
{
}

IntegerNormalizer::~IntegerNormalizer()
{
}

int IntegerNormalizer::normalize(int input)
{
  int output = input * (outputMax - outputMin);
  output = output / (inputMax - inputMin);

  // TODO: fix this equation, it aint right

  return output;
}

}
