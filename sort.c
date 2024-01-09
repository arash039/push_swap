/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:58:38 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:19:43 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_node **head)
{
	t_node	*pos;

	pos = *head;
	while (pos->next != NULL)
	{
		if (pos->data > pos->next->data)
			return (0);
		pos = pos->next;
	}
	return (1);
}

void	sort_3(t_node **head_a)
{
	if (sort_check(head_a) == 0)
	{
		if ((*head_a)->data > last_value(*head_a) 
			&& (*head_a)->data < (*head_a)->next->data)
		{
			rrev_a(head_a);
			return ;
		}
		else if ((*head_a)->data > last_value(*head_a) && 
			(*head_a)->data > (*head_a)->next->data)
		{
			rev_a(head_a);
			if (sort_check(head_a) == 0)
				swap_a(*head_a);
			return ;
		}
		else if ((*head_a)->data < (*head_a)->next->data && 
			(*head_a)->next->data > last_value(*head_a))
		{
			rrev_a(head_a);
			swap_a(*head_a);
		}
		else
			swap_a(*head_a);
	}
}

void	sort_5(t_node **head_a, t_node **head_b)
{
	min_pusher(head_a, head_b, min_finder(head_a));
	min_pusher(head_a, head_b, min_finder(head_a));
	sort_3(head_a);
	push_a(head_a, head_b);
	push_a(head_a, head_b);
}
