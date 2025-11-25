/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:43:17 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/25 12:23:10 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	calculate_mandelbrot_depth(t_data *d, t_pixel *pixel, int n)
{
	double				tmp;
	double				zrsq;
	double				zisq;
	static t_complex	z;
	static t_complex	c;

	c.r = pixel->tx;
	c.i = pixel->ty;
	z.r = 0;
	z.i = 0;
	while (n < d->max_depth)
	{
		zrsq = z.r * z.r;
		zisq = z.i * z.i;
		tmp = zrsq + (zisq * -1) + c.r;
		z.i = (2 * (z.r) * (z.i)) + c.i;
		z.r = tmp;
		if (zrsq + zisq > d->etsq)
			return (n);
		n++;
	}
	return (n);
}

int	calculate_julia_depth(t_data *d, t_pixel *pixel, int n)
{
	double				tmp;
	double				zrsq;
	double				zisq;
	static t_complex	z;
	static t_complex	c;

	c.r = d->julia_origin.tx;
	c.i = d->julia_origin.ty;
	z.r = pixel->tx;
	z.i = pixel->ty;
	while (n < d->max_depth)
	{
		zrsq = z.r * z.r;
		zisq = z.i * z.i;
		tmp = zrsq + (zisq * -1) + c.r;
		z.i = (2 * (z.r) * (z.i)) + c.i;
		z.r = tmp;
		if (zrsq + zisq > d->etsq)
			return (n);
		n++;
	}
	return (n);
}

int	calculate_ship_depth(t_data *d, t_pixel *pixel, int n)
{
	double				tmp;
	double				zrsq;
	double				zisq;
	static t_complex	z;
	static t_complex	c;

	c.r = pixel->tx;
	c.i = -pixel->ty;
	z.r = 0;
	z.i = 0;
	while (n < d->max_depth)
	{
		zrsq = z.r * z.r;
		zisq = z.i * z.i;
		tmp = zrsq - zisq + c.r;
		z.i = (2 * fabs(z.r * z.i)) + c.i;
		z.r = tmp;
		if (zrsq + zisq > d->etsq)
			return (n);
		n++;
	}
	return (n);
}

int	calculate_burning_depth(t_data *d, t_pixel *pixel, int n)
{
	double				tmp;
	double				zrsq;
	double				zisq;
	static t_complex	z;
	static t_complex	c;

	c.r = d->julia_origin.tx;
	c.i = -d->julia_origin.ty;
	z.r = pixel->tx;
	z.i = pixel->ty;
	while (n < d->max_depth)
	{
		zrsq = z.r * z.r;
		zisq = z.i * z.i;
		tmp = zrsq + (zisq * -1) + c.r;
		z.i = (2 * fabs(z.r * z.i)) + c.i;
		z.r = tmp;
		if (zrsq + zisq > d->etsq)
			return (n);
		n++;
	}
	return (n);
}
