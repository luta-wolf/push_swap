NAME	=	libft.a

SRCS	= 	ft_isalnum.c	ft_isalpha.c		ft_isascii.c \
			ft_isdigit.c	ft_isprint.c		ft_strlen.c \
			ft_memset.c 	ft_bzero.c			ft_memcpy.c \
			ft_memmove.c	ft_strlcpy.c		ft_strlcat.c \
			ft_toupper.c	ft_tolower.c		ft_strchr.c \
			ft_strrchr.c	ft_strncmp.c		ft_memchr.c \
			ft_memcmp.c		ft_strnstr.c		ft_atoi.c \
			ft_calloc.c		ft_strdup.c			ft_substr.c \
			ft_strjoin.c	ft_strtrim.c		ft_split.c \
			ft_itoa.c		ft_strmapi.c		ft_striteri.c \
			ft_putchar_fd.c	ft_putstr_fd.c		ft_putendl_fd.c \
			ft_putnbr_fd.c	get_next_line_utils.c	get_next_line.c

SRCS_B	=	ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c \
			ft_lstadd_back.c	ft_lstdelone.c		ft_lstlast.c \
			ft_lstclear.c		ft_lstiter.c		ft_lstmap.c

HEADER	= 	libft.h

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		= 	gcc
FLAGS	=	 -Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
			ar r $(NAME) $?
			@echo "\033[36;1m\n< Complited libft >\n\033[0m"

%.o 	:	%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

$(OBJ_B)	:	$(SRCS_B) $(HEADER)
			$(CC) $(FLAGS) -c $(SRCS_B)

bonus	:	$(OBJ_B)
			ar r $(NAME) $^

clean	:
			@rm -rf $(OBJ) $(OBJ_B)

fclean	:	clean
			@rm -f $(NAME)

re		:	fclean all
