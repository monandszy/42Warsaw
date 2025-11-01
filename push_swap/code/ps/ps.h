
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
} t_stack;

int initialize_stack(char **args, t_stack *a, t_stack *b);
int initialize_dlist(char **args, t_stack *a);
void print_steps(t_list *steps);

int validate_argv(char **args);
int check_numonly(char **args, int i);
int check_duplicates(char **args, int i, int j);
int check_maxint(char **args, int i);
int ft_isnumber(char *str);

t_list *sort(t_stack *a, t_stack *b, size_t element_count);
void free_stack(t_stack *s);
void free_split(char **s);
void free_dlist(t_dlist *dl);
void free_list(t_list *l);

#endif

