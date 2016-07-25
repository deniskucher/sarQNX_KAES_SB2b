#include "uclasses.h"
//__________________________________ TMR_MRO __________________________________

_TMR_MRO::_TMR_MRO()
{
}

_TMR_MRO::~_TMR_MRO()
{
}

smallint _TMR_MRO::_MR_MRO(const bool SO_SR1, const bool SZ_SG1, 
  const bool A03_A01, const bool A04_A02, const bool VH1VU, const bool VH2VU, 
  const bool DUPRVU, const bool DUUBVU, const bool BRAKMR, const bool VUH1D, 
  const bool VUH2D, const bool REZ1_SR, const bool REZ2_SG, const bool SADF, 
  const bool SA1F, const bool SA2F)
{
  /*Тело метода*/
   smallint outb;
 // Упаковка сигнала LBDMRО
  outb = 0;
  if (SO_SR1) outb = outb | 0x01;
  if (SZ_SG1) outb = outb | 0x02;
  if (A03_A01) outb = outb | 0x04;
  if (A04_A02) outb = outb | 0x08;
  if (VH1VU) outb = outb | 0x10;
  if (VH2VU) outb = outb | 0x20;
  if (DUPRVU) outb = outb | 0x40;
  if (DUUBVU) outb = outb | 0x80;
  if (BRAKMR) outb = outb | 0x100;
  if (VUH1D) outb = outb | 0x200;
  if (VUH2D) outb = outb | 0x400;
  if (REZ1_SR) outb = outb | 0x800;
  if (REZ2_SG) outb = outb | 0x1000;
  if (SADF) outb = outb | 0x2000;
  if (SA1F) outb = outb | 0x4000;
  if (SA2F) outb = outb | 0x8000;
  return outb;
}  /*_TMR_MRO::_MR_MRO*/

//__________________________________ TETrigger __________________________________

_TETrigger::_TETrigger()
{
  St = false;
}

_TETrigger::~_TETrigger()
{
}

void _TETrigger::_ETrigger(const bool S, const bool R, bool &_1, bool &_0)
{
  /*Тело метода*/
   if (S ^ R)
    St = St && (!R) || S;
  _1 = St;
  _0 = !St;
}  /*_TETrigger::_ETrigger*/


//__________________________________ TLFI_MR __________________________________

_TLFI_MR::_TLFI_MR()
{
  Tr_RHU = new _TETrigger();
}

_TLFI_MR::~_TLFI_MR()
{
}

void _TLFI_MR::_LFI_MR(bool B02, bool B01, bool SA2B, bool SA1B, bool SA1R, bool SA2R, bool RHU, bool BHU, 
  bool SA3, bool SA4, bool B05, bool B06, bool P_MUFT, bool P_KBR, bool &NP, bool &OTK, bool &ZAK, bool &MOTK, 
  bool &MZAK, bool &KOO, bool &KOZ, bool &R_HU)
{
  bool _1_R = false;
  bool _3_R = false;
  bool _2_R = false;
  bool _4_R = false;
  bool _5_R = false;
  bool _6_R = false;
  bool _11_R = false;
  bool _7_R = false;
  bool _12_R = false;
  bool _10_R = false;
  bool _8_R = false;
  bool _17_R = false;
  bool _19_R = false;
  bool _18_R = false;
  bool _9_R = false;
  bool _16_R = false;
  bool _15_R = false;
  bool _13_R = false;
  bool _14_R = false;
  bool _0_1 = false;
  bool _0_0 = false;
  bool _20_R = false;
  bool _22_R = false;
  bool _23_R = false;
  bool _21_R = false;
  bool _24_R = false;
  bool _25_R = false;
  bool _27_R = false;
  bool _26_R = false;

  _1_R =  ! B01;
  _3_R =  ! B02;
  _2_R = _1_R && _3_R;
  NP = _2_R;
  _4_R = _3_R && B01;
  OTK = _4_R;
  _5_R = _1_R && B02;
  ZAK = _5_R;
  _6_R =  ! B06;
  _11_R =  ! B05;
  _7_R = _6_R && _11_R;
  _12_R = _11_R && B06;
  _10_R = _7_R || _12_R;
  _8_R = P_MUFT && _10_R;
  _17_R =  ! P_MUFT;
  _19_R =  ! B05;
  _18_R = _17_R && _19_R && P_KBR;
  _9_R = _8_R || _18_R;
  MOTK = _9_R;
  _16_R = _6_R && B05;
  _15_R = _7_R || _16_R;
  _13_R = P_MUFT && _15_R;
  _14_R = _13_R || _18_R;
  MZAK = _14_R;
  Tr_RHU->_ETrigger(RHU,BHU,_0_1,_0_0);
  R_HU = _0_1;
  _20_R = SA1R && _0_1;
  _22_R = SA1B || SA3;
  _23_R = _22_R && _0_0;
  _21_R = _20_R || _23_R;
  KOO = _21_R;
  _24_R = SA2B || SA4;
  _25_R = _24_R && _0_0;
  _27_R = _0_1 && SA2R;
  _26_R = _25_R || _27_R;
  KOZ = _26_R;
}

//__________________________________ TPulsator __________________________________

_TPulsator::_TPulsator()
{
  Count = 0;
  Phase = true;
}

_TPulsator::~_TPulsator()
{
}

bool _TPulsator::_Pulsator(const bool Start, const smallint Tu,
  const smallint Tn, const bool PhSel)
{
  /*Тело метода*/
   if ((Tu == 0) || (Tn == 0))
    {
      Count = 0;
      Phase = true;
      return false;
    }
     if (Start)
      {
        if (Phase ^ PhSel)
         {
          if (Count < Tu) Count++;
           else
            { Phase = !Phase;
              Count = 1;
            }
          }
       else
        {
	if (Count < Tn)  Count++;
        else
          {  Phase = !Phase;
             Count = 1;
           }
        }
  return Phase ^ PhSel;
     } //if (start)=1
  else
    { Count = 0;
      Phase = true;
      return false;
    }
}  /*_TPulsator::_Pulsator*/

//__________________________________ TOffDelay __________________________________

_TOffDelay::_TOffDelay()
{
  Count = 0;
  OldA = false;
}

_TOffDelay::~_TOffDelay()
{
}

bool _TOffDelay::_OffDelay(const bool Decey, const smallint T)
{
  /*Тело метода*/
  bool OffDelay1;
  if ((!Decey) && OldA)
  {
    Count++;
     OffDelay1 = true;
     if (Count > T)
     {
         Count = 0;
         OffDelay1 = false;
     }
  }
  else
  {
    if (Decey) Count = 0;
    if (Count > 0)
    {
        Count++;
        if (Count > T)
        {
            Count = 0;
            OffDelay1 = false;
        }
        else   OffDelay1 = true;
    }
    else OffDelay1 = Decey;
  }
  OldA = Decey;
  return OffDelay1;
}  /*_TOffDelay::_OffDelay*/

//__________________________________ TSPulse __________________________________

_TSPulse::_TSPulse()
{
  Count = 0;
  OldA = false;
}

_TSPulse::~_TSPulse()
{
}

bool _TSPulse::_SPulse(const bool Front, const smallint T)
{
  /*Тело метода*/
   if (Front && !OldA)
    Count = 1;
  if (Count > T)
    Count = 0;
  OldA = Front;
  if (Count > 0)
  {
      Count ++;
      return true;
  }
  else return false;
}  /*_TSPulse::_SPulse*/

//__________________________________ TSTrigger __________________________________

_TSTrigger::_TSTrigger()
{
  St = false;
}

_TSTrigger::~_TSTrigger()
{
}

void _TSTrigger::_STrigger(const bool S, const bool R, bool &_1, bool &_0)
{
  /*Тело метода*/
   St = St && (!R) || S;
   _1 = St;
   _0 = !St;
}  /*_TSTrigger::_STrigger*/


//__________________________________ TLURK __________________________________

_TLURK::_TLURK()
{
  SR_Puls = new _TPulsator();
  Tr_TZO = new _TETrigger();
  Tr_TZZ = new _TETrigger();
  PRTZO = false;
  PRTZZ = false;
  Off_O = new _TOffDelay();
  Off_Z = new _TOffDelay();
  Sp_pauz = new _TSPulse();
  NZKO = false;
  NZKZ = false;
  NZVK = false;
  Lurk_Str = new _TSTrigger();
}

_TLURK::~_TLURK()
{
}

void _TLURK::_LURK(bool NP, bool OTK, bool ZAK, bool MOTK, bool MZAK, bool KOO, bool KOZ, bool R_HU, bool 
  TZO, bool TZZ, bool SAC, bool SAD, bool ZBO, bool ZBZ, bool ZO, bool ZZ, bool BLO, bool BLZ, bool OTKR, bool 
  ZAKR, bool REM, bool AVT, bool PRSINH, bool OBMEN, bool P_RKDU, bool &OTKRK, bool &ZAKRK, bool &SG)
{
  bool _12_R = false;
  bool _13_R = false;
  bool _R_Upr = false;  //  //Разрешение управления
  bool _32_R = false;
  bool _30_R = false;
  bool _17_R = false;
  bool _21_R = false;
  bool _27_R = false;
  bool _26_R = false;
  bool _25_R = false;
  bool _18_R = false;
  bool _2_1 = false;
  bool _2_0 = false;
  bool _35_R = false;
  bool _22_R = false;
  bool _20_R = false;
  bool _29_R = false;
  bool _28_R = false;
  bool _23_R = false;
  bool _3_1 = false;
  bool _3_0 = false;
  bool _24_R = false;
  bool _notTZZ = false;
  bool _41_R = false;
  bool _36_R = false;
  bool _ZB_O = false;
  bool _54_R = false;
  bool _8_R = false;
  bool _7_R = false;
  bool _notRM_RH = false;
  bool _48_R = false;
  bool _Z_O = false;
  bool _51_R = false;
  bool _notZO = false;
  bool _42_R = false;
  bool _19_R = false;
  bool _notTZO = false;
  bool _44_R = false;
  bool _ZB_Z = false;
  bool _43_R = false;
  bool _notZBZ = false;
  bool _56_R = false;
  bool _62_R = false;
  bool _55_R = false;
  bool _KO_O = false;
  bool _52_R = false;
  bool _Z_Z = false;
  bool _53_R = false;
  bool _notZZ = false;
  bool _40_R = false;
  bool _notZBO = false;
  bool _60_R = false;
  bool _58_R = false;
  bool _59_R = false;
  bool _KO_Z = false;
  bool _61_R = false;
  bool _notKOZ = false;
  bool _63_R = false;
  bool _67_R = false;
  bool _64_R = false;
  bool _BL_O = false;  //  //открыть РК по блокировке
  bool _66_R = false;
  bool _57_R = false;
  bool _notKOO = false;
  bool _69_R = false;
  bool _68_R = false;
  bool _BL_Z = false;  //  //закрыть РК по блокировке
  bool _70_R = false;
  bool _notBLZ = false;
  bool _71_R = false;
  bool _OTK_R = false;  //  //открыть РК от регулятора
  bool _34_R = false;
  bool _33_R = false;
  bool _4Out = false;
  bool _31_R = false;
  bool _65_R = false;
  bool _notBLO = false;
  bool _72_R = false;
  bool _ZAK_R = false;  //  //закрыть РК от регулятора 
  bool _46_R = false;
  bool _50_R = false;
  bool _49_R = false;
  bool _45_R = false;
  bool _39_R = false;
  bool _37_R = false;
  bool _5Out = false;
  bool _38_R = false;
  bool _6Out = false;
  bool _47_R = false;
  bool _0_1 = false;
  bool _0_0 = false;
  bool _9_R = false;
  bool _10_R = false;
  bool _15_R = false;
  bool _14_R = false;
  bool _16_R = false;
  bool _1Out = false;
  bool _11_R = false;

  _12_R =  ! NP;
  _13_R = _12_R && PRSINH;
  _R_Upr = _13_R;
  _R_Upr = _R_Upr;
  _R_Upr = _R_Upr;
  _32_R = OTK || MOTK;
  _30_R =  ! _32_R;
  _17_R =  ! PRTZZ;
  _21_R =  ! TZZ;
  _27_R = REM || NP || R_HU;
  _26_R = OTK || MOTK || _27_R;
  _25_R =  ! _26_R;
  _18_R = _17_R && TZO && _21_R && _25_R;
  Tr_TZO->_ETrigger(_18_R,_26_R,_2_1,_2_0);
  PRTZO = _2_1;
  PRTZO = PRTZO;
  _35_R =  ! REM;
  _22_R =  ! PRTZO;
  _20_R =  ! TZO;
  _29_R = _27_R || ZAK || MZAK;
  _28_R =  ! _29_R;
  _23_R = _22_R && _20_R && TZZ && _28_R;
  Tr_TZZ->_ETrigger(_23_R,_29_R,_3_1,_3_0);
  PRTZZ = _3_1;
  PRTZZ = PRTZZ;
  _24_R = _3_0 && _21_R;
  _notTZZ = _24_R;
  _notTZZ = _notTZZ;
  _notTZZ = _notTZZ;
  _41_R =  ! ZBZ;
  _36_R = _35_R && _notTZZ && ZBO && _41_R;
  _ZB_O = _36_R;
  _ZB_O = _ZB_O;
  _54_R =  ! AVT;
  _8_R = REM || R_HU;
  _7_R =  ! _8_R;
  _notRM_RH = _7_R;
  _notRM_RH = _notRM_RH;
  _notRM_RH = _notRM_RH;
  _48_R = ZO && _notRM_RH;
  _Z_O = _48_R;
  _51_R =  ! _48_R;
  _notZO = _51_R;
  _notZO = _notZO;
  _42_R =  ! ZBO;
  _19_R = _2_0 && _20_R;
  _notTZO = _19_R;
  _notTZO = _notTZO;
  _notTZO = _notTZO;
  _44_R = _42_R && ZBZ && _notTZO && _35_R;
  _ZB_Z = _44_R;
  _ZB_Z = _ZB_Z;
  _43_R =  ! _44_R;
  _notZBZ = _43_R;
  _notZBZ = _notZBZ;
  _56_R = _notZO && _notZBZ && _notTZZ;
  _62_R =  ! KOZ;
  _55_R = _54_R && _56_R && KOO && _62_R;
  _KO_O = _55_R;
  _KO_O = _KO_O;
  _52_R = _notRM_RH && ZZ;
  _Z_Z = _52_R;
  _53_R =  ! _52_R;
  _notZZ = _53_R;
  _notZZ = _notZZ;
  _40_R =  ! _36_R;
  _notZBO = _40_R;
  _notZBO = _notZBO;
  _60_R = _notZZ && _notZBO && _notTZO;
  _58_R =  ! KOO;
  _59_R = _54_R && _60_R && KOZ && _58_R;
  _KO_Z = _59_R;
  _KO_Z = _KO_Z;
  _61_R =  ! _59_R;
  _notKOZ = _61_R;
  _notKOZ = _notKOZ;
  _63_R = _56_R && _notKOZ && _notRM_RH;
  _67_R =  ! BLZ;
  _64_R = _63_R && BLO && _67_R;
  _BL_O = _64_R;
  _BL_O = _BL_O;
  _66_R =  ! BLO;
  _57_R =  ! _55_R;
  _notKOO = _57_R;
  _notKOO = _notKOO;
  _69_R = _notRM_RH && _notKOO && _60_R;
  _68_R = _66_R && BLZ && _69_R;
  _BL_Z = _68_R;
  _BL_Z = _BL_Z;
  _70_R =  ! _68_R;
  _notBLZ = _70_R;
  _notBLZ = _notBLZ;
  _71_R = _notBLZ && _63_R && OTKR && AVT;
  _OTK_R = _71_R;
  _OTK_R = _OTK_R;
  _34_R = PRTZO || _ZB_O || _KO_O || _BL_O || _OTK_R;
  _33_R = _R_Upr && _30_R && _34_R && NZKO && NZVK;
  OTKRK = _33_R;
  _4Out = Off_O->_OffDelay(_33_R,2);
  _31_R =  ! _4Out;
  NZKZ = _31_R;
  _65_R =  ! _64_R;
  _notBLO = _65_R;
  _notBLO = _notBLO;
  _72_R = AVT && _notBLO && _69_R && ZAKR;
  _ZAK_R = _72_R;
  _ZAK_R = _ZAK_R;
  _46_R = PRTZZ || _ZB_Z || _KO_Z || _BL_Z || _ZAK_R;
  _50_R = ZAK || MZAK;
  _49_R =  ! _50_R;
  _45_R = _R_Upr && _46_R && _49_R && NZKZ && NZVK;
  ZAKRK = _45_R;
  _39_R = _33_R || _45_R;
  _37_R =  ! _39_R;
  _5Out = Sp_pauz->_SPulse(_37_R,20);
  _38_R =  ! _5Out;
  NZVK = _38_R;
  _6Out = Off_Z->_OffDelay(_45_R,2);
  _47_R =  ! _6Out;
  NZKO = _47_R;
  Lurk_Str->_STrigger(SAC,SAD,_0_1,_0_0);
  _9_R = _0_0 || P_RKDU;
  _10_R = _9_R && _R_Upr;
  _15_R = OBMEN || P_RKDU || _0_0;
  _14_R =  ! _15_R;
  _16_R = _14_R && _R_Upr;
  _1Out = SR_Puls->_Pulsator(_16_R,50,50,false);
  _11_R = _10_R || _1Out;
  SG = _11_R;
}

//__________________________________ TFVZ __________________________________

_TFVZ::_TFVZ()
{
}

_TFVZ::~_TFVZ()
{
}

void _B1TO8(const byte INB, bool &OUT1, bool &OUT2, bool &OUT3, bool &OUT4, 
  bool &OUT5, bool &OUT6, bool &OUT7, bool &OUT8)
{
  /*Тело процедуры*/
  OUT1 = (INB & 1)   != 0;
  OUT2 = (INB & 2)   != 0;
  OUT3 = (INB & 4)   != 0;
  OUT4 = (INB & 8)   != 0;
  OUT5 = (INB & 16)  != 0;
  OUT6 = (INB & 32)  != 0;
  OUT7 = (INB & 64)  != 0;
  OUT8 = (INB & 128) != 0;
}  /*_B1TO8*/
  

void _TFVZ::_FVZ(bool B01, bool B02, bool OTK, bool ZAK, byte P_4B, byte P_5B, bool &REZ1D, bool &REZ2D, bool 
  &REZ3D, bool &REZ4D)
{
  bool _0OUT1 = false;
  bool _0OUT2 = false;
  bool _0OUT3 = false;
  bool _0OUT4 = false;
  bool _0OUT5 = false;
  bool _0OUT6 = false;
  bool _0OUT7 = false;
  bool _0OUT8 = false;
  bool _2_R = false;
  bool _4_R = false;
  bool _8_R = false;
  bool _10_R = false;
  bool _12_R = false;
  bool _14_R = false;
  bool _5_R = false;
  bool _1OUT1 = false;
  bool _1OUT2 = false;
  bool _1OUT3 = false;
  bool _1OUT4 = false;
  bool _1OUT5 = false;
  bool _1OUT6 = false;
  bool _1OUT7 = false;
  bool _1OUT8 = false;
  bool _3_R = false;
  bool _6_R = false;
  bool _9_R = false;
  bool _11_R = false;
  bool _13_R = false;
  bool _15_R = false;
  bool _7_R = false;
  bool _16_R = false;
  bool _18_R = false;
  bool _22_R = false;
  bool _24_R = false;
  bool _26_R = false;
  bool _28_R = false;
  bool _19_R = false;
  bool _17_R = false;
  bool _20_R = false;
  bool _23_R = false;
  bool _25_R = false;
  bool _27_R = false;
  bool _29_R = false;
  bool _21_R = false;

  _B1TO8(P_4B,_0OUT1,_0OUT2,_0OUT3,_0OUT4,_0OUT5,_0OUT6,_0OUT7,_0OUT8);
  _2_R =  ! _0OUT3;
  _4_R = _2_R && OTK && _0OUT1;
  _8_R = _0OUT2 && ZAK;
  _10_R =  ! _0OUT1;
  _12_R = _10_R && B02 && _0OUT3;
  _14_R = _0OUT3 && _0OUT1 && B01;
  _5_R = _4_R || _8_R || _12_R || _14_R;
  REZ1D = _5_R;
  _B1TO8(P_5B,_1OUT1,_1OUT2,_1OUT3,_1OUT4,_1OUT5,_1OUT6,_1OUT7,_1OUT8);
  _3_R =  ! _1OUT3;
  _6_R = _3_R && OTK && _1OUT1;
  _9_R = _1OUT2 && ZAK;
  _11_R =  ! _1OUT1;
  _13_R = _11_R && B02 && _1OUT3;
  _15_R = _1OUT3 && _1OUT1 && B01;
  _7_R = _6_R || _9_R || _13_R || _15_R;
  REZ3D = _7_R;
  _16_R =  ! _0OUT7;
  _18_R = _16_R && OTK && _0OUT5;
  _22_R = _0OUT6 && ZAK;
  _24_R =  ! _0OUT5;
  _26_R = _24_R && B02 && _0OUT7;
  _28_R = _0OUT7 && _0OUT5 && B01;
  _19_R = _18_R || _22_R || _26_R || _28_R;
  REZ2D = _19_R;
  _17_R =  ! _1OUT7;
  _20_R = _17_R && OTK && _1OUT5;
  _23_R = _1OUT6 && ZAK;
  _25_R =  ! _1OUT5;
  _27_R = _25_R && B02 && _1OUT7;
  _29_R = _1OUT7 && _1OUT5 && B01;
  _21_R = _20_R || _23_R || _27_R || _29_R;
  REZ4D = _21_R;
}

//__________________________________ TLFSVU __________________________________

_TLFSVU::_TLFSVU()
{
  Of_SA1 = new _TOffDelay();
  Of_SA2 = new _TOffDelay();
  Of_VH1 = new _TOffDelay();
  Of_VH2 = new _TOffDelay();
}

_TLFSVU::~_TLFSVU()
{
}

void _TLFSVU::_LFSVU(bool SA1B, bool SA2B, bool TZO, bool TZZ, bool &SA1VU, bool &SA2VU, bool &TZOVU, bool 
  &TZZVU)
{
  bool _0Out = false;
  bool _1Out = false;
  bool _2Out = false;
  bool _3Out = false;

  _0Out = Of_SA1->_OffDelay(SA1B,50);
  SA1VU = _0Out;
  _1Out = Of_SA2->_OffDelay(SA2B,50);
  SA2VU = _1Out;
  _2Out = Of_VH1->_OffDelay(TZO,50);
  TZOVU = _2Out;
  _3Out = Of_VH2->_OffDelay(TZZ,50);
  TZZVU = _3Out;
}

//__________________________________ TMR_009 __________________________________

_TMR_009::_TMR_009()
{
  LFI_SB = new _TLFI_MR();
  LURK_SB = new _TLURK();
  FVZ_SB = new _TFVZ();
  LFSVU1 = new _TLFSVU();
}

_TMR_009::~_TMR_009()
{
}

void _TMR_009::_MR_009(bool B02, bool B01, bool SA2B, bool SA1B, bool TZO, bool TZZ, bool SAC, bool SAD, bool 
  SA1R, bool SA2R, bool RHU, bool BHU, bool SA3, bool SA4, bool B05, bool B06, bool ZBO, bool ZBZ, bool ZO, 
  bool ZZ, bool BLO, bool BLZ, bool OTKR, bool ZAKR, bool REM, bool AVT, bool OBMEN, bool PRSINH, bool P_RKDU, 
  bool P_KBR, bool P_MUFT, byte P_4B, byte P_5B, bool &A03, bool &A04, bool &TZOVU, bool &TZZVU, bool &SA1VU, 
  bool &SA2VU, bool &SG, bool &REZ1D, bool &REZ2D, bool &REZ3D, bool &REZ4D)
{
  bool _0NP = false;
  bool _0OTK = false;
  bool _0ZAK = false;
  bool _0MOTK = false;
  bool _0MZAK = false;
  bool _0KOO = false;
  bool _0KOZ = false;
  bool _0R_HU = false;
  bool _1OTKRK = false;
  bool _1ZAKRK = false;
  bool _1SG = false;
  bool _2REZ1D = false;
  bool _2REZ2D = false;
  bool _2REZ3D = false;
  bool _2REZ4D = false;
  bool _3SA1VU = false;
  bool _3SA2VU = false;
  bool _3TZOVU = false;
  bool _3TZZVU = false;

  LFI_SB->_LFI_MR(B02,B01,SA2B,SA1B,SA1R,SA2R,RHU,BHU,SA3,SA4,B05,B06,P_MUFT,P_KBR,_0NP,_0OTK,_0ZAK,_0MOTK,
    _0MZAK,_0KOO,_0KOZ,_0R_HU);
  LURK_SB->_LURK(_0NP,_0OTK,_0ZAK,_0MOTK,_0MZAK,_0KOO,_0KOZ,_0R_HU,TZO,TZZ,SAC,SAD,ZBO,ZBZ,ZO,ZZ,BLO,BLZ,OTKR,
    ZAKR,REM,AVT,PRSINH,OBMEN,P_RKDU,_1OTKRK,_1ZAKRK,_1SG);
  A03 = _1OTKRK;
  A04 = _1ZAKRK;
  SG = _1SG;
  FVZ_SB->_FVZ(B01,B02,_0OTK,_0ZAK,P_4B,P_5B,_2REZ1D,_2REZ2D,_2REZ3D,_2REZ4D);
  REZ1D = _2REZ1D;
  REZ2D = _2REZ2D;
  REZ3D = _2REZ3D;
  REZ4D = _2REZ4D;
  LFSVU1->_LFSVU(SA1B,SA2B,TZO,TZZ,_3SA1VU,_3SA2VU,_3TZOVU,_3TZZVU);
  SA1VU = _3SA1VU;
  SA2VU = _3SA2VU;
  TZOVU = _3TZOVU;
  TZZVU = _3TZZVU;
}

//__________________________________ TMR_MRI __________________________________

_TMR_MRI::_TMR_MRI()
{
}

_TMR_MRI::~_TMR_MRI()
{
}

void _TMR_MRI::_MR_MRI(const smallint LBDMRI, bool &ZBPR, bool &ZBUB, 
  bool &ZO, bool &ZZ, bool &BPR, bool &BUB, bool &LOGPR, bool &LOGUB, 
  bool &VH1, bool &VH2, bool &VH3, bool &VH4, bool &REM, bool &AVT, 
  bool &ZVK, bool &ZS)
{
  /*Тело метода*/
  //      Распаковка сигнала LBDMRI

  ZBPR = (LBDMRI & 0x01) !=  0;
  ZBUB = (LBDMRI & 0x02) !=  0;
  ZO = (LBDMRI & 0x04)!= 0;
  ZZ = (LBDMRI & 0x08)!= 0;
  BPR = (LBDMRI & 0x10)!= 0;
  BUB = (LBDMRI & 0x20)!= 0;
  LOGPR = (LBDMRI & 0x40)!= 0;
  LOGUB = (LBDMRI & 0x80) != 0;
  VH1 = (LBDMRI & 0x100)!= 0;
  VH2 = (LBDMRI & 0x200)!= 0;
  VH3 = (LBDMRI & 0x400)!= 0;
  VH4 = (LBDMRI & 0x800)!= 0;
  REM = (LBDMRI & 0x1000) != 0;
  AVT = (LBDMRI & 0x2000)!= 0;
  ZVK = (LBDMRI & 0x4000)!= 0;
  ZS = (LBDMRI & 0x8000)!= 0;
}  /*_TMR_MRI::_MR_MRI*/

