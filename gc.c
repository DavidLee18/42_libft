/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:36:26 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:41:06 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gc_free_all(t_list *head)
{
	t_list	*curr;
	t_list	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		if (curr->content)
			free(curr->content);
		free(curr);
		curr = next;
	}
}

_Bool	gc_add_to_list(t_list **head, void *new)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_calloc(1, sizeof(t_list));
	if (!node)
		return (0);
	node->content = new;
	node->next = NULL;
	if (!(*head))
	{
		(*head) = node;
		return (1);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

void	*gc_calloc(t_list **head, const size_t count, const size_t size)
{
	void	*new;

	new = ft_calloc(count, size);
	if (!new)
		return (NULL);
	if (!gc_add_to_list(head, new))
	{
		free(new);
		return (NULL);
	}
	return (new);
}

_Bool	gc_realloc(t_list **dyn, void **oldp, const size_t old_size,
			const size_t new_size)
{
	void	*temp;
	t_list	*temp_node;

	temp = gc_calloc(dyn, 1, new_size);
	if (temp == NULL)
	{
		*oldp = NULL;
		return (0);
	}
	ft_bzero(temp, new_size);
	if (*oldp)
		ft_memmove(temp, *oldp, min_usize(old_size, new_size));
	temp_node = *dyn;
	if (temp_node->next == NULL)
		return (*oldp = temp, 1);
	if (temp_node->next && !temp_node->next->next)
	{
		*dyn = temp_node->next;
		free(temp_node->content);
		free(temp_node);
		*oldp = temp;
		return (1);
	}
	return (gc_realloc2(dyn, oldp, temp));
}

_Bool	gc_realloc2(t_list **dyn, void **oldp, void *new)
{
	t_list	*temp_node;

	temp_node = *dyn;
	if (temp_node->content == *oldp)
	{
		*dyn = temp_node->next;
		free(temp_node->content);
		free(temp_node);
		*oldp = new;
		return (1);
	}
	return (gc_realloc3(temp_node, oldp, new));
}
