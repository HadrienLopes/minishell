NAME=minishell
CC=gcc
CFLAGS=-Wall -Wextra -Werror
INC_LIB=-I ./libft
LIBFT=-L ./libft -lft
INC=-I ./include
SRC_DIR=./src/
SRC=	$(SRC_DIR)minishell.c \
	$(SRC_DIR)ft_env.c \
	$(SRC_DIR)ft_pwd.c
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

%.o: %.c
	$(CC) $(CLAGS) $(INC) $(INC_LIB) $(LIBFT) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 
