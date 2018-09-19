NAME		= fillit

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src/
SRC_NAME	= main.c \
				fill.c\
				check.c\
				recursive.c\
				read.c\
				replace.c
SRC			= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= ./obj/
OBJ			= $(addprefix $(OBJ_DIR),$(SRC_NAME:.c=.o))

INCLUDES	= -I $(LIB_DIR) -I ./includes/

LIB_DIR		= ./libft/
LIBFT		= $(LIB_DIR)libft.a
LIB_LINK	= -L$(LIB_DIR) -lft

all: $(NAME)

$(NAME): obj $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(LIB_LINK) -o $(NAME) $(OBJ)

obj:
		mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
		$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
		make -C $(LIB_DIR)

clean: 
		rm -rf $(OBJ_DIR)
		make fclean -C $(LIB_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all
