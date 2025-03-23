/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:36:26 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:33:51 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vecalloc(t_list **dyn, t_vec *vec)
{
	if (vec->cap == 0)
		vec->ptr = (int *)gc_calloc(dyn, 1, sizeof(int));
	else
		gc_realloc(dyn, (void **)&(vec->ptr), vec->cap
			* sizeof(int), vec->cap * 2 * sizeof(int));
	if (!vec->ptr)
		return ;
	if (vec->cap == 0)
		vec->cap = 1;
	else
		vec->cap *= 2;
}

_Bool	has_dup(const t_vec v)
{
	size_t	i;
	size_t	temp;

	temp = 0;
	while (temp < v.len)
	{
		i = 0;
		while (i < v.len)
		{
			if (i != temp && v.ptr[i] == v.ptr[temp])
				return (1);
			i++;
		}
		temp++;
	}
	return (0);
}

t_vec	*veccpy(t_list **dyn, const t_vec v)
{
	t_vec	*res;

	res = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (res == NULL)
		return (NULL);
	res->ptr = (int *)gc_calloc(dyn, v.cap, sizeof(int));
	ft_memmove(res->ptr, v.ptr, v.len * sizeof(int));
	res->cap = v.cap;
	res->len = v.len;
	return (res);
}

_Bool	velem(const int i, const t_vec v)
{
	size_t	j;

	j = 0;
	while (j < v.len)
	{
		if (v.ptr[j] == i)
			return (1);
		j++;
	}
	return (0);
}
