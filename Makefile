NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source files
SRCS = sources/process_stack.c sources/calculator_utils.c sources/osman_sort_utils.c sources/special_osman_ops.c sources/osman_calculator.c sources/osman_sort_algo.c \
       sources/input_validator.c sources/egde_case_handlers.c sources/pushswap.c sources/swapy_ops.c \
       sources/rotate_ops.c sources/push_ops.c sources/rev_rotate_ops.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

# ft_printf settings (contains its own Libft)
FTPRINT_DIR = includes/ft_printf/
FT_PRINTF = $(FTPRINT_DIR)libftprintf.a

# Libft settings
LIBFT_DIR = includes/Libft/
LIBFT = $(LIBFT_DIR)libft.a

# Main archive
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT)

# Rule to build ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(FTPRINT_DIR)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c -no-pie $< -o $@ -Iincludes -I$(LIBFT_DIR) -I$(FTPRINT_DIR)

# Cleaning rules
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(FTPRINT_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus
	$(MAKE) -C $(FTPRINT_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
