/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:26:14 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/10 08:26:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newl)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	while (*(lst + i))
		i++;
	*(lst + i) = newl;
	*(lst + i + 1) = NULL;
}
