#include "pulse.h"
//__________________________________ TSPulse1 __________________________________

_TSPulse1::_TSPulse1(smallint _1Count, bool _2OldA)
{
  Count = _1Count;
  OldA = _2OldA;
}

_TSPulse1::~_TSPulse1()
{
}

bool _TSPulse1::_SPulse(const bool Front, const smallint T)
{
  /*Тело метода*/
   if (Front && !OldA)
    Count = 1;
  if (Count > T)
    Count = 0;
  OldA = Front;
  if (Count > 0)
  {
      Count ++;
      return true;
  }
  else return false;
}  /*_TSPulse1::_SPulse*/

