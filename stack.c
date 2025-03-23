/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:36:26 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:33:36 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_back(t_list **dyn, t_vec *vec, const int value)
{
	if (vec->len == vec->cap)
		vecalloc(dyn, vec);
	vec->ptr[vec->len++] = value;
}

void	push_front(t_list **dyn, t_vec *vec, const int value)
{
	int	*newp;
	int	*temp;

	if (vec->len == vec->cap)
	{
		if (vec->cap == 0)
		{
			push_back(dyn, vec, value);
			return ;
		}
		newp = (int *)gc_calloc(dyn, 2 * vec->cap, sizeof(int));
		vec->cap *= 2;
	}
	else
		newp = (int *)gc_calloc(dyn, vec->cap, sizeof(int));
	temp = newp + 1;
	ft_memmove(temp, vec->ptr, sizeof(int) * (vec->len++));
	*newp = value;
	vec->ptr = newp;
}

int	*pop_back(t_list **dyn, t_vec *vec)
{
	int	*res;

	if (vec == NULL || vec->len == 0 || !vec->ptr)
		return (NULL);
	res = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (!res)
		return (NULL);
	*res = vec->ptr[--vec->len];
	return (res);
}

_Bool	consec_eq(const t_vec v)
{
	size_t	i;

	i = 0;
	while (v.len > 1 && i < v.len - 1)
	{
		if (v.ptr[i] == v.ptr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

t_vec	*vecrev(t_list **dyn, t_vec *v)
{
	t_vec	*new;
	int		*temp;

	if (!v || !v->ptr)
		return (NULL);
	new = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	if (!new)
		return (NULL);
	temp = pop_back(dyn, v);
	while (temp != NULL)
	{
		push_back(dyn, new, *temp);
		temp = pop_back(dyn, v);
	}
	return (new);
}
