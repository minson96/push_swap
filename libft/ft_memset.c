/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:43:44 by minson            #+#    #+#             */
/*   Updated: 2022/11/14 14:02:03 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr_str;
	size_t			i;

	i = 0;
	ptr_str = b;
	while (i < len)
	{
		*ptr_str = (unsigned char)c;
		ptr_str++;
		i++;
	}
	return (b);
}
