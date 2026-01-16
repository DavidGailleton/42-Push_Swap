#============================
# ALL FOLDERS 
#============================

STACK_UTILS_DIR = stack_utils

ALGO_UTILS_DIR = algorithms/utils

INSERT_DIR = algorithms/insertion

ALGO_DIR = algorithms

PARS_DIR = parsing

MEDIUM_DIR = medium

COMPLEX_DIR = radix

FLAGS_DIR = flags

CHECKER_DIR = check_error

INCLUDES = includes

#============================
# ALL FILES WITHOUT PATH 
#============================

SRC = main.c ft_putnbr.c secure_write.c

INSERTION = insertion.c

FLAGS_FILES = algorithms_sort.c flag.c bench.c

PARSING = ft_atoi.c parsing.c ft_strncmp.c ft_split.c ft_strlen.c ft_substr.c ft_itoa.c ft_isdigit.c \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c parsing_2.c disorder.c indexer.c

CHECKER_FILES = check_error.c verif_flag.c verif_is_digit.c verif_overflow.c verif_double.c

STACK_UTILS = push.c rev_rotate.c rotate.c stack_add.c stack_remove.c stacks_len.c swap.c

MEDIUM_ALGO = utils_medium.c utils_struct_tab.c utils_medium_two.c sort_utils.c sort_utils_two.c medium_algo.c \
			move_patha.c move_pathb.c 

COMPLEX_ALGO = radix.c

ALGO_UTILS = check_order.c compare.c iterate.c pre_sort.c

#============================
# ADDING PATH TO THE FILES
#============================

ALL_FILES = $(SRC) $(STACK_UTILS_DIR)/$(STACK_UTILS)  $(PARS_DIR)/$(PARSING) \
			$(ALGO_DIR)/$(MEDIUM_DIR)/$(MEDIUM_ALGO) $(ALGO_UTILS_DIR)/$(ALGO_UTILS) \
			$(INSERT_DIR)/$(INSERTION) $(ALGO_DIR)/$(COMPLEX_DIR)/$(COMPLEX_ALGO) \
			$(FLAGS_DIR)/$(FLAGS_FILES) $(CHECKER_DIR)/$(CHECKER_FILES)

OBJ_DIR = obj

CC = cc

CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

NAME = push_swap

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_FILES:.c=.o)))
DEP = $(OBJ:.o=.d)

#============================
# BONUS CONFIG
#============================

BONUS_DIR = bonus

GNL_D = GNL

GNL_DIR = bonus/GNL

BONUS_FILES = checker_bonus.c

GNL_FILES = get_next_line.c get_next_line_utils.c

SRC_FOR_BONUS = ft_putnbr.c secure_write.c

ALL_BONUS_FILES = $(SRC_FOR_BONUS) $(BONUS_DIR)/$(BONUS_FILES) $(BONUS_DIR)/$(GNL_D)/$(GNL_FILES) \
					$(STACK_UTILS_DIR)/$(STACK_UTILS)  $(PARS_DIR)/$(PARSING) \
					$(ALGO_DIR)/$(MEDIUM_DIR)/$(MEDIUM_ALGO) $(ALGO_UTILS_DIR)/$(ALGO_UTILS) \
					$(INSERT_DIR)/$(INSERTION) $(ALGO_DIR)/$(COMPLEX_DIR)/$(COMPLEX_ALGO) \
					$(FLAGS_DIR)/$(FLAGS_FILES) $(CHECKER_DIR)/$(CHECKER_FILES)

BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_BONUS_FILES:.c=.o)))

NAME_BONUS = checker

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "===================================="
	@echo "======= PUSH SWAP COMPILED ========="
	@echo "===================================="

$(NAME_BONUS): $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(NAME_BONUS)
	@echo "===================================="
	@echo "======= CHECKER COMPILED ==========="
	@echo "===================================="

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

$(OBJ_DIR)/%.o: $(ALGO_DIR)/$(COMPLEX_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(ALGO_UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(FLAGS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(CHECKER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/$(GNL_D)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c | $(OBJ_DIR_BONUS)
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
	@rm -f $(NAME_BONUS)
	@echo "========== EXEC DELETED ============"
	@echo "===================================="

re: fclean all

bonus: $(NAME_BONUS)

-include $(DEP)
