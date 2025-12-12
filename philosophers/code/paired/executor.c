#include "paired_philo.h"

void eat(t_philo *philo)
{
  pthread_mutex_t *mutex1;
  pthread_mutex_t *mutex2;
  t_fork *mine;
  t_fork *borrowed;

  mine = &philo->fork;
  borrowed = &philo->next->fork;
  mutex1 = mine->mutex;
  mutex2 = borrowed->mutex;
  pthread_mutex_lock(mutex1);
  print_state(philo, "has taken a fork");
  pthread_mutex_lock(mutex2);
  print_state(philo, "has taken a fork");
  print_state(philo, "is eating");
  usleep(philo->data->time_to_eat);
  pthread_mutex_unlock(mutex1);
  pthread_mutex_unlock(mutex2);
}

void *handler(void *arg)
{
  t_philo *philo;

  philo = (t_philo *) arg;
  while(1)
  {
    eat(philo);
    print_state(philo, "is sleeping");
    usleep(philo->data->time_to_sleep);
    print_state(philo, "is thinking");
  }
  return (0);
}