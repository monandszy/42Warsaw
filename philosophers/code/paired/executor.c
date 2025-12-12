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
  milisleep(philo->data->time_to_eat);
  philo->eat_count++;
  pthread_mutex_unlock(mutex1);
  pthread_mutex_unlock(mutex2);
}

void *handler(void *arg)
{
  t_philo *philo;
  long long expiration_time;

  philo = (t_philo *) arg;
  while (1)
  {
    eat(philo);
    expiration_time = philo->last_eaten + philo->data->time_to_die - getMiliTime();
    if (expiration_time < 0)
      return(0);
    if(philo->eat_count == philo->data->total_eat_count)
      return(0);
    philo->last_eaten=getMiliTime();
    print_state(philo, "is sleeping");
    milisleep(philo->data->time_to_sleep);
    fflush(stdout);
    print_state(philo, "is thinking");
  }
  return (0);
}