#ifndef PAIRED_PHILO_H
# define PAIRED_PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_fork
{
  int is_taken;
} t_fork;

typedef struct s_data
{
  int philo_count;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int total_eat_count;
  pthread_mutex_t *mutex;
} t_data;

typedef struct s_philo
{
  t_data *data;
  int id;
  int pid;
  int last_eaten;
  int eat_count;
  pthread_t buffer;
  t_fork fork;
  struct s_philo *next;
  struct s_philo *prev;
} t_philo;

void *handler(void *arg);
t_philo *create_philo(int id, t_data *data);
void init(t_data *data);
void end(t_data *data, t_philo *philo);
void resurrect(t_philo *philo);
void check_state(t_philo *philo);

#endif