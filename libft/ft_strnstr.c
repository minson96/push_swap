/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:26:16 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 15:52:54 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		if ((ft_strncmp(haystack + i, needle, ft_strlen(needle)) == 0)
			&& i + ft_strlen(needle) <= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
