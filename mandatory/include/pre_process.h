/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_process.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:02:11 by stanaka2          #+#    #+#             */
/*   Updated: 2025/12/11 01:57:19 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_PROCESS_H
# define PRE_PROCESS_H

# include "types.h"

# define LIS_INIT INT64_MAX

struct s_lis
{
	int64_t	*seq;
	int64_t	len;
	int64_t	*tails;
	int64_t	*prev;
};

int		*parse_argument(char *argv[], t_ctx *ctx);
bool	has_digit(char *argv[]);
bool	is_int(char *input);
bool	check_duplicated_num(int *num_array, int64_t size);
void	free_splitted(char **splitted);
void	create_stacks(t_ctx *ctx, int *num_array);
void	coordinate_compression(t_ctx *ctx, int *num_array);
void	sort_num_array(t_ctx *ctx, int *num_array);
void	create_rank_array(t_ctx *ctx);
void	mark_unsorted(t_ctx *ctx);
t_lis	get_lis(t_ctx *ctx);
void	init_lis_info(t_ctx *ctx, t_lis *lis);
void	reset_tails(t_lis lis, int64_t len);

#endif