
#include "ps.h"

t_move *calculate_cost(int b_index, int a_index)
{
  t_move *new;

  new = (t_move *) malloc(sizeof(t_move));
  if (!new)
    return (NULL);
  if (b_index >= a_index)
  {
    new -> shared = a_index;
    new -> a_index = 0;
    new -> b_index = b_index - a_index;
    new -> cost = new -> shared + new -> b_index;
  }
  else
  {
    new -> shared = b_index;
    new -> b_index = 0;
    new -> a_index = a_index - b_index;
    new -> cost = new -> shared + new -> a_index;
  }
  return (new);
}

int ft_abs(int i)
{
  if (i < 0)
    i = -i;
  return (i);
}

int ft_greater(int i1, int i2)
{
  if (i1 < i2)
    return (i2);
  return (i1);
}
