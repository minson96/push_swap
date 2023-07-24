/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:39:16 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:02:42 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min_cnt(t_info *info, long long int num, int i)
{
	int					tmp;
	long long int		diff;
	long long int		diff_min;
	t_node				*node;

	diff_min = 4294967295;
	node = info->t_a->top;
	while (node)
	{
		if (num > node->val)
			diff = num - node->val;
		else
			diff = node->val - num;
		if (diff_min >= diff)
		{
			diff_min = diff;
			tmp = node->val;
		}
		node = node->prev;
	}
	i = get_cnt(info, tmp);
	if (tmp < num)
		i++;
	return (i);
}

static int	set_new_a(t_info *info, int num)
{
	int	cnt;
	int	max;

	cnt = 0;
	if (info->t_a->top)
	{
		max = get_max(info);
		if (num > max)
			cnt = get_cnt(info, max) + 1;
		else
			cnt = get_min_cnt(info, num, 0);
		if (cnt > info->t_a->size / 2)
			cnt = (info->t_a->size - cnt) * (-1);
	}
	return (cnt);
}

static int	new_ab(int a, int b, int new_a, int new_b)
{
	int	ab_sum;
	int	new_sum;

	ab_sum = ft_abs(a) + ft_abs(b);
	new_sum = ft_abs(new_a) + ft_abs(new_b);
	if (ab_sum > new_sum)
		return (1);
	return (0);
}

static void	find_best(t_info *info, int *a, int *b)
{
	int		idx;
	int		num;
	int		new_a;
	int		new_b;
	t_node	*tmp;

	idx = 0;
	tmp = info->t_b->top;
	while (idx < info->t_b->size)
	{
		num = tmp->val;
		new_a = set_new_a(info, num);
		if (idx >= (info->t_b->size + 1) / 2)
			new_b = (info->t_b->size - idx) * (-1);
		else
			new_b = idx;
		if (idx == 0 || new_ab(*a, *b, new_a, new_b))
		{
			*a = new_a;
			*b = new_b;
		}
		tmp = tmp->prev;
		idx++;
	}
}

void	greedy_sort(t_info *info)
{
	int	a;
	int	b;

	while (info->t_b->size)
	{
		find_best(info, &a, &b);
		repeat_rotate_both(info, &a, &b);
		repeat_rotate_stack(info, &a, &b);
		push_stack(info, 1);
	}
	rotate_last(info);
}
