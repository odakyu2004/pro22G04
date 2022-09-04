PROGRAM = sample
OBJECTS = main.o Tile.o Dungeon.o PlayerBot.o
VPATH = src
CXXFLAGS = -Wall
all: $(PROGRAM)
$(PROGRAM) : $(OBJECTS)
	g++ $(CXXFLAGS) -o $(PROGRAM) $(OBJECTS)
run : $(PROGRAM)
	./$(PROGRAM)
.PHONY : clean
clean :
	-rm *.o $(PROGRAM)
