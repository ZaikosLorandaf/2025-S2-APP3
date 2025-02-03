CC = g++
SRC = canevas.cpp couche.cpp forme.cpp graphicus-02.cpp tests.cpp rectangle.cpp carre.cpp cercle.cpp vecteur.cpp
OBJ = ${SRC:.cpp=.o}
# CFLAGS = -Wall -Os -g -march=native
CFLAGS = -Wall -g

all: Graphicus

%.o: %.cpp
	${CC}  ${CFLAGS} -c ${SRC} $<

Graphicus: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o Graphicus

clean:
	rm -f ${OBJ}

