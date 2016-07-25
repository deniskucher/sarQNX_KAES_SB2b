#ifndef uclassesH
#define uclassesH
#include "usertype.h"

smallint _RAZN(const smallint IN1, const smallint IN2);
smallint _SUMMA(const smallint IN1, const smallint IN2);

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
//__________________________________ TKPIM __________________________________

class _TKPIM
{
public:
  bool ROTK;
  bool RZAK;
  _TKPIM(bool _0ROTK, bool _1RZAK);
  ~_TKPIM();
  void _KPIM(const bool NO, const bool NZ, bool &ZAK, bool &OTK,
  bool &NP);
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
//__________________________________ TSTrigger __________________________________

class _TSTrigger
{
public:
  bool St;
  _TSTrigger(bool _0St);
  ~_TSTrigger();
  void _STrigger(const bool S, const bool R, bool &_1, bool &_0);
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
//__________________________________ TFPATR __________________________________

class _TFPATR
{
public:
  smallint XPRPT;
  smallint RER;
  smallint XUR;
  _TFPATR(smallint _0XPRPT, smallint _1RER, smallint _2XUR);
  ~_TFPATR();
  void _FPATR(const bool RPP, const smallint XUI, const smallint D,
  const bool PRREG, const smallint VPR, const smallint DHNI,
  const bool RNR, const bool PVRPP_P, const smallint TC, smallint &XPR,
  smallint &DHNO, smallint &ER);
};
//__________________________________ TFZR __________________________________

class _TFZR
{
public:
  bool PREB;
  bool PREM;
  smallint CPIPT;
  smallint KPPR;
  smallint ERZPT;
  smallint CIPT;
  _TFZR(bool _0PREB, bool _1PREM, smallint _2CPIPT, smallint _3KPPR, smallint _4ERZPT, smallint _5CIPT);
  ~_TFZR();
  void _FZR(const bool RPP, const smallint ER, const smallint SM1,
  const bool PRREG, const smallint ZN, const smallint ZV, const smallint EMN,
  const smallint KP, const smallint TI1, const smallint TI2,
  const bool RNR, const bool PVRPI, const smallint TC, const smallint V,
  smallint &CI, smallint &CPI, smallint &ERZ, bool &PVRPO);
};
//__________________________________ TURK __________________________________

class _TURK
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
  smallint PAUZ;
  smallint THPT;
  smallint CZR;
  smallint SM1PT;
  smallint SMPT;
  smallint S0;
  _TURK(bool _0PRZRM, bool _1PRZRP, bool _2ZVKU, bool _3ZVKP, bool _4POTKR, bool _5PZAKR, smallint _6N1, 
    smallint _7N2, smallint _8PAUZ, smallint _9THPT, smallint _10CZR, smallint _11SM1PT, smallint _12SMPT, 
    smallint _13S0);
  ~_TURK();
  void _URK(const bool RPP, const bool AVT, const smallint CPI,
  const bool BLPR, const bool BLUB, const bool RKOTK, const bool RKZAK,
  const smallint ZNZ, const smallint ZVZ, const smallint NLO,
  const smallint NLZ, const smallint CI, const smallint S0, const smallint TC,
  smallint &SM1, bool &OTKR, bool &ZAKR);
};
//__________________________________ TCOUNT __________________________________

class _TCOUNT
{
public:
  _TCOUNT();
  ~_TCOUNT();
  smallint _COUNT(const smallint TC);
};
//__________________________________ TAR1 __________________________________

class _TAR1
{
public:
  _TFPATR *FPATR1;
  _TFZR *FZR1;
  _TURK *URKM1;
  bool PVRPP;
  smallint TC;
  smallint RSM1;
  _TCOUNT *COUNT1;
  _TAR1(smallint _0XPRPT, smallint _0RER, smallint _0XUR, bool _1PREB, bool _1PREM, smallint _1CPIPT, 
    smallint _1KPPR, smallint _1ERZPT, smallint _1CIPT, bool _2PRZRM, bool _2PRZRP, bool _2ZVKU, bool _2ZVKP, 
    bool _2POTKR, bool _2PZAKR, smallint _2N1, smallint _2N2, smallint _2PAUZ, smallint _2THPT, smallint _2CZR, 
    smallint _2SM1PT, smallint _2SMPT, smallint _2S0, bool _3PVRPP, smallint _4TC, smallint _5RSM1);
  ~_TAR1();
  void _AR(bool RPP, smallint XU, smallint D, bool PRREG, smallint VPR, smallint DHNI, bool RNR, smallint ZN, 
    smallint ZV, smallint EMN, smallint KP, smallint TI1, smallint TI2, bool BLPR, bool BLUB, bool OTK, bool ZAK, 
    smallint ZNZ, smallint ZVZ, smallint NLO, smallint NLZ, smallint V, smallint S0, smallint &DHNO, smallint 
    &XPR, smallint &CI, smallint &ERZ, bool &OTKR, bool &ZAKR, smallint &ER);
};
//__________________________________ TMIMKD __________________________________

class _TMIMKD
{
public:
  bool PV;
  smallint SM_V;
  bool RMPT;
  smallint N1;
  smallint N2;
  smallint RPRK;
  bool NESPT;
  smallint SH;
  _TMIMKD(bool _0PV, smallint _1SM_V, bool _2RMPT, smallint _3N1, smallint _4N2, smallint _5RPRK, bool 
    _6NESPT, smallint _7SH);
  ~_TMIMKD();
  void _MIMKD(const bool AVT, const smallint SRK, const bool SRKF,
  const bool SRKOKD, const bool OTKR, const bool ZAKR, const smallint NLO,
  const smallint NLZ, const smallint DP1, const smallint DP2,
  const bool RKOTK, const bool RKZAK, const smallint TH, const smallint TRK,
  const bool SBRN, smallint &SM, bool &RM, bool &NES, smallint &PRK,
  smallint &S0);
};
//__________________________________ TFOS __________________________________

class _TFOS
{
public:
  bool PODRK;
  bool PODM;
  bool POD1;
  bool POD2;
  smallint POSRK;
  smallint POSRKPT;
  smallint POSM;
  smallint POSMPT;
  smallint POS1;
  smallint POS1PT;
  smallint POS2;
  smallint POS2PT;
  smallint KOSRPT;
  smallint PRKPT;
  smallint KOS1PT;
  smallint KOS2PT;
  smallint DOS1PT;
  smallint DOS2PT;
  smallint POSRKP;
  smallint POSMP;
  smallint POS1P;
  smallint POS2P;
  smallint SMPT;
  smallint RXOS;
  smallint RDPOS;
  bool RBVK;
  smallint DPT;
  smallint KMPT;
  _TFOS(bool _0PODRK, bool _1PODM, bool _2POD1, bool _3POD2, smallint _4POSRK, smallint _5POSRKPT, smallint 
    _6POSM, smallint _7POSMPT, smallint _8POS1, smallint _9POS1PT, smallint _10POS2, smallint _11POS2PT, smallint 
    _12KOSRPT, smallint _13PRKPT, smallint _14KOS1PT, smallint _15KOS2PT, smallint _16DOS1PT, smallint _17DOS2PT, 
    smallint _18POSRKP, smallint _19POSMP, smallint _20POS1P, smallint _21POS2P, smallint _22SMPT, smallint 
    _23RXOS, smallint _24RDPOS, bool _25RBVK, smallint _26DPT, smallint _27KMPT);
  ~_TFOS();
  void _FOS(const bool RPP, const smallint SRK, const smallint SM,
  const smallint DOS1, const smallint DOS2, const smallint D,
  const bool RM, const bool OTDS1, const bool OTDS2, const smallint DPOSI,
  const smallint KM, const bool BVKI, const smallint KOSR, const smallint KOS1,
  const smallint KOS2, const bool PVRPP_F, const bool PRREG,
  const smallint TC, smallint &XOS, smallint &DPOS, bool &BVK);
};
//__________________________________ TFPSTR __________________________________

class _TFPSTR
{
public:
  smallint DX;
  smallint UK;
  smallint XPRPT;
  smallint DV;
  smallint ERPT;
  smallint KORU;
  smallint XUPT;
  smallint SHKU;
  bool PRIUS;
  _TFPSTR(smallint _0DX, smallint _1UK, smallint _2XPRPT, smallint _3DV, smallint _4ERPT, smallint _5KORU, 
    smallint _6XUPT, smallint _7SHKU, bool _8PRIUS);
  ~_TFPSTR();
  void _FPSTR(const bool RPP, const smallint XU, const smallint D,
  const smallint XOS, const smallint DPOS, const bool BVK, const smallint ERZ,
  const bool PRVOS, const bool PRREG, const smallint ZNK, const smallint TKU,
  const smallint VPR, const smallint DHNI, const bool RNR, const bool PVRPP_S,
  const smallint TC, const smallint VKOR, const smallint KM,
  const smallint DK, smallint &XPR, smallint &ER, smallint &DHNO);
};
//__________________________________ TSR1 __________________________________

class _TSR1
{
public:
  _TFOS *FOS1;
  _TFPSTR *FPSTR1;
  _TFZR *FZR1;
  _TURK *URKM1;
  smallint TC;
  bool PVRPP;
  smallint RSM1;
  smallint RERZ;
  _TCOUNT *COUNT1;
  _TSR1(bool _0PODRK, bool _0PODM, bool _0POD1, bool _0POD2, smallint _0POSRK, smallint _0POSRKPT, smallint 
    _0POSM, smallint _0POSMPT, smallint _0POS1, smallint _0POS1PT, smallint _0POS2, smallint _0POS2PT, smallint 
    _0KOSRPT, smallint _0PRKPT, smallint _0KOS1PT, smallint _0KOS2PT, smallint _0DOS1PT, smallint _0DOS2PT, 
    smallint _0POSRKP, smallint _0POSMP, smallint _0POS1P, smallint _0POS2P, smallint _0SMPT, smallint _0RXOS, 
    smallint _0RDPOS, bool _0RBVK, smallint _0DPT, smallint _0KMPT, smallint _1DX, smallint _1UK, smallint 
    _1XPRPT, smallint _1DV, smallint _1ERPT, smallint _1KORU, smallint _1XUPT, smallint _1SHKU, bool _1PRIUS, 
    bool _2PREB, bool _2PREM, smallint _2CPIPT, smallint _2KPPR, smallint _2ERZPT, smallint _2CIPT, bool _3PRZRM, 
    bool _3PRZRP, bool _3ZVKU, bool _3ZVKP, bool _3POTKR, bool _3PZAKR, smallint _3N1, smallint _3N2, smallint 
    _3PAUZ, smallint _3THPT, smallint _3CZR, smallint _3SM1PT, smallint _3SMPT, smallint _3S0, smallint _4TC, 
    bool _5PVRPP, smallint _6RSM1, smallint _7RERZ);
  ~_TSR1();
  void _SR(bool RPP, smallint XU, smallint SRK, smallint DOS1, smallint DOS2, smallint D, bool OTDS1, bool 
    OTDS2, smallint KOSR, smallint KOS1, smallint KOS2, smallint ZNK, smallint TKU, smallint VPR, smallint DHN, 
    bool RNR, bool PRVOS, bool PRREG, smallint ZN, smallint ZV, smallint EMN, smallint KP, smallint TI1, smallint 
    TI2, bool BLPR, bool BLUB, bool OTK, bool ZAK, smallint ZNZ, smallint ZVZ, smallint NLO, smallint NLZ, 
    smallint VKOR, smallint KM, smallint DK, smallint V, smallint SM, bool RM, smallint S0, smallint &XOS, 
    smallint &XPR, smallint &CI, smallint &ERZ, bool &OTKR, bool &ZAKR, smallint &DHNO, smallint &ER);
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
