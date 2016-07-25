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
  _TSPulse1 *Pl_TK12J02NES;
  _TSPulse1 *Pl_RL51S03NES;
  _TSPulse1 *Pl_RA11S04NES;
  _TSPulse1 *Pl_TH12S15NES;
  _TSPulse1 *Pl_TH12S18NES;
  _TSPulse1 *Pl_TK12J02NBRU;
  _TSPulse1 *Pl_TH12S15NBRU;
  _TSPulse1 *Pl_RL51S03NBRU;
  _TSPulse1 *Pl_RA11S04NBRU;
  _TSPulse1 *Pl_TH12S18NBRU;
  _TSPulse1 *Pl_TK12J02NP;
  _TSPulse1 *Pl_RA11S04NP;
  _TSPulse1 *Pl_RL51S03NP;
  _TSPulse1 *Pl_TH12S15NP;
  _TSPulse1 *Pl_TH12S18NP;
  _TSPulse1 *Pl_TP60S07NP;
  _TSPulse1 *Pl_TK12J02F;
  _TSPulse1 *Pl_RA11S04F;
  _TSPulse1 *Pl_RL51S03F;
  _TSPulse1 *Pl_Y066B20F;
  _TSPulse1 *Pl_T072B03F;
  _TSPulse1 *Pl_T117B03F;
  _TSPulse1 *Pl_T117B02F;
  _TSPulse1 *Pl_D14MC1_79F;
  _TSPulse1 *Pl_D14MC1_85F;
  _TSPulse1 *Pl_T117B0F;
  _TSPulse1 *Pl_TH12S15F;
  _TSPulse1 *Pl_TH12S18F;
  _TSPulse1 *Pl_TP60S07F;
  _TSPulse1 *Pl_YA11T766F;
  _TSPulse1 *Pl_YA11T778F;
  _TSPulse1 *Pl_TH12T152F;
  _TSPulse1 *Pl_T653P01F;
   bool bic_TK12J02F; 
   bool bic_RA11S04F; 
   bool bic_RL51S03F; 
   bool bic_Y066B20F; 
   bool bic_T072B03F; 
   bool bic_T117B03F; 
   bool bic_T117B02F; 
   bool bic_D14MC1_79F; 
   bool bic_D14MC1_85F; 
   bool bic_T117B0F; 
   bool bic_TH12S15F; 
   bool bic_TH12S18F; 
   bool bic_TP60S07F; 
   bool bic_YA11T766F; 
   bool bic_YA11T778F; 
   bool bic_TH12T152F; 
   bool bic_T653P01F; 
   bool bic_TK12J02NP; 
   bool bic_RA11S04NP; 
   bool bic_RL51S03NP; 
   bool bic_TH12S15NP; 
   bool bic_TH12S18NP; 
   bool bic_TP60S07NP; 
  _TSPulse1 *Pl_IS_GEN_ERR;
bool IS_GEN_ERR_Pl=false;
bool Zero=false;
bool _NFPO_D,_NFPO_NP;
void InitPulse()
{
  Pl_TK12J02NES = new _TSPulse1(0,false);
  Pl_RL51S03NES = new _TSPulse1(0,false);
  Pl_RA11S04NES = new _TSPulse1(0,false);
  Pl_TH12S15NES = new _TSPulse1(0,false);
  Pl_TH12S18NES = new _TSPulse1(0,false);
  Pl_TK12J02NBRU = new _TSPulse1(0,false);
  Pl_TH12S15NBRU = new _TSPulse1(0,false);
  Pl_RL51S03NBRU = new _TSPulse1(0,false);
  Pl_RA11S04NBRU = new _TSPulse1(0,false);
  Pl_TH12S18NBRU = new _TSPulse1(0,false);
  Pl_TK12J02NP = new _TSPulse1(0,false);
  Pl_RA11S04NP = new _TSPulse1(0,false);
  Pl_RL51S03NP = new _TSPulse1(0,false);
  Pl_TH12S15NP = new _TSPulse1(0,false);
  Pl_TH12S18NP = new _TSPulse1(0,false);
  Pl_TP60S07NP = new _TSPulse1(0,false);
  Pl_TK12J02F = new _TSPulse1(0,false);
  Pl_RA11S04F = new _TSPulse1(0,false);
  Pl_RL51S03F = new _TSPulse1(0,false);
  Pl_Y066B20F = new _TSPulse1(0,false);
  Pl_T072B03F = new _TSPulse1(0,false);
  Pl_T117B03F = new _TSPulse1(0,false);
  Pl_T117B02F = new _TSPulse1(0,false);
  Pl_D14MC1_79F = new _TSPulse1(0,false);
  Pl_D14MC1_85F = new _TSPulse1(0,false);
  Pl_T117B0F = new _TSPulse1(0,false);
  Pl_TH12S15F = new _TSPulse1(0,false);
  Pl_TH12S18F = new _TSPulse1(0,false);
  Pl_TP60S07F = new _TSPulse1(0,false);
  Pl_YA11T766F = new _TSPulse1(0,false);
  Pl_YA11T778F = new _TSPulse1(0,false);
  Pl_TH12T152F = new _TSPulse1(0,false);
  Pl_T653P01F = new _TSPulse1(0,false);
  Pl_IS_GEN_ERR = new _TSPulse1(0,false);
}
void Vizov()
{
////////////////// Vizov ////////////////////////////////////////////////// 
IS_GEN_ERR_Pl=Pl_IS_GEN_ERR->_SPulse((bool)Is_Gen_ErrP,time1);
   bic_TK12J02NP = _TK12J02NP  && !_TK12J02REM;
   bic_RA11S04NP = _RA11S04NP  && !_RA11S04REM;
   bic_RL51S03NP = _RL51S03NP  && !_RL51S03REM;
   bic_TH12S15NP = _TH12S15NP  && !_TH12S15REM;
   bic_TH12S18NP = _TH12S18NP  && !_TH12S18REM;
   bic_TP60S07NP = _TP60S07NP  && !_TP60S07REM;
_NEISPR_4 = Zero
    ||  _TK12J02NBRU
    ||  _TH12S15NBRU
    ||  _RL51S03NBRU
    ||  _RA11S04NBRU
    ||  _TH12S18NBRU
;
_NFPO_NP = Zero
   || Pl_TK12J02NES->_SPulse(_TK12J02NES,time1)
   || Pl_RL51S03NES->_SPulse(_RL51S03NES,time1)
   || Pl_RA11S04NES->_SPulse(_RA11S04NES,time1)
   || Pl_TH12S15NES->_SPulse(_TH12S15NES,time1)
   || Pl_TH12S18NES->_SPulse(_TH12S18NES,time1)
    ||  Pl_TK12J02NP->_SPulse(bic_TK12J02NP,time1) 
    ||  Pl_RA11S04NP->_SPulse(bic_RA11S04NP,time1) 
    ||  Pl_RL51S03NP->_SPulse(bic_RL51S03NP,time1) 
    ||  Pl_TH12S15NP->_SPulse(bic_TH12S15NP,time1) 
    ||  Pl_TH12S18NP->_SPulse(bic_TH12S18NP,time1) 
    ||  Pl_TP60S07NP->_SPulse(bic_TP60S07NP,time1) 
   || Pl_TK12J02NBRU->_SPulse(_TK12J02NBRU,time1)
   || Pl_TH12S15NBRU->_SPulse(_TH12S15NBRU,time1)
   || Pl_RL51S03NBRU->_SPulse(_RL51S03NBRU,time1)
   || Pl_RA11S04NBRU->_SPulse(_RA11S04NBRU,time1)
   || Pl_TH12S18NBRU->_SPulse(_TH12S18NBRU,time1)
;
_NEISPR_3 = Zero
    ||  _TK12J02NES
    ||  _RL51S03NES
    ||  _RA11S04NES
    ||  _TH12S15NES
    ||  _TH12S18NES
    ||  bic_TK12J02NP 
    ||  bic_RA11S04NP 
    ||  bic_RL51S03NP 
    ||  bic_TH12S15NP 
    ||  bic_TH12S18NP 
    ||  bic_TP60S07NP 
;
   bic_TK12J02F = _TK12J02F  && !_TK12J02KRS;
   bic_RA11S04F = _RA11S04F  && !_RA11S04KRS;
   bic_RL51S03F = _RL51S03F  && !_RL51S03KRS;
   bic_Y066B20F = _Y066B20F  && !_Y066B20KRS;
   bic_T072B03F = _T072B03F  && !_T072B03KRS;
   bic_T117B03F = _T117B03F  && !_T117B03KRS;
   bic_T117B02F = _T117B02F  && !_T117B02KRS;
   bic_D14MC1_79F = _D14MC1_79F  && !_D14MC1_79KRS;
   bic_D14MC1_85F = _D14MC1_85F  && !_D14MC1_85KRS;
   bic_TH12S15F = _TH12S15F  && !_TH12S15KRS;
   bic_TH12S18F = _TH12S18F  && !_TH12S18KRS;
   bic_TP60S07F = _TP60S07F  && !_TP60S07KRS;
   bic_YA11T766F = _YA11T766F  && !_YA11T766KRS;
   bic_YA11T778F = _YA11T778F  && !_YA11T778KRS;
   bic_TH12T152F = _TH12T152F  && !_TH12T152KRS;
   bic_T653P01F = _T653P01F  && !_T653P01KRS;
///gg
   bic_T117B0F = _T117B0F  && !_T117B0KRS;
// отказ датчиков
_NEISPR_1 = Zero
    ||  bic_TK12J02F 
    ||  bic_RA11S04F 
    ||  bic_RL51S03F 
    ||  bic_Y066B20F 
    ||  bic_T072B03F 
    ||  bic_T117B03F 
    ||  bic_T117B02F 
    ||  bic_D14MC1_79F 
    ||  bic_D14MC1_85F 
    ||  bic_TH12S15F 
    ||  bic_TH12S18F 
    ||  bic_TP60S07F 
    ||  bic_YA11T766F 
    ||  bic_YA11T778F 
    ||  bic_TH12T152F 
    ||  bic_T653P01F 
;
// отказ замеров
_NEISPR_2 = Zero
    ||  bic_T117B0F 
;
_NFPO_D = Zero
    ||  Pl_TK12J02F->_SPulse(bic_TK12J02F,time1) 
    ||  Pl_RA11S04F->_SPulse(bic_RA11S04F,time1) 
    ||  Pl_RL51S03F->_SPulse(bic_RL51S03F,time1) 
    ||  Pl_Y066B20F->_SPulse(bic_Y066B20F,time1) 
    ||  Pl_T072B03F->_SPulse(bic_T072B03F,time1) 
    ||  Pl_T117B03F->_SPulse(bic_T117B03F,time1) 
    ||  Pl_T117B0F->_SPulse(bic_T117B0F,time1) 
    ||  Pl_T117B0F->_SPulse(bic_T117B0F,time1) 
    ||  Pl_T117B02F->_SPulse(bic_T117B02F,time1) 
    ||  Pl_T117B02F->_SPulse(bic_T117B02F,time1) 
    ||  Pl_D14MC1_79F->_SPulse(bic_D14MC1_79F,time1) 
    ||  Pl_D14MC1_85F->_SPulse(bic_D14MC1_85F,time1) 
    ||  Pl_TH12S15F->_SPulse(bic_TH12S15F,time1) 
    ||  Pl_TH12S18F->_SPulse(bic_TH12S18F,time1) 
    ||  Pl_TP60S07F->_SPulse(bic_TP60S07F,time1) 
    ||  Pl_YA11T766F->_SPulse(bic_YA11T766F,time1) 
    ||  Pl_YA11T778F->_SPulse(bic_YA11T778F,time1) 
    ||  Pl_TH12T152F->_SPulse(bic_TH12T152F,time1) 
    ||  Pl_T653P01F->_SPulse(bic_T653P01F,time1) 
;
_NEISPR_0 = _NEISPR_1  || _NEISPR_2  ||  _NEISPR_3 ||  _NEISPR_4;
_NFPO     = _NFPO_D    || _NFPO_NP;
////////////////// Emergency governer switching OFF ///////////////////////
   _SHU6APN_SP  
   = IS_GEN_ERR_Pl;
   _SHU6APN  
      =   Is_Gen_Err;  // 
}
void Naladka()
{
Nal -> Get_Value(Nalad);
Gen_Err -> Get_Value(Is_Gen_Err);
Gen_ErrP -> Get_Value(Is_Gen_ErrP);
}
