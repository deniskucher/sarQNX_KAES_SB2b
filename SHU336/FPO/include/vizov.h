//Инициализация и удаление объектов
#ifndef vizovH
#define vizovH
#include "usertype.h"
#include "pulse.h"
#include "DSD.h"
#include "DSA.h"
#include "Signal.h"
extern TBindSignal *Nal;
extern TBindSignal *Gen_Err;
extern TBindSignal *Gen_ErrP;
/////////// F ////////////////
  extern _TSPulse1 *Pl_TK12J02F;
  extern _TSPulse1 *Pl_RA11S04F;
  extern _TSPulse1 *Pl_RL51S03F;
  extern _TSPulse1 *Pl_Y066B20F;
  extern _TSPulse1 *Pl_T072B03F;
  extern _TSPulse1 *Pl_T117B03F;
  extern _TSPulse1 *Pl_T117B02F;
  extern _TSPulse1 *Pl_D14MC1_79F;
  extern _TSPulse1 *Pl_D14MC1_85F;
  extern _TSPulse1 *Pl_T117B0F;
  extern _TSPulse1 *Pl_TH12S15F;
  extern _TSPulse1 *Pl_TH12S18F;
  extern _TSPulse1 *Pl_TP60S07F;
  extern _TSPulse1 *Pl_YA11T766F;
  extern _TSPulse1 *Pl_YA11T778F;
  extern _TSPulse1 *Pl_TH12T152F;
  extern _TSPulse1 *Pl_T653P01F;
/////////// NES //////////////
  extern _TSPulse1 *Pl_TK12J02NES;
  extern _TSPulse1 *Pl_RL51S03NES;
  extern _TSPulse1 *Pl_RA11S04NES;
  extern _TSPulse1 *Pl_TH12S15NES;
  extern _TSPulse1 *Pl_TH12S18NES;
/////////// NBRU /////////////
  extern _TSPulse1 *Pl_TK12J02NBRU;
  extern _TSPulse1 *Pl_TH12S15NBRU;
  extern _TSPulse1 *Pl_RL51S03NBRU;
  extern _TSPulse1 *Pl_RA11S04NBRU;
  extern _TSPulse1 *Pl_TH12S18NBRU;
/////////// NP ///////////////
  extern _TSPulse1 *Pl_TK12J02NP;
  extern _TSPulse1 *Pl_RA11S04NP;
  extern _TSPulse1 *Pl_RL51S03NP;
  extern _TSPulse1 *Pl_TH12S15NP;
  extern _TSPulse1 *Pl_TH12S18NP;
  extern _TSPulse1 *Pl_TP60S07NP;
/////////// NSTH //////////////
/////////// NSSH //////////////
/////////// ZS ///////////////
  extern _TSPulse1 *Pl_TK12J02ZS;
  extern _TSPulse1 *Pl_RL51S03ZS;
  extern _TSPulse1 *Pl_RA11S04ZS;
  extern _TSPulse1 *Pl_TH12S15ZS;
  extern _TSPulse1 *Pl_TH12S18ZS;
/////////// IS_GEN_ERR ///////
extern _TSPulse1 *Pl_IS_GEN_ERR;
extern void InitPulse();
extern void Vizov();
extern void Naladka();
#endif
