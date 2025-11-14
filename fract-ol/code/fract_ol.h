/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:16:10 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/14 18:25:21 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "./minilibx/mlx.h"
# include <X11/X.h>

typedef struct s_data
{
	void *id;
	void *win_id;
	int x;
	int y;
} t_data;

void pre_render(t_data *d);

#endif
