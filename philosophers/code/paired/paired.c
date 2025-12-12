
#include "paired_philo.h"

void parse(t_data *data)
{
  data->philo_count = 3;
  data->time_to_eat = 100000;
  data->time_to_sleep = 300000;
  data->time_to_die = 10000;
  data->total_eat_count = -1;
}

t_philo *initialize(t_data *data)
{
  int i;
  t_philo *head;
  t_philo *curr;
  t_philo *prev;

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
  return(head);
}

void start(t_data *data, t_philo *curr)
{
  int i;
  long long start;

  i = 0;
  start = getMiliTime();
  while (i < data->philo_count)
  {
    curr->last_eaten = start;
    resurrect(curr);
    usleep(1);
    curr=curr->next;
    i++;
  }
}

void monitor(t_data *data, t_philo *curr)
{
  (void) data;
  while(1)
  {
    usleep(100000);
    curr=curr->next;
  }
}

int main(void)
{
  static t_data data;
  t_philo *head;

  parse(&data);
  head = initialize(&data);
  // if (!head)
  //   ;
  start(&data, head);
  monitor(&data, head);
  end(&data, head);
}