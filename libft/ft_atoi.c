/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:20:07 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 17:44:42 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	min_max_check(long tot_res, int sign)
{
	if (sign < 0)
	{
		if (tot_res > 0 && sign < 0)
			return (0);
	}
	else
	{
		if (tot_res < 0 && sign > 0)
			return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long		res;
	int			sign;
	size_t		i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && (str[i] <= '9' && str[i] >= '0'))
	{
		res = res * 10 + str[i] - '0';
		if (min_max_check(res * sign, sign) != 1)
			return (min_max_check(res * sign, sign));
		i++;
	}
	return ((int)(sign * res));
}
