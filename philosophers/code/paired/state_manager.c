/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:46:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:46:02 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static int	has_expired(t_data *data, t_philo *curr)
{
	long long	expiration_time;

	expiration_time = curr->last_eaten + data->time_to_die - get_mili_time();
	if (expiration_time < 0)
	{
		data->end = 1;
		print_end_state(curr, "has died");
		return (1);
	}
	return (0);
}

void	monitor(t_data *data, t_philo *curr)
{
	int	i;
	int	flag;

	while (1)
	{
		milisleep(1);
		i = 0;
		flag = 0;
		while (i < data->philo_count)
		{
			if (curr->eat_count != data->total_eat_count)
			{
				flag = 1;
				if (has_expired(data, curr))
					return ;
			}
			curr = curr->next;
			i++;
		}
		if (!flag)
			return ;
	}
}

void	print_state(t_philo *philo, char *state)
{
	if (!philo->data->end)
	{
		pthread_mutex_lock(philo->data->mutex);
		printf("%lld %d %s\n", get_mili_time(), philo->id, state);
		pthread_mutex_unlock(philo->data->mutex);
	}
}

void	print_end_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(philo->data->mutex);
	printf("%lld %d %s\n", get_mili_time(), philo->id, state);
	pthread_mutex_unlock(philo->data->mutex);
}
