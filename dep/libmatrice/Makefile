NAME=libmatrice.a
CC=gcc
CFLAG=
#CFLAG+= -Werror
#CFLAG+= -Wextra
#CFLAG+= -Wall
#CFLAG+= -fsanitize=address
SRCNAME=ft_putnbr_fd mat_del mat_get mat_new mat_print mat_set mat_size

OBJDIR=./obj/
SRCDIR=./src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR=./inc/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rc $@ $(OBJ)
	@(echo "[ \033[35m$@\033[00m ]")

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INCDIR)
	@(echo "\033[32m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJ) $(OBJDIR)
	@(echo "\033[32mlib cleaned\033[00m")

fclean: clean
	@rm -rf $(NAME)

re: fclean all
