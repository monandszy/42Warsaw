#include "paired_philo.h"

t_philo *create_philo(int id, t_data *data)
{
  pthread_mutex_t *mutex;
  t_philo *new;
  t_fork *fork;

  new = (t_philo *) malloc(sizeof(t_philo));
  if (!new)
    return (NULL);
  new->data=data;
  new->id=id;
  new->pid=0;
  new->buffer=0;
  new->eat_count=0;
  fork = &new->fork;
  mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
  if (!mutex)
    return (free(new), NULL);
  fork->mutex = mutex;
  pthread_mutex_init(fork->mutex, NULL);
  return (new);
}

void end(t_data *data, t_philo *philo)
{
  int i;
  t_philo *tmp;

  i = 0;
  pthread_mutex_destroy(data->mutex);
  while (philo && i < data->philo_count)
  {
    tmp = philo;
    philo=philo->next;
    pthread_mutex_destroy(tmp->fork.mutex);
    free(tmp->fork.mutex);
    free(tmp);
    i++;
  }
}

void resurrect(t_philo *philo)
{
  pthread_t *buffer;
  int pid;

  buffer = &philo->buffer;
  pid = pthread_create(buffer, NULL, &handler, philo);
  philo->pid = pid;
}

void print_state(t_philo *philo, char *state)
{
  if(!philo->data->end)
  {
    pthread_mutex_lock(philo->data->mutex);
    printf("%lld %d %s\n", getMiliTime(), philo->id, state);
    pthread_mutex_unlock(philo->data->mutex);
  }
}

void print_end_state(t_philo *philo, char *state)
{
  printf("%lld %d %s\n", getMiliTime(), philo->id, state);
}

long long getMiliTime(void)
{
  struct timeval tv;

  gettimeofday(&tv, NULL);
  return((long long)(tv.tv_sec) * 1000 + (tv.tv_usec / 1000));
}

void milisleep(long long mili)
{
  usleep(mili * 1000);
}