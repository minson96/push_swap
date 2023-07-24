/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:14:57 by minson            #+#    #+#             */
/*   Updated: 2022/12/02 17:54:23 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*mem;

	if (!s)
		return (NULL);
	mem = NULL;
	len = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (mem == 0)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		mem[i] = f(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
