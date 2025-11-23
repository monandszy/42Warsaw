/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:17:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/17 17:30:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_atof(char *str)
{
	int		i;
	double	sign;
	double	result;
	double	power;

	i = 0;
	sign = 1.0;
	result = 0.0;
	power = 1.0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i++] - '0');
		power *= 10.0;
	}
	return (sign * result / power);
}

int	ft_is_double(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	print_usage(void)
{
	ft_printf("---ARGS---\n");
	ft_printf("[0] for Mandelbrot, [double] [double] for Julia\n");
}

static int	handle_julia(char *s1, char *s2)
{
	t_pixel	*origin;

	origin = (t_pixel *)malloc(sizeof(t_pixel));
	if (!origin)
		return (write(2, "Error\n", 6), 1);
	origin->tx = ft_atof(s1);
	origin->ty = ft_atof(s2);
	if (open_julia(origin))
		return (free(origin), write(2, "Error\n", 6), 1);
	return (free(origin), 0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		print_usage();
	else if (argc == 2 && argv[1][0] == '0' && argv[1][1] == '\0')
	{
		if (open_mandelbrot())
			return (write(2, "Error\n", 6), 1);
	}
	else if (argc == 3 && ft_is_double(argv[1]) && ft_is_double(argv[2]))
		return (handle_julia(argv[1], argv[2]));
	else
		return (write(2, "Input Error\n", 12), 1);
	return (0);
}
