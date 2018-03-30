.PHONY: all clean fclean re

NAME=libmem.a
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
SRCNAME= ft_memccpy \
		 ft_memcut \
		 ft_memchr   \
		 ft_memcmp   \
		 ft_memcpy   \
		 ft_memdel   \
		 ft_memmove  \
		 ft_memset   \
		 ft_memalloc \

OBJDIR=obj/
CLEANOBJDIR=OBJDIR
CLEANOBJ=OBJ
SRCDIR=src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR= inc/

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INCDIR)
	@(echo "_ \033[032m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
$(NAME): $(OBJDIR) $(OBJ)
	@ar -rc  $(NAME) $(OBJ)
	@(echo "[ \033[35m$(NAME)\033[00m ]")

clean:
	@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
