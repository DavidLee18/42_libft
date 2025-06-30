/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 01:46:17 by jaehylee          #+#    #+#             */
/*   Updated: 2025/07/01 01:46:49 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*get_zrot(t_list **dyn, double angle)
{
	t_matrix	*rot;

	rot = _3d_point_col(dyn, SCALE * cos(angle), SCALE * sin(angle), 0);
	if (rot == NULL)
		return (NULL);
	if (_3d_point_col(dyn, -SCALE * sin(angle), SCALE * cos(angle), 0) == NULL
		|| mat2vec(dyn, _3d_point_col(dyn, -SCALE * sin(angle),
				SCALE * cos(angle), 0)) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, -SCALE * sin(angle),
				SCALE * cos(angle), 0)), rot);
	if (_3d_point_col(dyn, 0, 0, SCALE)
		== NULL || mat2vec(dyn, _3d_point_col(dyn, 0, 0, SCALE)) == NULL)
		return (NULL);
	add_col(dyn, *mat2vec(dyn, _3d_point_col(dyn, 0, 0, SCALE)), rot);
	return (rot);
}

t_matrix	*rotate2(t_list **dyn, double angz, t_matrix *mat)
{
	t_matrix	*zrot;

	zrot = get_zrot(dyn, angz);
	if (zrot == NULL)
		return (NULL);
	return (matmul(dyn, zrot, mat));
}
