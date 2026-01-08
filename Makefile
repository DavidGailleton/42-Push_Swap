#============================
# ALL FOLDERS 
#============================

STACK_UTILS_DIR = stack_utils

ALGO_UTILS_DIR = algorithms/utils

INSERT_DIR = algorithms/insertion

ALGO_DIR = algorithms

PARS_DIR = parsing

MEDIUM_DIR = medium

FLAGS_DIR = flags

INCLUDES = headers

#============================
# ALL FILES WITHOUT PATH 
#============================

SRC = main.c test_one.c

INSERTION = insertion.c

FLAGS_FILES = algorithms_sort.c flag.c

PARSING = ft_atoi.c parsing.c ft_strncmp.c ft_split.c ft_strlen.c ft_substr.c

STACK_UTILS = push.c rev_rotate.c rotate.c stack_add.c stack_remove.c stacks_len.c swap.c print_stacks.c

MEDIUM_ALGO = utils_medium.c utils_struct_tab.c utils_medium_two.c sort_utils.c sort_utils_two.c medium_algo.c

ALGO_UTILS = check_order.c compare.c iterate.c pre_sort.c

#============================
# ADDING PATH TO THE FILES
#============================

ALL_FILES = $(SRC) $(STACK_UTILS_DIR)/$(STACK_UTILS)  $(PARS_DIR)/$(PARSING) \
			$(ALGO_DIR)/$(MEDIUM_DIR)/$(MEDIUM_ALGO) $(ALGO_UTILS_DIR)/$(ALGO_UTILS) \
			$(INSERT_DIR)/$(INSERTION)

OBJ_DIR = obj

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

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

$(OBJ_DIR)/%.o: $(PARS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(INSERT_DIR)/%.c | $(OBJ_DIR)
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