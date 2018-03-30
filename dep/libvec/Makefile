.PHONY: all clean fclean re

NAME=libvec.a
CC=gcc
CFLAG=
CFLAG+= -Werror
CFLAG+= -Wextra
CFLAG+= -Wall
SRCNAME= ft_realloc\
		 ft_memcpy\
		 st_copy\
		 st_del\
		 st_del_last\
		 st_get\
		 st_new\
		 st_print\
		 st_push\
		 st_push_first\
		 st_raw\
		 v_append_raw\
		 v_copy\
		 v_del\
		 v_del_last\
		 v_get\
		 v_new\
		 v_pop\
		 v_print\
		 v_push\
		 v_push_first\
		 v_push_int\
		 v_sort_size\
		 v_raw\
		 v_reverse_rotate\
		 v_rotate\
		 v_size\
		 v_split\
		 v_swap\

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
