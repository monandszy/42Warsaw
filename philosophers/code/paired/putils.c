#include "paired_philo.h"

void fork_takeover(t_philo *philo)
{
  pthread_mutex_t *mutex;
  t_fork *fork;

  mutex = philo->data->mutex;
  pthread_mutex_lock(mutex);
  fork = &philo->next->fork;
  while (1)
  {
    if (!fork->is_taken)
    {
      fork->is_taken = 1;
      break;
    }
  }
  pthread_mutex_unlock(mutex);
}

void fork_return(t_philo *philo)
{
  // pthread_mutex_t *mutex;
  t_fork *fork;

  // mutex = philo->data->mutex;
  // pthread_mutex_lock(mutex);
  fork = &philo->fork;
  while (1)
  {
    if (fork->is_taken)
    {
      fork->is_taken = 0;
      break;
    }
  }
  // pthread_mutex_unlock(mutex);
}

void *handler(void *arg)
{
  t_philo *philo;

  philo = (t_philo *) arg;
  while(1)
  {
    fork_takeover(philo);
    usleep(1000000);
    fork_return(philo);
    printf("threadium runnnin[%d]\n", philo->id);
    check_state(philo);
  }
  return (0);
}

t_philo *create_philo(int id, t_data *data)
{
  t_philo *new;

  new = (t_philo *) malloc(sizeof(t_philo));
  if (!new)
    return (NULL);
  new->data=data;
  new->id=id;
  new->pid=0;
  new->buffer=0;
  new->fork.is_taken=0;
  return (new);
}

void init(t_data *data)
{
  static pthread_mutex_t mutex;

  pthread_mutex_init(&mutex, NULL);
  data->philo_count = 3;
  data->mutex=&mutex;
}

void end(t_data *data, t_philo *philo)
{
  pthread_mutex_t *mutex;

  mutex = data->mutex;
  pthread_mutex_destroy(mutex);
  free(data); // TODO - free philo
  free(philo);
}

void resurrect(t_philo *philo)
{
  pthread_t *buffer;
  int pid;

  buffer = &philo->buffer;
  pid = pthread_create(buffer, NULL, &handler, philo);
  philo->pid = pid;
  pthread_detach(*buffer);
}

void check_state(t_philo *philo)
{
  printf("[%d, %d, %ld, %d]\n", philo->id, philo->pid, philo->buffer, philo->fork.is_taken);
}