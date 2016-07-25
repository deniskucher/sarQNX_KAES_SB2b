#include "ko3.h"
#include <sys/slog.h>

typedef short *pShort;
typedef int *pInt;
typedef float *pFloat;
typedef unsigned short *pUShort;

TKO3 *pKO3;
char pStat=0;       
char pStatPred=2;  // not master and not slave for 1st switch
char mode=0;
TBindSignal *err_count;
TBindSignal *sizeRez;
short countRep=0;
unsigned short chsum=0;
bool OnlyOneFault=true;

int V_CMD;
unsigned char bufCMD[MAX_MR];

TKO3::TKO3()
{
 kolbyte=0;
 kolbit=0;
 PrPack=true;
 PrUnPack=false;
 memset(&Buf[0],0,sizeBuf);
 pStart = &Buf[0];
 sizeKO3=0;
 posCurr=0;
 numPack=0;
 numPackT=0;
 kolPack=0;
 sizeDI=0;
 sizeDO=0;
 sizeDI=(Get_V_Zone(t_DI)<<1);
 sizeDO=(Get_V_Zone(t_DO)<<1);
}

TKO3::~TKO3()
{
}

void TKO3::pack(bool &b)
{
	
  kolbyte=(kolbit/8);
  switch (direction)
  { 
  case 1: if (b) pStart[kolbyte]|=mask[kolbit&7];
          else pStart[kolbyte]&=~mask[kolbit&7];
          break;
  case 2: b=(bool)(pStart[kolbyte]&mask[kolbit&7]);
          break;
  default:break;  
  }
  kolbit++;
}

void TKO3::pack(short &s)
{
  switch (direction)
  {  
  case 1: *(pShort)&pStart[kolbyte]=s;
          break;
  case 2: s=*(pShort)&pStart[kolbyte];
          break;
  default:break;  
  }
  kolbyte+=2;  
}

void TKO3::pack(int &i)
{
  switch (direction)
  {  
  case 1: *(pInt)&pStart[kolbyte]=i;
          break;
  case 2: i=*(pInt)&pStart[kolbyte];
          break;
  default:break;  
  }
  kolbyte+=4;  
}

void TKO3::pack(float &f)
{
  switch (direction)
  {  
  case 1: *(pFloat)&pStart[kolbyte]=f;
          break;
  case 2: f=*(pFloat)&pStart[kolbyte];
          break;
  default:break;  
  }
  kolbyte+=4;  
}

void TKO3::pack(unsigned char &c)
{
  switch (direction)
  { 
  case 1: pStart[kolbyte]=c;
          break;
  case 2: c=pStart[kolbyte];
          break;
  default:break;  
  }
  kolbyte++;
}

void TKO3::pack(unsigned short &s)
{
  switch (direction)
  {  
  case 1: *(pUShort)&pStart[kolbyte]=s;
          break;
  case 2: s=*(pUShort)&pStart[kolbyte];
          break;
  default:break;  
  }
  kolbyte+=2;  
}

void TKO3::pack(void *v)
{
}	

void TKO3::pack_run(unsigned char *pB, short BufLen)
{
  int len = 0;	
  std::cout << "PrPack=" << PrPack << std::endl;	
  if (PrPack)        // data preparation for transmit
  {
    std::cout << "Packing" << std::endl;
    direction=1;     // Pack
    kolbyte=0;
    kolbit=0;
    Pack_All();
    if (kolbyte >= sizeBuf) 
    {
    std::cout << "KO3.Error! Please increase KO3 sizeBuf to " << kolbyte << std::endl;
    }
    std::cout << "KO3.size=" << kolbyte << std::endl;
    pStart[kolbyte]=mode;
    kolbyte++;
    memset(&bufCMD[0],0,MAX_MR);
    Get_Zapr(t_REZ_CONT_CMD,&bufCMD[0],&V_CMD);
    memcpy(&pStart[kolbyte],&bufCMD[0],MAX_MR);
    kolbyte+=MAX_MR;
    Get_Zapr(t_IFO_VU_DI,&pStart[kolbyte],&len);
    kolbyte+=len;    
    len = 0;
    Get_Zapr(t_IFO_VU_DO,&pStart[kolbyte],&len);
    kolbyte+=len;
    chsum=0;
    chsum=Kss_IRA(pStart,(unsigned int)kolbyte); // calculate
    pStart[kolbyte]=chsum;kolbyte++;             // and pack
    pStart[kolbyte]=chsum >> 8;kolbyte++;      // check sum
    std::cout << "KO3main.Check sum=" << chsum << std::endl;
    sizeKO3=kolbyte;
    posCurr=0;
    numPack=0;
    kolPack=(sizeKO3/(BufLen-4));
    if ((sizeKO3-kolPack*(BufLen-4))!=0) kolPack++;
    PrPack=false;
  }  
  // data transmitting   
          
  memset(pB,0,BufLen);
  pB[0]=sizeKO3;
  pB[1]=sizeKO3 >> 8;
  pB[2]=kolPack;
  std::cout << "KO3.kolPack=" << short(kolPack) << std::endl;
  pB[3]=numPack;
  std::cout << "KO3.numPack=" << short(numPack) << std::endl;
  memcpy(&pB[4],&Buf[posCurr],(BufLen-4));
  posCurr=posCurr+(BufLen-4);
  numPack++;
  if (posCurr >= sizeKO3)         // all data transmit
  {
    PrPack=true;
    std::cout << "KO3.Pack OK!!!!!" << std::endl;
  }  
}

int TKO3::unpack_run(unsigned char *pB, short BufLen)
{
  // data receiving data
  sizeKO3=pB[1]*0x100+pB[0];
  kolPack=pB[2];
  numPack=pB[3];
  if (numPack != numPackT)
  {	
 	slogf(_SLOG_SETCODE(25,_SLOG_INFO),_SLOG_INFO,"Error ko3: %d <> %d",
  		numPack, numPackT);
  	 return -1;
  }
  numPackT++;
  if (numPackT==kolPack) numPackT=0;
  memcpy(&Buf[posCurr],&pB[4],(BufLen-4));
  std::cout << "KO3.posCurr=" << posCurr << std::endl;
  posCurr=posCurr+(BufLen-4);
  if (posCurr >= sizeKO3) PrUnPack=true;   // all data recieved 
  
  std::cout << "KO3.PrUnPack=" << (short)PrUnPack << std::endl;
  if (PrUnPack) // Data unpacking
  {
    direction=2; // UnPack
    kolbyte=0;
    kolbit=0; 
    std::cout << "resSizeKO3=" << sizeKO3 << std::endl;
    chsum=0;
    chsum=(pStart[sizeKO3-1]*0x100+pStart[sizeKO3-2]);
    std::cout << "KO3res.Check sum=" << chsum << std::endl;
    std::cout << "Kss_IRA.Check sum=" << Kss_IRA(pStart,(unsigned int)(sizeKO3-2)) << std::endl;
    if (Kss_IRA(pStart,(unsigned int)(sizeKO3-2))==chsum) // check sum control    
    {
    Pack_All();
    mode=pStart[kolbyte];
    kolbyte++;	
    std::cout << "ko3.mode" << (short)mode << std::endl;
    Put_Regim_Shu(mode);
    memset(&bufCMD[0],0,MAX_MR);	
    memcpy(&bufCMD[0],&pStart[kolbyte],MAX_MR);
    Add_Otv(t_REZ_CONT_CMD,&bufCMD[0],MAX_MR);	
    kolbyte+=MAX_MR;
    Add_Zapr(1111,t_IFO_VU,&pStart[kolbyte],(sizeDI+sizeDO)<<1);
    kolbyte+=(sizeDI+sizeDO)<<1;   // znach + maski
    std::cout << "KO3.UnPack OK!!!!!!!" << std::endl;
    memset(&Buf[0],0,sizeBuf);
    }
    posCurr=0;
    PrUnPack=false;    
  }
  return 0;
}

void KO3_Run()
{
  const short BufL=500;       // Volume of transmit/recieve buffer to/from ARM 
  unsigned char Buffer[BufL];
  int SizeRecBuf;
  
  Get_Status_Shu(pStat,mode);
//  pStat=1; //for debug
  if (pStatPred!=pStat)       // if status changed
  {
    memset(&Buffer[0],0,BufL);
    pKO3 -> PrPack=true;
    pKO3 -> PrUnPack=false;
    pKO3 -> sizeKO3=0;
    pKO3 -> posCurr=0;
    pKO3 -> numPack=0;
    pKO3 -> kolPack=0;
    pKO3 -> numPackT=0;
    OnlyOneFault=true;
    Delete_LBD(PC_ARM_REZ_BD);     
  } 
  std::cout << "KO3.pStat=" << short(pStat) << std::endl;
//////////////  if MAIN ////////////////////////////////////////////////////////  
  if (pStat==1) 
  {  
    pKO3 -> pack_run(&Buffer[0],BufL);
    Add_Zapr(1111,PC_ARM_REZ_BD,&Buffer[0],BufL);
    std::cout << "KO3.ADD_ZAPR" << std::endl;
    sizeRez -> Put_Value(pKO3 -> sizeKO3);
  }
//////////////  if Reserve /////////////////////////////////////////////////////
  else if (pStat==0)
  {
    memset(&Buffer[0],0,BufL);
    if (Get_LBD(PC_ARM_REZ_BD,&Buffer[0],SizeRecBuf)==1) // if data recived
    {
      Delete_LBD(PC_ARM_REZ_BD); 
      if (SizeRecBuf==BufL) 
      {
      	if (pKO3 -> unpack_run(&Buffer[0],BufL)==-1)     // if slave losed data
      	{                                                // repeat
      	 pKO3 -> numPackT=0;                             // from the 1st packet
      	 pKO3 -> posCurr=0;	
     	       if (OnlyOneFault) countRep++;
     	       OnlyOneFault=false;
     	       err_count -> Put_Value(countRep++);             // write to DSA
  	       std::cout << "KO3.countRep=" << countRep << std::endl;
      	}	
      	else OnlyOneFault=true;
      	std::cout << "KO3.numPack="  << (short)pKO3 -> numPack << std::endl;
      	std::cout << "KO3.numPackT=" << (short)pKO3 -> numPackT << std::endl;
      }	
      else std::cout << "KO3.SizeRecBuf=" << SizeRecBuf << " is wrong" << std::endl;
    }	 
    else std::cout << "KO3.Get_LBD.LBD not received" << std::endl;    
  }  
  pStatPred=pStat;
////////////////////////////////////////////////////////////////////////////////  
}
