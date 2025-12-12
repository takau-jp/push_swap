# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 14:10:40 by stanaka2          #+#    #+#              #
#    Updated: 2025/12/12 22:16:37 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------------------- #
#         Phony Rules        #
# -------------------------- #

.PHONY: all clean fclean re bonus norm debug asan sbuild

# -------------------------- #
#      Makefile Setting      #
# -------------------------- #

SHELL =	/bin/bash

ifeq ($(filter re,$(MAKECMDGOALS)),re)
MAKEFLAGS += --no-print-directory
else
MAKEFLAGS += --no-print-directory -j
endif

RM = rm -f

# -------------------------- #
# 　　　　　　Target　　　      #
# -------------------------- #

NAME = push_swap
CHECKER = checker

# -------------------------- #
# 　　     　LIBFT            #
# -------------------------- #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/include

# -------------------------- #
# 　　　Compiler Flags        #
# -------------------------- #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
CFLAGS += -g -fsanitize=address
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
CFLAGS += -g
endif

# -------------------------- #
#          Include           #
# -------------------------- #

INCLUDE_DIR 	= mandatory/include
INCLUDE			= -I $(INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR)
B_INCLUDE_DIR	= bonus/include
B_INCLUDE		= -I $(B_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR)

# -------------------------- #
#     Source Directories     #
# -------------------------- #

SRC_DIRS 	=	mandatory/src \
				$(addprefix mandatory/src/, \
					utils $(addprefix utils/, sort_utils order_utils stack_utils) \
					iddfs_sort $(addprefix iddfs_sort/, utils) \
					pre_process $(addprefix pre_process/, utils) \
					chunk_division $(addprefix chunk_division/, utils) \
					chunk_insertion $(addprefix chunk_insertion/, utils) \
				)

B_SRC_DIRS	=	bonus/src \
				$(addprefix bonus/src/, \
					error \
					pre_process \
					$(addprefix pre_process/, \
						utils \
					) \
					checker \
					$(addprefix checker/, \
						order_utils \
						stack_utils \
					) \
				)

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
SRC_DIRS = $(B_SRC_DIRS)
endif

# -------------------------- #
#        Source Files        #
# -------------------------- #

# mandatory
SRCS	=	main.c
# utils
SRCS	+=	clear_context.c  error.c
# utils/order_utils
SRCS	+=	clear_orders.c  print_orders.c  restore_order_push.c  restore_order_swap.c \
			add_order.c  add_order_rotate.c  add_order_push.c  add_order_reverse_rotate.c  add_order_swap.c \
			order_command_push.c  order_command_rotate.c  order_command_swap.c  order_command_reverse_rotate.c
# utils/sort_utils
SRCS	+=	calc_chunk_count.c  mark_chunk_number.c  calc_rotation_cost.c  calc_push_cost.c \
			rotate_a_to_rank.c  rotate_utils.c  execute_orders_rotate.c
# utils/stack_utils
SRCS	+=	ps_stack_add_back.c  ps_stack_add_front.c  ps_stack_clear.c  ps_stack_new.c
# iddfs_sort
SRCS	+=	iddfs_sort.c  is_sorted.c  is_valid_order.c  restore_order.c  set_order_table.c
# pre_process
SRCS	+=	coordinate_compression.c  get_longest_increasing_subsequence.c \
			mark_unsorted.c  sort_num_array.c  free_splitted.c  argument_validations.c \
			lis_utils.c  parse_argument.c  create_stacks.c
# division
SRCS	+=	chunk_division.c  mark_push_target_for_division.c  set_cost_data.c  calc_best_cost_rotation.c
# insertion
SRCS	+=	insert_chunk.c  chunk_insertion.c  search_best_biases.c  random.c  insert_positions.c \
			calc_search_area.c  calc_score.c  max_unsorted_element.c \
			restore.c  search_min_score_target.c  mark_push_target_for_insertion.c


# bonus
B_SRCS	=	main_bonus.c
# pre_process
B_SRCS	+=	create_stacks_bonus.c  parse_argument_bonus.c  argument_validations_bonus.c  free_splitted_bonus.c
# checker
B_SRCS	+=	is_sorted_bonus.c  read_orders_bonus.c
# checker/order_utils
B_SRCS	+=	order_command_push_bonus.c  order_command_reverse_rotate_bonus.c  order_command_rotate_bonus.c  order_command_swap_bonus.c
# checker/stack_utils
B_SRCS	+=	ps_stack_add_back_bonus.c  ps_stack_add_front_bonus.c  ps_stack_clear_bonus.c  ps_stack_new_bonus.c
# error
B_SRCS	+=	error_bonus.c

# -------------------------- #
#        VPATH Setup         #
# -------------------------- #

$(foreach dir,$(SRC_DIRS), $(eval vpath %.c $(dir)))

# -------------------------- #
#     Object & Dependency    #
# -------------------------- #

OBJ_DIR		=	.obj
OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
B_OBJS		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(B_SRCS)))

DEP_DIR		=	.dep
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(SRCS)))
B_DEPS		=	$(patsubst %.c, $(DEP_DIR)/%.d, $(notdir $(B_SRCS)))

# -------------------------- #
#       Bonus Switching      #
# -------------------------- #

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
INCLUDE = $(B_INCLUDE)
OBJS = $(B_OBJS)
DEPS = $(B_DEPS)
endif

# -------------------------- #
#    ANSI Escape Sequence    #
# -------------------------- #

DEF_COLOR	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA 	= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# -------------------------- #
#        Main Targets        #
# -------------------------- #

all	: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo -e "[PUSH_SWAP] $(GREEN)Build Complete:$(DEF_COLOR) $@"

$(CHECKER): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo -e "[PUSH_SWAP] $(GREEN)Build Complete:$(DEF_COLOR) $@"

# -------------------------- #
#        Build Rules         #
# -------------------------- #

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@-mkdir -p $@

$(DEP_DIR):
	@-mkdir -p $@

# -------------------------- #
#         LIBFT Rule         #
# -------------------------- #

$(LIBFT):
	@echo -e "[PUSH_SWAP] $(YELLOW)Build:$(DEF_COLOR) $@"
ifeq ($(filter asan,$(MAKECMDGOALS)),asan)
	@$(MAKE) -C $(LIBFT_DIR) asan
else ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	@$(MAKE) -C $(LIBFT_DIR) debug
else
	@$(MAKE) -C $(LIBFT_DIR)
endif

# -------------------------- #
#         Debug Rules        #
# -------------------------- #

asan:	$(NAME)

debug:  $(NAME)

sbuild:
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make
	@$(MAKE) fclean
	/usr/lib/llvm-12/bin/scan-build make bonus
	@$(MAKE) fclean

norm:
	@norminette -o mandatory bonus $(LIBFT_DIR) | grep Error || true

# -------------------------- #
#       Cleanup Rules        #
# -------------------------- #

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[PUSH_SWAP] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(OBJS) $(DEPS) $(B_OBJS) $(B_DEPS)
	@echo -e "[PUSH_SWAP] $(BLUE)Deleted Compiled Files$(DEF_COLOR): *.o *.d"
	@$(RM) -r $(NAME) $(CHECKER) $(OBJ_DIR) $(DEP_DIR)
	@echo -e "[PUSH_SWAP] $(BLUE)Deleted Target File and Object File Dir$(DEF_COLOR): $(NAME) $(CHECKER) $(OBJ_DIR) $(DEP_DIR)"

re:	fclean all

# -------------------------- #
#  Include Dependency Files  #
# -------------------------- #

-include $(DEPS) $(B_DEPS)
