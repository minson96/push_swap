/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:11:40 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:11:42 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_rotate_both(t_info *info, int *a, int *b)
{
	while (*a > 0 && *b > 0)
	{
		rotate_stack(info, 3);
		(*a)--;
		(*b)--;
	}
	while (*a < 0 && *b < 0)
	{
		reverse_rotate_stack(info, 3);
		(*a)++;
		(*b)++;
	}
}

void	repeat_rotate_stack(t_info *info, int *a, int *b)
{
	while (*a > 0)
	{
		rotate_stack(info, 1);
		(*a)--;
	}
	while (*a < 0)
	{
		reverse_rotate_stack(info, 1);
		(*a)++;
	}
	while (*b > 0)
	{
		rotate_stack(info, 2);
		(*b)--;
	}
	while (*b < 0)
	{
		reverse_rotate_stack(info, 2);
		(*b)++;
	}
}

void	rotate_last(t_info *info)
{
	int	i;

	i = get_cnt(info, get_max(info));
	if (i > (info->t_a->size / 2))
	{
		while (i < info->t_a->size - 1)
		{
			reverse_rotate_stack(info, 1);
			i++;
		}
	}
	else
	{
		while (i > -1)
		{
			rotate_stack(info, 1);
			i--;
		}
	}
}
