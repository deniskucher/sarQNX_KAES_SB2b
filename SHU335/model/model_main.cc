

         







#include "SigChangeM.h"
#include "model.h"
#include "model_pasp.h"
#include "cdsface.h"
#include "cdshead.h"
#include <cdsinch.h>
#include <stdio.h>

#include "globals_m.h"


main(int argc, char*argv[])
{
  void * start, *finish;
  int i, res;
  start  =(void*)&cds::startSession;//NP
  finish =(void*)&cds::stopSession;//NP 
  Init_PM();
  Init_modelPasp();
  Init_model();
  CDS_OCCUP = false;//NP 
  res = cdsinch_init(argc,argv, &start, &finish);
  for (;;) 
  {
	res = cdsinch_begin(start); 
	    Read_SigM();
	    Init_VH();
        model_run();
        Write_SigM();
             
	res = cdsinch_end(finish);
  }
}; 


