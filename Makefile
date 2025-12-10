SRC = main.c ft_atoi.c parsing.c

STACK_UTILS = stack_utils/push.c stack_utils/rev_rotate.c stack_utils/rotate.c \
				stack_utils/stack_add.c stack_utils/stack_remove.c stack_utils/swap.c

MEDIUM_ALGO = algorithms/medium_algo.c algorithms/medium_utils/utils_medium.c \
				algorithms/medium_utils/utils_struct_tab.c

ALGO_UTILS = algorithms/utils/check_order.c algorithms/utils/compare_value.c \
				algorithms/utils/stack_len.c

ALL_FILES = $(SRC) $(STACK_UTILS) $(MEDIUM_ALGO) $(ALGO_UTILS)

OBJ_DIR = obj

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

NAME = push_swap

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_FILES:.c=.o)))

DEP = $(OBJ:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "===================================="
	@echo "= ALL OBJECT AND DEPENDENCES CLEAN ="
	@echo "===================================="

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)