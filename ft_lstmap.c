/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:00:36 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/10 09:00:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	int		size;
	t_list	*temp;
	int		i;
	t_list	*temp2;

	if (!lst)
		return (NULL);
	size = ft_lstsize(lst);
	res = (t_list *)ft_calloc(size, sizeof(t_list));
	if (res == NULL)
		return (NULL);
	i = -1;
	temp = lst;
	temp2 = res;
	while (++i < size && temp)
	{
		temp2->content = (*f)(temp->content);
		temp = temp->next;
		temp2 = temp2->next;
	}
	ft_lstclear(&lst, del);
	return (res);
}
