
#include "ps.h"

int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = stack->e_count - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	radix(t_dlist **steps, t_stack *a, t_stack *b)
{
	int i = 0;
	int j;
	int max_bits;
	int stack_size;
	t_dlist *start;

	if (a->e_count <= 1)
		return (0);
	*steps = ft_dlstnew(ft_strdup("INIT"));
	start = *steps;

	stack_size = a->e_count;
	max_bits = get_max_bits(a);

	for (i = 0; i < max_bits; i++)
	{
		for (j = 0; j < stack_size; j++)
		{
			int num = *(int *)a->start->content;
			if (((num >> i) & 1) == 1)
				*steps = ra(*steps, a);
			else
				*steps = pb(*steps, a, b);
		}
		while (b->e_count > 0)
			*steps = pa(*steps, a, b);
	}
	*steps = start;
	return (0);
}