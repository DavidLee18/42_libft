/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:35:04 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:40:24 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

_Bool	gc_realloc3(t_list *temp_node, void **oldp, void *new)
{
	t_list	*temp_node2;

	while (temp_node->next && temp_node->next->next)
	{
		if (temp_node->next->content == *oldp)
		{
			temp_node2 = temp_node->next;
			temp_node->next = temp_node->next->next;
			free(temp_node2->content);
			free(temp_node2);
			*oldp = new;
			return (1);
		}
		temp_node = temp_node->next;
	}
	*oldp = new;
	return (1);
}

size_t	min_usize(const size_t a, const size_t b)
{
	if (a > b)
		return (b);
	return (a);
}
