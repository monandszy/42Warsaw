
#ifndef PS_H
# define PS_H

# include "./../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_stack
{
	struct s_dlist	*start;
	struct s_dlist	*end;
	size_t			e_count;
}					t_stack;

typedef struct s_move
{
  int shared;
  int to_index;
  int from_index;
  int cost;
} t_move;

void print_move(t_move *move);
void print_stack(t_stack *stack);
void print_dlist(t_dlist **dl);
void print_int_arr(int *arr, int size);
void print_int_matrice(int **arr, int size);
void print_lis_from_stack(t_stack *stack, int *lis_schema);

int	        initialize_stack(int ***args, t_stack **a, t_stack **b, int argc);  
int					initialize_dlist(int **args, t_stack *a);
int        indexify(int ***args, int argc);
int					to_int_arr(char **args, int ***int_args, int a_size);
char	      **argv_split(char **argv, int argc);

void				print_steps(t_dlist *steps);
void				f_st(t_stack *st);
void				f_dl(t_dlist *dl);
void free_int_matrix(int **matrix, int rows);
t_dlist			*ft_dlstnew(void *content);
t_dlist *pop(t_dlist *steps);
void	merge_move_lists(t_dlist **main_list, t_dlist *second_list);
void	sort_moves_list(t_dlist **moves_list);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_node);

int					validate_argv(char **args);
int					check_numonly(char **args, int i);
int					check_duplicates(char **args, int i, int j);
int					check_maxint(char **args, int i);
int					ft_isnumber(char *str);

int radix(t_dlist **steps, t_stack *a, t_stack *b);


int					plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b);
int execute_lis(int *schema, t_dlist **steps, t_stack *a, t_stack *b);
void calc_lis(int **int_args, int argc, int *counters, int *predecessors);
void extract_max(int argc, int *schema, int *counters, int *predecessors);
int *lis(int **int_args, int argc);

int find_solution_recursive(t_dlist **steps, t_stack *a, t_stack *b, size_t total_cost);

t_move *calculate_optimal_rr_cost(t_stack *a, t_stack *b);
int calculate_r_move(int target, t_stack *s);

t_move *calculate_optimal_rrr_cost(t_stack *a, t_stack *b);
int calculate_rr_move(int target, t_stack *b);

t_dlist *calculate_all_rr_moves(t_stack *from, t_stack *to);
t_dlist *calculate_all_rrr_moves(t_stack *from, t_stack *to);
int reverse_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move);
int execute_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move);

int execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b);
int execute_rr_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move);
int execute_rrr_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move);

int adjust_order_move(t_dlist **steps, t_stack *a, size_t total_cost);

int ft_abs(int i);
int ft_greater(int i1, int i2);
int ft_lower(int i1, int i2);
t_move *calculate_cost(int to_index, int from_index);
t_move *calculate_negative_cost(int from_index, int to_index);

void	push(t_stack *to, t_stack *from);
void	rrotate(t_stack *s);
void	rotate(t_stack *s);
void	swap(t_stack *s);
void swap_top(t_stack *a, t_stack *b);

t_dlist				*sa(t_dlist *steps, t_stack *a);
t_dlist				*sb(t_dlist *steps, t_stack *b);
t_dlist				*ss(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pa(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pb(t_dlist *steps, t_stack *a, t_stack *b);
int transfer(t_dlist **steps, t_stack *a, t_stack *b);
t_dlist				*ra(t_dlist *steps, t_stack *a);
t_dlist				*rb(t_dlist *steps, t_stack *b);
t_dlist				*rr(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*rra(t_dlist *steps, t_stack *a);
t_dlist				*rrb(t_dlist *steps, t_stack *b);
t_dlist				*rrr(t_dlist *steps, t_stack *a, t_stack *b);

#endif
