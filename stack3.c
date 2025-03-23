/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:35:04 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:40:49 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*vecmax(t_list **dyn, const t_vec v)
{
	size_t	j;
	int		*i;

	j = 0;
	i = (int *)gc_calloc(dyn, 1, sizeof(int));
	if (i == NULL || v.len == 0)
		return (NULL);
	*i = v.ptr[j];
	while (j < v.len && v.len != 1)
	{
		if (v.ptr[j] > *i)
			*i = v.ptr[j];
		j++;
	}
	return (i);
}

int	veccmp(const t_vec v1, const t_vec v2)
{
	size_t	i;

	i = 0;
	while (i < v1.len && i < v2.len)
	{
		if (v1.ptr[i] != v2.ptr[i])
			return (v1.ptr[i] - v2.ptr[i]);
		i++;
	}
	if (v1.len > v2.len)
		return (1);
	else if (v2.len > v1.len)
		return (-1);
	return (0);
}
