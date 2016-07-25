//Инициализация и удаление объектов
#ifndef uObjectH
#define uObjectH

#include "usertype.h"
#include "uclasses.h"

extern _TMNMRI *_TK13_MRI;
extern _TMNMRI *_TH13S15_MRI;
extern _TMNMRI *_RL52_MRI;
extern _TMNMRI *_TH13S18_MRI;
extern _TMNMRI *_RA12_MRI;
extern _TMNMRI *_TP60_MRI;
extern _TKPIM *_RA12_KPIM;
extern _TKPIM *_TP60S05_KPIM;
extern _TKPIM *_TK13_KPIM;
extern _TKPIM *_TH13S15_KPIM;
extern _TKPIM *_RL52_KPIM;
extern _TKPIM *_TH13S18_KPIM;
extern _TAF *_TH13S15_AF;
extern _TAF *_D14MC2_76_AF;
extern _TAF *_TH13S18_AF;
extern _TAF *_D14MC2_79_AF;
extern _TAF *_TK13J02_AF;
extern _TAF *_YA12T767_AF;
extern _TAF *_YA12T779_AF;
extern _TAF *_RL52S03_AF;
extern _TAF *_T118B0_AF;
extern _TAF *_RA12S04_AF;
extern _TAF *_TP60S05_AF;
extern _TAF *_T073B03_AF;
extern _TAF *_Y067B20_AF;
extern _TAF *_TH13T154_AF;
extern _TAF *_T651P01_AF;
extern _TOffDelay *_TH13_OffD;
extern _TOffDelay *_TK13_OffD;
extern _TOffDelay *_RA12_OffD;
extern _TOffDelay *_RL52_OffD;
extern _TSTrigger *_TH15_Str;
extern _TLVR *_TH13S15_LVR;
extern _TOnDelay *_TH13_OnD;
extern _TSTrigger *_TH18_Str;
extern _TLVR *_TH13S18_LVR;
extern _TOnDelay *_TH13_OnD2;
extern _TLFUKN *_TH13_LFU;
extern _TButtonState *_TH13BUT;
extern _TAR1 *_TH13S15_AR;
extern _TMIMKD *_TH13S15_MIM;
extern _TAR1 *_TH13S18_AR;
extern _TMIMKD *_TH13S18_MIM;
extern _TSTrigger *_TK13_Str1;
extern _TLVR *_TK13_LVR;
extern _TLFUKN *_TK13_LFU;
extern _TLFUKN *_TK13_LFUS;
extern _TSTrigger *_TK13_STr;
extern _TOnDelay *_TK13_OnD;
extern _TOnDelay *_TK13_OnD2;
extern _TSR1 *_TK13_SR;
extern _TAR1 *_TK13_AR;
extern _TMinHyst *_TK13_MH;
extern _TMIMKD *_TK13_MIM;
extern _TSTrigger *_RA12_Str;
extern _TLVR *_RA12_LVR;
extern _TLFUKN *_RA12_LFU;
extern _TMinHyst *_RA12_MnH;
extern _TButtonState *_RA12_BtSt;
extern _TMaxHyst *_RA12_MxH2;
extern _TAR1 *_RA12_AR;
extern _TMIMKD *_RA12_MIM;
extern _TETrigger *_RA12OT_Etr;
extern _TSTrigger *_RA12_STr1;
extern _TSPulse *_RA12_SPls;
extern _TSTrigger *_RL52_Str1;
extern _TLVR *_RL52_LVR;
extern _TLFUKN *_RL52_LFU;
extern _TSTrigger *_RL52_STr2;
extern _TOnDelay *_RL52_OnD;
extern _TSPulse *_RL52_SP;
extern _TSTrigger *_RL52_STr;
extern _TSR1 *_RL52_SR;
extern _TMIMKD *_RL52_MIM;
extern _TOCHK *_TK13_OCHK;
extern _TOCHK *_RA12_OCHK;
extern _TOCHK *_RL52_OCHK;
extern _TOCHK *_TH13S15_OCHK;
extern _TOCHK *_TH13S18_OCHK;
extern _TMNMRO *_TK13_MRO;
extern _TMNMRO *_RL52_MRO;
extern _TMNMRO *_TH13S15_MRO;
extern _TMNMRO *_RA12_MRO;
extern _TMNMRO *_TH13S18_MRO;
extern _TMNMRO *_TP60_MRO;

extern void InitObjects();
extern void DeleteObjects();

#endif
