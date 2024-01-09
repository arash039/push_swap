/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:58:16 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:20:01 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_finder(t_node **head)
{
	int		min;
	t_node	*pos;

	pos = *head;
	min = pos->data;
	while (pos != NULL)
	{
		if (pos->data < min)
			min = pos->data;
		pos = pos->next;
	}
	return (min);
}

void	min_pusher(t_node **head_a, t_node **head_b, int min)
{
	if (side_finder(head_a, min) == 0)
	{
		while ((*head_a)->data != min)
			rev_a(head_a);
	}
	else
	{
		while ((*head_a)->data != min)
			rrev_a(head_a);
	}
	push_b(head_b, head_a);
}

void	min_to_bottom(t_node **head, int min)
{
	if (side_finder(head, min) == 0)
	{
		while ((*head)->data != min)
			rev_b(head);
		rev_b(head);
	}
	else
	{
		while (last_value(*head) != min)
			rrev_b(head);
	}
}

void	push_back(t_node **head_a, t_node **head_b)
{
	while (list_size(*head_b) != 0)
		push_a(head_a, head_b);
}
