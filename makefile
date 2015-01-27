ifdef PROJECTNAME
EXE = $(PROJECTNAME)
else
PROJECTDIR = $(shell pwd)
EXE = $(notdir $(basename $(PROJECTDIR)))
endif

DIR = src/ \
	src/Common/Utility/ \
	src/GameTable/ \
        src/GameTools/ \
        src/GameTools/CardDeck/ \
        src/GameTypes/ \
        src/Log/MiLog/ \
	src/Player

SOURCE = *.cpp
SOURCELOCATION = $(DIR:/=/$(SOURCE))

INCLUDEPATH = -Isrc/
INCLUDEFILE = 

LIB = -lpthread 
LIBPATH = 

SO = 

LINKFLAG = -o
CCFLAG = -g -c

OBJS = $(SOURCE:.cpp=.o)

CC = g++ -w -std=c++11


all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LINKFLAG) $(EXE) $(OBJS) $(LIB) $(LIBPATH) $(SO)

$(OBJS): $(SOURCELOCATION)
	$(CC) $(CCFLAG) $(SOURCELOCATION) $(INCLUDEPATH) $(INCLUDEFILE)

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXE) $(EXEDEBUG)
