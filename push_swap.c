/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:22:08 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:21 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_info *info)
{
	info->t_a = (t_stack *)malloc(sizeof(t_stack));
	info->t_b = (t_stack *)malloc(sizeof(t_stack));
	if (!info->t_a || !info->t_b)
		exit_error();
	info->size = 0;
	info->arr = NULL;
	info->t_a->size = 0;
	info->t_b->size = 0;
	info->t_a->top = NULL;
	info->t_b->top = NULL;
	info->t_a->bottom = NULL;
	info->t_b->bottom = NULL;
}

static int	get_arr_size(int argc, char *argv[])
{
	int		i;
	int		num;
	int		sum;
	char	**tmp;

	i = 0;
	sum = 0;
	while (i < argc - 1)
	{
		num = 0;
		tmp = ft_split(argv[i + 1], &num);
		if (!tmp[0])
			exit_error();
		free_split(tmp, num);
		sum += num;
		i++;
	}
	return (sum);
}

static void	make_arr(char *argv[], t_info *info, int *arr, int sum)
{
	int		i;
	int		j;
	int		idx;
	int		num;
	char	**tmp;

	i = 0;
	idx = 0;
	while (idx < sum)
	{
		j = 0;
		num = 0;
		tmp = ft_split(argv[i + 1], &num);
		if (!tmp[0])
			exit_error();
		while (j < num)
		{
			arr[idx++] = ft_atoi(tmp[j++]);
			info->size++;
		}
		i++;
		free_split(tmp, num);
	}
}

static int	*make_stack(int argc, char *argv[], t_info *info, int i)
{
	int		sum;
	int		*arr;
	t_node	*new;

	i = 0;
	sum = get_arr_size(argc, argv);
	arr = (int *)malloc(sizeof(int) * sum);
	if (!arr)
		exit_error();
	make_arr(argv, info, arr, sum);
	while (i < sum)
	{
		new = newnode(arr[i++]);
		push_bottom(info->t_a, new);
	}
	return (arr);
}

int	main(int argc, char *argv[])
{
	int		flag;
	int		*arr;
	t_info	info;

	if (argc < 2)
		return (-1);
	init_stack(&info);
	arr = make_stack(argc, argv, &info, 0);
	flag = check_arr(&info, arr, 0, 0);
	if (flag == 0)
		return (0);
	info.arr = arr;
	if (info.t_a->size == 2)
	{
		if (info.t_a->top->val > info.t_a->bottom->val)
			swap_stack(&info, 1);
	}
	else
	{
		quick_sort(&info);
		greedy_sort(&info);
	}
	free_stack(&info);
	return (0);
}
