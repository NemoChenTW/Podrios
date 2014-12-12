ifdef PROJECTNAME
EXE = $(PROJECTNAME)
else
PROJECTDIR = $(shell pwd)
EXE = $(notdir $(basename $(PROJECTDIR)))
endif

DIR = src/ \
        src/GameTable/ \
        src/GameTools/CardDeck/ \
        src/GameTypes/

SOURCE = *.cpp
SOURCELOCATION = $(DIR:/=/$(SOURCE))

INCLUDEPATH = -Isrc/
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
