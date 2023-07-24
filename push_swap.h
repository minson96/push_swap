/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:22:36 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:07:25 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFFER_SIZE 42
# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_info
{
	int		size;
	int		*arr;
	t_stack	*t_a;
	t_stack	*t_b;
}	t_info;

void	swap_stack(t_info *info, int flag);
void	push_stack(t_info *info, int flag);
void	rotate_stack(t_info *info, int flag);
void	reverse_rotate_stack(t_info *info, int flag);
void	repeat_rotate_both(t_info *info, int *a, int *b);
void	repeat_rotate_stack(t_info *info, int *a, int *b);
void	rotate_last(t_info *info);
t_node	*newnode(int value);
void	push_top(t_stack *stack, t_node *node);
void	push_bottom(t_stack *stack, t_node *node);
t_node	*pop_top(t_stack *stack);
t_node	*pop_bottom(t_stack *stack);
int		get_max(t_info *info);
int		get_cnt(t_info *info, int num);
void	quick_sort(t_info *info);
void	greedy_sort(t_info *info);
void	exit_error(void);
void	free_stack(t_info *info);
void	free_split(char **arr, int idx);
int		check_arr(t_info *info, int *arr, int i, int flag);
int		ft_abs(int num);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

#endif