
#include "test.h"

void test_rrotate_empty_and_one_element()
{
	t_stack *s = init_stack();
	rrotate(s); // Should not crash
	assert(s->start == NULL && s->end == NULL && s->e_count == 0);

	t_dlist *node1 = new_node(1);
	s->start = node1;
	s->end = node1;
	s->e_count = 1;
	rrotate(s);
	assert(s->start == node1 && s->end == node1);
	assert(s->e_count == 1);
	
	printf("test_rrotate_empty_and_one_element: PASSED\n");
	free_stack(s);
}

void test_rrotate_multi_element()
{
	t_stack *s = init_stack();
	t_dlist *node1 = new_node(1);
	t_dlist *node2 = new_node(2);
	t_dlist *node3 = new_node(3);

	s->start = node1;
	node1->next = node2;
	node2->prev = node1;
	node2->next = node3;
	node3->prev = node2;
	s->end = node3;
	s->e_count = 3;

	rrotate(s);

	assert(s->start == node3);
	assert(s->start->next == node1);
	assert(s->start->prev == NULL);
	assert(s->end == node2);
	assert(s->end->next == NULL);
	assert(node1->prev == node3);
	assert(node2->next == NULL);
	assert(s->e_count == 3);

	printf("test_rrotate_multi_element: PASSED\n");
	free_stack(s);
}