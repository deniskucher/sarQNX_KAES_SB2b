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
  extern _TSPulse1 *Pl_TH13S15F;
  extern _TSPulse1 *Pl_TH13S18F;
  extern _TSPulse1 *Pl_TK13J02F;
  extern _TSPulse1 *Pl_RA12S04F;
  extern _TSPulse1 *Pl_RL52S03F;
  extern _TSPulse1 *Pl_Y067B20F;
  extern _TSPulse1 *Pl_T073B03F;
  extern _TSPulse1 *Pl_T118B03F;
  extern _TSPulse1 *Pl_T118B02F;
  extern _TSPulse1 *Pl_D14MC2_79F;
  extern _TSPulse1 *Pl_D14MC2_86F;
  extern _TSPulse1 *Pl_YA12T767F;
  extern _TSPulse1 *Pl_TH13T151F;
  extern _TSPulse1 *Pl_TP60S05F;
  extern _TSPulse1 *Pl_T651P01F;
  extern _TSPulse1 *Pl_YA12T779F;
  extern _TSPulse1 *Pl_T118B0F;
/////////// NES //////////////
  extern _TSPulse1 *Pl_TK13J02NES;
  extern _TSPulse1 *Pl_RL52S03NES;
  extern _TSPulse1 *Pl_RA12S04NES;
  extern _TSPulse1 *Pl_TH13S15NES;
  extern _TSPulse1 *Pl_TH13S18NES;
/////////// NBRU /////////////
  extern _TSPulse1 *Pl_TK13J02NBRU;
  extern _TSPulse1 *Pl_RL52S03NBRU;
  extern _TSPulse1 *Pl_TH13S18NBRU;
  extern _TSPulse1 *Pl_RA12S04NBRU;
  extern _TSPulse1 *Pl_TH13S15NBRU;
/////////// NP ///////////////
  extern _TSPulse1 *Pl_TH13S15NP;
  extern _TSPulse1 *Pl_TH13S18NP;
  extern _TSPulse1 *Pl_TK13J02NP;
  extern _TSPulse1 *Pl_RA12S04NP;
  extern _TSPulse1 *Pl_RL52S03NP;
  extern _TSPulse1 *Pl_TP60S05NP;
/////////// NSTH //////////////
/////////// NSSH //////////////
/////////// ZS ///////////////
  extern _TSPulse1 *Pl_TK13J02ZS;
  extern _TSPulse1 *Pl_RL52S03ZS;
  extern _TSPulse1 *Pl_RA12S04ZS;
  extern _TSPulse1 *Pl_TH13S15ZS;
  extern _TSPulse1 *Pl_TH13S18ZS;
/////////// IS_GEN_ERR ///////
extern _TSPulse1 *Pl_IS_GEN_ERR;
extern void InitPulse();
extern void Vizov();
extern void Naladka();
#endif
