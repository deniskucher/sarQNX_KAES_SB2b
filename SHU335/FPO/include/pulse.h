#ifndef pulseH
#define pulseH
#include "usertype.h"

//__________________________________ TSPulse __________________________________

class _TSPulse1
{
public:
  smallint Count;
  bool OldA;
  _TSPulse1(smallint _1Count, bool _2OldA);
  ~_TSPulse1();
  bool _SPulse(const bool Front, const smallint T);
};

#endif
