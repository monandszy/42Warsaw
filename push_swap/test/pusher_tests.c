
#include "test.h"

void test_push_to_empty()
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dlist *node1 = new_node(10);

	a->start = node1;
	a->end = node1;
	a->e_count = 1;

	push(b, a);

	assert(b->e_count == 1);
	assert(b->start == node1);
	assert(b->end == node1);
	assert(*(int *)b->start->content == 10);
	assert(a->e_count == 0);
	assert(a->start == NULL);
	assert(a->end == NULL);

	printf("test_push_to_empty: PASSED\n");
	free_stack(a);
	free_stack(b);
}

void test_push_from_one_element_stack()
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dlist *node1 = new_node(10);
	t_dlist *node2 = new_node(20);

	a->start = node1;
	a->end = node1;
	a->e_count = 1;

	b->start = node2;
	b->end = node2;
	b->e_count = 1;

	push(b, a);

	assert(b->e_count == 2);
	assert(b->start == node1);
	assert(b->start->next == node2);
	assert(node2->prev == node1);
	assert(b->end == node2);
	assert(*(int *)b->start->content == 10);
	assert(a->e_count == 0);
	assert(a->start == NULL);
	assert(a->end == NULL);

	printf("test_push_from_one_element_stack: PASSED\n");
	free_stack(a);
	free_stack(b);
}

void test_push_from_multi_element_stack()
{
  t_stack *a = init_stack();
  t_stack *b = init_stack();
  t_dlist *node1 = new_node(10);
  t_dlist *node2 = new_node(20);
  t_dlist *node3 = new_node(30);

  a->start = node1;
  node1->next = node2;
  node2->prev = node1;
  a->end = node2;
  a->e_count = 2;

  b->start = node3;
  b->end = node3;
  b->e_count = 1;

  push(b, a);

  assert(b->e_count == 2);
  assert(b->start == node1);
  assert(b->start->next == node3);
  assert(node3->prev == node1);
  assert(b->end == node3);
  assert(a->e_count == 1);
  assert(a->start == node2);
  assert(a->end == node2);
  assert(node2->prev == NULL);

  printf("test_push_from_multi_element_stack: PASSED\n");
  free_stack(a);
  free_stack(b);
}

void test_push_from_empty_stack()
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dlist *node1 = new_node(10);

	b->start = node1;
	b->end = node1;
	b->e_count = 1;

	push(b, a);

	assert(a->e_count == 0);
	assert(a->start == NULL);
	assert(a->end == NULL);
	assert(b->e_count == 1);
	assert(b->start == node1);
	assert(b->end == node1);

	free_stack(b);
	b = init_stack();
	push(b, a);
	
	assert(a->e_count == 0);
	assert(a->start == NULL);
	assert(b->e_count == 0);
	assert(b->start == NULL);

	printf("test_push_from_empty_stack: PASSED\n");
	free_stack(a);
	free_stack(b);
}
