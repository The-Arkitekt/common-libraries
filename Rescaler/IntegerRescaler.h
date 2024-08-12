#ifndef COMMON_LIB_INT_RESCALER_H
#define COMMON_LIB_INT_RESCALER_H

namespace COMMON_LIB
{

class IntegerRescaler
{
public:

  IntegerRescaler(int inputMin, int inputMax, int outputMin, int outputMax);
  ~IntegerRescaler();

  int scale(int input);

private:

  static const unsigned int PRECISION = 10U;

  int inputMax;
  int outputMax;
  int scaleFactor;
};

}

#endif //COMMON_LIB_INT_RESCALER_H
