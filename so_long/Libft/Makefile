SRC			=	ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_strchr.c\
ft_strrchr.c\
ft_strlen.c\
ft_tolower.c\
ft_toupper.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strncmp.c\
ft_memchr.c\
ft_memcmp.c\
ft_strnstr.c\
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c  \
ft_putnbr_fd.c \
ft_striteri.c \
ft_strmapi.c \
ft_itoa.c \
ft_split.c \

SRCBONUS	=	ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c \

SRCPRINTF 	=	ft_printf.c \
ft_printf_utils.c \
ft_putchar.c \

SRCGNL		=	get_next_line.c \
get_next_line_utils.c \

SRCETC		= 	ft_free_split.c \

SRCALL	=	$(SRC) $(SRCBONUS) $(SRCPRINTF) $(SRCGNL) $(SRCETC)
OBJ	=	$(SRCALL:.c=.o)
CC	 =	cc
AR = ar
CFLAGS	=	-Wall -Werror -Wextra
#CFLAGS += -fsanitize=address
ARFLAG = -rcs
NAME =	libft.a

all: ${NAME}

${NAME}: ${OBJ}
	$(AR) $(ARFLAG) $(NAME) $(OBJ) 

clean:
	rm -f ${OBJ}
fclean: clean 
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re