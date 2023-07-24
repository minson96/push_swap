/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:39:39 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 13:21:53 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_info *info)
{
	t_node	*tmp;
	t_node	*next;

	tmp = info->t_a->bottom;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(info->t_a);
	free(info->t_b);
	free(info->arr);
}

void	free_split(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	check_dup(t_info *info, int *arr)
{
	int	i;

	i = 0;
	while (i < info->t_a->size - 1)
	{
		if (arr[i] == arr[i + 1])
			exit_error();
		i++;
	}
}

int	check_arr(t_info *info, int *arr, int i, int flag)
{
	int	j;
	int	tmp;

	while (i < info->t_a->size - 1)
	{
		j = i + 1;
		while (j < info->t_a->size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				flag++;
			}
			j++;
		}
		i++;
	}
	check_dup(info, arr);
	return (flag);
}
