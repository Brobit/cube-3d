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

PARSING_SOURCES = ./Parsing/main.c
RAYCASTING_SOURCES = ./Raycasting/raycasting_entry.c\
                     ./Raycasting/utils.c\
                     ./Raycasting/mlx_handler/init_mlx.c\
                     ./Raycasting/mlx_handler/event_handler.c\
                     ./Raycasting/mlx_handler/image_handler.c\
                     ./Raycasting/drawing/fill_image.c\
                     ./Raycasting/drawing/color_writing.c\
					 ./Raycasting/drawing/display_raycasting_result.c\
					 ./Raycasting/raycasting_utils/init_raycasting.c\
					 ./Raycasting/raycasting_utils/free_raycasting.c\
					 ./Raycasting/raycasting_utils/raycasting_calculation.c\
					 ./Raycasting/raycasting_utils/set_shortest_length_of_ray.c\
					 ./Raycasting/raycasting_utils/calculate_height_to_display.c\
					 ./Raycasting/raycasting_utils/calculate_verticale_collision.c\
					 ./Raycasting/raycasting_utils/calculate_horizontale_collision.c

PARSING_OBJ_PATH = obj/Parsing/
PARSING_SUBDIRS = 
RAYCASTING_OBJ_PATH = obj/Raycasting/
RAYCASTING_SUBDIRS = mlx_handler drawing raycasting_utils

PARSING_OBJS = ${PARSING_SOURCES:./Parsing/%.c=${PARSING_OBJ_PATH}%.o}
RAYCASTING_OBJS = ${RAYCASTING_SOURCES:./Raycasting/%.c=${RAYCASTING_OBJ_PATH}%.o}

all: ${PARSING_OBJ_PATH} ${PARSING_SUBDIRS:%=${PARSING_OBJ_PATH}%/} ${RAYCASTING_OBJ_PATH} ${RAYCASTING_SUBDIRS:%=${RAYCASTING_OBJ_PATH}%/} ${NAME}

${PARSING_OBJ_PATH}:
	mkdir -p ${PARSING_OBJ_PATH}

${RAYCASTING_OBJ_PATH}:
	mkdir -p ${RAYCASTING_OBJ_PATH}

${RAYCASTING_OBJ_PATH}%/:
	mkdir -p $@

${NAME}: ${PARSING_OBJS} ${RAYCASTING_OBJS} ${MLX_LIB} ${LIBFT_LIB}
	${CC} ${FLAGS} ${PARSING_OBJS} ${RAYCASTING_OBJS} \
	-L${MLX_DIR} -L${LIBFT_DIR} -o $@ ${MLX_FLAG} ${LIBFT_FLAG}

${MLX_LIB}:
	${MAKE} -C ${MLX_DIR}

${LIBFT_LIB}:
	${MAKE} -C ${LIBFT_DIR}

${PARSING_OBJ_PATH}%.o: ./Parsing/%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

${RAYCASTING_OBJ_PATH}%.o: ./Raycasting/%.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean:
	${MAKE} clean -C ${MLX_DIR}
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${PARSING_OBJS} ${RAYCASTING_OBJS}
	${RM} -r obj/

fclean: clean
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
