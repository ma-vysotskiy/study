
SCR := func_objs
OBJDIR := obj

CXX := g++

FILENAME := $(COMP)

all: compile

compile:
	$(CXX) $(SCR).cpp -o $(OBJDIR)/$(SCR)

clean:
	rm -rf $(OBJDIR)/*
