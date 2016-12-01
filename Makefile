#makefile projet Experience

#-g -> augmente les informations pour le debugging
#-Wall -> augmente les warnings

CC = g++ #nom du compilateur
CFLAGS = -g -Wall -W -pedantic -std=c++11 #options du compilateur
LDFLAGS = #options de l'éditions des liens
#EXEC_NAME = #nom executable
#INCLUDES = #chemin vers les fichiers headers
#LIBS = #chemin vers les librairies
#OBJ_FILES = #liste des fichiers que l'on veut obtenir

SRC = $(wildcard *.cpp) #création de la liste des sources
OBJ = $(SRC:.cpp = .o)


#Exemple type pour compiliation:

#Varialbe interne au Makefile:
# - $@ -> Le nom de la cible
# - $< -> Le nom de la premiere dépendance
# - $^ -> La liste des dépendances
# - $? -> La liste des dépendances plus récntes que la cible
# - $* -> Le nom du fichier sans suffixe

all: $(EXEC_NAME)
	$(CC) $(LDFLAGS) -o $(OUTPUT) $^

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


#hello: hello.o main.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#%.o: %.cpp:
#	$(CC) -o $@ -c $< $(CFLAGS)

#Peut s'écrire aussi:

#hello.o: hello.cpp
#	$(CC) -o $@ -c $< $(CFLAGS)


#main.o: main.cpp hello.h
#	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm *.o


mrpropre:clean
	rm -rf $(EXEC_NAME)
