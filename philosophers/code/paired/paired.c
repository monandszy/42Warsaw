/* 
- number_of_philosophers: The number of philosophers and also the number of forks.
- time_to_die (in milliseconds): If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the simulation, they die.
- time_to_eat (in milliseconds): The time it takes for a philosopher to end eat.
During that time, they will need to hold two forks.
- time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
- number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
*/
// eat -> sleep -> eat ...
// eating queue or if free takeover - communicate with peers;

/*
pthread_create,
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
  void *(*start_routine) (void *), void *arg);

pthread_detach, 
int pthread_detach(pthread_t thread);

pthread_join, 
// get return value of the thread
int pthread_join(pthread_t thread, void **retval);

pthread_mutex_init,
pthread_mutex_destroy, 

int pthread_mutex_init(pthread_mutex_t *mutex, 
    const pthread_mutexattr_t *attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex)

pthread_mutex_lock,
pthread_mutex_unlock

int pthread_mutex_lock(pthread_mutex_t *mutex);;
int pthread_mutex_unlock(pthread_mutex_t *mutex);
*/

/*
int gettimeofday(struct timeval *tv, struct timezone *tz);
*/

#include "paired_philo.h"

int main(void)
{
  static t_data data;
  int i;
  t_philo *head;
  t_philo *curr;
  t_philo *prev;

  init(&data);

  prev = NULL;
  curr = create_philo(0, &data);
  head = curr;
  if (!curr)
    return (end(&data, head), 1);
  i = 1;
  while (i < data.philo_count)
  {
    curr->next = create_philo(i, &data);
    if (!curr->next)
      return (end(&data, head), 1);
    prev = curr;
    curr = curr->next;
    curr->prev = prev;
    i++;
  }
  curr->next=head;
  head->prev=curr;
  curr=head;

  i = 0;
  while (i < data.philo_count)
  {
    check_state(curr);
    resurrect(curr);
    curr=curr->next;
    i++;
  }

  while(1)
  {
    check_state(curr);
    usleep(100000);
    curr=curr->next;
  }
}