# Variables

NAME		=philo

SRC_DIR		=srcs/

OBJ_DIR		=objs/

INC_DIR		=includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall
RM = rm -rf

SRC_FILES = main\
			utils\
			parse\
			inits\
			thread\
			routine\
			check\
			free\
			ft_isint\
			action\


SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)



$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(INC_DIR)*.h | $(OBJ_DIR)
				$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
			-mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 