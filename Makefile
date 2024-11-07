NAME = cub3D

CC = cc

FLAGS = -g -Wall -Wextra -Werror

MLX_DIR = ./minilibx-linux

MLX_LIB = ${MLX_DIR}/libmlx.a

MLX_FLAG = -lm -lmlx -lX11 -lXext

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libft_complete.a

LIBFT_FLAG = -lft_complete

INCLUDES = -I ./Includes/

PARSING_SOURCES = ./Parsing/

RAYCASTING_SOURCES = ./Raycasting/

OBJ_PATH = obj/

PARSING_OBJS = ${addprefix ${OBJ_PATH}, ${PARSING_SOURCES:.c=.o}}

RAYCASTING_OBJS = ${addprefix ${OBJ_PATH}, ${RAYCASTING_SOURCES:.c=.o}}

all : ${OBJ_PATH} ${NAME}

${OBJ_PATH} :
	mkdir ${OBJ_PATH}

${NAME} : ${PARSING_OBJS} ${RAYCASTING_OBJS} ${MLX_LIB} ${LIBFT_LIB}
	${CC} ${FLAGS} \
	# ${PARSING_OBJS} \
	${RAYCASTING_OBJS} \
	-L${MLX_DIR} -L${LIBFT_DIR} -o $@ ${MLX_FLAG} ${LIBFT_FLAG}

${MLX_LIB} :
	${MAKE} -C ${MLX_DIR}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

${OBJ_PATH}%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${PARSING_OBJS}
	${RM} ${RAYCASTING_OBJS}
	${RM} ${OBJ_PATH}

fclean : clean
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
