/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:50:59 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:58:27 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

static void	split_list(t_dlist *head, t_dlist **front, t_dlist **back)
{
	t_dlist	*fast;
	t_dlist	*slow;

	if (!head || !head->next)
	{
		*front = head;
		*back = NULL;
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
	*front = head;
	*back = slow->next;
	if (*back)
		(*back)->prev = NULL;
	slow->next = NULL;
}

void	dlst_sort(t_dlist **head)
{
	t_dlist	*a;
	t_dlist	*b;

	if (!*head || !(*head)->next)
		return ;
	split_list(*head, &a, &b);
	dlst_sort(&a);
	dlst_sort(&b);
	*head = sorted_merge(a, b);
}
