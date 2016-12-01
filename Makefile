CC = g++
CFLAGS = -Wall
EXEC_NAME = NuitInfo2016
INCLUDES = -I"boost_1_62/" -I"include/"
FILES = $(wildcard src/*.cpp)
INSTALL_DIR = ./bin

all: $(EXEC_NAME)

clean:
	rm $(EXEC_NAME).exe $(EXEC_NAME) $(FILES).o

$(EXEC_NAME):
	$(CC) -o $(EXEC_NAME) $(FILES).cpp

install:
	cp $(EXEC_NAME) $(INSTALL_DIR)