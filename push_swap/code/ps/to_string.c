
#include "ps.h"

void print_move(t_move *move)
{
  printf("move:[shared: %d, b_i: %d, a_i: %d, cost: %d]\n", 
  move -> shared,
  move -> a_index,
  move -> b_index,
  move -> cost);
  fflush(stdout);
}

void print_stack(t_stack *stack)
{
  t_dlist *i;

  printf("%s", "stack:[");
  i = stack -> start;
  while (i)
  {
    printf("(%d)", *((int *)(i -> content)));
    i = i -> next;
  }
  printf("%s", "]\n");
  fflush(stdout);
}

void print_dlist(t_dlist **dl)
{
  t_dlist *i;

  printf("%s", "dlist:[");
  i = *dl;
  while (i)
  {
    printf("(%s)", ((char *)(i -> content)));
    i = i -> next;
  }
  printf("%s", "]\n");
  fflush(stdout);
}

void	print_lis_from_stack(t_stack *stack, int *lis_schema)
{
	t_dlist	*n_i = stack->start;
	size_t	i = 0;

	printf("LIS elements: ");
	while (n_i && i < stack->e_count)
	{
		if (lis_schema[i] == 1)
		{	
			int value = *(int *)(n_i->content);
			printf("%d ", value);
		}
		n_i = n_i->next;
		i++;
	}
	printf("\n");
}

void print_int_arr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// void print_int_arr(int *arr, int size) {
//   (void) arr;
//   (void) size;
// }

// void print_move(t_move *move)
// {
//   (void) move;
// }

// void print_stack(t_stack *stack)
// {
//   (void) stack;
// }
// void print_dlist(t_dlist **dl)
// {
//   (void) dl;
// }

