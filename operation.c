/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:14:05 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:29 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_info *info, int flag)
{
	int	temp;

	if (flag == 1 || flag == 3)
	{
		if (info->t_a->size < 2)
			return ;
		temp = info->t_a->top->val;
		info->t_a->top->val = info->t_a->top->prev->val;
		info->t_a->top->prev->val = temp;
		if (flag == 1)
			ft_printf("sa\n");
	}
	if (flag == 2 || flag == 3)
	{
		if (info->t_b->size < 2)
			return ;
		temp = info->t_b->top->val;
		info->t_b->top->val = info->t_b->top->prev->val;
		info->t_b->top->prev->val = temp;
		if (flag == 2)
			ft_printf("sb\n");
	}
	if (flag == 3)
		ft_printf("ss\n");
}

void	push_stack(t_info *info, int flag)
{
	t_node	*tmp;

	if (flag == 1)
	{
		if (info->t_b->size < 1)
			return ;
		tmp = pop_top(info->t_b);
		push_top(info->t_a, tmp);
		ft_printf("pa\n");
	}
	else if (flag == 2)
	{
		if (info->t_a->size < 1)
			return ;
		tmp = pop_top(info->t_a);
		push_top(info->t_b, tmp);
		ft_printf("pb\n");
	}
}

void	rotate_stack(t_info *info, int flag)
{
	t_node	*tmp;

	if (flag == 1 || flag == 3)
	{
		if (info->t_a->size < 2)
			return ;
		tmp = pop_top(info->t_a);
		push_bottom(info->t_a, tmp);
		if (flag == 1)
			ft_printf("ra\n");
	}
	if (flag == 2 || flag == 3)
	{
		if (info->t_b->size < 2)
			return ;
		tmp = pop_top(info->t_b);
		push_bottom(info->t_b, tmp);
		if (flag == 2)
			ft_printf("rb\n");
	}
	if (flag == 3)
		ft_printf("rr\n");
}

void	reverse_rotate_stack(t_info *info, int flag)
{
	t_node	*tmp;

	if (flag == 1 || flag == 3)
	{
		if (info->t_a->size < 2)
			return ;
		tmp = pop_bottom(info->t_a);
		push_top(info->t_a, tmp);
		if (flag == 1)
			ft_printf("rra\n");
	}
	if (flag == 2 || flag == 3)
	{
		if (info->t_b->size < 2)
			return ;
		tmp = pop_bottom(info->t_b);
		push_top(info->t_b, tmp);
		if (flag == 2)
			ft_printf("rrb\n");
	}
	if (flag == 3)
		ft_printf("rrr\n");
}
