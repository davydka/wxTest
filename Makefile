OBJS = main.cpp

CC = g++

COMPILER_FLAGS = -Wall

LINKER_FLAGS = `wx-config --cxxflags --libs std, media`

OBJ_NAME = app

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

# g++ main.cpp -Wall `wx-config --cxxflags --libs std, media` -o app
