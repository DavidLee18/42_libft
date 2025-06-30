/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:16:03 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 01:42:13 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matalloc(t_list **dyn, t_matrix *mat)
{
	if (mat->cap == 0)
		mat->ptr = (t_vec *)gc_calloc(dyn, 1, sizeof(t_vec));
	else
		gc_realloc(dyn, (void **)&mat->ptr, mat->cap * sizeof(t_vec),
			mat->cap * 2 * sizeof(t_vec));
	if (!mat->ptr)
		return ;
	if (mat->cap == 0)
		mat->cap = 1;
	else
		mat->cap *= 2;
}

_Bool	add_row(t_list **dyn, t_vec row, t_matrix *mat)
{
	t_vec	*v;

	if (mat->col == mat->cap)
		matalloc(dyn, mat);
	if (mat->col != 0 && mat->ptr[0].len != row.len)
		return (0);
	v = veccpy(dyn, row);
	if (v == NULL)
		return (0);
	mat->ptr[mat->col++] = *v;
	return (1);
}

_Bool	add_col(t_list **dyn, t_vec col, t_matrix *mat)
{
	size_t	i;

	if (mat->col == 0)
	{
		i = 0;
		while (i < col.len)
		{
			add_row(dyn, (t_vec){.ptr = NULL, .len = 0, .cap = 0}, mat);
			i++;
		}
	}
	else if (mat->col != col.len)
		return (0);
	i = 0;
	while (i < mat->col)
	{
		push_back(dyn, mat->ptr + i, col.ptr[i]);
		i++;
	}
	return (1);
}

t_matrix	*matmul(t_list **dyn, t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	size_t		i;

	if (a->col == 0 || b->col == 0 || a->ptr->len != b->col)
		return (NULL);
	c = (t_matrix *)gc_calloc(dyn, 1, sizeof(t_matrix));
	if (c == NULL)
		return (NULL);
	c->ptr = (t_vec *)gc_calloc(dyn, a->col, sizeof(t_vec));
	if (c->ptr == NULL)
		return (NULL);
	i = 0;
	c->cap = a->col;
	c->col = a->col;
	while (i < a->col)
	{
		c->ptr[i].ptr = (int *)gc_calloc(dyn, b->ptr->len, sizeof(int));
		if (c->ptr[i].ptr == NULL)
			return (NULL);
		c->ptr[i].cap = b->ptr->len;
		c->ptr[i].len = b->ptr->len;
		i++;
	}
	return (matmul2(c, a, b));
}

t_matrix	*matmul2(t_matrix *c, t_matrix *a, t_matrix *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < a->col)
	{
		j = 0;
		while (j < b->ptr->len)
		{
			c->ptr[i].ptr[j] = dot_prod(a->ptr[i], b, j);
			j++;
		}
		i++;
	}
	return (c);
}
