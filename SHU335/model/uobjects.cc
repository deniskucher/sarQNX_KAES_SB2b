//Инициализация и удаление объектов
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TMR_MRO *_TH11S15M_MRO;
_TMR_MRI *_TH11S15M_MRI;
_TMR_009 *_TH11S15_MR;
_TMR_MRO *_TH11S18M_MRO;
_TMR_009 *_TH11S18_MR;
_TMR_MRI *_TH11S18M_MRI;
_TMR_MRO *_TK11J02M_MRO;
_TMR_009 *_TK11_MR;
_TMR_MRI *_TK11J02M_MRI;
_TMR_MRO *_RA13M_MRO;
_TMR_009 *_RA13S_MR;
_TMR_MRI *_RA13M_MRI;
_TMR_MRO *_RA14M_MRO;
_TMR_009 *_RA14_MR;
_TMR_MRI *_RA14M_MRI;
_TMR_MRO *_RL53M_MRO;
_TMR_009 *_RL53_MR;
_TMR_MRI *_RL53M_MRI;
_TMR_MRO *_RL54M_MRO;
_TMR_009 *_RL54_MR;
_TMR_MRI *_RL54M_MRI;
void InitObjects()
{
  _TH11S15M_MRO = new(_TMR_MRO);
  _TH11S15M_MRI = new(_TMR_MRI);
  _TH11S15_MR = new(_TMR_009);
  _TH11S18M_MRO = new(_TMR_MRO);
  _TH11S18_MR = new(_TMR_009);
  _TH11S18M_MRI = new(_TMR_MRI);
  _TK11J02M_MRO = new(_TMR_MRO);
  _TK11_MR = new(_TMR_009);
  _TK11J02M_MRI = new(_TMR_MRI);
  _RA13M_MRO = new(_TMR_MRO);
  _RA13S_MR = new(_TMR_009);
  _RA13M_MRI = new(_TMR_MRI);
  _RA14M_MRO = new(_TMR_MRO);
  _RA14_MR = new(_TMR_009);
  _RA14M_MRI = new(_TMR_MRI);
  _RL53M_MRO = new(_TMR_MRO);
  _RL53_MR = new(_TMR_009);
  _RL53M_MRI = new(_TMR_MRI);
  _RL54M_MRO = new(_TMR_MRO);
  _RL54_MR = new(_TMR_009);
  _RL54M_MRI = new(_TMR_MRI);
}
void DeleteObjects()
{
  delete(_TH11S15M_MRO);
  delete(_TH11S15M_MRI);
  delete(_TH11S15_MR);
  delete(_TH11S18M_MRO);
  delete(_TH11S18_MR);
  delete(_TH11S18M_MRI);
  delete(_TK11J02M_MRO);
  delete(_TK11_MR);
  delete(_TK11J02M_MRI);
  delete(_RA13M_MRO);
  delete(_RA13S_MR);
  delete(_RA13M_MRI);
  delete(_RA14M_MRO);
  delete(_RA14_MR);
  delete(_RA14M_MRI);
  delete(_RL53M_MRO);
  delete(_RL53_MR);
  delete(_RL53M_MRI);
  delete(_RL54M_MRO);
  delete(_RL54_MR);
  delete(_RL54M_MRI);
}
