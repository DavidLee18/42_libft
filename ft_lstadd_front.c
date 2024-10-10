/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 07:56:48 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/10 07:56:48 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	int	l;

	if (!lst || !new || !*lst)
		return ;
	l = 0;
	while (lst[l])
		l++;
	while (--l >= 0)
		lst[l + 1] = lst[l];
	lst[0] = new;
}
