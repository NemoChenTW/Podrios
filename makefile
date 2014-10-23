EXE = runPodrios

#DIR = Common/ Common/Types/ Common/Utility/ Common/Instruction/ Common/Provider/ \
#      CollectionLogical/ GateController/ GateEMM/ MiLog/ \
#      MMIManager/ PaidReader/ PassengerLogical/ \
#      ReaderControl/ ReaderControl/FEP/ ReaderControl/Reader/ ReaderControl/Ticket/ \
#      SPSInterface/ TagReader/ UnPaidReader/ ParametersManager/

DIR = ./

SOURCE = *.cpp
SOURCELOCATION = $(DIR:/=/$(SOURCE))

INCLUDEPATH = 
INCLUDEFILE = 

LIB =  
LIBPATH = 

SO = 

LINKFLAG = -o
CCFLAG = -g -c

OBJS = $(SOURCE:.cpp=.o)

CC = g++ -w


all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LINKFLAG) $(EXE) $(OBJS) $(LIB) $(LIBPATH) $(SO)

$(OBJS): $(SOURCELOCATION)
	$(CC) $(CCFLAG) $(SOURCELOCATION) $(INCLUDEPATH) $(INCLUDEFILE)

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXE) $(EXEDEBUG)
