/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:45 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 18:13:02 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			e_count;
}					t_stack;

typedef struct s_move
{
	int				shared;
	int				to_index;
	int				from_index;
	int				cost;
}					t_move;

int     find_origin(t_stack *a);

void				print_move(t_move *move);
void				print_stack(t_stack *stack);
void				print_dlist(t_dlist **dl);
void				print_int_arr(int *arr, int size);
void				print_int_matrice(int **arr, int size);
void				print_lis_from_stack(t_stack *stack, int *lis_schema);
void				print_dlist_moves(t_dlist **dl);

void				print_steps(t_dlist *steps);

char				**argv_split(char **argv, int argc);
int					i_stack(int ***args, t_stack **a, t_stack **b,
						int argc);

int					validate_argv(char **args);
int					check_numonly(char **args, int i);
int					check_duplicates(char **args, int i, int j);
int					check_maxint(char **args, int i);
int					ft_isnumber(char *str);


int					to_int_arr(char **args, int ***int_args, int a_size);
int					indexify(int ***args, int argc);

int sorted(t_dlist **steps, t_stack *a);

int optimal_sort(t_dlist **steps, t_stack *a, t_stack *b);
int sort_3(t_dlist **steps, t_stack *a);
int sort_4(t_dlist **steps, t_stack *a, t_stack *b);
int sort_5(t_dlist **steps, t_stack *a, t_stack *b);

void				f_st(t_stack *st);
void				f_dl(t_dlist *dl);
void				free_int_matrix(int **matrix, int rows);

t_dlist				*ft_dlstnew(void *content);
t_dlist				*pop(t_dlist *steps);

int					*lis(int **int_args, int argc);
int					execute_lis(int *schema, t_dlist **steps, t_stack *a,
						t_stack *b);

int					plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b);

int					execute_move(t_dlist **steps, t_stack *a, t_stack *b,
						t_move *move);
int					reverse_move(t_dlist **steps, t_stack *a, t_stack *b,
						t_move *move);

int					execute_optimal_move(t_dlist **steps, t_stack *a,
						t_stack *b);
int					execute_rr_move(t_dlist **steps, t_stack *a, t_stack *b,
						t_move *move);
int					execute_rrr_move(t_dlist **steps, t_stack *a, t_stack *b,
						t_move *move);

int					adjust_order(t_dlist **steps, t_stack *a);

t_move				*calculate_optimal_rr_cost(t_stack *a, t_stack *b);
int					calculate_r_move(int target, t_stack *s);

t_move				*calculate_optimal_rrr_cost(t_stack *a, t_stack *b);
int					calculate_rr_move(int target, t_stack *b);

int					ft_abs(int i);
int					ft_greater(int i1, int i2);
int					ft_lower(int i1, int i2);
t_move				*calculate_cost(int to_index, int from_index);
t_move				*calculate_negative_cost(int from_index, int to_index);

void				push(t_stack *to, t_stack *from);
void				rrotate(t_stack *s);
void				rotate(t_stack *s);
void				swap(t_stack *s);
void				swap_top(t_stack *a, t_stack *b);

t_dlist				*sa(t_dlist *steps, t_stack *a);
t_dlist				*sb(t_dlist *steps, t_stack *b);
t_dlist				*ss(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pa(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*pb(t_dlist *steps, t_stack *a, t_stack *b);
int					transfer(t_dlist **steps, t_stack *a, t_stack *b);
t_dlist				*ra(t_dlist *steps, t_stack *a);
t_dlist				*rb(t_dlist *steps, t_stack *b);
t_dlist				*rr(t_dlist *steps, t_stack *a, t_stack *b);
t_dlist				*rra(t_dlist *steps, t_stack *a);
t_dlist				*rrb(t_dlist *steps, t_stack *b);
t_dlist				*rrr(t_dlist *steps, t_stack *a, t_stack *b);

#endif
