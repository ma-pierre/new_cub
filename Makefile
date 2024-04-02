NAME			=	cub

LIBFT			=	libft.a

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	main.c\
					raycasting.c\
					move.c\
					move_camera.c\
					keys.c\
					image.c\

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC				=	-Iincludes -Ilibft -Iminilibx-linux

LIB				=	-Llibft -lft -lXext -lX11 -lm

CC				=	cc

CDFLAGS 		= -MMD -MP

CFLAGS			=	-Wall -Wextra -Werror -g3 

MAKEFLAGS		=	--no-print-directory

all:	${NAME}

$(NAME): $(DIR_OBJS) $(OBJS) 
	make -C libft
	make -C minilibx-linux
	$(CC) ${CFLAGS} ${INC} $(OBJS) $(LIB) ./minilibx-linux/libmlx.a -o $(NAME)


$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@ 

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/srcs

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re