/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:02:16 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:07:28 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->t_a->top->val;
	b = info->t_a->top->prev->val;
	c = info->t_a->bottom->val;
	if (a > b && b < c && c > a)
		swap_stack(info, 1);
	else if (a > b && b < c && c < a)
		rotate_stack(info, 1);
	else if (a < b && b > c && c < a)
		reverse_rotate_stack(info, 1);
	else if (a > b && b > c && c < a)
	{
		swap_stack(info, 1);
		reverse_rotate_stack(info, 1);
	}
	else if (a < b && b > c && c > a)
	{
		swap_stack(info, 1);
		rotate_stack(info, 1);
	}
}

void	quick_sort(t_info *info)
{
	int		pvt_1;
	int		pvt_2;
	int		cnt;
	t_node	*tmp;

	cnt = 0;
	pvt_1 = info->arr[info->size / 3];
	pvt_2 = info->arr[info->size * 2 / 3];
	while (cnt < info->size && info->t_a->size > 3)
	{
		tmp = info->t_a->top;
		if (tmp->val <= pvt_1)
		{
			push_stack(info, 2);
			rotate_stack(info, 2);
		}
		else if (tmp->val > pvt_1 && tmp->val <= pvt_2)
			push_stack(info, 2);
		else
			rotate_stack(info, 1);
		cnt++;
	}
	while (info->t_a->size > 3)
		push_stack(info, 2);
	sort_3(info);
}
