.PHONY = all clean

CXX = g++
SIZE = size
SRCDIR  = src
OBJDIR = obj
BINDIR = bin
CFLAGS = -pipe -O2 -g -Wall

SRCCXX = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS += $(subst $(SRCDIR)/, $(OBJDIR)/, $(SRCCXX:.cpp=.o))

TARGET = bin/roulette

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c $< $(CFLAGS) -o $@


clean:
	@rm -f $(OBJDIR)/*
	@rm -f $(BINDIR)/*

