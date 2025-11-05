#include "ps.h"

void	f_st(t_stack *st)
{
  if (st)
  {
    if (st->start)
		  f_dl(st->start);
    free(st);
  }
}

void	f_dl(t_dlist *dl)
{
	t_dlist	*tmp;

	while (dl)
	{
		tmp = dl;
    if (tmp -> content)
      free(tmp -> content);
		dl = tmp->next;
		free(tmp);
	}
}

void	f_sp(char **sp)
{
	int	i;

	i = 0;
	if (sp)
	{
		while (sp[i])
		{
			free(sp[i]);
			i++;
		}
		free(sp);
	}
}
