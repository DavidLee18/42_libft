/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:35:55 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/02 09:35:55 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	*ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	unsigned long long	t_size;
	unsigned long long	i;

	t_size = (unsigned long long) count * (unsigned long long) size;
	if (t_size > 4294967295)
		return (NULL);
	ptr = (void *)malloc((unsigned long)t_size);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < t_size)
		*(char *)(ptr + i) = 0;
	return (ptr);
}
