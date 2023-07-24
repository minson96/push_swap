/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:14:35 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:14:37 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * (-1));
	return (num);
}

int	get_max(t_info *info)
{
	int		max;
	t_node	*node;

	node = info->t_a->top;
	max = node->val;
	while (node)
	{
		if (node->val > max)
			max = node->val;
		node = node->prev;
	}
	return (max);
}

int	get_cnt(t_info *info, int num)
{
	int		i;
	t_node	*node;

	i = 0;
	node = info->t_a->top;
	while (node)
	{
		if (node->val == num)
			break ;
		i++;
		node = node->prev;
	}
	return (i);
}
