#for use on Windows:

#MKDIR=mkdir
#RM=del /y

#CXXFLAGS+=-static-libgcc -static-libstdc++

#export

OBJDIR=obj
OUTDIR=out

OUT=$(OUTDIR)/cards
LIB=-lmingw32 -lSDLmain -lSDL

CXXFLAGS+=-std=c++11

all: $(OBJDIR) $(OUTDIR)
	$(MAKE) -C src
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJDIR)/* $(LIB)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OUTDIR):
	mkdir $(OUTDIR)

clean:
	$(RM) *.o *.a *.exe

rebuild: clean all
