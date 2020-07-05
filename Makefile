.PHONY = all clean

CXX = g++
SIZE = size
SRCDIR  = src
OBJDIR = obj
BINDIR = bin
IDIR = inc
CFLAGS = -pipe -O2 -g -Wall -std=c++11
CFLAGS += -I$(IDIR)

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

