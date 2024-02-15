NAME = ft_ssl

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs/
INC_DIR = incs/

SRCS =	ft_ssl.c	\
		md5.c		\
		ft_in_out.c \
		utils.c
# sha256.c

OBJ 		= 	$(SRCS:.c=.o)
OBJ_DIR = objs/
OBJS 		= 	$(addprefix $(OBJ_DIR), $(OBJ))


$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c  $< -o $@
	@echo "Compiling $<"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "Exec 'ft_ssl' created"

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Exec removed"

re: fclean all