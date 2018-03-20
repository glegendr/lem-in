NAME=lem-in
CC=gcc
CFLAG=
#CFLAG+= -Werror
#CFLAG+= -Wextra
#CFLAG+= -Wall
#CFLAG+= -fsanitize=address
SRCNAME=get_next_line main pars make_matrice algo print_ant print_vec dijkstra

LIBS= ./dep/libft/libft.a ./dep/libmem/libmem.a ./dep/libvec/libvec.a ./dep/libmatrice/libmatrice.a

CC_LIBS= make -C ./dep/libft/; make -C ./dep/libmem/; make -C ./dep/libvec/; make -C ./dep/libmatrice/;

INC_DIR_LIBS= -I ./dep/libft/inc/ -I ./dep/libmem/inc/ -I ./dep/libvec/inc/ -I ./dep/libmatrice/inc/

INC_DIR=./inc/

OBJDIR=./obj/
SRCDIR=./src/

SRC= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCNAME)))

OBJ= $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCNAME)))

INCDIR=./inc/

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@$(CC_LIBS)
	@$(CC) -o $@ $(OBJ) $(LIBS)
	@(echo "[ \033[35m$@\033[00m ]")

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAG) -c $< -o $@ -I $(INC_DIR) $(INC_DIR_LIBS)
	@(echo "\033[32m$@\033[00m")

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJ) $(OBJDIR)
	@(echo "\033[32mcleaned\033[00m")

fclean: clean
	@rm -rf $(NAME)

re: fclean all
