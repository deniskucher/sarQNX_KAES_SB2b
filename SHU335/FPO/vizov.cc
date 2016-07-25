//Инициализация и удаление объектов
#include "usertype.h"
#include "pulse.h"
#include "globals.h"
#include "vizov.h"
#include "cdsface.h"
TBindSignal *Nal;
TBindSignal *Gen_Err;
TBindSignal *Gen_ErrP;
int Nalad=0;
int Is_Gen_Err=0;
int Is_Gen_ErrP=0;
short time1=10;    //  1 second
  _TSPulse1 *Pl_TK11J02NES;
  _TSPulse1 *Pl_RL53S03NES;
  _TSPulse1 *Pl_RA13S04NES;
  _TSPulse1 *Pl_RA14S04NES;
  _TSPulse1 *Pl_RL54S03NES;
  _TSPulse1 *Pl_TH11S15NES;
  _TSPulse1 *Pl_TH11S18NES;
  _TSPulse1 *Pl_TK11J02NBRU;
  _TSPulse1 *Pl_RL53S03NBRU;
  _TSPulse1 *Pl_RL54S03NBRU;
  _TSPulse1 *Pl_RA13S04NBRU;
  _TSPulse1 *Pl_RA14S04NBRU;
  _TSPulse1 *Pl_TH11S15NBRU;
  _TSPulse1 *Pl_TH11S18NBRU;
  _TSPulse1 *Pl_TK11J02NP;
  _TSPulse1 *Pl_RA13S04NP;
  _TSPulse1 *Pl_RA14S04NP;
  _TSPulse1 *Pl_RL53S03NP;
  _TSPulse1 *Pl_RL54S03NP;
  _TSPulse1 *Pl_TH11S15NP;
  _TSPulse1 *Pl_TH11S18NP;
  _TSPulse1 *Pl_TH11S15F;
  _TSPulse1 *Pl_TH11S18F;
  _TSPulse1 *Pl_TK11J02F;
  _TSPulse1 *Pl_RA13S04F;
  _TSPulse1 *Pl_RA14S04F;
  _TSPulse1 *Pl_RL53S03F;
  _TSPulse1 *Pl_RL54S03F;
  _TSPulse1 *Pl_Y065B20F;
  _TSPulse1 *Pl_T071B03F;
  _TSPulse1 *Pl_T116B03F;
  _TSPulse1 *Pl_T116B02F;
  _TSPulse1 *Pl_D14MC3_79F;
  _TSPulse1 *Pl_D14MC4_79F;
  _TSPulse1 *Pl_D14MC3_84F;
  _TSPulse1 *Pl_D14MC4_84F;
  _TSPulse1 *Pl_YA13T768F;
  _TSPulse1 *Pl_TH11T153F;
  _TSPulse1 *Pl_T116B0F;
  _TSPulse1 *Pl_YA13T780F;
   bool bic_TH11S15F; 
   bool bic_TH11S18F; 
   bool bic_TK11J02F; 
   bool bic_RA13S04F; 
   bool bic_RA14S04F; 
   bool bic_RL53S03F; 
   bool bic_RL54S03F; 
   bool bic_Y065B20F; 
   bool bic_T071B03F; 
   bool bic_T116B03F; 
   bool bic_T116B02F; 
   bool bic_D14MC3_79F; 
   bool bic_D14MC4_79F; 
   bool bic_D14MC3_84F; 
   bool bic_D14MC4_84F; 
   bool bic_YA13T768F; 
   bool bic_TH11T153F; 
   bool bic_T116B0F; 
   bool bic_YA13T780F; 
   bool bic_TK11J02NP; 
   bool bic_RA13S04NP; 
   bool bic_RA14S04NP; 
   bool bic_RL53S03NP; 
   bool bic_RL54S03NP; 
   bool bic_TH11S15NP; 
   bool bic_TH11S18NP; 
  _TSPulse1 *Pl_IS_GEN_ERR;
bool IS_GEN_ERR_Pl=false;
bool Zero=false;
bool _NFPO_D,_NFPO_NP;
void InitPulse()
{
  Pl_TK11J02NES = new _TSPulse1(0,false);
  Pl_RL53S03NES = new _TSPulse1(0,false);
  Pl_RA13S04NES = new _TSPulse1(0,false);
  Pl_RA14S04NES = new _TSPulse1(0,false);
  Pl_RL54S03NES = new _TSPulse1(0,false);
  Pl_TH11S15NES = new _TSPulse1(0,false);
  Pl_TH11S18NES = new _TSPulse1(0,false);
  Pl_TK11J02NBRU = new _TSPulse1(0,false);
  Pl_RL53S03NBRU = new _TSPulse1(0,false);
  Pl_RL54S03NBRU = new _TSPulse1(0,false);
  Pl_RA13S04NBRU = new _TSPulse1(0,false);
  Pl_RA14S04NBRU = new _TSPulse1(0,false);
  Pl_TH11S15NBRU = new _TSPulse1(0,false);
  Pl_TH11S18NBRU = new _TSPulse1(0,false);
  Pl_TK11J02NP = new _TSPulse1(0,false);
  Pl_RA13S04NP = new _TSPulse1(0,false);
  Pl_RA14S04NP = new _TSPulse1(0,false);
  Pl_RL53S03NP = new _TSPulse1(0,false);
  Pl_RL54S03NP = new _TSPulse1(0,false);
  Pl_TH11S15NP = new _TSPulse1(0,false);
  Pl_TH11S18NP = new _TSPulse1(0,false);
  Pl_TH11S15F = new _TSPulse1(0,false);
  Pl_TH11S18F = new _TSPulse1(0,false);
  Pl_TK11J02F = new _TSPulse1(0,false);
  Pl_RA13S04F = new _TSPulse1(0,false);
  Pl_RA14S04F = new _TSPulse1(0,false);
  Pl_RL53S03F = new _TSPulse1(0,false);
  Pl_RL54S03F = new _TSPulse1(0,false);
  Pl_Y065B20F = new _TSPulse1(0,false);
  Pl_T071B03F = new _TSPulse1(0,false);
  Pl_T116B03F = new _TSPulse1(0,false);
  Pl_T116B02F = new _TSPulse1(0,false);
  Pl_D14MC3_79F = new _TSPulse1(0,false);
  Pl_D14MC4_79F = new _TSPulse1(0,false);
  Pl_D14MC3_84F = new _TSPulse1(0,false);
  Pl_D14MC4_84F = new _TSPulse1(0,false);
  Pl_YA13T768F = new _TSPulse1(0,false);
  Pl_TH11T153F = new _TSPulse1(0,false);
  Pl_T116B0F = new _TSPulse1(0,false);
  Pl_YA13T780F = new _TSPulse1(0,false);
  Pl_IS_GEN_ERR = new _TSPulse1(0,false);
}
void Vizov()
{
////////////////// Vizov ////////////////////////////////////////////////// 
IS_GEN_ERR_Pl=Pl_IS_GEN_ERR->_SPulse((bool)Is_Gen_ErrP,time1);
   bic_TH11S15NP = _TH11S15NP  && !_TH11S15REM;
   bic_TH11S18NP = _TH11S18NP  && !_TH11S18REM;
   bic_TK11J02NP = _TK11J02NP  && !_TK11J02REM;
   bic_RA13S04NP = _RA13S04NP  && !_RA13S04REM;
   bic_RA14S04NP = _RA14S04NP  && !_RA14S04REM;
   bic_RL53S03NP = _RL53S03NP  && !_RL53S03REM;
   bic_RL54S03NP = _RL54S03NP  && !_RL54S03REM;
_NEISPR_4 = Zero
    ||  _TK11J02NBRU
    ||  _RL53S03NBRU
    ||  _RL54S03NBRU
    ||  _RA13S04NBRU
    ||  _RA14S04NBRU
    ||  _TH11S15NBRU
    ||  _TH11S18NBRU
;
_NFPO_NP = Zero
   || Pl_TK11J02NES->_SPulse(_TK11J02NES,time1)
   || Pl_RL53S03NES->_SPulse(_RL53S03NES,time1)
   || Pl_RA13S04NES->_SPulse(_RA13S04NES,time1)
   || Pl_RA14S04NES->_SPulse(_RA14S04NES,time1)
   || Pl_RL54S03NES->_SPulse(_RL54S03NES,time1)
   || Pl_TH11S15NES->_SPulse(_TH11S15NES,time1)
   || Pl_TH11S18NES->_SPulse(_TH11S18NES,time1)
    ||  Pl_TH11S15NP->_SPulse(bic_TH11S15NP,time1) 
    ||  Pl_TH11S18NP->_SPulse(bic_TH11S18NP,time1) 
    ||  Pl_TK11J02NP->_SPulse(bic_TK11J02NP,time1) 
    ||  Pl_RA13S04NP->_SPulse(bic_RA13S04NP,time1) 
    ||  Pl_RA14S04NP->_SPulse(bic_RA14S04NP,time1) 
    ||  Pl_RL53S03NP->_SPulse(bic_RL53S03NP,time1) 
    ||  Pl_RL54S03NP->_SPulse(bic_RL54S03NP,time1) 
   || Pl_TK11J02NBRU->_SPulse(_TK11J02NBRU,time1)
   || Pl_RL53S03NBRU->_SPulse(_RL53S03NBRU,time1)
   || Pl_RL54S03NBRU->_SPulse(_RL54S03NBRU,time1)
   || Pl_RA13S04NBRU->_SPulse(_RA13S04NBRU,time1)
   || Pl_RA14S04NBRU->_SPulse(_RA14S04NBRU,time1)
   || Pl_TH11S15NBRU->_SPulse(_TH11S15NBRU,time1)
   || Pl_TH11S18NBRU->_SPulse(_TH11S18NBRU,time1)
;
_NEISPR_3 = Zero
    ||  _TK11J02NES
    ||  _RL53S03NES
    ||  _RA13S04NES
    ||  _RA14S04NES
    ||  _RL54S03NES
    ||  _TH11S15NES
    ||  _TH11S18NES
    ||  bic_TK11J02NP 
    ||  bic_RA13S04NP 
    ||  bic_RA14S04NP 
    ||  bic_RL53S03NP 
    ||  bic_RL54S03NP 
    ||  bic_TH11S15NP 
    ||  bic_TH11S18NP 
;
   bic_TH11S15F = _TH11S15F  && !_TH11S15KRS;
   bic_TH11S18F = _TH11S18F  && !_TH11S18KRS;
   bic_TK11J02F = _TK11J02F  && !_TK11J02KRS;
   bic_RA13S04F = _RA13S04F  && !_RA13S04KRS;
   bic_RA14S04F = _RA14S04F  && !_RA14S04KRS;
   bic_RL53S03F = _RL53S03F  && !_RL53S03KRS;
   bic_RL54S03F = _RL54S03F  && !_RL54S03KRS;
   bic_Y065B20F = _Y065B20F  && !_Y065B20KRS;
   bic_T071B03F = _T071B03F  && !_T071B03KRS;
   bic_T116B03F = _T116B03F  && !_T116B03KRS;
   bic_T116B02F = _T116B02F  && !_T116B02KRS;
   bic_D14MC3_79F = _D14MC3_79F  && !_D14MC3_79KRS;
   bic_D14MC4_79F = _D14MC4_79F  && !_D14MC4_79KRS;
   bic_D14MC3_84F = _D14MC3_84F  && !_D14MC3_84KRS;
   bic_D14MC4_84F = _D14MC4_84F  && !_D14MC4_84KRS;
   bic_YA13T768F = _YA13T768F  && !_YA13T768KRS;
   bic_TH11T153F = _TH11T153F  && !_TH11T153KRS;
   bic_YA13T780F = _YA13T780F  && !_YA13T780KRS;
///gg
   bic_T116B0F = _T116B0F  && !_T116B0KRS;
// отказ датчиков
_NEISPR_1 = Zero
    ||  bic_TH11S15F 
    ||  bic_TH11S18F 
    ||  bic_TK11J02F 
    ||  bic_RA13S04F 
    ||  bic_RA14S04F 
    ||  bic_RL53S03F 
    ||  bic_RL54S03F 
    ||  bic_Y065B20F 
    ||  bic_T071B03F 
    ||  bic_T116B03F 
    ||  bic_T116B02F 
    ||  bic_D14MC3_79F 
    ||  bic_D14MC4_79F 
    ||  bic_D14MC3_84F 
    ||  bic_D14MC4_84F 
    ||  bic_YA13T768F 
    ||  bic_TH11T153F 
    ||  bic_YA13T780F 
;
// отказ замеров
_NEISPR_2 = Zero
    ||  bic_T116B0F 
;
_NFPO_D = Zero
    ||  Pl_TH11S15F->_SPulse(bic_TH11S15F,time1) 
    ||  Pl_TH11S18F->_SPulse(bic_TH11S18F,time1) 
    ||  Pl_TK11J02F->_SPulse(bic_TK11J02F,time1) 
    ||  Pl_RA13S04F->_SPulse(bic_RA13S04F,time1) 
    ||  Pl_RA14S04F->_SPulse(bic_RA14S04F,time1) 
    ||  Pl_RL53S03F->_SPulse(bic_RL53S03F,time1) 
    ||  Pl_RL54S03F->_SPulse(bic_RL54S03F,time1) 
    ||  Pl_Y065B20F->_SPulse(bic_Y065B20F,time1) 
    ||  Pl_T071B03F->_SPulse(bic_T071B03F,time1) 
    ||  Pl_T116B03F->_SPulse(bic_T116B03F,time1) 
    ||  Pl_T116B0F->_SPulse(bic_T116B0F,time1) 
    ||  Pl_T116B0F->_SPulse(bic_T116B0F,time1) 
    ||  Pl_T116B02F->_SPulse(bic_T116B02F,time1) 
    ||  Pl_T116B02F->_SPulse(bic_T116B02F,time1) 
    ||  Pl_D14MC3_79F->_SPulse(bic_D14MC3_79F,time1) 
    ||  Pl_D14MC4_79F->_SPulse(bic_D14MC4_79F,time1) 
    ||  Pl_D14MC3_84F->_SPulse(bic_D14MC3_84F,time1) 
    ||  Pl_D14MC4_84F->_SPulse(bic_D14MC4_84F,time1) 
    ||  Pl_YA13T768F->_SPulse(bic_YA13T768F,time1) 
    ||  Pl_TH11T153F->_SPulse(bic_TH11T153F,time1) 
    ||  Pl_YA13T780F->_SPulse(bic_YA13T780F,time1) 
;
_NEISPR_0 = _NEISPR_1  || _NEISPR_2  ||  _NEISPR_3 ||  _NEISPR_4;
_NFPO     = _NFPO_D    || _NFPO_NP;
////////////////// Emergency governer switching OFF ///////////////////////
   _SHU5APN_SP  
   = IS_GEN_ERR_Pl;
   _SHU5APN  
      =   Is_Gen_Err;  // 
}
void Naladka()
{
Nal -> Get_Value(Nalad);
Gen_Err -> Get_Value(Is_Gen_Err);
Gen_ErrP -> Get_Value(Is_Gen_ErrP);
}
