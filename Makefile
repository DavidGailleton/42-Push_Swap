STACK_UTILS_DIR = stack_utils

ALGO_UTILS_DIR = algorithms/utils

ALGO_DIR = algorithms

MEDIUM_DIR = medium_utils

SRC = main.c ft_atoi.c parsing.c

STACK_UTILS = push.c rev_rotate.c rotate.c stack_add.c stack_remove.c swap.c

ALGO_SORT = medium_algo.c

MEDIUM_ALGO = utils_medium.c utils_struct_tab.c

ALGO_UTILS = check_order.c compare_value.c stack_len.c

ALL_FILES = $(SRC) $(STACK_UTILS_DIR)/$(STACK_UTILS) $(ALGO_DIR)/$(ALGO_SORT) \
			$(ALGO_DIR)/$(MEDIUM_DIR)/$(MEDIUM_ALGO) $(ALGO_UTILS_DIR)/$(ALGO_UTILS)

OBJ_DIR = obj

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

NAME = push_swap

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_FILES:.c=.o)))
DEP = $(OBJ:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "===================================="
	@echo "======= PUSH SWAP COMPILED ========="
	@echo "===================================="

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(STACK_UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(ALGO_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(ALGO_DIR)/$(MEDIUM_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(ALGO_UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "===================================="
	@echo "= ALL OBJECT AND DEPENDENCES CLEAN ="
	@echo "===================================="

fclean: clean
	@rm -f $(NAME)
	@echo "========== EXEC DELETED ============"
	@echo "===================================="

re: fclean all

-include $(DEP)