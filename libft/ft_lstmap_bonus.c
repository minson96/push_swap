/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minson <minson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:08:32 by minson            #+#    #+#             */
/*   Updated: 2022/12/03 17:39:33 by minson           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_mem;
	t_list	*now;
	void	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	now = NULL;
	new_mem = now;
	while (lst)
	{
		tmp = f(lst->content);
		now = ft_lstnew(tmp);
		if (now == NULL)
		{
			del(tmp);
			ft_lstclear(&new_mem, del);
			return (NULL);
		}
		ft_lstadd_back(&new_mem, now);
		lst = lst->next;
	}
	return (new_mem);
}
