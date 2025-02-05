CC = g++
SRC = canevas.cpp layer.cpp shape.cpp graphicus-03.cpp tests.cpp rectangle.cpp square.cpp circle.cpp
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
