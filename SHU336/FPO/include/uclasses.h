#ifndef uclassesH
#define uclassesH
#include "usertype.h"

float _SmallintToFloat(const smallint X, const float MAX);
smallint _FloatToSmallint(const float X, const float MAX);
smallint _RAZN(const smallint IN1, const smallint IN2);

//__________________________________ TMNMRI __________________________________

class _TMNMRI
{
public:
  _TMNMRI();
  ~_TMNMRI();
  void _MNMRI(const smallint LBDMRI, bool &SO_SR1, bool &SZ_SG1,
  bool &A03_A01, bool &A04_A02, bool &VH1VU, bool &VH2VU, bool &DUPRVU,
  bool &DUUBVU, bool &BRAKMR, bool &VUH1D, bool &VUH2D, bool &REZ1_SR,
  bool &REZ2_SG, bool &SADF, bool &SA1F, bool &SA2F);
};
//__________________________________ TSTrigger __________________________________

class _TSTrigger
{
public:
  bool St;
  _TSTrigger(bool _0St);
  ~_TSTrigger();
  void _STrigger(const bool S, const bool R, bool &_1, bool &_0);
};
//__________________________________ TKPIM __________________________________

class _TKPIM
{
public:
  _TSTrigger *STr1;
  _TSTrigger *STr2;
  _TKPIM(bool _0St, bool _1St);
  ~_TKPIM();
  void _KPIM_K(bool B02, bool B01, bool &OTK, bool &ZAK, bool &NP);
};
//__________________________________ TAF __________________________________

class _TAF
{
public:
  bool PVAPZ;
  smallint RD;
  _TAF(bool _0PVAPZ, smallint _1RD);
  ~_TAF();
  smallint _AF(const bool SBRN, const smallint VH, const smallint TF,
  const smallint AMX);
};
//__________________________________ TOffDelay __________________________________

class _TOffDelay
{
public:
  smallint Count;  //Счетчик тактов задержки
  bool OldA;  //Предыдущее значение входа А
  _TOffDelay(smallint _0Count, bool _1OldA);
  ~_TOffDelay();
  bool _OffDelay(const bool Decey, const smallint T);
};
//__________________________________ TLVR __________________________________

class _TLVR
{
public:
  bool PRSTR;
  int T;
  int T1;
  bool PRM;
  smallint TCLVR;
  bool RAVT;
  bool RLK;
  bool RLZ;
  bool RZS;
  bool RNBRU;
  bool PV;
  smallint SH;
  _TLVR(bool _0PRSTR, int _1T, int _2T1, bool _3PRM, smallint _4TCLVR, bool _5RAVT, bool _6RLK, bool _7RLZ, 
    bool _8RZS, bool _9RNBRU, bool _10PV, smallint _11SH);
  ~_TLVR();
  void _LVR(const bool BRUAV, const bool BRUDU, const bool ZH,
  const bool ZHBL, const bool OTKD, const bool NPRK, const bool STR,
  const bool REMRK, const smallint Tv, bool &AVT, bool &LK, bool &LZ,
  bool &ZS, bool &NBRU);
};
//__________________________________ TSPulse __________________________________

class _TSPulse
{
public:
  smallint Count;
  bool OldA;
  _TSPulse(smallint _0Count, bool _1OldA);
  ~_TSPulse();
  bool _SPulse(const bool Front, const smallint T);
};
//__________________________________ TOCDSI __________________________________

class _TOCDSI
{
public:
  bool prin;  //признак первого такта выполнения блока
  smallint hin;  //начение входа SiIn на предыдущем такте
  smallint hin_n;
  _TOCDSI(bool _0prin, smallint _1hin, smallint _2hin_n);
  ~_TOCDSI();
  smallint _OCDSI(const smallint SiIn);
};
//__________________________________ Tintegrator1 __________________________________

class _Tintegrator1
{
public:
  float Intgr;
  _Tintegrator1(float _0Intgr);
  ~_Tintegrator1();
  smallint _integrator1(const bool RISH, const bool RINT,
  const float VH1, const float VH2, const smallint Ti);
};
//__________________________________ TLFUKN __________________________________

class _TLFUKN
{
public:
  _TSPulse *SP;
  _TOCDSI *OCD;
  _Tintegrator1 *INT;
  bool STOPM;
  bool STOPB;
  _TLFUKN(smallint _0Count, bool _0OldA, bool _1prin, smallint _1hin, smallint _1hin_n, float _2Intgr, bool 
    _3STOPM, bool _4STOPB);
  ~_TLFUKN();
  smallint _LFUKN(smallint UST, smallint UMIN, smallint UMAX, smallint VUST, bool KNPR, bool KNUB);
};
//__________________________________ TOnDelay __________________________________

class _TOnDelay
{
public:
  smallint Count;  //Счетчик тактов задержки
  bool Pd;  //Признак окончания задержки
  _TOnDelay(smallint _0Count, bool _1Pd);
  ~_TOnDelay();
  bool _OnDelay(const bool Front, const smallint T);
};
//__________________________________ TCOUNT __________________________________

class _TCOUNT
{
public:
  _TCOUNT();
  ~_TCOUNT();
  smallint _COUNT(const smallint TC);
};
//__________________________________ TMinHyst __________________________________

class _TMinHyst
{
public:
  bool old;
  bool prin;
  _TMinHyst(bool _0old, bool _1prin);
  ~_TMinHyst();
  bool _MinHyst(const smallint CP, const smallint Min,
  const smallint Delta);
};
//__________________________________ TUCounter __________________________________

class _TUCounter
{
public:
  smallint CntSt;  //состояние счетчика
  bool Pov;  //Признак переполнения
  _TUCounter(smallint _0CntSt, bool _1Pov);
  ~_TUCounter();
  void _UCounter(const bool Count, const smallint Limit, const bool Reset,
  smallint &Value, bool &Over);
};
//__________________________________ TMIMKD_K __________________________________

class _TMIMKD_K
{
public:
  bool P_SM;
  smallint NLO_1;
  smallint NLZ_1;
  smallint TH_1;
  smallint TRK_1;
  _TSPulse *Spls1;
  _Tintegrator1 *Int_SM;
  _TUCounter *NLO_Cnt;
  _TUCounter *NLZ_Cnt;
  bool Stop_int;
  _TUCounter *TRK_Cnt;
  _TMIMKD_K(bool _0P_SM, smallint _1NLO_1, smallint _2NLZ_1, smallint _3TH_1, smallint _4TRK_1, smallint 
    _5Count, bool _5OldA, float _6Intgr, smallint _7CntSt, bool _7Pov, smallint _8CntSt, bool _8Pov, bool 
    _9Stop_int, smallint _10CntSt, bool _10Pov);
  ~_TMIMKD_K();
  void _MIMKD_K(bool AVT, smallint SRK, bool SRKF, bool SRKOKD, bool OTKR, bool ZAKR, smallint NLO, smallint 
    NLZ, smallint DP1, smallint DP2, bool RKOTK, bool RKZAK, smallint TH, smallint TRK, bool SBRN, smallint &SM, 
    bool &RM, bool &NES, smallint &PRK);
};
//__________________________________ TFPATR_K __________________________________

class _TFPATR_K
{
public:
  smallint XPRPT;
  smallint XUR;
  _TFPATR_K(smallint _0XPRPT, smallint _1XUR);
  ~_TFPATR_K();
  void _FPATR_K(const bool RPP, const smallint XUI, const smallint D, 
  const smallint VPR, const smallint DHNI, const bool RNR, const bool PVRPP_P, 
  const smallint TC, smallint &XPR, smallint &DHNO);
};
//__________________________________ TURK_K __________________________________

class _TURK_K
{
public:
  bool PRZRM;
  bool PRZRP;
  bool ZVKU;
  bool ZVKP;
  bool POTKR;
  bool PZAKR;
  smallint N1;
  smallint N2;
  smallint SM1PT;
  smallint SMPT;
  smallint PAUZ;
  smallint S0;
  smallint CZR;
  _TURK_K(bool _0PRZRM, bool _1PRZRP, bool _2ZVKU, bool _3ZVKP, bool _4POTKR, bool _5PZAKR, smallint _6N1, 
    smallint _7N2, smallint _8SM1PT, smallint _9SMPT, smallint _10PAUZ, smallint _11S0, smallint _12CZR);
  ~_TURK_K();
  void _URK_K(const bool RPP, const bool AVT, const smallint CPI, 
  const bool BLPR, const bool BLUB, const bool RKOTK, const bool RKZAK, 
  const smallint ZNZ, const smallint ZVZ, const smallint NLO, 
  const smallint NLZ, const smallint CI, const smallint TH, const smallint TC, 
  smallint &SM1, bool &OTKR, bool &ZAKR);
};
//__________________________________ TFZR_K __________________________________

class _TFZR_K
{
public:
  smallint CPIPT;
  smallint CIPT;
  smallint KPPR;
  smallint ERZPT;
  _TFZR_K(smallint _0CPIPT, smallint _1CIPT, smallint _2KPPR, smallint _3ERZPT);
  ~_TFZR_K();
  void _FZR_K(const bool RPP, const smallint ER, const bool PRER,
  const smallint SM1, const smallint EMN, const smallint KP,
  const smallint TI1, const smallint TI2, const bool RNR, const bool PVRPI,
  const smallint TC, smallint &CI, smallint &CPI, smallint &ERZ,
  bool &PVRPO);
};
//__________________________________ TMaxHyst __________________________________

class _TMaxHyst
{
public:
  bool old;
  bool prin;  //Признак первого такта выполнения
  _TMaxHyst(bool _0old, bool _1prin);
  ~_TMaxHyst();
  bool _MaxHyst(const smallint CP, const smallint Max, 
  const smallint Delta);
};
//__________________________________ TERGIST __________________________________

class _TERGIST
{
public:
  _TMaxHyst *MaxH1;
  _TERGIST(bool _0old, bool _0prin);
  ~_TERGIST();
  void _ERGIST(bool PRREG, bool RPP, smallint XPR, smallint D, smallint ZN, smallint ZV, smallint &ERO, bool 
    &PRER);
};
//__________________________________ TFOS_K __________________________________

class _TFOS_K
{
public:
  bool PODRK;
  bool PODM;
  smallint POSRK;
  smallint POSRKPT;
  smallint POSM;
  smallint POSMPT;
  smallint KOSRPT;
  smallint PRKPT;
  smallint POSRKP;
  smallint POSMP;
  smallint SMPT;
  smallint RXOS;
  smallint RDPOS;
  bool RBVK;
  smallint DPT;
  smallint KMPT;
  _TFOS_K(bool _0PODRK, bool _1PODM, smallint _2POSRK, smallint _3POSRKPT, smallint _4POSM, smallint _5POSMPT,
     smallint _6KOSRPT, smallint _7PRKPT, smallint _8POSRKP, smallint _9POSMP, smallint _10SMPT, smallint _11RXOS,
     smallint _12RDPOS, bool _13RBVK, smallint _14DPT, smallint _15KMPT);
  ~_TFOS_K();
  void _FOS_K(const bool RPP, const smallint SRK, const smallint SM,
  const smallint D, const bool RM, const smallint KM, const smallint KOSR,
  const bool PVRPP_F, const bool PRREG, const smallint TC, smallint &XOS,
  smallint &DPOS, bool &BVK);
};
//__________________________________ TFPSTR_K __________________________________

class _TFPSTR_K
{
public:
  smallint DX;
  smallint DV;
  smallint XUPT;
  smallint SHKU;
  smallint UK;
  smallint ERPT;
  smallint KORU;
  smallint XPRPT;
  bool PRIUS;
  _TFPSTR_K(smallint _0DX, smallint _1DV, smallint _2XUPT, smallint _3SHKU, smallint _4UK, smallint _5ERPT, 
    smallint _6KORU, smallint _7XPRPT, bool _8PRIUS);
  ~_TFPSTR_K();
  void _FPSTR_K(const bool RPP, const smallint XU, const smallint D,
  const smallint XOS, const smallint DPOS, const bool BVK, const smallint ERZ,
  const smallint ZNK, const smallint TKU, const smallint VPR,
  const smallint DHNI, const bool RNR, const bool PVRPP_S, const smallint VKOR,
  const smallint KM, const smallint DK, const smallint TC, smallint &XPR,
  smallint &DHNO);
};
//__________________________________ TButtonState __________________________________

class _TButtonState
{
public:
  bool old;
  bool St;
  _TButtonState(bool _0old, bool _1St);
  ~_TButtonState();
  bool _ButtonState(const bool Click);
};
//__________________________________ TETrigger __________________________________

class _TETrigger
{
public:
  bool St;
  _TETrigger(bool _0St);
  ~_TETrigger();
  void _ETrigger(const bool S, const bool R, bool &_1, bool &_0);
};
//__________________________________ TOCHK __________________________________

class _TOCHK
{
public:
  smallint S1;
  smallint S2;
  smallint S3;
  smallint SV;
  smallint SV1;
  smallint SV2;
  smallint SV3;
  smallint SV4;
  smallint SV5;
  smallint SV6;
  smallint SHK;
  smallint PV;
  smallint RKUIO;
  smallint RINHOIR;
  bool RBCHV;
  _TOCHK(smallint _0S1, smallint _1S2, smallint _2S3, smallint _3SV, smallint _4SV1, smallint _5SV2, smallint 
    _6SV3, smallint _7SV4, smallint _8SV5, smallint _9SV6, smallint _10SHK, smallint _11PV, smallint _12RKUIO, 
    smallint _13RINHOIR, bool _14RBCHV);
  ~_TOCHK();
  void _OCHK(const bool RPU, const bool OTKR, const bool ZAKR,
  smallint &KUIO, smallint &INHOIR, bool &BCHV);
};
//__________________________________ TMNMRO __________________________________

class _TMNMRO
{
public:
  _TMNMRO();
  ~_TMNMRO();
  smallint _MNMR0(const bool ZBPR, const bool ZBUB, const bool ZO, 
  const bool ZZ, const bool BPR, const bool BUB, const bool LOGPR, 
  const bool LOGUB, const bool VH1, const bool VH2, const bool VH3, 
  const bool VH4, const bool REM, const bool ZVK_AVT, const bool KNMRPR, 
  const bool KNMRUB);
};
#endif
