/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_getline2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:57:55 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:38:26 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	take_line(t_list **dyn, char **strp, size_t until, char **temp)
{
	size_t	k;
	ssize_t	res;
	size_t	alloc;

	if (!*temp)
	{
		alloc = gc_realloc(dyn, (void **)temp, 0, 1);
		if (!alloc)
			return (-1);
	}
	k = 0;
	if (!*strp)
		return (-1);
	while (k < until && *(*strp + k) && *(*strp + k) != '\n')
		k++;
	res = add_substr(dyn, until, k, (char **[]){strp, temp});
	if (res < 0)
		return (res);
	alloc = gc_realloc(dyn, (void **)strp, res + 1, res + 1 + BUFFER_SIZE);
	if (!alloc)
		return (-1);
	return (res);
}

ssize_t	add_substr(t_list **dyn, const size_t src_len, const size_t from,
	char ***src_dst)
{
	size_t	dest_len;
	size_t	alloc;

	if (!**src_dst)
		return (-1);
	if (from != 0 && from == src_len)
		return ((ssize_t)src_len);
	dest_len = ft_strlen(*src_dst[1]);
	alloc = gc_realloc(dyn, (void **)src_dst[1], dest_len + 1,
			dest_len + src_len - from);
	if (!alloc)
		return (-1);
	ft_memmove(*src_dst[1] + dest_len, **src_dst + from + 1,
		src_len - from - 1);
	*(*src_dst[1] + dest_len + src_len - from - 1) = '\0';
	alloc = gc_realloc(dyn, (void **)*src_dst, src_len, from + 2);
	if (!alloc)
		return (-1);
	*(**src_dst + from + 1) = '\0';
	return ((ssize_t)from + 1);
}
