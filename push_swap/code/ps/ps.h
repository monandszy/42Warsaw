
#ifndef PS_H
# define PS_H

# include "./../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_dlist
{
	void			*content;
	int				target;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_stack
{
	struct s_dlist	*start;
	struct s_dlist	*end;
	size_t			size;
}					t_stack;

int					initialize_stack(char **args, t_stack *a, t_stack *b);
int					initialize_dlist(int **args, t_stack *a);
int					to_int_arr(char **args, int **int_args, int a_size);
void				bubble_sort(int **args);
void				initialize_targets(int **args, t_stack *a);
void				print_steps(t_dlist *steps);

t_dlist				*ft_dlstnew(void *content);

int					validate_argv(char **args);
int					check_numonly(char **args, int i);
int					check_duplicates(char **args, int i, int j);
int					check_maxint(char **args, int i);
int					ft_isnumber(char *str);

int					plan(t_dlist *steps, t_stack *a, t_stack *b);
void				f_st(t_stack *st);
void				f_sp(char **sp);
void				f_dl(t_dlist *dl);

t_dlist				*sa(t_dlist *steps, t_stack *a);
t_dlist				*sb(t_dlist *steps, t_stack *b);
t_dlist				*ss(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pa(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pb(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*ra(t_dlist *steps, t_stack *a);
t_dlist				*rb(t_dlist *steps, t_stack *b);
t_dlist				*rr(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*rra(t_dlist *steps, t_stack *a);
t_dlist				*rrb(t_dlist *steps, t_stack *b);
t_dlist				*rrr(t_dlist *steps, t_stack *a, t_stack *b);

#endif
