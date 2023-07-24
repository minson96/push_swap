/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:13:50 by minson            #+#    #+#             */
/*   Updated: 2023/07/24 15:27:01 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **arr, int idx)
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

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_cnt_split(const char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isspace(str[i]))
		{
			cnt++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (cnt);
}

static char	*ft_arr(const char *str)
{
	int		cnt;
	char	*word;

	cnt = 0;
	while (str[cnt] && !ft_isspace(str[cnt]))
		cnt++;
	word = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, cnt + 1);
	return (word);
}

char	**ft_split(char const *s, int *i)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (ft_cnt_split(s) + 1));
	if (!s || !arr)
		return (NULL);
	while (*s)
	{
		while (*s && ft_isspace(*s))
			s++;
		if (*s == '\0')
			break ;
		arr[*i] = ft_arr(s);
		if (arr[*i] == NULL)
		{
			ft_free_split(arr, *i);
			return (NULL);
		}
		(*i)++;
		while (*s && !ft_isspace(*s))
			s++;
	}
	arr[*i] = 0;
	return (arr);
}
