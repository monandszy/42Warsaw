
#include "ps.h"


int get_target(t_stack *a, int start, int end)
{
  t_dlist	*current_a;
	int		best_move_cost;
	int		target_pos;
  int		current_pos;
  int		s_idx;
  int		cost;

  current_a = a->start;
  best_move_cost = -1;
  target_pos = -1;
  current_pos = 0;
  while (current_a)
  {
    s_idx = *(int *)current_a->content;
    if (s_idx >= start && s_idx < end)
    {
      if (current_pos <= a->e_count / 2)
        cost = current_pos;
      else
        cost = a->e_count - current_pos;
      if (target_pos == -1 || cost < best_move_cost)
      {
        best_move_cost = cost;
        target_pos = current_pos;
      }
    }
    current_a = current_a->next;
    current_pos++;
  }
  return (target_pos);
}

int	push_chunks(t_dlist **steps, t_stack *a, t_stack *b)
{
	int		num_chunks;
	int		chunk_size;
	int		i;
  int target_pos;
	int		e_pushed;

	num_chunks = 1 + a->e_count / 200;
	chunk_size = a->e_count / num_chunks;
	i = 0;

	while (i < num_chunks)
	{
		e_pushed = 0;

		while (e_pushed < (chunk_size) && a->e_count > 0)
		{
      target_pos = get_target(a, i * chunk_size, (i + 1) * chunk_size);
      // adjust_order(a, target_pos);
			if (target_pos != -1)
			{
				if (target_pos <= a->e_count / 2)
				{
					while (target_pos-- > 0)
					{
						*steps = ra(*steps, a);
					}
				}
				else
				{
					while (target_pos++ < a->e_count)
					{
						*steps = rra(*steps, a);
					}
				}
				*steps = pb(*steps, a, b);
				e_pushed++;
				if (b->e_count > 1 && *(int *)b->start->content < (i * chunk_size + (chunk_size / 2)))
				{
					*steps = rb(*steps, b);
				}
			}
		}
		i++;
	}
	return (0);
}
