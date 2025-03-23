/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:46:12 by jaehylee          #+#    #+#             */
/*   Updated: 2025/03/23 14:37:43 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gc_getline(t_list **dyn, int fd)
{
	static char	*temp;
	char		*str;

	if (fd < 0)
		return (NULL);
	str = (char *)gc_calloc(dyn, BUFFER_SIZE, sizeof(char));
	if (!str)
		return (NULL);
	read_loop(dyn, fd, 0, (char **[]){&str, &temp});
	return (str);
}

void	read_loop(t_list **dyn, int fd, size_t offset, char ***templ)
{
	ssize_t	i;
	ssize_t	idx;

	if (!**templ)
	{
		idx = take_temp(dyn, templ[0], templ[1]);
		if ((templ[1] && *templ[1] && *(**templ + idx) == '\n') || idx < 0)
			return ;
		offset = idx;
	}
	else if (offset != 0 && *(**templ + offset - 1) == '\n')
		return ;
	i = read(fd, **templ + offset, BUFFER_SIZE);
	if (i < 0 || (i == 0 && **templ && !***templ))
		**templ = NULL;
	if (i == 0 && (!**templ || !*(**templ + offset)) && (**templ && !***templ))
		*templ[1] = NULL;
	if (i <= 0)
		return ;
	idx = take_line(dyn, *templ, offset + i, templ[1]);
	if (idx >= 0)
		read_loop(dyn, fd, idx, templ);
}

ssize_t	take_temp(t_list **dyn, char **strp, char **temp)
{
	size_t	i;
	size_t	alloc;

	alloc = gc_realloc(dyn, (void **)strp, 0, 1);
	if (!alloc)
		return (-1);
	if (!*temp)
	{
		alloc = gc_realloc(dyn, (void **)temp, 0, 1);
		if (!alloc)
			return (-1);
	}
	else if (!**temp)
	{
		*temp = NULL;
		return ((ssize_t)gc_realloc(dyn, (void **)strp, 1,
				BUFFER_SIZE + 1) - 1);
	}
	i = 0;
	while (*(*temp + i) && *(*temp + i) != '\n')
		i++;
	return (load_substr(dyn, strp, temp, i));
}

ssize_t	load_substr(t_list **dyn, char **strp, char **temp, size_t nl)
{
	size_t	temp_len;
	size_t	alloc;

	temp_len = ft_strlen(*temp);
	alloc = gc_realloc(dyn, (void **)strp, 1,
			nl + (nl != temp_len) + BUFFER_SIZE + 1);
	if (!alloc)
		return (-1);
	ft_memmove(*strp, *temp, nl + (nl != temp_len));
	if (temp_len == nl)
	{
		*temp = NULL;
		return ((ssize_t)nl);
	}
	ft_memmove(*temp, *temp + nl + 1, temp_len - nl - 1);
	alloc = gc_realloc(dyn, (void **)temp, temp_len + 1, temp_len - nl);
	if (!alloc)
		return (-1);
	*(*temp + temp_len - nl - 1) = '\0';
	return ((ssize_t)nl + (nl != temp_len));
}
