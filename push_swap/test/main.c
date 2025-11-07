
#include "test.h"

int main(void)
{
  printf("Testing push\n");
	test_push_to_empty();
	test_push_from_one_element_stack();
	test_push_from_multi_element_stack();
	test_push_from_empty_stack();

	printf("\nTesting rotate\n");
	test_rotate_empty_and_one_element();
	test_rotate_multi_element();

	printf("\nTesting rrotate\n");
	test_rrotate_empty_and_one_element();
	test_rrotate_multi_element();

	printf("\nTesting swap\n");
	test_swap_single_stack_empty_and_one_element();
	test_swap_single_stack_multi_element();
	test_swap_two_stacks();
	test_swap_two_stacks_empty_scenarios();
	test_swap_two_stacks_one_element_each();
}

t_dlist *new_node(int content)
{
	t_dlist *node = (t_dlist *)malloc(sizeof(t_dlist));
	assert(node != NULL);
	node->content = malloc(sizeof(int));
	assert(node->content != NULL);
	*(int *)node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack *init_stack()
{
	t_stack *s = (t_stack *)malloc(sizeof(t_stack));
	assert(s != NULL);
	s->start = NULL;
	s->end = NULL;
	s->e_count = 0;
	return (s);
}

void free_stack(t_stack *s)
{
	if (!s)
		return;
	t_dlist *current = s->start;
	t_dlist *next;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	free(s);
}