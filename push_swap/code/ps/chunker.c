
#include "ps.h"

int    push_chunks(t_dlist **steps, t_stack *a, t_stack *b)
{
  int num_chunks;
  int chunk_size;
  int i;
  int chunk_start_index;
  int chunk_end_index;
  int elements_pushed_in_chunk;

  num_chunks = 1 + a -> e_count / 200; 

  chunk_size = (int) a->e_count / num_chunks;
  i = 0;
  while (i < num_chunks)
  {
    chunk_start_index = i * chunk_size;
    chunk_end_index = (i + 1) * chunk_size;

    if (i == num_chunks - 1)
      chunk_end_index = (int) a->e_count;

    elements_pushed_in_chunk = 0;
    while (elements_pushed_in_chunk < (chunk_end_index - chunk_start_index) && (int) a->e_count > 0)
    {
      t_dlist *current_a = a->start;
      int   best_move_cost = -1;
      int   target_pos = -1;
      int   current_pos = 0;

      while (current_a)
      {
        int s_idx = *(int *) current_a->content;

        if (s_idx >= chunk_start_index && s_idx < chunk_end_index)
        {
          int cost;

          if (current_pos <= (int) (int) a->e_count / 2)
            cost = current_pos;
          else
            cost = (int) a->e_count - current_pos;

          if (target_pos == -1 || cost < best_move_cost)
          {
            best_move_cost = cost;
            target_pos = current_pos;
          }
        }
        current_a = current_a->next;
        current_pos++;
      }

      if (target_pos != -1)
      {
        if (target_pos <= (int) (int) a->e_count / 2)
        {
          while (target_pos-- > 0)
          {
            *steps = ra(*steps, a);
          }
        }
        else
        {
          while (target_pos++ < (int)(int) a->e_count)
          {
            *steps = rra(*steps, a);
          }
        }

        *steps = pb(*steps, a, b);
        elements_pushed_in_chunk++;

        if ((int) b->e_count > 1 && *(int *) b->start->content < (chunk_start_index + (chunk_size / 2)))
        {
          *steps = rb(*steps, b);
        }
      }
    }
    i++;
  }

  while ((int) a->e_count > 0)
  {
    *steps = pb(*steps, a, b);
  }

  return (0);
}
