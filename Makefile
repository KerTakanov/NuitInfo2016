CC = g++
CFLAGS = -Wall -std=c++11
EXEC_NAME = NuitInfo2016
INCLUDES = -I "include" -I "boost_1_62_0" -I "sfml/include"
LIBS = -L"SFML/lib" -lsfml-graphics -lsfml-window -lsfml-system
FILES = src/*.cpp
INSTALL_DIR = ./bin

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME).exe $(EXEC_NAME) $(FILES).o

$(EXEC_NAME):
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(INCLUDES) $(FILES) $(LIBS)

install:
	cp $(EXEC_NAME) $(INSTALL_DIR)