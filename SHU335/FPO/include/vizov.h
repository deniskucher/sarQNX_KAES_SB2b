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
  extern _TSPulse1 *Pl_TH11S15F;
  extern _TSPulse1 *Pl_TH11S18F;
  extern _TSPulse1 *Pl_TK11J02F;
  extern _TSPulse1 *Pl_RA13S04F;
  extern _TSPulse1 *Pl_RA14S04F;
  extern _TSPulse1 *Pl_RL53S03F;
  extern _TSPulse1 *Pl_RL54S03F;
  extern _TSPulse1 *Pl_Y065B20F;
  extern _TSPulse1 *Pl_T071B03F;
  extern _TSPulse1 *Pl_T116B03F;
  extern _TSPulse1 *Pl_T116B02F;
  extern _TSPulse1 *Pl_D14MC3_79F;
  extern _TSPulse1 *Pl_D14MC4_79F;
  extern _TSPulse1 *Pl_D14MC3_84F;
  extern _TSPulse1 *Pl_D14MC4_84F;
  extern _TSPulse1 *Pl_YA13T768F;
  extern _TSPulse1 *Pl_TH11T153F;
  extern _TSPulse1 *Pl_T116B0F;
  extern _TSPulse1 *Pl_YA13T780F;
/////////// NES //////////////
  extern _TSPulse1 *Pl_TK11J02NES;
  extern _TSPulse1 *Pl_RL53S03NES;
  extern _TSPulse1 *Pl_RA13S04NES;
  extern _TSPulse1 *Pl_RA14S04NES;
  extern _TSPulse1 *Pl_RL54S03NES;
  extern _TSPulse1 *Pl_TH11S15NES;
  extern _TSPulse1 *Pl_TH11S18NES;
/////////// NBRU /////////////
  extern _TSPulse1 *Pl_TK11J02NBRU;
  extern _TSPulse1 *Pl_RL53S03NBRU;
  extern _TSPulse1 *Pl_RL54S03NBRU;
  extern _TSPulse1 *Pl_RA13S04NBRU;
  extern _TSPulse1 *Pl_RA14S04NBRU;
  extern _TSPulse1 *Pl_TH11S15NBRU;
  extern _TSPulse1 *Pl_TH11S18NBRU;
/////////// NP ///////////////
  extern _TSPulse1 *Pl_TK11J02NP;
  extern _TSPulse1 *Pl_RA13S04NP;
  extern _TSPulse1 *Pl_RA14S04NP;
  extern _TSPulse1 *Pl_RL53S03NP;
  extern _TSPulse1 *Pl_RL54S03NP;
  extern _TSPulse1 *Pl_TH11S15NP;
  extern _TSPulse1 *Pl_TH11S18NP;
/////////// NSTH //////////////
/////////// NSSH //////////////
/////////// ZS ///////////////
  extern _TSPulse1 *Pl_TK11J02ZS;
  extern _TSPulse1 *Pl_RL53S03ZS;
  extern _TSPulse1 *Pl_RA13S04ZS;
  extern _TSPulse1 *Pl_RA14S04ZS;
  extern _TSPulse1 *Pl_RL54S03ZS;
  extern _TSPulse1 *Pl_TH11S15ZS;
  extern _TSPulse1 *Pl_TH11S18ZS;
/////////// IS_GEN_ERR ///////
extern _TSPulse1 *Pl_IS_GEN_ERR;
extern void InitPulse();
extern void Vizov();
extern void Naladka();
#endif
