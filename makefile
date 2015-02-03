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

ifeq ($(OS),Darwin)
# Run MacOS commands 
CC = clang++ -w -stdlib=libstdc++ -std=c++11
else
# check for Linux and run other commands
CC = g++ -w -std=c++11
endif

#INCLUDEPATH += -I/Library/Developer/CommandLineTools/usr/include/c++/v1/

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LINKFLAG) $(EXE) $(OBJS) $(LIB) $(LIBPATH) $(SO)

$(OBJS): $(SOURCELOCATION)
	$(CC) $(CCFLAG) $(SOURCELOCATION) $(INCLUDEPATH) $(INCLUDEFILE)

clean:
	rm -f *.o

cleanall:
	rm -f *.o $(EXE) $(EXEDEBUG)
