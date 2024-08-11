#ifndef COMMON_LIB_INT_NORMALIZER_H
#define COMMON_LIB_INT_NORMALIZER_H

namespace COMMON_LIB
{

class IntegerNormalizer
{
public:

  IntegerNormalizer(int inputMin, int inputMax, int outputMin, int outputMax);
  ~IntegerNormalizer();

  int normalize(int input);

private:

  int inputMin;
  int inputMax;
  int outputMin;
  int outputMax;

};

}

#endif //COMMON_LIB_INT_NORMALIZER_H
