CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
SRCS = $(SRC_DIR)/test.c $(SRC_DIR)/inv_rotate.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/ft_split.c $(SRC_DIR)/rotate.c $(SRC_DIR)/swap.c $(SRC_DIR)/ten_elements.c

OBJS = $(SRCS:.c=.o)

NAME = pushswap.out
LIBFT_DIR = 42_libft
Printf_DIR = 42_printf

LIBFT = $(LIBFT_DIR)/libft.a
Printf = $(Printf_DIR)/libftprintf.a

all: $(LIBFT) $(Printf) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(Printf):
	$(MAKE) -C $(Printf_DIR)
$(NAME): $(OBJS) $(LIBFT) $(Printf)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -L$(Printf_DIR) -lft -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(Printf_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(Printf_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(Printf_DIR) fclean

re: fclean all

.PHONY: all clean fclean re