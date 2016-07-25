#include "KD.h"
#include "globals.h"
  bool _TK12J02F_1; // to reserve MK
  bool _RA11S04F_1; // to reserve MK
  bool _RL51S03F_1; // to reserve MK
  bool _Y066B20F_1; // to reserve MK
  bool _T072B03F_1; // to reserve MK
  bool _T117B03F_1; // to reserve MK
  bool _T117B02F_1; // to reserve MK
  bool _D14MC1_79F_1; // to reserve MK
  bool _D14MC1_85F_1; // to reserve MK
  bool _TH12S15F_1; // to reserve MK
  bool _TH12S18F_1; // to reserve MK
  bool _TP60S07F_1; // to reserve MK
  bool _YA11T766F_1; // to reserve MK
  bool _YA11T778F_1; // to reserve MK
  bool _TH12T152F_1; // to reserve MK
  bool _T653P01F_1; // to reserve MK
_TKD1 *pAI1[KOL_AI1+1]; // +1 worked in case KOL_AI count = 0 
_TKD2 *pAI2[KOL_AI2+1];
_TKD3 *pAI3[KOL_AI3+1];
void Init_KD()
{
 short i;
 for (i=0;i <= KOL_AI1;i++) 
 pAI1[i] = new _TKD1(0,0,0,0,0,0,0,0,0,0,0,0,0); 
 for (i=0;i <= KOL_AI2;i++) 
 pAI2[i] = new _TKD2(0); 
 for (i=0;i <= KOL_AI3;i++) 
 pAI3[i] = new _TKD3(0,0,0,0,0); 
   i=0;
  i++;
  i++;
  i++;
  i++;
  i++;
  i++;
  pAI1[i]->pMask_ZMX = &_Y066B20ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_T072B03ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_T117B03ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_T117B02ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_D14MC1_79ZMX;
  i++;
  i++;
  pAI1[i]->pMask_ZMX = &_YA11T766ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_YA11T778ZMX;
  i++;
  pAI1[i]->pMask_ZMX = &_TH12T152ZMX;
  i++;
  i++;
   i=0;
  i++;
  i++;
  i++;
  i++;
  i++;
  i++;
  pAI1[i]->pMask_ZMN = &_Y066B20ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_T072B03ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_T117B03ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_T117B02ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_D14MC1_79ZMN;
  i++;
  i++;
  pAI1[i]->pMask_ZMN = &_YA11T766ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_YA11T778ZMN;
  i++;
  pAI1[i]->pMask_ZMN = &_TH12T152ZMN;
  i++;
  i++;
   i=0;
  i++;
  i++;
  i++;
  i++;
  i++;
  i++;
  pAI1[i]->pMask_ZDV = &_Y066B20ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_T072B03ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_T117B03ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_T117B02ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_D14MC1_79ZDV;
  i++;
  i++;
  pAI1[i]->pMask_ZDV = &_YA11T766ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_YA11T778ZDV;
  i++;
  pAI1[i]->pMask_ZDV = &_TH12T152ZDV;
  i++;
  i++;
   i=0;
  pAI2[i]->pMask_ZRK = &_T117B0RZRK;
  i++;
   i=0;
};
void KD_RUN()
{
 short i;
 i=0;
 if (Delay_1m<600) Delay_1m++;
  pAI1[i] -> _KD1(_TH12S15,_TH12S15OKD,_TH12S15KRS,_TH12S15K1N,_TH12S15K2N,_TH12S15DV,
  _TH12S15MN,_TH12S15MX,_TH12S15SBRN,_TH12S15R,_TH12S15F,_TH12S15ZZ,_TH12S15F_1);i++;
  pAI1[i] -> _KD1(_TH12S18,_TH12S18OKD,_TH12S18KRS,_TH12S18K1N,_TH12S18K2N,_TH12S18DV,
  _TH12S18MN,_TH12S18MX,_TH12S18SBRN,_TH12S18R,_TH12S18F,_TH12S18ZZ,_TH12S18F_1);i++;
  pAI1[i] -> _KD1(_TP60S07,_TP60S07OKD,_TP60S07KRS,_TP60S07K1N,_TP60S07K2N,_TP60S07DV,
  _TP60S07MN,_TP60S07MX,_TP60S07SBRN,_TP60S07R,_TP60S07F,_TP60S07ZZ,_TP60S07F_1);i++;
  pAI1[i] -> _KD1(_TK12J02,_TK12J02OKD,_TK12J02KRS,_TK12J02K1N,_TK12J02K2N,_TK12J02DV,
  _TK12J02MN,_TK12J02MX,_TK12J02SBRN,_TK12J02R,_TK12J02F,_TK12J02ZZ,_TK12J02F_1);i++;
  pAI1[i] -> _KD1(_RA11S04,_RA11S04OKD,_RA11S04KRS,_RA11S04K1N,_RA11S04K2N,_RA11S04DV,
  _RA11S04MN,_RA11S04MX,_RA11S04SBRN,_RA11S04R,_RA11S04F,_RA11S04ZZ,_RA11S04F_1);i++;
  pAI1[i] -> _KD1(_RL51S03,_RL51S03OKD,_RL51S03KRS,_RL51S03K1N,_RL51S03K2N,_RL51S03DV,
  _RL51S03MN,_RL51S03MX,_RL51S03SBRN,_RL51S03R,_RL51S03F,_RL51S03ZZ,_RL51S03F_1);i++;
  pAI1[i] -> _KD1(_Y066B20,_Y066B20OKD,_Y066B20KRS,_Y066B20K1N,_Y066B20K2N,_Y066B20DV,
  _Y066B20MN,_Y066B20MX,_Y066B20SBRN,_Y066B20R,_Y066B20F,_Y066B20ZZ,_Y066B20F_1);i++;
  pAI1[i] -> _KD1(_T072B03,_T072B03OKD,_T072B03KRS,_T072B03K1N,_T072B03K2N,_T072B03DV,
  _T072B03MN,_T072B03MX,_T072B03SBRN,_T072B03R,_T072B03F,_T072B03ZZ,_T072B03F_1);i++;
  pAI1[i] -> _KD1(_T117B03,_T117B03OKD,_T117B03KRS,_T117B03K1N,_T117B03K2N,_T117B03DV,
  _T117B03MN,_T117B03MX,_T117B0SBRN,_T117B03R,_T117B03F,_T117B03ZZ,_T117B03F_1);i++;
  pAI1[i] -> _KD1(_T117B02,_T117B02OKD,_T117B02KRS,_T117B02K1N,_T117B02K2N,_T117B02DV,
  _T117B02MN,_T117B02MX,_T117B0SBRN,_T117B02R,_T117B02F,_T117B02ZZ,_T117B02F_1);i++;
  pAI1[i] -> _KD1(_D14MC1_79,_D14MC1_79OKD,_D14MC1_79KRS,_D14MC1_79K1N,_D14MC1_79K2N,_D14MC1_79DV,
  _D14MC1_79MN,_D14MC1_79MX,_D14MC1_79SBRN,_D14MC1_79R,_D14MC1_79F,_D14MC1_79ZZ,_D14MC1_79F_1);i++;
  pAI1[i] -> _KD1(_D14MC1_85,_D14MC1_85OKD,_D14MC1_85KRS,_D14MC1_85K1N,_D14MC1_85K2N,_D14MC1_85DV,
  _D14MC1_85MN,_D14MC1_85MX,_D14MC1_85SBRN,_D14MC1_85R,_D14MC1_85F,_D14MC1_85ZZ,_D14MC1_85F_1);i++;
  pAI1[i] -> _KD1(_YA11T766,_YA11T766OKD,_YA11T766KRS,_YA11T766K1N,_YA11T766K2N,_YA11T766DV,
  _YA11T766MN,_YA11T766MX,_YA11T766SBRN,_YA11T766R,_YA11T766F,_YA11T766ZZ,_YA11T766F_1);i++;
  pAI1[i] -> _KD1(_YA11T778,_YA11T778OKD,_YA11T778KRS,_YA11T778K1N,_YA11T778K2N,_YA11T778DV,
  _YA11T778MN,_YA11T778MX,_YA11T778SBRN,_YA11T778R,_YA11T778F,_YA11T778ZZ,_YA11T778F_1);i++;
  pAI1[i] -> _KD1(_T653P01,_T653P01OKD,_T653P01KRS,_T653P01K1N,_T653P01K2N,_T653P01DV,
  _T653P01MN,_T653P01MX,_T653P01SBRN,_T653P01R,_T653P01F,_T653P01ZZ,_T653P01F_1);i++;
  pAI1[i] -> _KD1(_TH12T152,_TH12T152OKD,_TH12T152KRS,_TH12T152K1N,_TH12T152K1N,_TH12T152DV,
  _TH12T152MN,_TH12T152MX,_TH12T152SBRN,_TH12T152R,_TH12T152F,_TH12T152ZZ,_TH12T152F_1);i++;
 i=0;
pAI2[i] -> _KD2(_T117B02R,_T117B03R,_T117B0OKD,_T117B0KRS,_T117B0DEL,
   _T117B02F,_T117B03F,_T117B0SBRN,_T117B0R,_T117B0F,_T117B0ZZ);i++;
 i=0;
};