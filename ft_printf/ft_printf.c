/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:11:19 by minson            #+#    #+#             */
/*   Updated: 2023/04/29 17:11:01 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_form(const char c, va_list *ap)
{
	if (c == 'c')
		return (print_char(va_arg(*ap, int)));
	else if (c == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(*ap, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(*ap, int), "0123456789"));
	else if (c == 'u')
		return (print_unsigned_int(va_arg(*ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (print_hex(va_arg(*ap, long long), "0123456789abcdef"));
	else if (c == 'X')
		return (print_hex(va_arg(*ap, long long), "0123456789ABCDEF"));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *sentence, ...)
{
	size_t		idx;
	size_t		len;
	va_list		ap;

	va_start(ap, sentence);
	idx = 0;
	len = 0;
	while (sentence[idx])
	{
		if (sentence[idx] == '%')
		{
			len += check_form(sentence[idx + 1], &ap);
			idx++;
		}
		else
			len += print_char(sentence[idx]);
		idx++;
	}
	va_end(ap);
	return (len);
}
