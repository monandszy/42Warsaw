
#ifndef TEST_H
# define TEST_H

# include "./../code/ps/ps.h"
# include "./../code/sc/sc.h"

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

t_dlist *new_node(int content);
t_stack *init_stack();
void free_stack(t_stack *s);
void test_push_to_empty();
void test_push_from_one_element_stack();
void test_push_from_multi_element_stack();
void test_push_from_empty_stack();
void test_rotate_empty_and_one_element();
void test_rotate_multi_element();
void test_rrotate_empty_and_one_element();
void test_rrotate_multi_element();
void test_swap_single_stack_empty_and_one_element();
void test_swap_single_stack_multi_element();
void test_swap_two_stacks();
void test_swap_two_stacks_empty_scenarios();
void test_swap_two_stacks_one_element_each();

#endif