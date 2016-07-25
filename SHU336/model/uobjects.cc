//Инициализация и удаление объектов
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TMR_MRO *_TK12M_MRO;
_TMR_009 *_TK12_MR;
_TMR_MRI *_TK12M_MRI;
_TMR_MRO *_RA11M_MRO;
_TMR_009 *_RA11_MR;
_TMR_MRI *_RA11M_MRI;
_TMR_MRO *_RL51M_MRO;
_TMR_009 *_RL51_MR;
_TMR_MRI *_RL51M_MRI;
_TMR_MRO *_TH15M_MRO;
_TMR_009 *_TH15_MR;
_TMR_MRI *_TH15M_MRI;
_TMR_MRO *_TH18M_MRO;
_TMR_009 *_TH18_MR;
_TMR_MRI *_TH18M_MRI;
_TMR_MRO *_TP60M_MRO;
_TMR_009 *_TP60_MR;
_TMR_MRI *_TP60M_MRI;
void InitObjects()
{
  _TK12M_MRO = new(_TMR_MRO);
  _TK12_MR = new(_TMR_009);
  _TK12M_MRI = new(_TMR_MRI);
  _RA11M_MRO = new(_TMR_MRO);
  _RA11_MR = new(_TMR_009);
  _RA11M_MRI = new(_TMR_MRI);
  _RL51M_MRO = new(_TMR_MRO);
  _RL51_MR = new(_TMR_009);
  _RL51M_MRI = new(_TMR_MRI);
  _TH15M_MRO = new(_TMR_MRO);
  _TH15_MR = new(_TMR_009);
  _TH15M_MRI = new(_TMR_MRI);
  _TH18M_MRO = new(_TMR_MRO);
  _TH18_MR = new(_TMR_009);
  _TH18M_MRI = new(_TMR_MRI);
  _TP60M_MRO = new(_TMR_MRO);
  _TP60_MR = new(_TMR_009);
  _TP60M_MRI = new(_TMR_MRI);
}
void DeleteObjects()
{
  delete(_TK12M_MRO);
  delete(_TK12_MR);
  delete(_TK12M_MRI);
  delete(_RA11M_MRO);
  delete(_RA11_MR);
  delete(_RA11M_MRI);
  delete(_RL51M_MRO);
  delete(_RL51_MR);
  delete(_RL51M_MRI);
  delete(_TH15M_MRO);
  delete(_TH15_MR);
  delete(_TH15M_MRI);
  delete(_TH18M_MRO);
  delete(_TH18_MR);
  delete(_TH18M_MRI);
  delete(_TP60M_MRO);
  delete(_TP60_MR);
  delete(_TP60M_MRI);
}
