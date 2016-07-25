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
  _TSPulse1 *Pl_TK13J02NES;
  _TSPulse1 *Pl_RL52S03NES;
  _TSPulse1 *Pl_RA12S04NES;
  _TSPulse1 *Pl_TH13S15NES;
  _TSPulse1 *Pl_TH13S18NES;
  _TSPulse1 *Pl_TK13J02NBRU;
  _TSPulse1 *Pl_RL52S03NBRU;
  _TSPulse1 *Pl_TH13S18NBRU;
  _TSPulse1 *Pl_RA12S04NBRU;
  _TSPulse1 *Pl_TH13S15NBRU;
  _TSPulse1 *Pl_TH13S15NP;
  _TSPulse1 *Pl_TH13S18NP;
  _TSPulse1 *Pl_TK13J02NP;
  _TSPulse1 *Pl_RA12S04NP;
  _TSPulse1 *Pl_RL52S03NP;
  _TSPulse1 *Pl_TP60S05NP;
  _TSPulse1 *Pl_TH13S15F;
  _TSPulse1 *Pl_TH13S18F;
  _TSPulse1 *Pl_TK13J02F;
  _TSPulse1 *Pl_RA12S04F;
  _TSPulse1 *Pl_RL52S03F;
  _TSPulse1 *Pl_Y067B20F;
  _TSPulse1 *Pl_T073B03F;
  _TSPulse1 *Pl_T118B03F;
  _TSPulse1 *Pl_T118B02F;
  _TSPulse1 *Pl_D14MC2_79F;
  _TSPulse1 *Pl_D14MC2_86F;
  _TSPulse1 *Pl_YA12T767F;
  _TSPulse1 *Pl_TH13T151F;
  _TSPulse1 *Pl_TP60S05F;
  _TSPulse1 *Pl_T651P01F;
  _TSPulse1 *Pl_YA12T779F;
  _TSPulse1 *Pl_T118B0F;
   bool bic_TH13S15F; 
   bool bic_TH13S18F; 
   bool bic_TK13J02F; 
   bool bic_RA12S04F; 
   bool bic_RL52S03F; 
   bool bic_Y067B20F; 
   bool bic_T073B03F; 
   bool bic_T118B03F; 
   bool bic_T118B02F; 
   bool bic_D14MC2_79F; 
   bool bic_D14MC2_86F; 
   bool bic_YA12T767F; 
   bool bic_TH13T151F; 
   bool bic_TP60S05F; 
   bool bic_T651P01F; 
   bool bic_YA12T779F; 
   bool bic_T118B0F; 
   bool bic_TH13S15NP; 
   bool bic_TH13S18NP; 
   bool bic_TK13J02NP; 
   bool bic_RA12S04NP; 
   bool bic_RL52S03NP; 
   bool bic_TP60S05NP; 
  _TSPulse1 *Pl_IS_GEN_ERR;
bool IS_GEN_ERR_Pl=false;
bool Zero=false;
bool _NFPO_D,_NFPO_NP;
void InitPulse()
{
  Pl_TK13J02NES = new _TSPulse1(0,false);
  Pl_RL52S03NES = new _TSPulse1(0,false);
  Pl_RA12S04NES = new _TSPulse1(0,false);
  Pl_TH13S15NES = new _TSPulse1(0,false);
  Pl_TH13S18NES = new _TSPulse1(0,false);
  Pl_TK13J02NBRU = new _TSPulse1(0,false);
  Pl_RL52S03NBRU = new _TSPulse1(0,false);
  Pl_TH13S18NBRU = new _TSPulse1(0,false);
  Pl_RA12S04NBRU = new _TSPulse1(0,false);
  Pl_TH13S15NBRU = new _TSPulse1(0,false);
  Pl_TH13S15NP = new _TSPulse1(0,false);
  Pl_TH13S18NP = new _TSPulse1(0,false);
  Pl_TK13J02NP = new _TSPulse1(0,false);
  Pl_RA12S04NP = new _TSPulse1(0,false);
  Pl_RL52S03NP = new _TSPulse1(0,false);
  Pl_TP60S05NP = new _TSPulse1(0,false);
  Pl_TH13S15F = new _TSPulse1(0,false);
  Pl_TH13S18F = new _TSPulse1(0,false);
  Pl_TK13J02F = new _TSPulse1(0,false);
  Pl_RA12S04F = new _TSPulse1(0,false);
  Pl_RL52S03F = new _TSPulse1(0,false);
  Pl_Y067B20F = new _TSPulse1(0,false);
  Pl_T073B03F = new _TSPulse1(0,false);
  Pl_T118B03F = new _TSPulse1(0,false);
  Pl_T118B02F = new _TSPulse1(0,false);
  Pl_D14MC2_79F = new _TSPulse1(0,false);
  Pl_D14MC2_86F = new _TSPulse1(0,false);
  Pl_YA12T767F = new _TSPulse1(0,false);
  Pl_TH13T151F = new _TSPulse1(0,false);
  Pl_TP60S05F = new _TSPulse1(0,false);
  Pl_T651P01F = new _TSPulse1(0,false);
  Pl_YA12T779F = new _TSPulse1(0,false);
  Pl_T118B0F = new _TSPulse1(0,false);
  Pl_IS_GEN_ERR = new _TSPulse1(0,false);
}
void Vizov()
{
////////////////// Vizov ////////////////////////////////////////////////// 
IS_GEN_ERR_Pl=Pl_IS_GEN_ERR->_SPulse((bool)Is_Gen_ErrP,time1);
   bic_TH13S15NP = _TH13S15NP  && !_TH13S15REM;
   bic_TH13S18NP = _TH13S18NP  && !_TH13S18REM;
   bic_TK13J02NP = _TK13J02NP  && !_TK13J02REM;
   bic_RA12S04NP = _RA12S04NP  && !_RA12S04REM;
   bic_RL52S03NP = _RL52S03NP  && !_RL52S03REM;
   bic_TP60S05NP = _TP60S05NP  && !_TP60S05REM;
_NEISPR_4 = Zero
    ||  _TK13J02NBRU
    ||  _RL52S03NBRU
    ||  _TH13S18NBRU
    ||  _RA12S04NBRU
    ||  _TH13S15NBRU
;
_NFPO_NP = Zero
   || Pl_TK13J02NES->_SPulse(_TK13J02NES,time1)
   || Pl_RL52S03NES->_SPulse(_RL52S03NES,time1)
   || Pl_RA12S04NES->_SPulse(_RA12S04NES,time1)
   || Pl_TH13S15NES->_SPulse(_TH13S15NES,time1)
   || Pl_TH13S18NES->_SPulse(_TH13S18NES,time1)
    ||  Pl_TH13S15NP->_SPulse(bic_TH13S15NP,time1) 
    ||  Pl_TH13S18NP->_SPulse(bic_TH13S18NP,time1) 
    ||  Pl_TK13J02NP->_SPulse(bic_TK13J02NP,time1) 
    ||  Pl_RA12S04NP->_SPulse(bic_RA12S04NP,time1) 
    ||  Pl_RL52S03NP->_SPulse(bic_RL52S03NP,time1) 
    ||  Pl_TP60S05NP->_SPulse(bic_TP60S05NP,time1) 
   || Pl_TK13J02NBRU->_SPulse(_TK13J02NBRU,time1)
   || Pl_RL52S03NBRU->_SPulse(_RL52S03NBRU,time1)
   || Pl_TH13S18NBRU->_SPulse(_TH13S18NBRU,time1)
   || Pl_RA12S04NBRU->_SPulse(_RA12S04NBRU,time1)
   || Pl_TH13S15NBRU->_SPulse(_TH13S15NBRU,time1)
;
_NEISPR_3 = Zero
    ||  _TK13J02NES
    ||  _RL52S03NES
    ||  _RA12S04NES
    ||  _TH13S15NES
    ||  _TH13S18NES
    ||  bic_TH13S15NP 
    ||  bic_TH13S18NP 
    ||  bic_TK13J02NP 
    ||  bic_RA12S04NP 
    ||  bic_RL52S03NP 
    ||  bic_TP60S05NP 
;
   bic_TH13S15F = _TH13S15F  && !_TH13S15KRS;
   bic_TH13S18F = _TH13S18F  && !_TH13S18KRS;
   bic_TK13J02F = _TK13J02F  && !_TK13J02KRS;
   bic_RA12S04F = _RA12S04F  && !_RA12S04KRS;
   bic_RL52S03F = _RL52S03F  && !_RL52S03KRS;
   bic_Y067B20F = _Y067B20F  && !_Y067B20KRS;
   bic_T073B03F = _T073B03F  && !_T073B03KRS;
   bic_T118B03F = _T118B03F  && !_T118B03KRS;
   bic_T118B02F = _T118B02F  && !_T118B02KRS;
   bic_D14MC2_79F = _D14MC2_79F  && !_D14MC2_79KRS;
   bic_D14MC2_86F = _D14MC2_86F  && !_D14MC2_86KRS;
   bic_YA12T767F = _YA12T767F  && !_YA12T767KRS;
   bic_TH13T151F = _TH13T151F  && !_TH13T151KRS;
   bic_YA12T779F = _YA12T779F  && !_YA12T779KRS;
   bic_TP60S05F = _TP60S05F  && !_TP60S05KRS;
   bic_T651P01F = _T651P01F  && !_T651P01KRS;
///gg
   bic_T118B0F = _T118B0F  && !_T118B0KRS;
// отказ датчиков
_NEISPR_1 = Zero
    ||  bic_TH13S15F 
    ||  bic_TH13S18F 
    ||  bic_TK13J02F 
    ||  bic_RA12S04F 
    ||  bic_RL52S03F 
    ||  bic_Y067B20F 
    ||  bic_T073B03F 
    ||  bic_T118B03F 
    ||  bic_T118B02F 
    ||  bic_D14MC2_79F 
    ||  bic_D14MC2_86F 
    ||  bic_YA12T767F 
    ||  bic_TH13T151F 
    ||  bic_TP60S05F 
    ||  bic_T651P01F 
    ||  bic_YA12T779F 
;
// отказ замеров
_NEISPR_2 = Zero
    ||  bic_T118B0F 
;
_NFPO_D = Zero
    ||  Pl_TH13S15F->_SPulse(bic_TH13S15F,time1) 
    ||  Pl_TH13S18F->_SPulse(bic_TH13S18F,time1) 
    ||  Pl_TK13J02F->_SPulse(bic_TK13J02F,time1) 
    ||  Pl_RA12S04F->_SPulse(bic_RA12S04F,time1) 
    ||  Pl_RL52S03F->_SPulse(bic_RL52S03F,time1) 
    ||  Pl_Y067B20F->_SPulse(bic_Y067B20F,time1) 
    ||  Pl_T073B03F->_SPulse(bic_T073B03F,time1) 
    ||  Pl_T118B03F->_SPulse(bic_T118B03F,time1) 
    ||  Pl_T118B0F->_SPulse(bic_T118B0F,time1) 
    ||  Pl_T118B0F->_SPulse(bic_T118B0F,time1) 
    ||  Pl_T118B02F->_SPulse(bic_T118B02F,time1) 
    ||  Pl_T118B02F->_SPulse(bic_T118B02F,time1) 
    ||  Pl_D14MC2_79F->_SPulse(bic_D14MC2_79F,time1) 
    ||  Pl_D14MC2_86F->_SPulse(bic_D14MC2_86F,time1) 
    ||  Pl_YA12T767F->_SPulse(bic_YA12T767F,time1) 
    ||  Pl_TH13T151F->_SPulse(bic_TH13T151F,time1) 
    ||  Pl_YA12T779F->_SPulse(bic_YA12T779F,time1) 
    ||  Pl_TP60S05F->_SPulse(bic_TP60S05F,time1) 
    ||  Pl_T651P01F->_SPulse(bic_T651P01F,time1) 
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
