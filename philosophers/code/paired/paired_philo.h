/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paired_philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:09:40 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/13 14:15:38 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIRED_PHILO_H
# define PAIRED_PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/*
- number_of_philosophers: The number of philosophers and also
	the number of forks.
- time_to_die (in milliseconds): If a philosopher has not started eating
	within time_to_die milliseconds since the start of their last meal or
	the start of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher
	to end eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument):
	If all philosophers have eaten at least
	number_of_times_each_philosopher_must_eat times,
	the simulation stops. If not specified,
	the simulation stops when a philosopher dies.
*/
// eat -> sleep -> eat ...
// eating queue or if free takeover - communicate with peers;

/*
pthread_create,
int	pthread_create(pthread_t *thread, const pthread_attr_t *attr,
  void *(*start_routine) (void *), void *arg);

pthread_detach,
int						pthread_detach(pthread_t thread);

pthread_join,
// get return value of the thread
int						pthread_join(pthread_t thread, void **retval);

pthread_mutex_init,
pthread_mutex_destroy,

int	pthread_mutex_init(pthread_mutex_t *mutex,
	const pthread_mutexattr_t *attr);
int	pthread_mutex_destroy(pthread_mutex_t *mutex)

pthread_mutex_lock,
pthread_mutex_unlock

int						pthread_mutex_lock(pthread_mutex_t *mutex);;
int						pthread_mutex_unlock(pthread_mutex_t *mutex);
*/

/*
int						gettimeofday(struct timeval *tv, struct timezone *tz);
*/

typedef struct s_fork
{
	pthread_mutex_t		*mutex;
}						t_fork;

typedef struct s_data
{
	int					philo_count;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					total_eat_count;
	volatile int		end;
	pthread_mutex_t		*mutex;
}						t_data;

typedef struct s_philo
{
	t_data				*data;
	int					id;
	int					pid;
	volatile long long	last_eaten;
	volatile int		eat_count;
	pthread_t			buffer;
	t_fork				fork;
	struct s_philo		*next;
	struct s_philo		*prev;
}						t_philo;

void					*handler(void *arg);

int						parse(t_data *data, int argc, char **argv);
t_philo					*initialize(t_data *data);
void					start(t_data *data, t_philo *curr);
void					monitor(t_data *data, t_philo *curr);
void					waitforend(t_data *data, t_philo *curr);
void					end(t_data *data, t_philo *philo);

void					print_state(t_philo *philo, char *state);
void					print_end_state(t_philo *philo, char *state);
long long				get_mili_time(void);
void					milisleep(long long mili);

#endif
