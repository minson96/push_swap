/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:02:01 by minson            #+#    #+#             */
/*   Updated: 2023/04/29 17:06:31 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char *base)
{
	size_t	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base);
		ft_putnbr_base(nbr % len, base);
	}
	else
		write(1, &base[nbr], 1);
}

int	print_nbr(int nbr, char *base)
{
	unsigned int	nb;
	size_t			len;

	len = 0;
	nb = nbr;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nb = (-1) * nbr;
		len++;
	}
	if (nbr == 0)
		len++;
	ft_putnbr_base(nb, base);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	print_unsigned_int(unsigned int nbr, char *base)
{
	unsigned int	nb;
	size_t			len;

	len = 0;
	nb = nbr;
	if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	ft_putnbr_base(nbr, base);
	return (len);
}

int	print_hex(unsigned int nbr, char *base)
{
	unsigned int	nb;
	size_t			len;

	len = 0;
	nb = nbr;
	if (nb == 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	ft_putnbr_base(nbr, base);
	return (len);
}
