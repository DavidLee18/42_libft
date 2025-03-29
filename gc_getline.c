/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:46:12 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/30 00:53:01 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gc_getline(t_list **dyn, int fd)
{
	static char	**temp;
	char		*str;
	ssize_t		stat;

	if (fd < 0)
		return (NULL);
	str = load_temp(dyn, &temp);
	if (!str)
		return (NULL);
	while (ft_strchr(str, '\n') == NULL)
	{
		stat = read(fd, str + stat, BUFFER_SIZE);
		if (stat < 0)
			return (NULL);
		if (ft_strchr(str, '\n'))
			break ;
		if (stat < BUFFER_SIZE)
			return (str);
		stat = ft_strlen(str);
		gc_realloc(dyn, (void **)&str, ft_strlen(str),
			ft_strlen(str) + BUFFER_SIZE + 1);
	}
	return (pop_split(dyn, str, &temp));
}

char	*pop_temp(t_list **dyn, char ***temp)
{
	char	*str;
	size_t	i;

	if (**temp == NULL)
	{
		*temp = NULL;
		return (NULL);
	}
	str = gc_strdup(dyn, **temp);
	i = 1;
	while (*(*temp + i) != NULL)
	{
		ft_memmove(*(*temp + (i - 1)), *(*temp + i), ft_strlen(*(*temp + i)));
		i++;
	}
	*(*temp + (i - 1)) = NULL;
	if (i == 1)
		*temp = NULL;
	return (str);
}

char	*pop_split(t_list **dyn, char *str, char ***temp)
{
}

char	*load_temp(t_list **dyn, char ***temp)
{
}
