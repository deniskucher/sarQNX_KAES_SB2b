//Инициализация и удаление объектов
#include "usertype.h"
#include "uclasses.h"
#include "uobjects.h"

_TMR_MRO *_TH13S15M_MRO;
_TMR_009 *_TH13S15_MR;
_TMR_MRI *_TH13S15M_MRI;
_TMR_MRO *_TH13S18M_MRO;
_TMR_009 *_TH13S18_MR;
_TMR_MRI *_TH13S18M_MRI;
_TMR_MRO *_TK13M_MRO;
_TMR_009 *_TK13_MR;
_TMR_MRI *_TK13M_MRI;
_TMR_MRO *_RA12M_MRO;
_TMR_009 *_RA12_MR;
_TMR_MRI *_RA12M_MRI;
_TMR_MRO *_RL52M_MRO;
_TMR_009 *_RL52_MR;
_TMR_MRI *_RL52M_MRI;
_TMR_MRO *_TP60M_MRO;
_TMR_009 *_TP60_MR;
_TMR_MRI *_TP60M_MRI;
void InitObjects()
{
  _TH13S15M_MRO = new(_TMR_MRO);
  _TH13S15_MR = new(_TMR_009);
  _TH13S15M_MRI = new(_TMR_MRI);
  _TH13S18M_MRO = new(_TMR_MRO);
  _TH13S18_MR = new(_TMR_009);
  _TH13S18M_MRI = new(_TMR_MRI);
  _TK13M_MRO = new(_TMR_MRO);
  _TK13_MR = new(_TMR_009);
  _TK13M_MRI = new(_TMR_MRI);
  _RA12M_MRO = new(_TMR_MRO);
  _RA12_MR = new(_TMR_009);
  _RA12M_MRI = new(_TMR_MRI);
  _RL52M_MRO = new(_TMR_MRO);
  _RL52_MR = new(_TMR_009);
  _RL52M_MRI = new(_TMR_MRI);
  _TP60M_MRO = new(_TMR_MRO);
  _TP60_MR = new(_TMR_009);
  _TP60M_MRI = new(_TMR_MRI);
}
void DeleteObjects()
{
  delete(_TH13S15M_MRO);
  delete(_TH13S15_MR);
  delete(_TH13S15M_MRI);
  delete(_TH13S18M_MRO);
  delete(_TH13S18_MR);
  delete(_TH13S18M_MRI);
  delete(_TK13M_MRO);
  delete(_TK13_MR);
  delete(_TK13M_MRI);
  delete(_RA12M_MRO);
  delete(_RA12_MR);
  delete(_RA12M_MRI);
  delete(_RL52M_MRO);
  delete(_RL52_MR);
  delete(_RL52M_MRI);
  delete(_TP60M_MRO);
  delete(_TP60_MR);
  delete(_TP60M_MRI);
}
