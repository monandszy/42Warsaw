/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paired.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:31 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:09:34 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static int	parse(t_data *data, int argc, char **argv)
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
		if (data->total_eat_count < 0)
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

static t_philo	*initialize(t_data *data)
{
	int		i;
	t_philo	*head;
	t_philo	*curr;
	t_philo	*prev;

	prev = NULL;
	curr = create_philo(1, data);
	head = curr;
	if (!curr)
		return (end(data, head), NULL);
	i = 2;
	while (i <= data->philo_count)
	{
		curr->next = create_philo(i, data);
		if (!curr->next)
			return (end(data, head), NULL);
		prev = curr;
		curr = curr->next;
		curr->prev = prev;
		i++;
	}
	curr->next = head;
	head->prev = curr;
	return (head);
}

// printf("start: %lld\n", start);
static void	start(t_data *data, t_philo *curr)
{
	int			i;
	long long	start;

	i = 0;
	start = getMiliTime();
	while (i < data->philo_count)
	{
		curr->last_eaten = start;
		resurrect(curr);
		usleep(10);
		curr = curr->next;
		i++;
	}
}

static void	monitor(t_data *data, t_philo *curr)
{
	int			i;
	int			flag;
	long long	expiration_time;

	while (1)
	{
		milisleep(1);
		i = 0;
		flag = 0;
		while (i < data->philo_count)
		{
			curr = curr->next;
			if (curr->eat_count != data->total_eat_count)
			{
				flag = 1;
				expiration_time = curr->last_eaten + data->time_to_die
					- getMiliTime();
				if (expiration_time < 0)
				{
					data->end = 1;
					print_end_state(curr, "has died");
					return ;
				}
			}
			i++;
		}
		if (!flag)
			return ;
	}
}

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

int	main(int argc, char **argv)
{
	static t_data	data;
	t_philo			*head;

	if (parse(&data, argc, argv))
		return (1);
	head = initialize(&data);
	if (!head)
		return (end(&data, head), 1);
	(void)start;
	(void)monitor;
	start(&data, head);
	monitor(&data, head);
	waitforend(&data, head);
	end(&data, head);
	return (0);
}
