.PHONY: all, run, clean

SRCDIR = src
OBJDIR = build
BINDIR = bin
HDDIR = include
MAIN = main
GAME = 3-puzzle

TARGET = $(BINDIR)/$(MAIN)
HDRS = $(wildcard $(HDDIR)/*.h)
CPPSRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(CPPSRCS))

CXX = g++
CFLAGS = -DDEBUG -Wall -g

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HDRS)
	$(CXX) -c $< -o $@ $(CFLAGS)

run:
ifeq ($(OS), Windows_NT)
	.\$(GAME)
else
	./$(GAME)
endif

install:
ifeq ($(OS), Windows_NT)
	copy $(BINDIR)\main.exe $(GAME).exe
else
	cp -rf $(TARGET) ./
	mv $(MAIN) $(GAME)
endif

clean:
ifeq ($(OS), Windows_NT)
	del $(OBJDIR)\*.o $(BINDIR)\main.exe .\$(GAME).exe
else
	rm -f $(OBJDIR)/*.o $(TARGET) $(GAME)
endif