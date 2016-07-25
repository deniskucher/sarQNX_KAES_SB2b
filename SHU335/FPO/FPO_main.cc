

         







#include "tasks.h"
#include "KD.h"
#include "SigChange.h"
#include "uobjects.h"
#include "ko3.h"
#include "vizov.h"
#include <cdsinch.h>
#include <stdio.h>


main(int argc, char*argv[])
{
  void * start, *finish;
  start  =(void*)&cds::startSession;//NP
  finish =(void*)&cds::stopSession;//NP
 
  int i, res;
  cds::startSession();
  CDS_OCCUP = true; //NP
  Init_P();
  Init_KD();
  InitObjects();
  InitPulse();
  pKO3 = new TKO3();
  MACRO_CreateSignal("ERR_COUNT_KO3", err_count, t_DSA, "FPO_main");
  MACRO_CreateSignal("SIZE_REZ", sizeRez, t_DSA, "FPO_main");
  MACRO_CreateSignal("GEN_ERROR", Gen_Err, t_DSD, "FPO_main");
  MACRO_CreateSignal("IMP_ERROR", Gen_ErrP, t_DSD, "FPO_main");
  MACRO_CreateSignal("REGIM_NALAD", Nal, t_DSD, "FPO_main");
  
  cds::stopSession();
  CDS_OCCUP = false;//NP
  
  res = cdsinch_init(argc,argv, &start, &finish);
  for (;;) 
  {
	res = cdsinch_begin(start); 
//	cds::startSession();NP
    if (Get_Start_FPO())
    	{
	    Read_Sig();
	    KO3_Run();
	    Naladka();
	    KD_RUN();
        _TaskFPO();
        Vizov();
        Write_Sig();             
       	};
//	cds::stopSession();NP
	res = cdsinch_end(finish);
  }
}; 


