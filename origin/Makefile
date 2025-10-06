# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/29 14:10:40 by stanaka2          #+#    #+#              #
#    Updated: 2025/09/28 14:04:57 by stanaka2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc

# FLAGS
CFLAGS = -Wall -Wextra -Werror
DEPSFLAGS = -MMD

# libft
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}/includes

# INCLUDE
INCLUDE = -I includes ${LIBFT_INCLUDE}

# srcs
SRCDIR = mandatory
SRCS = ${addprefix ${SRCDIR}/, main.c}
SRCS += ${addprefix ${SRCDIR}/push_swap/, \
			get_index_utils.c \
			push_swap_utils.c \
			push_swap.c \
			rotate_a_to_index.c \
		}
SRCS += ${addprefix ${SRCDIR}/push_swap/chunk_division/, \
			chunk_division.c \
			efficient_rotate_utils.c \
			efficient_rotate.c \
			mark_pushed_for_division.c \
			order_push.c \
			push_chunk.c \
		}
SRCS += ${addprefix ${SRCDIR}/push_swap/chunk_insertion/, \
			calc_cost_last_chunk.c \
			calc_cost.c \
			calc_grid_search_area.c \
			chunk_insertion.c \
			evaluate_bias_factors.c \
			grid_search_others.c \
			grid_search_rotate_b_last_chunk.c \
			grid_search_rotate_b.c \
			insert_chunk_utils.c \
			insert_chunk.c \
			order_insert.c \
			restores.c \
			search_best_biases.c \
			search_min_cost_target.c \
		}
SRCS += ${addprefix ${SRCDIR}/push_swap/less_than_5_elements/, \
			one_unsorted_element_case.c \
			two_unsorted_elements_case.c \
			three_unsorted_elements_case.c \
		}
SRCS += ${addprefix ${SRCDIR}/list_utils/, \
			ps_lstadd_back.c \
			ps_lstadd_front.c \
			ps_lstclear.c \
			ps_lstnew.c \
		}
SRCS += ${addprefix ${SRCDIR}/orders/, \
			add_order.c \
			add_push_order.c \
			add_reverse_rotate_order.c \
			add_rotate_order.c \
			add_swap_order.c \
			clear_orders.c \
			print_orders.c \
			push_order.c \
			reverse_rotate_order.c \
			rotate_order.c \
			swap_order.c \
			restore_order.c \
		}
SRCS += ${addprefix ${SRCDIR}/pre_process/, \
			coordinate_compression.c \
			create_element_array_by_index.c \
			create_stack_a.c \
			get_longest_increasing_subsequence.c \
			mark_unsorted.c \
			parse_argument_utils.c \
			parse_argument.c \
			sort_num_array.c \
		}
B_SRCDIR = bonus
B_SRCS = ${addprefix ${B_SRCDIR}/, main_bonus.c}

# objs
OBJDIR = objs
OBJS = ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.o}}}
B_OBJS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.o}}}
# deps
DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${SRCS:.c=.d}}}
B_DEPS	= ${addprefix ${OBJDIR}/, ${notdir ${B_SRCS:.c=.d}}}

# bonus
ifeq ($(MAKECMDGOALS), bonus)
DEPS	= ${B_DEPS}
endif

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} $^ -o $@ -lm

# ${NAME}: ${OBJS} ${LIBFT}
# 	${CC} $^ -o $@

${LIBFT}:
	@make -C $(LIBFT_DIR)

${OBJDIR}:
	-mkdir -p ${OBJDIR}

${OBJDIR}/%.o: ${SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/push_swap/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/push_swap/chunk_division/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/push_swap/chunk_insertion/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/push_swap/less_than_5_elements/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/list_utils/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/orders/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${SRCDIR}/pre_process/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

${OBJDIR}/%.o: ${B_SRCDIR}/%.c | ${OBJDIR}
	${CC} ${CFLAGS} ${DEPSFLAGS} ${INCLUDE} -c $< -o $@

bonus: ${B_OBJS} ${LIBFT}
	${CC} $^ -o ${CHECKER}

clean:
	@make -C ${LIBFT_DIR} clean
	${RM} ${OBJS} ${B_OBJS} ${DEPS} ${B_DEPS}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	${RM} -r ${NAME} ${OBJDIR}

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
