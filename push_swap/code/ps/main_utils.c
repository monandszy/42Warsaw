#include "ps.h"

int initialize_stack(char **args, t_stack *a, t_stack *b)
{
  a = (t_stack *) malloc(sizeof(t_stack));
  b = (t_stack *) malloc(sizeof(t_stack));
  if (!a || !b || initialize_dlist(args, a))
    return (1);
  a -> size = (sizeof(*args) / sizeof(**args));
  b -> size = 0;
  return (0);
}

int initialize_dlist(char **args, t_stack *a)
{
  t_dlist *prev;
  t_dlist *new;
  int i;

  prev = (t_dlist *) malloc (sizeof(t_dlist));
  if (!prev)
    return (1);
  prev -> content = ft_atoi(args[0]);
  a -> start = prev;
  i = 1;
  while (args[i])
  {
    new = (t_dlist *) malloc (sizeof(t_dlist));
    if (!new)
      return (1);
    new -> content = ft_atoi(args[i]);
    new -> prev = prev;
    prev -> next = new;
    prev = new;
    i++;
  }
  a -> end = prev;
  return (0);
}

void free_stack(t_stack *s)
{
  if (s -> start)
    free_dlist(s -> start);
  if (s)
    free(s);
}

void free_dlist(t_dlist *dl)
{
	t_dlist	*tmp;

  while (dl)
  {
    tmp = dl;
    dl = tmp->next;
    free(tmp);
  }
}

void free_list(t_list *l)
{
	t_list	*tmp;

  while (l)
  {
    tmp = l;
    l = tmp->next;
    free(tmp);
  }
}

void free_split(char **s)
{
  int i;

  i = 0;
  if (s)
  {
    while (s[i])
  	{
      free(s[i]);
    	i++;
    }
  free(s);
  }
}
