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


//__________________________________ TKPIM __________________________________

_TKPIM::_TKPIM(bool _0ROTK, bool _1RZAK)
{
  ROTK = _0ROTK;
  RZAK = _1RZAK;
}

_TKPIM::~_TKPIM()
{
}

void _TKPIM::_KPIM(const bool NO, const bool NZ, bool &ZAK, bool &OTK,
  bool &NP)
{
   OTK = ROTK;
   ZAK = RZAK;
  if ((!NO)&&(!NZ)) NP=true;
  if ((!NO)&& NZ)
  {
         ZAK=false;
         OTK=true;
         NP=false;
  }
  if (NO && (!NZ))
  {
         ZAK=true;
         OTK=false;
         NP=false;
  }
  if (NO && NZ)
  {
         ZAK=false;
         OTK=false;
         NP=false;
  }
   ROTK = OTK;
   RZAK = ZAK;
  return ;
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

//__________________________________ TFPATR __________________________________

_TFPATR::_TFPATR(smallint _0XPRPT, smallint _1RER, smallint _2XUR)
{
  XPRPT = _0XPRPT;
  RER = _1RER;
  XUR = _2XUR;
}

_TFPATR::~_TFPATR()
{
}

void _TFPATR::_FPATR(const bool RPP, const smallint XUI, const smallint D,
  const bool PRREG, const smallint VPR, const smallint DHNI,
  const bool RNR, const bool PVRPP_P, const smallint TC, smallint &XPR,
  smallint &DHNO, smallint &ER)
{ /*Тело метода*/
 smallint DX;
     DHNO = DHNI;
    ER = RER;
    XPR =  XPRPT;

    if (TC == 0)
     {
        if (!RPP)
         { ER=0;
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

        if (PRREG) ER=XPRPT-D;
        else ER=D-XPRPT;
     }
Ml1:  XPRPT = XPR;
      RER = ER;

}  /*_TFPATR::_FPATR*/



//__________________________________ TFZR __________________________________

_TFZR::_TFZR(bool _0PREB, bool _1PREM, smallint _2CPIPT, smallint _3KPPR, smallint _4ERZPT, smallint _5CIPT)
{
  PREB = _0PREB;
  PREM = _1PREM;
  CPIPT = _2CPIPT;
  KPPR = _3KPPR;
  ERZPT = _4ERZPT;
  CIPT = _5CIPT;
}

_TFZR::~_TFZR()
{
}

void _TFZR::_FZR(const bool RPP, const smallint ER, const smallint SM1,
  const bool PRREG, const smallint ZN, const smallint ZV, const smallint EMN,
  const smallint KP, const smallint TI1, const smallint TI2,
  const bool RNR, const bool PVRPI, const smallint TC, const smallint V,
  smallint &CI, smallint &CPI, smallint &ERZ, bool &PVRPO)
{
  /*???? ??????*/
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

       if (ER >= 0)
       {
           PREM = false;
          if (PREB)
          {
              if (ER >=ZV)  goto Ml2;
              {
                PREB = false;
Ml3:            ERZ = 0;
                CPI = SM1;
                CPIPT = CPI;
                CI = SM1;
                CIPT = CI;
                PP = 0;
                goto Ml1;
              }
          }
           else
           {
              if (ER < ZN)  goto Ml3;
              PREB = true;
              goto Ml2;
           }
       }//if (ER >= 0)
       PREB = false;
       if (PREM)
          if (abs(ER) >= ZV) goto Ml2;
          else
          {
                PREM = false;
                goto Ml3;
          }
       if (abs(ER) < ZN) goto Ml3;
       else  PREM = true;

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
       if (PRREG)
       {
          PER = float(CPIPT-V);
          CPI = PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));
          CPIPT = CPI;
       }//if (PRREG)
       else
       {
         PER = float(CPIPT + V);
         CPI = PER > 32767.? 32767 : (PER < -32767.? -32767 : smallint (PER));
         CPIPT = CPI;
       }//if (PRREG)

  KPPR = KP;
  ERZPT = ERZ;

  }
}// {_TFZR._FZR}

//__________________________________ TURK __________________________________

_TURK::_TURK(bool _0PRZRM, bool _1PRZRP, bool _2ZVKU, bool _3ZVKP, bool _4POTKR, bool _5PZAKR, smallint _6N1, 
  smallint _7N2, smallint _8PAUZ, smallint _9THPT, smallint _10CZR, smallint _11SM1PT, smallint _12SMPT, 
  smallint _13S0)
{
  PRZRM = _0PRZRM;
  PRZRP = _1PRZRP;
  ZVKU = _2ZVKU;
  ZVKP = _3ZVKP;
  POTKR = _4POTKR;
  PZAKR = _5PZAKR;
  N1 = _6N1;
  N2 = _7N2;
  PAUZ = _8PAUZ;
  THPT = _9THPT;
  CZR = _10CZR;
  SM1PT = _11SM1PT;
  SMPT = _12SMPT;
  S0 = _13S0;
}

_TURK::~_TURK()
{
}

void _TURK::_URK(const bool RPP, const bool AVT, const smallint CPI,
  const bool BLPR, const bool BLUB, const bool RKOTK, const bool RKZAK,
  const smallint ZNZ, const smallint ZVZ, const smallint NLO,
  const smallint NLZ, const smallint CI, const smallint S0, const smallint TC,
  smallint &SM1, bool &OTKR, bool &ZAKR)
{
  bool POTKR, PZAKR;
  bool FLAG;
  //smallint TH_V;
  int PER;
  SM1 = SM1PT;

  if (TC==0) FLAG = true;
  else FLAG = false;
//  SMO = SMI;
/*  TH_V = TH;
  if (TH_V != THPT)
  {
          if (TH_V < 328)  TH_V = 328;
          S0_V = int((float)32767/TH_V*164*0.1);
  }
  S0 = S0_V;
  THPT = TH_V;*/
 /* if (!UPR)
  {
           N1 = 0;
           N2 = 0;
           SM1 = 0;
           SM1PT = SM1;
           OTKR = false;
           ZAKR = false;
           goto M2;
  }*/
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
 M2:;      // SMPT = SMO;
 // S0 = S0_V;
}    //  {_TURKM._URKM}


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

//__________________________________ TAR1 __________________________________

_TAR1::_TAR1(smallint _0XPRPT, smallint _0RER, smallint _0XUR, bool _1PREB, bool _1PREM, smallint _1CPIPT, 
  smallint _1KPPR, smallint _1ERZPT, smallint _1CIPT, bool _2PRZRM, bool _2PRZRP, bool _2ZVKU, bool _2ZVKP, 
  bool _2POTKR, bool _2PZAKR, smallint _2N1, smallint _2N2, smallint _2PAUZ, smallint _2THPT, smallint _2CZR, 
  smallint _2SM1PT, smallint _2SMPT, smallint _2S0, bool _3PVRPP, smallint _4TC, smallint _5RSM1)
{
  FPATR1 = new _TFPATR(_0XPRPT, _0RER, _0XUR);
  FZR1 = new _TFZR(_1PREB, _1PREM, _1CPIPT, _1KPPR, _1ERZPT, _1CIPT);
  URKM1 = new _TURK(_2PRZRM, _2PRZRP, _2ZVKU, _2ZVKP, _2POTKR, _2PZAKR, _2N1, _2N2, _2PAUZ, _2THPT, _2CZR, 
    _2SM1PT, _2SMPT, _2S0);
  PVRPP = _3PVRPP;
  TC = _4TC;
  RSM1 = _5RSM1;
  COUNT1 = new _TCOUNT();
}

_TAR1::~_TAR1()
{
}

smallint _RAZN(const smallint IN1, const smallint IN2)
{
  /*Тело функции*/
  int  per= IN1-IN2;
  if (per >= 32767) return 32767;
  else if (per <= -32767) return -32767;
       else return per;
}  /*_RAZN*/


smallint _SUMMA(const smallint IN1, const smallint IN2)
{
  /*Тело функции*/
  int per = IN1+IN2;
  if (per >= 32767)  return 32767;
  else if (per <= -32768)  return -32768;
       else return per;
}  /*_SUMMA*/


void _TAR1::_AR(bool RPP, smallint XU, smallint D, bool PRREG, smallint VPR, smallint DHNI, bool RNR, 
  smallint ZN, smallint ZV, smallint EMN, smallint KP, smallint TI1, smallint TI2, bool BLPR, bool BLUB, bool 
  OTK, bool ZAK, smallint ZNZ, smallint ZVZ, smallint NLO, smallint NLZ, smallint V, smallint S0, smallint 
  &DHNO, smallint &XPR, smallint &CI, smallint &ERZ, bool &OTKR, bool &ZAKR, smallint &ER)
{
  smallint _4OUT1 = 0;
  smallint _5OUT1 = 0;
  smallint _0XPR = 0;
  smallint _0DHNO = 0;
  smallint _0ER = 0;
  smallint _2CI = 0;
  smallint _2CPI = 0;
  smallint _2ERZ = 0;
  bool _2PVRPO = false;
  smallint _1SM1 = 0;
  bool _1OTKR = false;
  bool _1ZAKR = false;
  smallint _3TCO = 0;

  _4OUT1 = _RAZN(0,0);
  _5OUT1 = _SUMMA(0,0);
  FPATR1->_FPATR(RPP,XU,D,PRREG,VPR,DHNI,RNR,PVRPP,TC,_0XPR,_0DHNO,_0ER);
  XPR = _0XPR;
  DHNO = _0DHNO;
  ER = _0ER;
  FZR1->_FZR(RPP,_0ER,RSM1,PRREG,ZN,ZV,EMN,KP,TI1,TI2,RNR,PVRPP,TC,V,_2CI,_2CPI,_2ERZ,_2PVRPO);
  CI = _2CI;
  ERZ = _2ERZ;
  PVRPP = _2PVRPO;
  URKM1->_URK(RPP,true,_2CPI,BLPR,BLUB,OTK,ZAK,ZNZ,ZVZ,NLO,NLZ,_2CI,S0,TC,_1SM1,_1OTKR,_1ZAKR);
  RSM1 = _1SM1;
  OTKR = _1OTKR;
  ZAKR = _1ZAKR;
  _3TCO = COUNT1->_COUNT(TC);
  TC = _3TCO;
}

//__________________________________ TMIMKD __________________________________

_TMIMKD::_TMIMKD(bool _0PV, smallint _1SM_V, bool _2RMPT, smallint _3N1, smallint _4N2, smallint _5RPRK, bool 
  _6NESPT, smallint _7SH)
{
  PV = _0PV;
  SM_V = _1SM_V;
  RMPT = _2RMPT;
  N1 = _3N1;
  N2 = _4N2;
  RPRK = _5RPRK;
  NESPT = _6NESPT;
  SH = _7SH;
}

_TMIMKD::~_TMIMKD()
{
}

void _TMIMKD::_MIMKD(const bool AVT, const smallint SRK, const bool SRKF,
  const bool SRKOKD, const bool OTKR, const bool ZAKR, const smallint NLO,
  const smallint NLZ, const smallint DP1, const smallint DP2,
  const bool RKOTK, const bool RKZAK, const smallint TH, const smallint TRK,
  const bool SBRN, smallint &SM, bool &RM, bool &NES, smallint &PRK,
  smallint &S0)

{
  /*Тело метода*/
  smallint DS ;
  int PER;
  RM = RMPT;
  NES =NESPT;
  PRK = RPRK;
  //TH_V = TH;

  S0 = int((float)32767/TH*164*0.1);   //!!!!!!!!!!!!!!!


    if (SBRN)
       {
         NES =false;
         if(!RM)
         SM_V = SRK;
       }
    if (SRKF || SRKOKD)
	{
	RM = true;
 	NES = false;
	}
     else
    {
        if (RM)  SM_V = SRK;
 	RM = false;
 
 	if ((RKZAK && (SRK >= 1638)) || (RKOTK && (SRK <= 31128)))
	  NES = true;     // >= 5% , <=95%
 	else
      	NES = false;
     }
  if (!AVT)
  {
    SM_V = SRK;         //10_04_08
    PRK = SRK;
    RM = false;
    N1 = 0;//03_01_12
    N2 = 0;//03_01_12
    goto END;
  }
    if (OTKR)
    {
      N2 = 0;
    if (N1 < NLO)
    { PER = N1 + 328;        //  N1 = N1 + 328;
    N1 = PER > 32767? 32767 : PER;
    goto M_A;
    }
    else
    {
//N2 = 0;  10_04_08
      PER = int(SM_V + S0);
      SM_V = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
     // DK++;
    }
  }
  else    //!otkr
    {
    if (!ZAKR) goto M_A;
    	N1 = 0;
     if (N2 < NLZ)
      {
       PER = N2 + 328;   // N2 = N2 + 328;
       N2 = PER > 32767? 32767 : PER;
       goto M_A;
      }
      else
      {
//	N1 = 0;  10_04_08
        PER = int(SM_V - S0);
        SM_V = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
        if (SM_V <= 0) SM_V = 0;

      }
     }  //!otkr

M_A:
       if (RM)
      {
        PRK = SM_V;
	goto END;
       }

      PRK = SRK;
      DS = SM_V - SRK;
      if (abs(DS) <= DP1)
      {
      SH = 0;
      goto END;
    }
      SH++;
      if (SH <= TRK*10) goto END;
          SH = TRK*10;
    if (abs(DS) > DP2)  NES=true;
    else SM_V = SRK;

END:

  RMPT = RM;
  SM = SM_V;
  RPRK = PRK;
  NESPT = NES;

}  /*_TMIM::_MIM*/



//__________________________________ TFOS __________________________________

_TFOS::_TFOS(bool _0PODRK, bool _1PODM, bool _2POD1, bool _3POD2, smallint _4POSRK, smallint _5POSRKPT, 
  smallint _6POSM, smallint _7POSMPT, smallint _8POS1, smallint _9POS1PT, smallint _10POS2, smallint _11POS2PT, 
  smallint _12KOSRPT, smallint _13PRKPT, smallint _14KOS1PT, smallint _15KOS2PT, smallint _16DOS1PT, smallint 
  _17DOS2PT, smallint _18POSRKP, smallint _19POSMP, smallint _20POS1P, smallint _21POS2P, smallint _22SMPT, 
  smallint _23RXOS, smallint _24RDPOS, bool _25RBVK, smallint _26DPT, smallint _27KMPT)
{
  PODRK = _0PODRK;
  PODM = _1PODM;
  POD1 = _2POD1;
  POD2 = _3POD2;
  POSRK = _4POSRK;
  POSRKPT = _5POSRKPT;
  POSM = _6POSM;
  POSMPT = _7POSMPT;
  POS1 = _8POS1;
  POS1PT = _9POS1PT;
  POS2 = _10POS2;
  POS2PT = _11POS2PT;
  KOSRPT = _12KOSRPT;
  PRKPT = _13PRKPT;
  KOS1PT = _14KOS1PT;
  KOS2PT = _15KOS2PT;
  DOS1PT = _16DOS1PT;
  DOS2PT = _17DOS2PT;
  POSRKP = _18POSRKP;
  POSMP = _19POSMP;
  POS1P = _20POS1P;
  POS2P = _21POS2P;
  SMPT = _22SMPT;
  RXOS = _23RXOS;
  RDPOS = _24RDPOS;
  RBVK = _25RBVK;
  DPT = _26DPT;
  KMPT = _27KMPT;
}

_TFOS::~_TFOS()
{
}

void _TFOS::_FOS(const bool RPP, const smallint SRK, const smallint SM,
  const smallint DOS1, const smallint DOS2, const smallint D,
  const bool RM, const bool OTDS1, const bool OTDS2, const smallint DPOSI,
  const smallint KM, const bool BVKI, const smallint KOSR, const smallint KOS1,
  const smallint KOS2, const bool PVRPP_F, const bool PRREG,
  const smallint TC, smallint &XOS, smallint &DPOS, bool &BVK)
{
  /*Тело метода*/
   smallint DPSRK, DPSM, DPD, DPD1, DPD2;
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
        POD1 = false;
        POD2 = false;
        XOS = 0;
        goto l1;
     }

     BVK = false;
     DPSRK = 0;
     DPSM = 0;
     DPD1 = 0;
     DPD2 = 0;
     DPD = 0;
     POSRKPT = POSRK;
     POSMPT = POSM;
     POS1PT = POS1;
     POS2PT = POS2;

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

  if(OTDS1)
  {
    if (!POD1)
    {
      BVK = true;
      POD1 = true;
      DPD1 = -POS1P;
    }
    POS1 = 0;
  }
  else
   {
    POS1 = smallint((float)KOS1/32767*DOS1);
    if (POD1)
    {
      BVK = true;
      POD1 = false;
      DPD1 = POS1;
    }
    else if (KOS1 != KOS1PT)
         {
            DPD1 = smallint((float)(KOS1-KOS1PT)/32767*DOS1PT);
            BVK = true;
         }
   }

  if (OTDS2)
   {
      if (!POD2)
      {
         BVK = true;
         POD2 = true;
         DPD2 = -POS2P;
      }
      POS2 = 0;
   }
    else
    {
      POS2 = smallint((float)KOS2/32767*DOS2);
       if (POD2)
       {
          BVK = true;
          POD2 = false;
          DPD2 = POS2;
       }
      else
         if (KOS2 != KOS2PT)
         {
           DPD2 = smallint((float)(KOS2-KOS2PT)/32767*DOS2PT);
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
//	  XOS =  _SUMMA(_SUMMA(_RAZN(_RAZN(smallint(KM*D/32767),POSRK),POSM),POS1),POS2);
	  PER = int(smallint(KM*D/32767)-POSRK-POSM+POS1+POS2);
	   XOS = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
/*           if (PER > 32767) XOS = 32767;
           else
             if (PER < -32768)  XOS = -32768;
             else XOS = PER;*/

          DPOS = DPOSI+DPSRK+DPSM+DPD1+DPD2+DPD;
        }
       else
       {
//	  XOS =  _SUMMA(_SUMMA(_SUMMA(_SUMMA(smallint(KM*D/32767),POSRK),POSM),POS1),POS2);
          PER = int(smallint(KM*D/32767)+POSRK+POSM+POS1+POS2);
           XOS = PER > 32767? 32767 : (PER < -32767? -32767 : PER);
/*          if (PER > 32767)  XOS = 32767;
           else if (PER < -32768) XOS = -32768;
             else XOS = PER; */

          DPOS = DPOSI-DPSRK-DPSM+DPD1+DPD2+DPD;
       }

      if (BVKI) BVK = true;
      KOSRPT = KOSR;
      KOS1PT = KOS1;
      KOS2PT = KOS2;
      KMPT = KM;
      DPT = D;
      PRKPT = SRK;
      SMPT = SM;
      DOS1PT = DOS1;
      DOS2PT = DOS2;

      if (!PVRPP_F)
      {
          POSRKP = POSRK;
          POSMP = POSM;
          POS1P = POS1;
          POS2P = POS2;
      }
      else
      {
        POSRKP = POSRKPT;
        POSMP = POSMPT;
        POS1P = POS1PT;
        POS2P = POS2PT;
      }
   }

l1: RXOS  = XOS;
    RDPOS = DPOS;
    RBVK = BVK;
    return;
}  /*_TFOS::_FOS*/

//__________________________________ TFPSTR __________________________________

_TFPSTR::_TFPSTR(smallint _0DX, smallint _1UK, smallint _2XPRPT, smallint _3DV, smallint _4ERPT, smallint 
  _5KORU, smallint _6XUPT, smallint _7SHKU, bool _8PRIUS)
{
  DX = _0DX;
  UK = _1UK;
  XPRPT = _2XPRPT;
  DV = _3DV;
  ERPT = _4ERPT;
  KORU = _5KORU;
  XUPT = _6XUPT;
  SHKU = _7SHKU;
  PRIUS = _8PRIUS;
}

_TFPSTR::~_TFPSTR()
{
}

void _TFPSTR::_FPSTR(const bool RPP, const smallint XU, const smallint D,
  const smallint XOS, const smallint DPOS, const bool BVK, const smallint ERZ,
  const bool PRVOS, const bool PRREG, const smallint ZNK, const smallint TKU,
  const smallint VPR, const smallint DHNI, const bool RNR, const bool PVRPP_S,
  const smallint TC, const smallint VKOR, const smallint KM,
  const smallint DK, smallint &XPR, smallint &ER, smallint &DHNO)
{
  /*Тело метода*/
  
   //         XPR!!!!!
   smallint DM, XUM, DU;
   int PER;
   DHNO = DHNI;
   XPR = XPRPT;
   ER = ERPT;


   if  (TC == 0)
   {
     if (!RPP)
     {
       ER = 0;
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
        if (PRVOS) UK = XOS;
        else UK = (XUM-DM)+XOS;
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
            goto l34;
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

l34:
     if (PRREG)  ER = XPRPT-XOS;
     else ER = XOS-XPRPT;
 }  //  TC

l2: XPRPT = XPR;
    ERPT = ER;

}  /*_TFPSTR::_FPSTR*/

//__________________________________ TSR1 __________________________________

_TSR1::_TSR1(bool _0PODRK, bool _0PODM, bool _0POD1, bool _0POD2, smallint _0POSRK, smallint _0POSRKPT, 
  smallint _0POSM, smallint _0POSMPT, smallint _0POS1, smallint _0POS1PT, smallint _0POS2, smallint _0POS2PT, 
  smallint _0KOSRPT, smallint _0PRKPT, smallint _0KOS1PT, smallint _0KOS2PT, smallint _0DOS1PT, smallint 
  _0DOS2PT, smallint _0POSRKP, smallint _0POSMP, smallint _0POS1P, smallint _0POS2P, smallint _0SMPT, smallint 
  _0RXOS, smallint _0RDPOS, bool _0RBVK, smallint _0DPT, smallint _0KMPT, smallint _1DX, smallint _1UK, 
  smallint _1XPRPT, smallint _1DV, smallint _1ERPT, smallint _1KORU, smallint _1XUPT, smallint _1SHKU, bool 
  _1PRIUS, bool _2PREB, bool _2PREM, smallint _2CPIPT, smallint _2KPPR, smallint _2ERZPT, smallint _2CIPT, bool 
  _3PRZRM, bool _3PRZRP, bool _3ZVKU, bool _3ZVKP, bool _3POTKR, bool _3PZAKR, smallint _3N1, smallint _3N2, 
  smallint _3PAUZ, smallint _3THPT, smallint _3CZR, smallint _3SM1PT, smallint _3SMPT, smallint _3S0, smallint 
  _4TC, bool _5PVRPP, smallint _6RSM1, smallint _7RERZ)
{
  FOS1 = new _TFOS(_0PODRK, _0PODM, _0POD1, _0POD2, _0POSRK, _0POSRKPT, _0POSM, _0POSMPT, _0POS1, _0POS1PT, 
    _0POS2, _0POS2PT, _0KOSRPT, _0PRKPT, _0KOS1PT, _0KOS2PT, _0DOS1PT, _0DOS2PT, _0POSRKP, _0POSMP, _0POS1P, 
    _0POS2P, _0SMPT, _0RXOS, _0RDPOS, _0RBVK, _0DPT, _0KMPT);
  FPSTR1 = new _TFPSTR(_1DX, _1UK, _1XPRPT, _1DV, _1ERPT, _1KORU, _1XUPT, _1SHKU, _1PRIUS);
  FZR1 = new _TFZR(_2PREB, _2PREM, _2CPIPT, _2KPPR, _2ERZPT, _2CIPT);
  URKM1 = new _TURK(_3PRZRM, _3PRZRP, _3ZVKU, _3ZVKP, _3POTKR, _3PZAKR, _3N1, _3N2, _3PAUZ, _3THPT, _3CZR, 
    _3SM1PT, _3SMPT, _3S0);
  TC = _4TC;
  PVRPP = _5PVRPP;
  RSM1 = _6RSM1;
  RERZ = _7RERZ;
  COUNT1 = new _TCOUNT();
}

_TSR1::~_TSR1()
{
}

void _TSR1::_SR(bool RPP, smallint XU, smallint SRK, smallint DOS1, smallint DOS2, smallint D, bool OTDS1, 
  bool OTDS2, smallint KOSR, smallint KOS1, smallint KOS2, smallint ZNK, smallint TKU, smallint VPR, smallint 
  DHN, bool RNR, bool PRVOS, bool PRREG, smallint ZN, smallint ZV, smallint EMN, smallint KP, smallint TI1, 
  smallint TI2, bool BLPR, bool BLUB, bool OTK, bool ZAK, smallint ZNZ, smallint ZVZ, smallint NLO, smallint 
  NLZ, smallint VKOR, smallint KM, smallint DK, smallint V, smallint SM, bool RM, smallint S0, smallint &XOS, 
  smallint &XPR, smallint &CI, smallint &ERZ, bool &OTKR, bool &ZAKR, smallint &DHNO, smallint &ER)
{
  smallint _5OUT1 = 0;
  smallint _6OUT1 = 0;
  smallint _0XOS = 0;
  smallint _0DPOS = 0;
  bool _0BVK = false;
  smallint _1XPR = 0;
  smallint _1ER = 0;
  smallint _1DHNO = 0;
  smallint _2CI = 0;
  smallint _2CPI = 0;
  smallint _2ERZ = 0;
  bool _2PVRPO = false;
  smallint _3SM1 = 0;
  bool _3OTKR = false;
  bool _3ZAKR = false;
  smallint _4TCO = 0;

  _5OUT1 = _RAZN(0,0);
  _6OUT1 = _SUMMA(0,0);
  FOS1->_FOS(RPP,SRK,SM,DOS1,DOS2,D,RM,OTDS1,OTDS2,0,KM,false,KOSR,KOS1,KOS2,PVRPP,PRREG,TC,_0XOS,_0DPOS,
    _0BVK);
  XOS = _0XOS;
  FPSTR1->_FPSTR(RPP,XU,D,_0XOS,_0DPOS,_0BVK,RERZ,PRVOS,PRREG,ZNK,TKU,VPR,DHN,RNR,PVRPP,TC,VKOR,KM,DK,_1XPR,
    _1ER,_1DHNO);
  XPR = _1XPR;
  ER = _1ER;
  DHNO = _1DHNO;
  FZR1->_FZR(RPP,_1ER,RSM1,PRREG,ZN,ZV,EMN,KP,TI1,TI2,RNR,PVRPP,TC,V,_2CI,_2CPI,_2ERZ,_2PVRPO);
  CI = _2CI;
  RERZ = _2ERZ;
  ERZ = _2ERZ;
  PVRPP = _2PVRPO;
  URKM1->_URK(RPP,true,_2CPI,BLPR,BLUB,OTK,ZAK,ZNZ,ZVZ,NLO,NLZ,_2CI,S0,TC,_3SM1,_3OTKR,_3ZAKR);
  RSM1 = _3SM1;
  OTKR = _3OTKR;
  ZAKR = _3ZAKR;
  _4TCO = COUNT1->_COUNT(TC);
  TC = _4TCO;
}

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

