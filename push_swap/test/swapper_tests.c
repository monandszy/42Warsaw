
#include "test.h"

void test_swap_two_stacks_empty_scenarios()
{
	t_stack *a, *b;

	// Case 1: Both stacks are empty
	a = init_stack();
	b = init_stack();
	swap_first(a, b);
	assert(a->start == NULL && a->e_count == 0);
	assert(b->start == NULL && b->e_count == 0);
	free_stack(a);
	free_stack(b);

	// Case 2: 'a' is empty, 'b' has one element
	a = init_stack();
	b = init_stack();
	t_dlist *node1 = new_node(10);
	b->start = b->end = node1;
	b->e_count = 1;
	swap_first(a, b);
	// 'a' should now have the element, 'b' should be empty
	assert(a->start == node1 && a->e_count == 1);
	assert(b->start == NULL && b->e_count == 0);
	free_stack(a);
	free_stack(b);

	// Case 3: 'a' has one element, 'b' is empty
	a = init_stack();
	b = init_stack();
	t_dlist *node2 = new_node(20);
	a->start = a->end = node2;
	a->e_count = 1;
	swap_first(a, b);
	// 'b' should now have the element, 'a' should be empty
	assert(b->start == node2 && b->e_count == 1);
	assert(a->start == NULL && a->e_count == 0);
	free_stack(a);
	free_stack(b);

	// Case 4: 'a' is empty, 'b' has multiple elements
	a = init_stack();
	b = init_stack();
	t_dlist *b_node1 = new_node(30);
	t_dlist *b_node2 = new_node(40);
	b->start = b_node1;
	b_node1->next = b_node2;
	b_node2->prev = b_node1;
	b->end = b_node2;
	b->e_count = 2;
	swap_first(a, b);
	// 'a' should get the first element of 'b'
	assert(a->start == b_node1 && a->e_count == 1 && a->start->next == NULL);
	assert(b->start == b_node2 && b->e_count == 1 && b->start->prev == NULL);
	free_stack(a);
	free_stack(b);

	printf("test_swap_two_stacks_empty_scenarios: PASSED\n");
}

void test_swap_two_stacks_one_element_each()
{
	t_stack *a = init_stack();
	t_stack *b = init_stack();
	t_dlist *node_a = new_node(100);
	t_dlist *node_b = new_node(200);

	a->start = a->end = node_a;
	a->e_count = 1;
	b->start = b->end = node_b;
	b->e_count = 1;

	swap_first(a, b);

	assert(a->e_count == 1);
	assert(a->start == node_b);
	assert(a->end == node_b);
	assert(*(int *)a->start->content == 200);

	assert(b->e_count == 1);
	assert(b->start == node_a);
	assert(b->end == node_a);
	assert(*(int *)b->start->content == 100);

	printf("test_swap_two_stacks_one_element_each: PASSED\n");
	free_stack(a);
	free_stack(b);
}

void test_swap_single_stack_empty_and_one_element()
{
	t_stack *s = init_stack();
	swap(s); // Should not crash
	assert(s->start == NULL && s->end == NULL && s->e_count == 0);

	t_dlist *node1 = new_node(1);
	s->start = node1;
	s->end = node1;
	s->e_count = 1;
	swap(s);
	assert(s->start == node1 && s->end == node1);
	assert(s->e_count == 1);

	printf("test_swap_single_stack_empty_and_one_element: PASSED\n");
	free_stack(s);
}

void test_swap_single_stack_multi_element()
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

	swap(s);

	assert(s->start == node2);
	assert(s->start->next == node1);
	assert(s->start->prev == NULL);
	assert(node1->prev == node2);
	assert(node1->next == node3);
	assert(node3->prev == node1);
	assert(s->end == node3);
	assert(s->e_count == 3);

	printf("test_swap_single_stack_multi_element: PASSED\n");
	free_stack(s);
}

void test_swap_two_stacks()
{
    t_stack *a = init_stack();
    t_stack *b = init_stack();
    t_dlist *node1 = new_node(10);
    t_dlist *node2 = new_node(20);
    t_dlist *node3 = new_node(30);
    t_dlist *node4 = new_node(40);

    a->start = node1;
    node1->next = node2;
    node2->prev = node1;
    a->end = node2;
    a->e_count = 2;

    b->start = node3;
    node3->next = node4;
    node4->prev = node3;
    b->end = node4;
    b->e_count = 2;

    swap_first(a, b);

    assert(a->start == node3);
    assert(a->start->next == node2);
    assert(node2->prev == node3);
    assert(a->end == node2);
    assert(a->e_count == 2);

    assert(b->start == node1);
    assert(b->start->next == node4);
    assert(node4->prev == node1);
    assert(b->end == node4);
    assert(b->e_count == 2);

    printf("test_swap_two_stacks: PASSED\n");
	free_stack(a);
	free_stack(b);
}