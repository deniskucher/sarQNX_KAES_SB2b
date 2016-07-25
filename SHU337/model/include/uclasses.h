#ifndef uclassesH
#define uclassesH
#include "usertype.h"

void _B1TO8(const byte INB, bool &OUT1, bool &OUT2, bool &OUT3, bool &OUT4, 
  bool &OUT5, bool &OUT6, bool &OUT7, bool &OUT8);

//__________________________________ TMR_MRO __________________________________

class _TMR_MRO
{
public:
  _TMR_MRO();
  ~_TMR_MRO();
  smallint _MR_MRO(const bool SO_SR1, const bool SZ_SG1, 
  const bool A03_A01, const bool A04_A02, const bool VH1VU, const bool VH2VU, 
  const bool DUPRVU, const bool DUUBVU, const bool BRAKMR, const bool VUH1D, 
  const bool VUH2D, const bool REZ1_SR, const bool REZ2_SG, const bool SADF, 
  const bool SA1F, const bool SA2F);
};
//__________________________________ TETrigger __________________________________

class _TETrigger
{
public:
  bool St;
  _TETrigger();
  ~_TETrigger();
  void _ETrigger(const bool S, const bool R, bool &_1, bool &_0);
};
//__________________________________ TLFI_MR __________________________________

class _TLFI_MR
{
public:
  _TETrigger *Tr_RHU;
  _TLFI_MR();
  ~_TLFI_MR();
  void _LFI_MR(bool B02, bool B01, bool SA2B, bool SA1B, bool SA1R, bool SA2R, bool RHU, bool BHU, bool SA3, 
    bool SA4, bool B05, bool B06, bool P_MUFT, bool P_KBR, bool &NP, bool &OTK, bool &ZAK, bool &MOTK, bool 
    &MZAK, bool &KOO, bool &KOZ, bool &R_HU);
};
//__________________________________ TPulsator __________________________________

class _TPulsator
{
public:
  smallint Count;  //Счетчик длительности импульса или паузы
  bool Phase;  //Фаза импульса (true) или паузы (false)
  _TPulsator();
  ~_TPulsator();
  bool _Pulsator(const bool Start, const smallint Tu,
  const smallint Tn, const bool PhSel);
};
//__________________________________ TOffDelay __________________________________

class _TOffDelay
{
public:
  smallint Count;  //Счетчик тактов задержки
  bool OldA;  //Предыдущее значение входа А
  _TOffDelay();
  ~_TOffDelay();
  bool _OffDelay(const bool Decey, const smallint T);
};
//__________________________________ TSPulse __________________________________

class _TSPulse
{
public:
  smallint Count;
  bool OldA;
  _TSPulse();
  ~_TSPulse();
  bool _SPulse(const bool Front, const smallint T);
};
//__________________________________ TSTrigger __________________________________

class _TSTrigger
{
public:
  bool St;
  _TSTrigger();
  ~_TSTrigger();
  void _STrigger(const bool S, const bool R, bool &_1, bool &_0);
};
//__________________________________ TLURK __________________________________

class _TLURK
{
public:
  _TPulsator *SR_Puls;
  _TETrigger *Tr_TZO;
  _TETrigger *Tr_TZZ;
  bool PRTZO;  //Признак TZO
  bool PRTZZ;  //Признак TZZ
  _TOffDelay *Off_O;
  _TOffDelay *Off_Z;
  _TSPulse *Sp_pauz;
  bool NZKO;
  bool NZKZ;
  bool NZVK;
  _TSTrigger *Lurk_Str;
  _TLURK();
  ~_TLURK();
  void _LURK(bool NP, bool OTK, bool ZAK, bool MOTK, bool MZAK, bool KOO, bool KOZ, bool R_HU, bool TZO, bool 
    TZZ, bool SAC, bool SAD, bool ZBO, bool ZBZ, bool ZO, bool ZZ, bool BLO, bool BLZ, bool OTKR, bool ZAKR, bool 
    REM, bool AVT, bool PRSINH, bool OBMEN, bool P_RKDU, bool &OTKRK, bool &ZAKRK, bool &SG);
};
//__________________________________ TFVZ __________________________________

class _TFVZ
{
public:
  _TFVZ();
  ~_TFVZ();
  void _FVZ(bool B01, bool B02, bool OTK, bool ZAK, byte P_4B, byte P_5B, bool &REZ1D, bool &REZ2D, bool 
    &REZ3D, bool &REZ4D);
};
//__________________________________ TLFSVU __________________________________

class _TLFSVU
{
public:
  _TOffDelay *Of_SA1;
  _TOffDelay *Of_SA2;
  _TOffDelay *Of_VH1;
  _TOffDelay *Of_VH2;
  _TLFSVU();
  ~_TLFSVU();
  void _LFSVU(bool SA1B, bool SA2B, bool TZO, bool TZZ, bool &SA1VU, bool &SA2VU, bool &TZOVU, bool &TZZVU);
};
//__________________________________ TMR_009 __________________________________

class _TMR_009
{
public:
  _TLFI_MR *LFI_SB;
  _TLURK *LURK_SB;
  _TFVZ *FVZ_SB;
  _TLFSVU *LFSVU1;
  _TMR_009();
  ~_TMR_009();
  void _MR_009(bool B02, bool B01, bool SA2B, bool SA1B, bool TZO, bool TZZ, bool SAC, bool SAD, bool SA1R, 
    bool SA2R, bool RHU, bool BHU, bool SA3, bool SA4, bool B05, bool B06, bool ZBO, bool ZBZ, bool ZO, bool ZZ, 
    bool BLO, bool BLZ, bool OTKR, bool ZAKR, bool REM, bool AVT, bool OBMEN, bool PRSINH, bool P_RKDU, bool 
    P_KBR, bool P_MUFT, byte P_4B, byte P_5B, bool &A03, bool &A04, bool &TZOVU, bool &TZZVU, bool &SA1VU, bool 
    &SA2VU, bool &SG, bool &REZ1D, bool &REZ2D, bool &REZ3D, bool &REZ4D);
};
//__________________________________ TMR_MRI __________________________________

class _TMR_MRI
{
public:
  _TMR_MRI();
  ~_TMR_MRI();
  void _MR_MRI(const smallint LBDMRI, bool &ZBPR, bool &ZBUB, 
  bool &ZO, bool &ZZ, bool &BPR, bool &BUB, bool &LOGPR, bool &LOGUB, 
  bool &VH1, bool &VH2, bool &VH3, bool &VH4, bool &REM, bool &AVT, 
  bool &ZVK, bool &ZS);
};
#endif
