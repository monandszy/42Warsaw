
#include "ps.h"

int main(int argc, char **argv)
{
	char **args;
	t_list *steps;
	t_stack *a;
	t_stack *b;

  a = NULL;
  b = NULL; 
	if (argc == 1)
		return (0); 
	else if (argc == 2)
	{	
    args = ft_split(*argv, ' ');
		if (!args || validate_argv(args))
			return (free_split(args), ft_printf("Error\n"), 1);
		if (initialize_stack(args, a, b))
      return (free_split(args), free_stack(a), free_stack(b), ft_printf("Error\n"), 1);
		steps = sort(a, b);
    print_steps(steps);
    return (free_split(args), free_stack(a), free_stack(b), free_list(steps), 0);
	}
	else
		return (ft_printf("Error\n"), 1);
}

void print_steps(t_list *steps)
{
  t_list *i;

  i = steps;
  while (i)
  {
    ft_printf("%s\n", (const char *) i -> content);
    i = i -> next;
  }
}