/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:38:56 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 01:43:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*_3d_point_col(t_list **dyn, int x, int y, int z)
{
	t_matrix	*p;
	t_vec		v;

	p = (t_matrix *)gc_calloc(dyn, 1, sizeof(t_matrix));
	if (p == NULL)
		return (NULL);
	p->col = 0;
	p->cap = 0;
	v = (t_vec){.ptr = NULL, .len = 0, .cap = 0};
	push_back(dyn, &v, x);
	if (!add_row(dyn, v, p))
		return (NULL);
	v.ptr[0] = y;
	if (!add_row(dyn, v, p))
		return (NULL);
	v.ptr[0] = z;
	if (!add_row(dyn, v, p))
		return (NULL);
	return (p);
}

t_vec	*mat2vec(t_list **dyn, t_matrix *mat)
{
	t_vec	v;
	size_t	i;

	if (mat->col != 1 && mat->col > 0 && mat->ptr[0].len != 1)
		return (NULL);
	if (mat->col == 1)
		return (veccpy(dyn, mat->ptr[0]));
	v = (t_vec){.ptr = NULL, .len = 0, .cap = 0};
	i = 0;
	while (i < mat->col)
	{
		push_back(dyn, &v, mat->ptr[i].ptr[0]);
		i++;
	}
	return (veccpy(dyn, v));
}

t_matrix	*transpose(t_list **dyn, t_matrix *mat)
{
	t_matrix	*t;
	size_t		i;

	if (mat->col == 0 || mat->ptr->len == 0)
		return (NULL);
	t = (t_matrix *)gc_calloc(dyn, 1, sizeof(t_matrix));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < mat->col)
	{
		add_col(dyn, mat->ptr[i], t);
		i++;
	}
	return (t);
}

t_matrix	*append(t_list **dyn, t_matrix *a, t_matrix *b)
{
	size_t		i;
	t_matrix	*res;

	if (a->col == 0 || a->ptr->len == 0 || b->col == 0 || b->ptr->len == 0
		|| (a->col != b->col && a->ptr->len != b->ptr->len))
		return (NULL);
	i = 0;
	if (a->ptr->len == b->ptr->len)
	{
		res = matcpy(dyn, a);
		while (i < b->col)
		{
			if (res == NULL || !add_row(dyn, b->ptr[i], res))
				return (NULL);
			i++;
		}
		return (res);
	}
	res = append(dyn, transpose(dyn, a), transpose(dyn, b));
	if (res == NULL)
		return (NULL);
	return (transpose(dyn, res));
}

t_matrix	*matcpy(t_list **dyn, t_matrix *mat)
{
	t_matrix	*cpy;
	t_vec		*temp;
	size_t		i;

	if (mat->col == 0 || mat->ptr->len == 0)
		return (NULL);
	cpy = (t_matrix *)gc_calloc(dyn, 1, sizeof(t_matrix));
	if (cpy == NULL)
		return (NULL);
	cpy->ptr = (t_vec *)gc_calloc(dyn, mat->col, sizeof(t_vec));
	if (cpy->ptr == NULL)
		return (NULL);
	cpy->col = mat->col;
	cpy->cap = mat->col;
	i = 0;
	while (i < mat->col)
	{
		temp = veccpy(dyn, mat->ptr[i]);
		if (temp == NULL)
			return (NULL);
		cpy->ptr[i] = *temp;
		i++;
	}
	return (cpy);
}
