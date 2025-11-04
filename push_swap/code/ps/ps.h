
#ifndef PS_H
# define PS_H

# include "./../printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_dlist
{
	int content;
	struct s_dlist *next;
	struct s_dlist *prev;
} t_dlist;


typedef struct s_stack
{
	struct s_dlist *start;
	struct s_dlist *end;
  size_t size;
} t_stack;

int initialize_stack(char **args, t_stack *a, t_stack *b);
int initialize_dlist(char **args, t_stack *a);
void print_steps(t_list *steps);

int validate_argv(char **args);
int check_numonly(char **args, int i);
int check_duplicates(char **args, int i, int j);
int check_maxint(char **args, int i);
int ft_isnumber(char *str);

int plan(t_list *steps, t_stack *a, t_stack *b);
void free_stack(t_stack *s);
void free_split(char **s);
void free_dlist(t_dlist *dl);
void free_list(t_list *l);

t_list *sa(t_list *steps, t_stack *a);
t_list *sb(t_list *steps, t_stack *b);
t_list *ss(t_list *steps, t_stack *a, t_stack *b);
t_list *pa(t_list *steps, t_stack *a, t_stack *b);
t_list *pb(t_list *steps, t_stack *a, t_stack *b);
t_list *ra(t_list *steps, t_stack *a);
t_list *rb(t_list *steps, t_stack *b);
t_list *rr(t_list *steps, t_stack *a, t_stack *b);
t_list *rra(t_list *steps, t_stack *a);
t_list *rrb(t_list *steps, t_stack *b);
t_list *rrr(t_list *steps, t_stack *a, t_stack *b);

#endif

