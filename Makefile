NAME	=	push_swap

NAME_B	=	checker

SRCS	=	src/push_swap.c	src/parser_init.c	src/parser_add.c \
			src/cmd_push.c	src/ps_print.c 		src/parser_check.c \
			src/cmd_swap.c	src/cmd_rotate.c	src/cmd_reverse.c \
			src/sort_big.c	src/sort_med.c		src/sort_min.c \

SRCS_B	=	src/cheker.c		src/parser_check.c \
			src/parser_init.c 	src/parser_add.c 	src/cmd_push.c \
			src/cmd_swap.c		src/cmd_rotate.c 	src/cmd_reverse.c \
			src/sort_big.c		src/sort_med.c		src/sort_min.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	include/

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------
.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "$(TURQUOISE)\n< Complited $(NAME_B) >\n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft/ clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(YELLOW)\n< All files were deleted >\n$(END)"

re:			fclean all
			@echo "$(BLUE)\n< Remake done >\n$(END)"


