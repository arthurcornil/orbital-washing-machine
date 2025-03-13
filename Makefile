CC = clang
FLAGS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I ./includes
NAME = owm
SOURCE = ./srcs/
LIB = ./lib/libraylib.a
CFILES = main.c\
		 wm.c\
		 colors.c\
		 walls.c

${NAME}:
	${CC} ${FLAGS} ${LIB} ${addprefix ${SOURCE}, ${CFILES}} -o ${NAME}

clean:

fclean: clean

.PHONY: ${NAME} clean fclean
