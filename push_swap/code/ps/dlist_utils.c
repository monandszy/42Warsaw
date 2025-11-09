/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:06 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:10:08 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dlist	*pop(t_dlist *steps)
{
	t_dlist	*tmp;

	if (steps)
	{
		tmp = steps;
		if (steps->prev)
		{
			steps = steps->prev;
			steps->next = NULL;
		}
		f_dl(tmp);
	}
	return (steps);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new_node)
{
	t_dlist	*current;

	if (!lst || !new_node)
		return ;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
	new_node->prev = current;
}

void	merge_move_lists(t_dlist **main_list, t_dlist *second_list)
{
	t_dlist	*tail;

	if (!second_list)
		return ;
	if (!main_list || !*main_list)
	{
		if (main_list)
			*main_list = second_list;
		return ;
	}
	tail = *main_list;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = second_list;
	second_list->prev = tail;
}

static t_dlist	*sorted_merge(t_dlist *a, t_dlist *b)
{
	t_dlist	*result;
	t_move	*move_a;
	t_move	*move_b;

	if (!a)
		return (b);
	if (!b)
		return (a);
	move_a = (t_move *)a->content;
	move_b = (t_move *)b->content;
	if (move_a->cost <= move_b->cost)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
		if (result->next)
			result->next->prev = result;
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
		if (result->next)
			result->next->prev = result;
	}
	return (result);
}

static void	split_list(t_dlist *head, t_dlist **front_half, t_dlist **back_half)
{
	t_dlist	*fast;
	t_dlist	*slow;

	if (!head || !head->next)
	{
		*front_half = head;
		*back_half = NULL;
		return ;
	}
	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front_half = head;
	*back_half = slow->next;
	if (*back_half)
		(*back_half)->prev = NULL;
	slow->next = NULL;
}

void	sort_moves_list(t_dlist **moves_list)
{
	t_dlist	*head;
	t_dlist	*a;
	t_dlist	*b;

	head = *moves_list;
	if (!head || !head->next)
		return ;
	split_list(head, &a, &b);
	sort_moves_list(&a);
	sort_moves_list(&b);
	*moves_list = sorted_merge(a, b);
}
