.SUFFIXES = .cc .o 
CDSPRJ=/opt/cds/kernel:/home/BPO/my_lib/include:/opt/include:./include
#CDSPRJ=/home/BPO/cds:/home/BPO/my_lib/include:/opt/include

CFLAG=-c -g -V 3.3.5,gcc_ntox86 -Y _gpp -I $(CDSPRJ)
#LFLAG=-g -L $(CDSPRJ):/home/BPO/my_lib
LFLAG=-g -V 3.3.5,gcc_ntox86 -Y _gpp -L /opt/cds/kernel:/home/BPO/my_lib

#LFLAG= /home/FPO/
#SOLIB= -lcds -l BPO_PC
#SOLIB1=$(SOLIB) -l socket -l cdsinch
SOLIB1=-lcds -lBPO_PC -l/lib/libcdsinch.a

OBJS=FPO_main.o SHU221.o SigChange.o  KD_Classes.o KD.o \
     globals.o uobjects.o uclasses.o tasks.o \
     ko3.o ko3_FPO.o vizov.o pulse.o

all : $(OBJS)
		QCC $(LFLAG) $(OBJS) $(SOLIB1) -o FPO_main
		 
.cc.o: 		
	QCC $(CFLAG) $< -o $@

clean:
		rm -f *.o *.map		

