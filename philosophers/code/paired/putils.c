/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:52 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:58:19 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

void	waitforend(t_data *data, t_philo *curr)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(curr->buffer, NULL);
		curr = curr->next;
		i++;
	}
}

void	end(t_data *data, t_philo *philo)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	pthread_mutex_destroy(data->mutex);
	while (philo && i < data->philo_count)
	{
		tmp = philo;
		philo = philo->next;
		pthread_mutex_destroy(tmp->fork.mutex);
		free(tmp->fork.mutex);
		free(tmp);
		i++;
	}
}

// https://stackoverflow.com/questions/10192903/time-in-milliseconds-in-c
long long	get_mili_time(void)
{
	struct timeval	tv;
	long long		sec;
	long long		usec;

	gettimeofday(&tv, NULL);
	sec = ((long long)(tv.tv_sec)) * (1000);
	usec = (tv.tv_usec / 1000);
	return (sec + usec);
}

void	milisleep(long long mili)
{
	usleep(mili * 1000);
}
