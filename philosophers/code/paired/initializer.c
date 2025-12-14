/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:46:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 13:46:14 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paired_philo.h"

static t_philo	*create_philo(int id, t_data *data)
{
	pthread_mutex_t	*mutex;
	t_philo			*new;
	t_fork			*fork;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->data = data;
	new->id = id;
	new->pid = 0;
	new->buffer = 0;
	new->eat_count = 0;
	fork = &new->fork;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (free(new), NULL);
	fork->mutex = mutex;
	pthread_mutex_init(fork->mutex, NULL);
	return (new);
}

t_philo	*initialize(t_data *data)
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

static void	resurrect(t_philo *philo)
{
	pthread_t	*buffer;
	int			pid;

	buffer = &philo->buffer;
	pid = pthread_create(buffer, NULL, &handler, philo);
	philo->pid = pid;
}

// printf("start: %lld\n", start);
void	start(t_data *data, t_philo *curr)
{
	int			i;
	long long	start;

	i = 0;
	start = get_mili_time();
	while (i < data->philo_count)
	{
		curr->last_eaten = start;
		resurrect(curr);
		milisleep(1);
		curr = curr->next;
		i++;
	}
}
