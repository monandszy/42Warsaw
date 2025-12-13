/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:09:49 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static long long	ft_altoi(char *i)
{
	long long	value;
	long long	c;

	value = 0;
	c = 0;
	while (i[c])
	{
		if (!ft_isdigit(i[c]))
			return (-1);
		value *= 10;
		value += (i[c] - '0');
		c++;
	}
	return (value);
}

int	parse(t_data *data, int argc, char **argv)
{
	static pthread_mutex_t	mutex;

	if (!(argc == 5 || argc == 6))
		return (1);
	data->philo_count = ft_altoi(argv[1]);
	data->time_to_die = ft_altoi(argv[2]);
	data->time_to_eat = ft_altoi(argv[3]);
	data->time_to_sleep = ft_altoi(argv[4]);
	if (argc == 6)
	{
		data->total_eat_count = ft_altoi(argv[5]);
		if (data->total_eat_count < 1)
			return (1);
	}
	else
		data->total_eat_count = -1;
	if (data->philo_count < 1 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->time_to_die < 0)
		return (1);
	data->end = 0;
	pthread_mutex_init(&mutex, NULL);
	data->mutex = &mutex;
	return (0);
}
