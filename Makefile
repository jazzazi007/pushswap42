CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
INC_DIR = include
SRCS = $(SRC_DIR)/test.c $(SRC_DIR)/main.c $(SRC_DIR)/pushswap.c $(SRC_DIR)/ft_split.c

OBJS = $(SRCS:.c=.o)

NAME = pushswap.out

HEADERS = $(INC_DIR)/pushswap.h

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re