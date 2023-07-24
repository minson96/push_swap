/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:10:57 by minson            #+#    #+#             */
/*   Updated: 2023/04/29 17:05:44 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	char	one_letter;

	one_letter = c;
	write (1, &one_letter, 1);
	return (1);
}

static int	print_array(char *str)
{
	size_t	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}
	return (idx);
}

int	print_str(char *str)
{
	size_t	len;

	if (str == 0)
	{
		len = print_array("(null)");
		return (len);
	}
	len = print_array(str);
	return (len);
}

static void	ft_putptr(unsigned long long ptr, size_t *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += print_char('0' + ptr);
		else
			*len += print_char(ptr - 10 + 'a');
	}
}

int	print_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 2;
	write(1, "0x", 2);
	ft_putptr(ptr, &len);
	return (len);
}
