
#include "ps.h"

int find_solution_recursive(t_dlist **steps, t_stack *a, t_stack *b, size_t total_cost)
{
  size_t i = 0;
	t_dlist	*all_moves;
	t_dlist	*rr_moves;
	t_dlist	*rrr_moves;
	t_dlist *current_move_node;

  // printf("c[%ld]\n", total_cost);
  // fflush(stdout);
  if (b -> e_count == 0)
    return (adjust_order_move(steps, a, total_cost));
	rr_moves = calculate_all_rr_moves(b, a);
	rrr_moves = calculate_all_rrr_moves(b, a);
	all_moves = rr_moves;
	merge_move_lists(&all_moves, rrr_moves);
  // all_moves = rr_moves;
	sort_moves_list(&all_moves);

	current_move_node = all_moves;
	while (current_move_node && i < (a->e_count + b->e_count) / ((a->e_count + b->e_count) / 2))
	{
    // print_move(current_move_node -> content);
		t_move *current_move = (t_move *)current_move_node->content;
		execute_move(steps, a, b, current_move);
		if (find_solution_recursive(steps, a, b, total_cost + current_move->cost + 1) == 0)
		{
			f_dl(all_moves);
			return (0);
		}
    i++;
		reverse_move(steps, a, b, current_move);
		current_move_node = current_move_node->next;
	}
	f_dl(all_moves); 
	return (1);
}

int adjust_order_move(t_dlist **steps, t_stack *a, size_t total_cost)
{
  size_t cs;
  size_t ce;
  size_t res;
  t_dlist *i;

  i = a -> start;
  cs = 0;
  ce = 0;
  while (i && i -> next && *((int*) (i -> content)) < *((int*) (i -> next -> content)))
  {
    cs++;
    i = i -> next;
  }
  i = a -> end;
  while (i && i -> prev && *((int*) (i -> content)) > *((int*) (i -> prev -> content)))
  {
    ce++;
    i = i -> prev;
  }
  res = ft_lower(ce, cs);
  // printf("c[%ld, %ld, %ld, %ld]\n", total_cost, res, cs, ce);
  // print_stack(a);
  // if (((total_cost + res) < (a->e_count * (7 + (a->e_count)/100 - 1 ))))
  if (((total_cost + res) < (6400)))
  {
    if (cs > ce)
      while (*((int*) (a -> start -> content)) > *((int*) (a -> end -> content)))
        *steps = rra(*steps, a);
    else
      while (*((int*) (a -> start -> content)) > *((int*) (a -> end -> content)))
        *steps = ra(*steps, a);
    return (0);
  }
  else
    return (1);
}

int reverse_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
  int tmp;

  push(b, a);
  *steps = pop(*steps);
  tmp = move -> shared;
  while (tmp < 0)
  {
    rotate(a);
    rotate(b);
    *steps = pop(*steps);
    tmp++;
  }
  tmp = move -> from_index;
  while (tmp < 0)
  {
    rotate(b);
    *steps = pop(*steps);
    tmp++;
  }
  tmp = move -> to_index;
  while (tmp < 0)
  {
    rotate(a);
    *steps = pop(*steps);
    tmp++;
  }

  tmp = move -> shared;
  while (tmp > 0)
  {
    rrotate(a);
    rrotate(b);
    *steps = pop(*steps);
    tmp--;
  }
  tmp = move -> from_index;
  while (tmp > 0)
  {
    rrotate(b);
    *steps = pop(*steps);
    tmp--;
  }
  tmp = move -> to_index;
  while (tmp > 0)
  {
    rrotate(a);
    *steps = pop(*steps);
    tmp--;
  }
  return (0);
}

int execute_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
  int tmp;
  
  tmp = move -> shared;
  while (tmp < 0)
  {
    *steps = rrr(*steps, a, b);
    tmp++;
  }
  tmp = move -> from_index;
  while (tmp < 0)
  {
    *steps = rrb(*steps, b);
    tmp++;
  }
  tmp = move -> to_index;
  while (tmp < 0)
  {
    *steps = rra(*steps, a);
    tmp++;
  }

  tmp = move -> shared;
  while (tmp > 0)
  {
    *steps = rr(*steps, a, b);
    tmp--;
  }
  tmp = move -> from_index;
  while (tmp > 0)
  {
    *steps = rb(*steps, b);
    tmp--;
  }
  tmp = move -> to_index;
  while (tmp > 0)
  {
    *steps = ra(*steps, a);
    tmp--;
  }
  *steps = pa(*steps, a, b);
  return (0);
}

// move from b to a
int execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
  int cost;
  t_move *rr_move;
  t_move *rrr_move;

  rr_move = calculate_optimal_rr_cost(b, a);
  rrr_move = calculate_optimal_rrr_cost(b, a);

  if (!rr_move || !rrr_move)
    return (free(rr_move), free(rrr_move), 1);
  if (rrr_move -> cost > rr_move->cost)
  {
    if (execute_move(steps, a, b, rr_move))
      return (free(rr_move), free(rrr_move), -1);
    cost = rr_move -> cost; 
  }
  else
  {
    if (execute_move(steps, a, b, rrr_move))
      return (free(rr_move), free(rrr_move), -1);
    cost = rrr_move -> cost; 
  }
  return (free(rr_move), free(rrr_move), cost); 
}