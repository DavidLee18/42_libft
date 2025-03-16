/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:35:55 by jaehylee          #+#    #+#             */
/*   Updated: 2024/10/02 09:35:55 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	**gc_alloc_split(t_list **dyn, char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == c)
			total++;
		i++;
	}
	split = (char **)gc_calloc(dyn, total + 2, sizeof(char *));
	if (!split)
		return (NULL);
	return (split);
}

static void
	*gc_split_range(t_list **dyn, char **split, char const *s,
		t_split_next *ts)
{
	split[(ts + 1)->length] = gc_substr(dyn, s, ts->start, ts->length);
	if (!split[(ts + 1)->length])
		return (NULL);
	(ts + 1)->length++;
	return (split);
}

static void
	*gc_split_by_char(t_list **dyn, char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	ts[2];

	i = 0;
	ts[1].length = 0;
	ts[1].start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ts[0].start = ts[1].start;
			ts[0].length = (i - ts[1].start);
			if (i > ts[1].start && !gc_split_range(dyn, split, s, &ts[0]))
				return (NULL);
			ts[1].start = i + 1;
		}
		i++;
	}
	ts[0].start = ts[1].start;
	ts[0].length = (i - ts[1].start);
	if (i > ts[1].start && i > 0 && !gc_split_range(dyn, split, s, &ts[0]))
		return (NULL);
	split[ts[1].length] = 0;
	return (split);
}

char
	**gc_split(t_list **dyn, char const *s, char c)
{
	char	**split;

	split = gc_alloc_split(dyn, s, c);
	if (!split)
		return (NULL);
	if (!gc_split_by_char(dyn, split, s, c))
		return (NULL);
	return (split);
}
