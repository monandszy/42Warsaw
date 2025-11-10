
#include "ps.h"

int find_pos_of_smallest(t_stack *stack)
{
  t_dlist *current;
  int  min_index = 2147483647;
  int  min_pos = 0;
  int  current_pos = 0;

  current = stack->start;
  while(current)
  {
    int current_index = *(int *) (current->content);
    if (current_index < min_index)
    {
      min_index = current_index;
      min_pos = current_pos;
    }
    current = current->next;
    current_pos++;
  }
  return (min_pos);
}


int find_insert_pos_in_a(t_stack *a, int b_sorted_index)
{
  t_dlist *current_a;
  int  current_pos;
  int  best_match_pos;
  int  best_match_index;

  current_a = a->start;
  current_pos = 0;
  best_match_pos = -1;
  best_match_index = 2147483647;

  while (current_a)
  {
    int a_sorted_index = *(int *) (current_a->content);
    if (a_sorted_index > b_sorted_index && a_sorted_index < best_match_index)
    {
      best_match_index = a_sorted_index;
      best_match_pos = current_pos;
    }
    current_a = current_a->next;
    current_pos++;
  }
  if (best_match_pos == -1)
  {
    best_match_pos = find_pos_of_smallest(a);
  }
  return (best_match_pos);
}

void  push_back(t_dlist **steps, t_stack *a, t_stack *b)
{
  while ((int) b->e_count > 0)
  {
    int   best_cost = -1;
    int   final_moves_a = 0;
    int   final_moves_b = 0;

    t_dlist *current_b = b->start;
    int  current_pos_b = 0;
    while (current_b)
    {
      int cost_b = (current_pos_b <= (int) b->e_count / 2) ? current_pos_b : ((int) b->e_count - current_pos_b) * -1;

      int target_pos_a = find_insert_pos_in_a(a, *(int *)current_b->content);

      int cost_a = (target_pos_a <= (int) a->e_count / 2) ? target_pos_a : ((int) a->e_count - target_pos_a) * -1;

      int total_cost;
      if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
      {
        total_cost = (ft_abs(cost_a) > ft_abs(cost_b)) ? ft_abs(cost_a) : ft_abs(cost_b);
      }
      else
      {
        total_cost = ft_abs(cost_a) + ft_abs(cost_b);
      }

      if (best_cost == -1 || total_cost < best_cost)
      {
        best_cost = total_cost;
        final_moves_a = cost_a;
        final_moves_b = cost_b;
      }
      current_b = current_b->next;
      current_pos_b++;
    }

    while (final_moves_a > 0 && final_moves_b > 0) { *steps = rr(*steps, a, b); final_moves_a--; final_moves_b--; }
    while (final_moves_a < 0 && final_moves_b < 0) { *steps = rrr(*steps, a, b); final_moves_a++; final_moves_b++; }
    while (final_moves_a > 0) { *steps = ra(*steps, a); final_moves_a--; }
    while (final_moves_a < 0) { *steps = rra(*steps, a); final_moves_a++; }
    while (final_moves_b > 0) { *steps = rb(*steps, b); final_moves_b--; }
    while (final_moves_b < 0) { *steps = rrb(*steps, b); final_moves_b++; }

    *steps = pa(*steps, a, b);
  }
}

int    push_chunks(t_dlist **steps, t_stack *a, t_stack *b)
{
  int num_chunks;
  int chunk_size;
  int i;
  int chunk_start_index;
  int chunk_end_index;
  int elements_pushed_in_chunk;

  num_chunks = 3;

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