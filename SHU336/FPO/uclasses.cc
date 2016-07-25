#include "uclasses.h"
//__________________________________ TMNMRI __________________________________

_TMNMRI::_TMNMRI()
{
}

_TMNMRI::~_TMNMRI()
{
}

void _TMNMRI::_MNMRI(const smallint LBDMRI, bool &SO_SR1, bool &SZ_SG1,
  bool &A03_A01, bool &A04_A02, bool &VH1VU, bool &VH2VU, bool &DUPRVU,
  bool &DUUBVU, bool &BRAKMR, bool &VUH1D, bool &VUH2D, bool &REZ1_SR,
  bool &REZ2_SG, bool &SADF, bool &SA1F, bool &SA2F)
{
  /*Тело метода*/
 //bool  A03, A04;
 //      Распаковка сигнала LBDMRI

  SO_SR1 = (LBDMRI & 0x01) !=  0;
  SZ_SG1 = (LBDMRI & 0x02) !=  0;
  A03_A01 = (LBDMRI & 0x04)!= 0;
  A04_A02 = (LBDMRI & 0x08)!= 0;
  VH1VU = (LBDMRI & 0x10)!= 0;
  VH2VU = (LBDMRI & 0x20)!= 0;
  DUPRVU = (LBDMRI & 0x40)!= 0;
  DUUBVU = (LBDMRI & 0x80) != 0;
  BRAKMR = (LBDMRI & 0x100)!= 0;
  VUH1D = (LBDMRI & 0x200)!= 0;
  VUH2D = (LBDMRI & 0x400)!= 0;
  REZ1_SR = (LBDMRI & 0x800)!= 0;
  REZ2_SG = (LBDMRI & 0x1000) != 0;
  SADF = (LBDMRI & 0x2000)!= 0;
  SA1F = (LBDMRI & 0x4000)!= 0;
  SA2F = (LBDMRI & 0x8000)!= 0;

}  /*_TMNMRI::_MNMRI*/


//__________________________________ TSTrigger __________________________________

_TSTrigger::_TSTrigger(bool _0St)
{
  St = _0St;
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


//__________________________________ TKPIM __________________________________

_TKPIM::_TKPIM(bool _0St, bool _1St)
{
  STr1 = new _TSTrigger(_0St);
  STr2 = new _TSTrigger(_1St);
}

_TKPIM::~_TKPIM()
{
}

void _TKPIM::_KPIM_K(bool B02, bool B01, bool &OTK, bool &ZAK, bool &NP)
{
  bool _2_R = false;
  bool _4_R = false;
  bool _3_R = false;
  bool _5_R = false;
  bool _0_1 = false;
  bool _0_0 = false;
  bool _6_R = false;
  bool _1_1 = false;
  bool _1_0 = false;

  _2_R =  ! B02;
  _4_R =  ! B01;
  _3_R = _2_R && _4_R;
  NP = _3_R;
  _5_R = B02 && _4_R;
  STr1->_STrigger(_5_R,B01,_0_1,_0_0);
  ZAK = _0_1;
  _6_R = _2_R && B01;
  STr2->_STrigger(_6_R,B02,_1_1,_1_0);
  OTK = _1_1;
}

//__________________________________ TAF __________________________________

_TAF::_TAF(bool _0PVAPZ, smallint _1RD)
{
  PVAPZ = _0PVAPZ;
  RD = _1RD;
}

_TAF::~_TAF()
{
}

smallint _TAF::_AF(const bool SBRN, const smallint VH, const smallint TF,
  const smallint AMX)
{
     /*Тело метода*/
//такт включения 100 мс
  smallint DELTA;
  int PER;
  if (SBRN)
  {
    RD = VH;
    return RD;
  }
  else
  {
     if (!PVAPZ)
     {
        PVAPZ=true;
        RD = VH;
        return RD;
     }
     PER=VH-RD;
//////////////////////////////
  DELTA = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
//////////////////////////////
     if (abs(DELTA) >= AMX)
     {
	 if (DELTA > 0)  DELTA=AMX;
           else DELTA=-AMX;
     }
        if ((TF <= (0.1*32767/100)) || (abs(DELTA)<=6))
  {
       RD = VH;
       return RD;
     }
 if (abs(smallint((DELTA*0.1/TF)*32767/100)) >1)
     {
      RD = smallint(RD+((float)DELTA*0.1/TF)*32767/100);
       return RD;
     }
     if   (DELTA>0)     RD++;
                  else  RD--;
     return RD;
  }//if (SBRN)
}  /*_TAF::_AF*/


//__________________________________ TOffDelay __________________________________

_TOffDelay::_TOffDelay(smallint _0Count, bool _1OldA)
{
  Count = _0Count;
  OldA = _1OldA;
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

//__________________________________ TLVR __________________________________

_TLVR::_TLVR(bool _0PRSTR, int _1T, int _2T1, bool _3PRM, smallint _4TCLVR, bool _5RAVT, bool _6RLK, bool 
  _7RLZ, bool _8RZS, bool _9RNBRU, bool _10PV, smallint _11SH)
{
  PRSTR = _0PRSTR;
  T = _1T;
  T1 = _2T1;
  PRM = _3PRM;
  TCLVR = _4TCLVR;
  RAVT = _5RAVT;
  RLK = _6RLK;
  RLZ = _7RLZ;
  RZS = _8RZS;
  RNBRU = _9RNBRU;
  PV = _10PV;
  SH = _11SH;
}

_TLVR::~_TLVR()
{
}

void _TLVR::_LVR(const bool BRUAV, const bool BRUDU, const bool ZH,
  const bool ZHBL, const bool OTKD, const bool NPRK, const bool STR,
  const bool REMRK, const smallint Tv, bool &AVT, bool &LK, bool &LZ,
  bool &ZS, bool &NBRU)
{   /*Тело метода*/
  AVT = RAVT;
  LK = RLK;
  LZ = RLZ;
  ZS = RZS;
  NBRU = RNBRU;

  LK = false;
  LZ = false;

  if  (BRUAV ^ BRUDU)
  {
    SH = 0;
    NBRU = false;
  }
  else
    if (SH < 20)
    {
      SH++;
      goto LVR4;
    }
    else
    {
      NBRU = true;
      goto LVR4;
    }

  if (!BRUAV)
  {
    if (BRUDU)
    {
      ZS = false;
      PRSTR = false;
      T = Tv;
      PV = true;

LVR34:
      if (NPRK) goto LVR305;
      else
        if (NBRU) goto MT4;
        else goto LVR30;

     }
     else  goto LVR4;
  }
  if (!PV) ZS = true;
  if (!ZS) AVT = true;
LVR4:
  if (!AVT)
  {
    if (ZS) goto LVR24;
    else  goto LVR34;
  }
  else
     if (REMRK) goto LVR24;

  if (NPRK)
  {
    if (T >= Tv)
         goto LVR24;
    else
         T++;
  }
  else  T = 0;
  if(NBRU || OTKD || ZH || ZHBL)
          goto LVR24;
  if (STR)
  {
    PRSTR = true;
    LZ = true;
    goto LVR23;
  }

  if (!PRSTR)  goto LVR23;

  if (T1>150)
  {
    PRSTR = false;
    goto LVR23;
  }
  else T1++;

  PRM = true;
  goto KLVR;

LVR23:
  PRM = false;
  T1 = 0;
  LK = true;
  goto KLVR;
LVR24:
  ZS = true;
  if (NPRK)  goto LVR305;

MT4:
  PRM = true;
  //LK = true;
  goto LVR31;

LVR30:
  LZ = true;
LVR305:
  PRM = false;
LVR31:
  AVT = false;
  PRSTR = false;
KLVR:
  if (PRM)
  {
     TCLVR++;
     if (TCLVR >= 5)
       if (PRSTR) LK = true;
       else LZ = true;
  }
  if (TCLVR == 10)  TCLVR = 0;

 RAVT = AVT;
 RLK = LK;
 RLZ = LZ;
 RZS = ZS;
 RNBRU = NBRU;


}/*_TLVR::_LVR*/


//__________________________________ TSPulse __________________________________

_TSPulse::_TSPulse(smallint _0Count, bool _1OldA)
{
  Count = _0Count;
  OldA = _1OldA;
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

//__________________________________ TOCDSI __________________________________

_TOCDSI::_TOCDSI(bool _0prin, smallint _1hin, smallint _2hin_n)
{
  prin = _0prin;
  hin = _1hin;
  hin_n = _2hin_n;
}

_TOCDSI::~_TOCDSI()
{
}

smallint _TOCDSI::_OCDSI(const smallint SiIn)
{
  /*Тело метода*/
   if (!prin)
    {
	prin = true;
	hin_n = SiIn;
    }
  hin = hin_n;
  hin_n = SiIn;
  return hin;
}  /*_TOCDSI::_OCDSI*/

//__________________________________ Tintegrator1 __________________________________

_Tintegrator1::_Tintegrator1(float _0Intgr)
{
  Intgr = _0Intgr;
}

_Tintegrator1::~_Tintegrator1()
{
}

smallint _Tintegrator1::_integrator1(const bool RISH, const bool RINT,
  const float VH1, const float VH2, const smallint Ti)
{
  /*Тело метода*/
  float  PER;

  if (RISH)
  {
     Intgr = VH2;
     goto m1;
  }
  if (!RINT)  goto m1;
  if (Ti > 0)
  {
   PER = Intgr + (VH1/Ti);
   Intgr = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
   }
m1:
   return  smallint(Intgr);
}  /*_Tintegrator1::_integrator1*/

//__________________________________ TLFUKN __________________________________

_TLFUKN::_TLFUKN(smallint _0Count, bool _0OldA, bool _1prin, smallint _1hin, smallint _1hin_n, float _2Intgr, 
  bool _3STOPM, bool _4STOPB)
{
  SP = new _TSPulse(_0Count, _0OldA);
  OCD = new _TOCDSI(_1prin, _1hin, _1hin_n);
  INT = new _Tintegrator1(_2Intgr);
  STOPM = _3STOPM;
  STOPB = _4STOPB;
}

_TLFUKN::~_TLFUKN()
{
}

smallint _TLFUKN::_LFUKN(smallint UST, smallint UMIN, smallint UMAX, smallint VUST, bool KNPR, bool KNUB)
{
  bool _0Out = false;
  smallint _1SiOut = 0;
  bool _3_R = false;
  bool _7_R = false;
  bool _6_R = false;
  bool _5_R = false;
  bool _4_R = false;
  bool _14_R = false;
  bool _13_R = false;
  smallint _11_R = 0;
  bool _9_R = false;
  bool _8_R = false;
  smallint _15Res;
  smallint _17Res;
  smallint _2OUT1 = 0;
  bool _10_R = false;
  bool _12_R = false;
  smallint _16Res;
  smallint USTO;

  _0Out = SP->_SPulse(true,3);
  _1SiOut = OCD->_OCDSI(UST);
  _3_R = _1SiOut != UST;
  _7_R = KNUB || KNPR;
  _6_R =  ! _7_R;
  _5_R = _3_R && _6_R;
  _4_R = _0Out || _5_R;
  _14_R =  ! STOPM;
  _13_R = KNUB && _14_R;
  _11_R = VUST * -1;
  _9_R =  ! STOPB;
  _8_R = KNPR && _9_R;
    _15Res = _8_R? VUST : 0;
/*  if (_8_R) _15Res = VUST;
    
       else _15Res = 0; */

    _17Res = _13_R? _11_R : _15Res;
/*  if (_13_R) _17Res = _11_R;
    
       else _17Res = _15Res; */

  _2OUT1 = INT->_integrator1(_4_R,true,_17Res,UST,10);
  _10_R = _2OUT1 < UMIN;
  STOPM = _10_R;
  _12_R = _2OUT1 > UMAX;
  STOPB = _12_R;
  //  {Тело процедуры}
  if (_2OUT1 < UMIN) _16Res = UMIN;
    
    else if (_2OUT1 > UMAX) _16Res = UMAX;
    
           else _16Res = _2OUT1;
//{End of _Lim}

  USTO = _16Res;
  return USTO;
}

//__________________________________ TOnDelay __________________________________

_TOnDelay::_TOnDelay(smallint _0Count, bool _1Pd)
{
  Count = _0Count;
  Pd = _1Pd;
}

_TOnDelay::~_TOnDelay()
{
}

bool _TOnDelay::_OnDelay(const bool Front, const smallint T)
{
  /*Тело метода*/
   if (!Front)
   {
       Count = 0;
       Pd = false;
       return false;
   }
  else
   if ((Count < T) && (!Pd))
   {
         Count++;
         return false;
   }
   else
   {
        Pd = true;
        return true;
   }
}  /*_TOnDelay::_OnDelay*/

//__________________________________ TCOUNT __________________________________

_TCOUNT::_TCOUNT()
{
}

_TCOUNT::~_TCOUNT()
{
}

smallint _TCOUNT::_COUNT(const smallint TC)
{
  /*Тело метода*/
   if (TC < 9)
    return TC+1;
  else
    return 0;

}  /*_TCOUNT::_COUNT*/

//__________________________________ TMinHyst __________________________________

_TMinHyst::_TMinHyst(bool _0old, bool _1prin)
{
  old = _0old;
  prin = _1prin;
}

_TMinHyst::~_TMinHyst()
{
}

bool _TMinHyst::_MinHyst(const smallint CP, const smallint Min,
  const smallint Delta)
{   /*Тело метода*/
  if (!prin)
  {  prin = true;
     old = CP < Min;
  }
  old = old && (CP <= (Min + Delta)) || (CP < Min);
  return old;
}
    //{_TMinHyst._MinHyst}



//__________________________________ TUCounter __________________________________

_TUCounter::_TUCounter(smallint _0CntSt, bool _1Pov)
{
  CntSt = _0CntSt;
  Pov = _1Pov;
}

_TUCounter::~_TUCounter()
{
}

void _TUCounter::_UCounter(const bool Count, const smallint Limit, const bool Reset,
  smallint &Value, bool &Over)
{
  /*Тело метода*/
   if (Reset || (Limit==0))
    {
      CntSt = 0;
      Pov = false;
      Value = 0;
      Over = false;
    }
  else
  {
    if (Count)
      if ((CntSt < Limit) && !Pov) CntSt++;
    Value = CntSt;
     if (Pov) Over = true;
       else
          if (CntSt >= Limit)
             {Pov = true;
              Over = true;
	     }
          else Over = false;
  }

}  /*_TUCounter::_UCounter*/

//__________________________________ TMIMKD_K __________________________________

_TMIMKD_K::_TMIMKD_K(bool _0P_SM, smallint _1NLO_1, smallint _2NLZ_1, smallint _3TH_1, smallint _4TRK_1, 
  smallint _5Count, bool _5OldA, float _6Intgr, smallint _7CntSt, bool _7Pov, smallint _8CntSt, bool _8Pov, 
  bool _9Stop_int, smallint _10CntSt, bool _10Pov)
{
  P_SM = _0P_SM;
  NLO_1 = _1NLO_1;
  NLZ_1 = _2NLZ_1;
  TH_1 = _3TH_1;
  TRK_1 = _4TRK_1;
  Spls1 = new _TSPulse(_5Count, _5OldA);
  Int_SM = new _Tintegrator1(_6Intgr);
  NLO_Cnt = new _TUCounter(_7CntSt, _7Pov);
  NLZ_Cnt = new _TUCounter(_8CntSt, _8Pov);
  Stop_int = _9Stop_int;
  TRK_Cnt = new _TUCounter(_10CntSt, _10Pov);
}

_TMIMKD_K::~_TMIMKD_K()
{
}

float _SmallintToFloat(const smallint X, const float MAX)
{
  /*Тело функции*/
 return ((float)X/32767.0*MAX);
}  /*_SmallintToFloat*/

smallint _FloatToSmallint(const float X, const float MAX)
{
  /*Тело функции*/
  if  (X > MAX) return 32767;
  else
    if (X < -MAX) return -32768;
    else return (smallint(X/MAX*32767));
}  /*_FloatToSmallint*/

smallint _RAZN(const smallint IN1, const smallint IN2)
{
  /*Тело функции*/
  int  per= IN1-IN2;
  if (per >= 32767) return 32767;
  else if (per <= -32767) return -32767;
       else return per;
}  /*_RAZN*/


void _TMIMKD_K::_MIMKD_K(bool AVT, smallint SRK, bool SRKF, bool SRKOKD, bool OTKR, bool ZAKR, smallint NLO, 
  smallint NLZ, smallint DP1, smallint DP2, bool RKOTK, bool RKZAK, smallint TH, smallint TRK, bool SBRN, 
  smallint &SM, bool &RM, bool &NES, smallint &PRK)
{
  float _14_R = 0.0;
  smallint _5Res = 0;
  smallint _15_R = 0;
  float _16_R = 0.0;
  float _17_R = 0.0;
  smallint _18_R = 0;
  float _20_R = 0.0;
  smallint _6Res = 0;
  smallint _19_R = 0;
  float _7Y = 0.0;
  float _21_R = 0.0;
  smallint _8Y = 0;
  bool _22_R = false;
  bool _24_R = false;
  bool _0Out = false;
  bool _26_R = false;
  bool _27_R = false;
  bool _25_R = false;
  bool _23_R = false;
  bool _29_R = false;
  bool _32_R = false;
  smallint _2Value = 0;
  bool _2Over = false;
  bool _30_R = false;
  bool _33_R = false;
  bool _34_R = false;
  bool _36_R = false;
  smallint _3Value = 0;
  bool _3Over = false;
  bool _35_R = false;
  bool _28_R = false;
  smallint _10OUT1 = 0;
  smallint _9Res;
  smallint _1OUT1 = 0;
  bool _31_R = false;
  smallint _11OUT1 = 0;
  smallint _12Res;
  bool _41_R = false;
  bool _43_R = false;
  bool _42_R = false;
  smallint _4Value = 0;
  bool _4Over = false;
  bool _46_R = false;
  bool _47_R = false;
  bool _44_R = false;
  bool _38_R = false;
  bool _37_R = false;
  bool _39_R = false;
  bool _40_R = false;
  bool _48_R = false;
  bool _50_R = false;
  bool _49_R = false;
  bool _45_R = false;
  bool _51_R = false;
  smallint _13Res;

  _14_R = (float)NLO / (float)328;
  /*Тело процедуры*/
  if ((_14_R - floor(_14_R)) > 0.5) _5Res = smallint(ceil(_14_R));
  else _5Res = smallint(floor(_14_R));
  /*End of _Round*/

  _15_R = _5Res + 1;
  NLO_1 = _15_R;
  _16_R = (float)200 / (float)32767;
  _17_R = _16_R * 10;
  _18_R = _17_R * TH;
  TH_1 = _18_R;
  _20_R = (float)NLZ / (float)328;
  /*Тело процедуры*/
  if ((_20_R - floor(_20_R)) > 0.5) _6Res = smallint(ceil(_20_R));
  else _6Res = smallint(floor(_20_R));
  /*End of _Round*/

  _19_R = 1 + _6Res;
  NLZ_1 = _19_R;
  _7Y = _SmallintToFloat(TRK,32767);
  _21_R = _7Y * 10;
  _8Y = _FloatToSmallint(_21_R,32767);
  TRK_1 = _8Y;
  _22_R = SRKF || SRKOKD;
  RM = _22_R;
  _24_R =  ! _22_R;
  _0Out = Spls1->_SPulse(_24_R,1);
  _26_R = _24_R && SBRN;
  _27_R =  ! AVT;
  _25_R = _0Out || _26_R || _27_R || P_SM;
  _23_R = _24_R && _25_R;
  _29_R = AVT && OTKR;
  _32_R = _27_R || ZAKR;
  NLO_Cnt->_UCounter(_29_R,NLO_1,_32_R,_2Value,_2Over);
  _30_R = OTKR && _2Over;
  _33_R =  ! Stop_int;
  _34_R = AVT && ZAKR;
  _36_R = _27_R || OTKR;
  NLZ_Cnt->_UCounter(_34_R,NLZ_1,_36_R,_3Value,_3Over);
  _35_R = _33_R && _3Over && ZAKR;
  _28_R = _30_R || _35_R;
  _10OUT1 = _RAZN(0,32767);
    _9Res = _35_R? _10OUT1 : 32767;
/*  if (_35_R) _9Res = _10OUT1;
    
       else _9Res = 32767; */

  _1OUT1 = Int_SM->_integrator1(_23_R,_28_R,_9Res,SRK,TH_1);
  SM = _1OUT1;
  _31_R = _1OUT1 <= 0;
  Stop_int = _31_R;
  _11OUT1 = _RAZN(_1OUT1,SRK);
    /*Тело процедуры*/
  _12Res = abs(_11OUT1);
/*End of _Abs*/

  _41_R = _12Res > DP1;
  _43_R =  ! _41_R;
  _42_R = _27_R || _43_R;
  TRK_Cnt->_UCounter(_41_R,TRK_1,_42_R,_4Value,_4Over);
  _46_R = _12Res > DP2;
  _47_R =  ! _46_R;
  _44_R = _4Over && _47_R;
  P_SM = _44_R;
  _38_R = SRK > 1638;
  _37_R = RKZAK && _38_R;
  _39_R = SRK < 31129;
  _40_R = _39_R && RKOTK;
  _48_R =  ! _22_R;
  _50_R = _4Over && _46_R;
  _49_R = _48_R && _50_R;
  _45_R = _37_R || _40_R || _49_R;
  NES = _45_R;
  _51_R = _22_R && AVT;
    _13Res = _51_R? _1OUT1 : SRK;
/*  if (_51_R) _13Res = _1OUT1;
    
       else _13Res = SRK; */

  PRK = _13Res;
}

//__________________________________ TFPATR_K __________________________________

_TFPATR_K::_TFPATR_K(smallint _0XPRPT, smallint _1XUR)
{
  XPRPT = _0XPRPT;
  XUR = _1XUR;
}

_TFPATR_K::~_TFPATR_K()
{
}

void _TFPATR_K::_FPATR_K(const bool RPP, const smallint XUI, const smallint D, 
  const smallint VPR, const smallint DHNI, const bool RNR, const bool PVRPP_P, 
  const smallint TC, smallint &XPR, smallint &DHNO)
{ /*Тело метода*/
 smallint DX;
     DHNO = DHNI;
    //ER = RER;
    XPR =  XPRPT;

    if (TC == 0)
     {
        if (!RPP)
         { //ER=0;
           XUR=XUI;
            goto Ml1;
         }
         if (RNR)
           { XUR=XUR+DHNI;
             XPR=XPRPT+DHNI;
             XPRPT = XPR;
             DHNO = 0;}
         else
         {
	    XUR = XUI;
            DHNO = 0;
            if (!PVRPP_P)
	    {
	     XPR=D;
             XPRPT=XPR;
            }
	  }

        DX=XUR-XPRPT;
        if (abs(DX) > VPR)
          {
            if (DX > 0) XPR=XPRPT+VPR;
            else XPR=XPRPT-VPR;
            XPRPT=XPR;
          }
         else
            {  XPR=XUR;
              XPRPT=XPR;
            }

        /*if (PRREG) ER=XPRPT-D;
        else ER=D-XPRPT;        */
     }
Ml1:  XPRPT = XPR;
     // RER = ER;
}  /*_TFPATR_K::_FPATR_K*/

//__________________________________ TURK_K __________________________________

_TURK_K::_TURK_K(bool _0PRZRM, bool _1PRZRP, bool _2ZVKU, bool _3ZVKP, bool _4POTKR, bool _5PZAKR, smallint 
  _6N1, smallint _7N2, smallint _8SM1PT, smallint _9SMPT, smallint _10PAUZ, smallint _11S0, smallint _12CZR)
{
  PRZRM = _0PRZRM;
  PRZRP = _1PRZRP;
  ZVKU = _2ZVKU;
  ZVKP = _3ZVKP;
  POTKR = _4POTKR;
  PZAKR = _5PZAKR;
  N1 = _6N1;
  N2 = _7N2;
  SM1PT = _8SM1PT;
  SMPT = _9SMPT;
  PAUZ = _10PAUZ;
  S0 = _11S0;
  CZR = _12CZR;
}

_TURK_K::~_TURK_K()
{
}

void _TURK_K::_URK_K(const bool RPP, const bool AVT, const smallint CPI, 
  const bool BLPR, const bool BLUB, const bool RKOTK, const bool RKZAK, 
  const smallint ZNZ, const smallint ZVZ, const smallint NLO, 
  const smallint NLZ, const smallint CI, const smallint TH, const smallint TC, 
  smallint &SM1, bool &OTKR, bool &ZAKR)
{
  bool POTKR, PZAKR;
  bool FLAG;
  int PER;
  SM1 = SM1PT;
  
  S0 = int((float)32767/TH*164*0.1);   //!!!!!!!!!!!!!!!
  
  if (TC==0) FLAG = true;
  else FLAG = false;

  if (!RPP)
  {        N1 = 0;
           N2 = 0;
           SM1 = 0;
           SM1PT = SM1;
           OTKR = false;
           ZAKR = false;
           goto M2;
  }
  if (SM1PT > 29490)
  {
    if (CI < 3604)//0.11
    {
      PER =int(SM1PT - 29490);
      SM1 =PER > 32767? 32767 : (PER < -32767? -32767 : PER);// {90%}
      SM1PT = SM1;
    }
  }
  else if (SM1PT < -29490)
  {
    if (CI > -3604) //-0.11
    {
      PER =int(SM1PT + 29490);
      SM1 =PER > 32767? 32767 : (PER < -32767? -32767 : PER);// {90%}
      SM1PT = SM1;
    }
  }
  PER = int(CPI - SM1PT);
  CZR = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
  if (CZR >= 0)
  {
    PRZRM = false;
    if (PRZRP)
    {
      if (CZR <= ZVZ)
      {
        PRZRP = false;
        goto M3;
      }
      else goto MW;
    }
    else
      if (CZR <= ZNZ)  goto M3;
      else
      {
        PRZRP = true;
        goto MW;
       }
  }//if (CZR >= 0)
  else
  {
    PRZRP = false;
    if (PRZRM)
    {
      if (abs(CZR) > ZVZ)  goto MW;
      PRZRM = false;
      goto M3;
    }
    else if (abs(CZR) > ZNZ)
         {
           PRZRM = true;
           goto MW;
         }
M3:
    CZR = 0;
    goto ML;
  }//if (CZR >= 0)
MW:
  if (CZR > 0)
  {
MQ:
    if (ZVKP || (PAUZ == 1))  goto ML;
    POTKR = true;
    PZAKR = false;
    ZVKU = true;
    PAUZ = 0;
    if (RKOTK || BLPR) goto M30;
    OTKR = true;
    ZAKR = false;
    goto M9;
  }//if (CZR > 0)
  else
  {
MS:
    if (ZVKU || (PAUZ == 1))
    {
ML:
      POTKR = false;
      PZAKR = false;
      ZVKP = false;
      ZVKU = false;
      if (PAUZ < 2)  PAUZ++;
M30:
      OTKR = false;
      ZAKR = false;
      goto M9;
    }//if (ZVKU || PAUZ)
    else
    {
      POTKR = false;
      PZAKR = true;
      ZVKP = true;
      PAUZ = 0;
      if (RKZAK || BLUB) goto M30;
      OTKR = false;
      ZAKR = true;
    }//if (ZVKU || PAUZ)
  }//if (CZR > 0)
M9:
  if (!RPP) goto M2;
  if (!AVT) N1 = N2 = 0;
  if (POTKR)
  {
     N2 = 0;
    if (RKOTK || BLPR) goto M31;//03_01_12
    if (N1 < NLO)
    { PER = N1 + 328;        //  N1 = N1 + 328;
      N1 = PER > 32767? 32767 : PER;
    }
    else
    {
    //  N2 = 0;    10_04_08
M31:
      PER = int(SM1PT + S0);
      SM1 = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
      SM1PT = SM1;
    }
  }
  else
    if (PZAKR)
    {
     	N1 = 0;
      if (RKZAK || BLUB) goto M32;//03_01_12
      if (N2 < NLZ)
       { PER = N2 + 328;        //  N1 = N1 + 328;
         N2 = PER > 32767? 32767 : PER;
        }
      else
      {
//	N1 = 0;    10_04_08
M32:
      PER = int(SM1PT - S0);
      SM1 = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
        SM1PT = SM1;
       }
    }
 M2:;
}    //  {_TURKM._URKM}

//__________________________________ TFZR_K __________________________________

_TFZR_K::_TFZR_K(smallint _0CPIPT, smallint _1CIPT, smallint _2KPPR, smallint _3ERZPT)
{
  CPIPT = _0CPIPT;
  CIPT = _1CIPT;
  KPPR = _2KPPR;
  ERZPT = _3ERZPT;
}

_TFZR_K::~_TFZR_K()
{
}

void _TFZR_K::_FZR_K(const bool RPP, const smallint ER, const bool PRER,
  const smallint SM1, const smallint EMN, const smallint KP,
  const smallint TI1, const smallint TI2, const bool RNR, const bool PVRPI,
  const smallint TC, smallint &CI, smallint &CPI, smallint &ERZ,
  bool &PVRPO)
{
  /*Тело метода*/
  smallint PP, TI1_V, TI2_V;
  float PER;
  PVRPO = PVRPI;
  CI = CIPT;
  CPI = CPIPT;
  ERZ = ERZPT;
  TI1_V = TI1;
  TI2_V = TI2;

  if (TC == 0)
  {
       if (!RPP)
       {
              CI = 0;
              CPI = 0;
              CIPT = 0;
              CPIPT = 0;
              PVRPO = false;
              ERZ = 0;
              ERZPT = 0;
             return;
       }


       if (!RNR && !PVRPI)
       {
            CI=SM1;
            CIPT=CI;
       }
       PVRPO = true;

       if (PRER)  goto Ml2;
       else
	{
	    ERZ = 0;
            CPI = SM1;
            CPIPT = CPI;
            CI = SM1;
            CIPT = CI;
            PP = 0;
            goto Ml1;
	}

Ml2:
       ERZ = ER;
       if (KPPR != KP)
       {
          PER = float(CIPT) - float(ERZPT*((KP-KPPR)/32767.*50.));
          CI =  PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));
          CIPT = CI;
       }//if (KPPR != KP)

       PER = float(ERZ*KP/32767.*50.);
       PP = PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));

       if (abs(ERZ) <= EMN)
       {
           if (TI1_V < 66) TI1_V = 66;
            PER = float(CIPT+1*PP*32767./(TI1_V*500));
            CI = PER > 32767? 32767 : (PER < -32767? -32767 : smallint (PER));
            CIPT = CI;
        }//if (abs(ERZ) <= EMN)
       else
       {
           if (TI2_V < 66) TI2_V = 66;
          PER = float(CIPT+1*PP*32767/(TI2_V*500));
          CI = PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));
          CIPT = CI;
       }//if (abs(ERZ) <= EMN)

Ml1:
       if (SM1 > 29490)      //  {90%}
       {
         CI = CIPT - 29490;
         CIPT = CI;

       }
       else
         if (SM1 < -29490)   // {-90%}
         {
            CI = CIPT+29490;
            CIPT = CI;

          }
       PER = float(PP + CIPT);
       CPI = PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));
       CPIPT = CPI;

  KPPR = KP;
  ERZPT = ERZ;
   }
}  /*_TFZR_K::_FZR_K*/

//__________________________________ TMaxHyst __________________________________

_TMaxHyst::_TMaxHyst(bool _0old, bool _1prin)
{
  old = _0old;
  prin = _1prin;
}

_TMaxHyst::~_TMaxHyst()
{
}

bool _TMaxHyst::_MaxHyst(const smallint CP, const smallint Max, 
  const smallint Delta)
{
  /*Тело метода*/
   if (!prin)
    {
      prin  = true;
      old  = (CP > Max);
    }
  old = old && (CP >= (Max - Delta)) || (CP > Max);
  return old;
}  /*_TMaxHyst::_MaxHyst*/

//__________________________________ TERGIST __________________________________

_TERGIST::_TERGIST(bool _0old, bool _0prin)
{
  MaxH1 = new _TMaxHyst(_0old, _0prin);
}

_TERGIST::~_TERGIST()
{
}

void _TERGIST::_ERGIST(bool PRREG, bool RPP, smallint XPR, smallint D, smallint ZN, smallint ZV, smallint 
  &ERO, bool &PRER)
{
  smallint _4OUT1 = 0;
  smallint _6OUT1 = 0;
  smallint _3Res;
  smallint _1Res;
  smallint _2Res;
  smallint _5OUT1 = 0;
  bool _0B = false;

  _4OUT1 = _RAZN(XPR,D);
  _6OUT1 = _RAZN(D,XPR);
    _3Res = PRREG? _4OUT1 : _6OUT1;
/*  if (PRREG) _3Res = _4OUT1;
    
       else _3Res = _6OUT1; */

    _1Res = RPP? _3Res : 0;
/*  if (RPP) _1Res = _3Res;
    
       else _1Res = 0; */

  ERO = _1Res;
    /*Тело процедуры*/
  _2Res = abs(_1Res);
/*End of _Abs*/

  _5OUT1 = _RAZN(ZN,ZV);
  _0B = MaxH1->_MaxHyst(_2Res,ZN,_5OUT1);
  PRER = _0B;
}

//__________________________________ TFOS_K __________________________________

_TFOS_K::_TFOS_K(bool _0PODRK, bool _1PODM, smallint _2POSRK, smallint _3POSRKPT, smallint _4POSM, smallint 
  _5POSMPT, smallint _6KOSRPT, smallint _7PRKPT, smallint _8POSRKP, smallint _9POSMP, smallint _10SMPT, 
  smallint _11RXOS, smallint _12RDPOS, bool _13RBVK, smallint _14DPT, smallint _15KMPT)
{
  PODRK = _0PODRK;
  PODM = _1PODM;
  POSRK = _2POSRK;
  POSRKPT = _3POSRKPT;
  POSM = _4POSM;
  POSMPT = _5POSMPT;
  KOSRPT = _6KOSRPT;
  PRKPT = _7PRKPT;
  POSRKP = _8POSRKP;
  POSMP = _9POSMP;
  SMPT = _10SMPT;
  RXOS = _11RXOS;
  RDPOS = _12RDPOS;
  RBVK = _13RBVK;
  DPT = _14DPT;
  KMPT = _15KMPT;
}

_TFOS_K::~_TFOS_K()
{
}

void _TFOS_K::_FOS_K(const bool RPP, const smallint SRK, const smallint SM,
  const smallint D, const bool RM, const smallint KM, const smallint KOSR,
  const bool PVRPP_F, const bool PRREG, const smallint TC, smallint &XOS,
  smallint &DPOS, bool &BVK)
{
  /*Тело метода*/
  smallint DPSRK, DPSM, DPD;// DPD1, DPD2;
   int PER;
   XOS = RXOS;
   DPOS = RDPOS;
   BVK = RBVK;

   if (TC == 0)
   {
     if (!RPP)
     {
        PODRK = false;
        PODM = false;
        //POD1 = false;
        //POD2 = false;
        XOS = 0;
        goto l1;
     }

     BVK = false;
     DPSRK = 0;
     DPSM = 0;
     //DPD1 = 0;
     //DPD2 = 0;
     DPD = 0;
     POSRKPT = POSRK;
     POSMPT = POSM;
     //POS1PT = POS1;
     //POS2PT = POS2;

     if (RM)
      {
        if (!PODRK)
        {
            BVK = true;
            PODRK = true;
            DPSRK = POSRKP;
        }
        POSRK = 0;
      }
     else
     {
       POSRK = smallint((float)KOSR/32767*SRK);
       if (PODRK)
       {
          BVK = true;
          PODRK = false;
          DPSRK = -POSRK;
       }
       else if (KOSR != KOSRPT)
              {
                DPSRK=-(smallint((float)(KOSR-KOSRPT)/32767*PRKPT));
                BVK = true;
              }
     }

     if (!RM)
     {
          if (!PODM)
          {
            BVK = true;
            PODM = true;
            DPSM = POSMP;
          }
         POSM = 0;
     }
     else
     {
        POSM = smallint((float)KOSR/32767*SM);
        if (PODM)
        {
         BVK = true;
         PODM = false;
         DPSM = -POSM;
        }
        else
          if (KOSR != KOSRPT)
          {
            DPSM = -(smallint((float)(KOSR-KOSRPT)/32767*SM));
            BVK = true;
          }
     }

    if (KM != KMPT)
    {
       DPD = smallint((float)(KM-KMPT)/32767*DPT);
       BVK = true;
    }

        if (!PRREG)
        {

	  PER = int(smallint(KM*D/32767)-POSRK-POSM);
	   XOS = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
           DPOS = DPSRK+DPSM+DPD;
        }
       else
       {
          PER = int(smallint(KM*D/32767)+POSRK+POSM);
          XOS = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
          DPOS = 0-DPSRK-DPSM+DPD;
       }

     // if (BVKI) BVK = true;
      KOSRPT = KOSR;
      //KOS1PT = KOS1;
      //KOS2PT = KOS2;
      KMPT = KM;
      DPT = D;
      PRKPT = SRK;
      SMPT = SM;
      //DOS1PT = DOS1;
      //DOS2PT = DOS2;

      if (!PVRPP_F)
      {
          POSRKP = POSRK;
          POSMP = POSM;
          //POS1P = POS1;
          //POS2P = POS2;
      }
      else
      {
        POSRKP = POSRKPT;
        POSMP = POSMPT;
        //POS1P = POS1PT;
        //POS2P = POS2PT;
      }
   }

l1: RXOS  = XOS;
    RDPOS = DPOS;
    RBVK = BVK;
    return;
}  /*_TFOS_K::_FOS_K*/

//__________________________________ TFPSTR_K __________________________________

_TFPSTR_K::_TFPSTR_K(smallint _0DX, smallint _1DV, smallint _2XUPT, smallint _3SHKU, smallint _4UK, smallint 
  _5ERPT, smallint _6KORU, smallint _7XPRPT, bool _8PRIUS)
{
  DX = _0DX;
  DV = _1DV;
  XUPT = _2XUPT;
  SHKU = _3SHKU;
  UK = _4UK;
  ERPT = _5ERPT;
  KORU = _6KORU;
  XPRPT = _7XPRPT;
  PRIUS = _8PRIUS;
}

_TFPSTR_K::~_TFPSTR_K()
{
}

void _TFPSTR_K::_FPSTR_K(const bool RPP, const smallint XU, const smallint D,
  const smallint XOS, const smallint DPOS, const bool BVK, const smallint ERZ,
  const smallint ZNK, const smallint TKU, const smallint VPR,
  const smallint DHNI, const bool RNR, const bool PVRPP_S, const smallint VKOR,
  const smallint KM, const smallint DK, const smallint TC, smallint &XPR,
  smallint &DHNO)
{
  /*Тело метода*/
  smallint DM, XUM, DU;
   int PER;
   DHNO = DHNI;
   XPR = XPRPT;

   if  (TC == 0)
   {
     if (!RPP)
     {

       goto l2;
     }

     DM = smallint((float)KM/32767*D);
     XUM = smallint((float)KM/32767*XU);

     if (!PVRPP_S)
     {
       if (RNR) goto l1;
       else
       {
        XPR = XOS;
        XPRPT = XPR;
        DV = VPR;
        PRIUS = true;
        UK = (XUM-DM)+XOS;
        SHKU = 0;
        XUPT = XU;
       }
     }
     else if (BVK)
     {
         UK = UK+DPOS;
         XPR = XPRPT+DPOS;
         XPRPT = XPR;
     }

l1:
    if (XU != XUPT)
    {
       DU = smallint((float)KM/32767*(XU-XUPT));
       UK = UK+DU;
       DV = VPR;
       PRIUS = true;
       goto l3;
    }
    if (RNR) { SHKU = 0;  goto l3; }   //10_04_06

    if (XPRPT == UK)
    {
        if (!ERZ)
        {
           SHKU++;
           if (SHKU >= TKU)
           {
               KORU = XU-D;    //10_04_06
               SHKU = 0;
               if (abs(KORU) > ZNK)
               {
                 if (KORU >0)
                 {
                   PER = int(UK + DK);
                   UK = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
                   DV = VKOR;
                 }
                 else
                 {
                   PER = int(UK - DK);
                   UK = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
                   DV = VKOR;
                 }                  ////
               }
            }
          }//if (!ERZ)
          else SHKU = 0;
    }
    else SHKU = 0;

l3:
    XUPT = XU;
    if (RNR)
    {
      UK = UK+DHNI;
      XPR = XPRPT+DHNI;
      XPRPT = XPR;
    }
    DHNO = 0;
    DX = UK-XPRPT;

    if (abs(DX) > DV)
    {
      if (!PRIUS)
        if (abs(XUM-DM) <= (ZNK/2))
        {
            UK = XPR;
            goto l2;
        }
      if (DX > 0)
      {
           PER = int(XPRPT + DV);
           XPR = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
           XPRPT = XPR;
      }
      else
      {
           PER = int(XPRPT - DV);
           XPR = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
           XPRPT = XPR;
      }
    }
    else
    {
      XPR = UK;
      XPRPT = XPR;
      PRIUS = false;
    }

 }  //  TC

l2: XPRPT = XPR;

}  /*_TFPSTR_K::_FPSTR_K*/

//__________________________________ TButtonState __________________________________

_TButtonState::_TButtonState(bool _0old, bool _1St)
{
  old = _0old;
  St = _1St;
}

_TButtonState::~_TButtonState()
{
}

bool _TButtonState::_ButtonState(const bool Click)
{
  /*Тело метода*/
   if (Click && !old) St = !St;
  old = Click;
 return St;
}  /*_TButtonState::_ButtonState*/

//__________________________________ TETrigger __________________________________

_TETrigger::_TETrigger(bool _0St)
{
  St = _0St;
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


//__________________________________ TOCHK __________________________________

_TOCHK::_TOCHK(smallint _0S1, smallint _1S2, smallint _2S3, smallint _3SV, smallint _4SV1, smallint _5SV2, 
  smallint _6SV3, smallint _7SV4, smallint _8SV5, smallint _9SV6, smallint _10SHK, smallint _11PV, smallint 
  _12RKUIO, smallint _13RINHOIR, bool _14RBCHV)
{
  S1 = _0S1;
  S2 = _1S2;
  S3 = _2S3;
  SV = _3SV;
  SV1 = _4SV1;
  SV2 = _5SV2;
  SV3 = _6SV3;
  SV4 = _7SV4;
  SV5 = _8SV5;
  SV6 = _9SV6;
  SHK = _10SHK;
  PV = _11PV;
  RKUIO = _12RKUIO;
  RINHOIR = _13RINHOIR;
  RBCHV = _14RBCHV;
}

_TOCHK::~_TOCHK()
{
}

void _TOCHK::_OCHK(const bool RPU, const bool OTKR, const bool ZAKR,
  smallint &KUIO, smallint &INHOIR, bool &BCHV)
{
  /*Тело метода*/

  int  PER;

  KUIO = RKUIO;
  INHOIR = RINHOIR;
  BCHV = RBCHV;

  if  (!RPU)
  {
    S1 = 0;
    S2 = 0;
    S3 = 0;
    INHOIR = 0;
    BCHV = false;
    KUIO = 0;
    SV = 0;
    SV1 = 0;
    SV2 = 0;
    SV3 = 0;
    SV4 = 0;
    SV5 = 0;
    SV6 = 0;
    SHK = 0;
    goto l2;
  }
  if (OTKR || ZAKR)
  {
    PV++;
    if (PV == 1)
    {
      SV++;
      SHK++;
    }
    goto l1;
  }
  PV = 0;
l1:
  if (S1 != 600)  S1++;
  else
  {
    S1 = 0;
    S2++;
    KUIO = SHK;
    SHK = 0;
  }
  if (S2 == 10)
  {
    SV6 = SV5;
    SV5 = SV4;
    SV4 = SV3;
    SV3 = SV2;
    SV2 = SV1;
    SV1 = SV;
    SV = 0;
    S2 = 0;
    PER = SV1+SV2+SV3+SV4+SV5+SV6;
    if (PER > 32767) INHOIR = 32767;
    else INHOIR = PER;
  }
  if (KUIO > 4)
  {
    S3++;
    if (S3 > 6000)  BCHV = true;
  }
  else
  {
    S3 = 0;
    BCHV = false;
  }
l2:
   RKUIO = KUIO;
   RINHOIR = INHOIR;
   RBCHV = BCHV;
}  /*_TOCHK::_OCHK*/





//__________________________________ TMNMRO __________________________________

_TMNMRO::_TMNMRO()
{
}

_TMNMRO::~_TMNMRO()
{
}

smallint _TMNMRO::_MNMR0(const bool ZBPR, const bool ZBUB, const bool ZO, 
  const bool ZZ, const bool BPR, const bool BUB, const bool LOGPR, 
  const bool LOGUB, const bool VH1, const bool VH2, const bool VH3, 
  const bool VH4, const bool REM, const bool ZVK_AVT, const bool KNMRPR, 
  const bool KNMRUB)
{
  /*Тело метода*/
  smallint outb;
 // Упаковка сигнала LBDMRО
  outb = 0;
  if (ZBPR) outb = outb | 0x01;
  if (ZBUB) outb = outb | 0x02;
  if (ZO) outb = outb | 0x04;
  if (ZZ) outb = outb | 0x08;
  if (BPR) outb = outb | 0x10;
  if (BUB) outb = outb | 0x20;
  if (LOGPR) outb = outb | 0x40;
  if (LOGUB) outb = outb | 0x80;
  if (VH1) outb = outb | 0x100;
  if (VH2) outb = outb | 0x200;
  if (VH3) outb = outb | 0x400;
  if (VH4) outb = outb | 0x800;
  if (REM) outb = outb | 0x1000;
  if (ZVK_AVT) outb = outb | 0x2000;
  if (KNMRPR) outb = outb | 0x4000;
  if (KNMRUB) outb = outb | 0x8000;
  return outb;
}  /*_TMNMRO::_MNMR0*/

