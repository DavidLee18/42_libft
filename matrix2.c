/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:28:19 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 01:44:19 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dot_prod(t_vec row, t_matrix *mat, size_t col)
{
	int		res;
	size_t	k;

	res = 0;
	k = 0;
	while (k < mat->col)
	{
		res += row.ptr[k] * mat->ptr[k].ptr[col];
		k++;
	}
	return (res);
}

t_matrix	*rotate(t_list **dyn, double angx, double angy, t_matrix *mat)
{
	t_matrix	*yrot;
	t_matrix	*xrot;
	t_matrix	*res;

	if (mat->col != 3)
		return (NULL);
	yrot = get_yrot(dyn, angy);
	xrot = get_xrot(dyn, angx);
	if (yrot == NULL || xrot == NULL)
		return (NULL);
	res = matmul(dyn, xrot, mat);
	if (res == NULL)
		return (NULL);
	return (matmul(dyn, yrot, res));
}

t_matrix	*get_yrot(t_list **dyn, double angle)
{
	t_matrix	*rot;

	rot = _3d_point_col(dyn, SCALE * cos(angle), 0, -SCALE * sin(angle));
	if (rot == NULL)
		return (NULL);
	if (_3d_point_col(dyn, 0, SCALE, 0) == NULL
		|| mat2vec(dyn, _3d_point_col(dyn, 0, SCALE, 0)) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, SCALE, 0)), rot);
	if (_3d_point_col(dyn, SCALE * sin(angle), 0, SCALE * cos(angle))
		== NULL || mat2vec(dyn, _3d_point_col(dyn, SCALE * sin(angle), 0,
				SCALE * cos(angle))) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, SCALE * sin(angle), 0,
				SCALE * cos(angle))), rot);
	return (rot);
}

t_matrix	*get_xrot(t_list **dyn, double angle)
{
	t_matrix	*rot;

	rot = _3d_point_col(dyn, SCALE, 0, 0);
	if (rot == NULL)
		return (NULL);
	if (_3d_point_col(dyn, 0, SCALE * cos(angle), SCALE * sin(angle))
		== NULL || mat2vec(dyn, _3d_point_col(dyn, 0, SCALE * cos(angle),
				SCALE * sin(angle))) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, SCALE * cos(angle),
				SCALE * sin(angle))), rot);
	if (_3d_point_col(dyn, 0, -SCALE * sin(angle), SCALE * cos(angle))
		== NULL || mat2vec(dyn, _3d_point_col(dyn, 0, -SCALE * sin(angle),
				SCALE * cos(angle))) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, -SCALE * sin(angle),
				SCALE * cos(angle))), rot);
	return (rot);
}

t_matrix	*ortho_proj(t_list **dyn, t_matrix *mat)
{
	t_matrix	*proj;

	proj = _3d_point_col(dyn, 1, 0, 0);
	if (proj == NULL)
		return (NULL);
	if (_3d_point_col(dyn, 0, 1, 0) == NULL
		|| mat2vec(dyn, _3d_point_col(dyn, 0, 1, 0)) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, 1, 0)), proj);
	if (_3d_point_col(dyn, 0, 0, 0) == NULL
		|| mat2vec(dyn, _3d_point_col(dyn, 0, 0, 0)) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, 0, 0)), proj);
	return (matmul(dyn, proj, mat));
}
