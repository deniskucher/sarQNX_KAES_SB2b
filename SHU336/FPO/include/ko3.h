#ifndef KO3H
#define KO3H
#include "ko3_FPO.h"
#include "lib_PC.h"
#include "ObmenARM.h"
#include "DSA.h"
#include "Signal.h"
#include <iostream>
#include <string.h>

const unsigned char mask[8]={0x01,0x02,0x04,0x08,      //array of masks
                             0x10,0x20,0x40,0x80};

const short sizeBuf=5000;

class TKO3
{
  public:
  short kolbyte;              // Quantity of KO3_FPO
  short kolbit;               // Bit counter
  char direction;             // 1-Pack 2-UnPack
  unsigned char *pStart;      // Pointer to Buf[0]
  bool PrPack;       
  bool PrUnPack;
  short sizeKO3;              // Total volume
  short sizeDI;               // DI volume
  short sizeDO;               // DO volume    
  short posCurr;              // Position of current packet  
  unsigned char numPack;      // Packet number
  unsigned char kolPack;      // Quantity of packets
  unsigned char numPackT;     // It will be current packet number
  unsigned char Buf[sizeBuf]; // Recieve - Transmit buffer size of sizeBuf
  TKO3();
  ~TKO3();
  void pack(bool &b);
  void pack(short &s);
  void pack(int &i);
  void pack(float &f); 
  void pack(unsigned char &c);
  void pack(unsigned short &s); 
  void pack(void *v);
  void pack_run(unsigned char *pB, short BufLen);
  int  unpack_run(unsigned char *pB, short BufLen);
};

extern TKO3 *pKO3;
extern char pStat;
extern char pStatPred;
extern char mode;
extern void KO3_Run();
extern TBindSignal *err_count;
extern TBindSignal *sizeRez;

#endif

