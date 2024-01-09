/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:56:21 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:26:42 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	updater(t_node **head_a, t_node **head_b)
{
	int		i;
	t_node	*pos;

	i = 0;
	pos = (*head_a);
	while (pos != NULL)
	{
		pos->match = match_finder(&pos, head_b);
		i = move_counter(head_b, pos->match);
		i = i + move_counter(head_a, pos->data) + 1;
		pos->moves = i;
		pos = pos->next;
	}
}

void	push_swap_first(t_node **head_a, t_node **head_b)
{
	int	to_move_a;
	int	to_move_b;
	int	side_a;
	int	side_b;

	while (list_size(*head_a) != 0)
	{
		updater(head_a, head_b);
		to_move_a = node_selector(head_a);
		to_move_b = match_extractor(head_a, to_move_a);
		side_a = side_finder(head_a, to_move_a);
		side_b = side_finder(head_b, to_move_b);
		if (side_a == side_b && side_a == 0)
			mutual_rotate_rr(head_a, head_b, to_move_a, to_move_b);
		else if (side_a == side_b && side_a == 1)
			mutual_rotate_rrr(head_a, head_b, to_move_a, to_move_b);
		else
		{
			rotator_a(head_a, to_move_a, side_a);
			rotator_b(head_b, to_move_b, side_b);
		}
		push_b(head_b, head_a);
	}
}

void	free_linked_list(t_node *head)
{
	t_node	*current;
	t_node	*next;

	current = head;
	while (current != NULL) 
	{
		next = current->next;
		free(current);
		current = next;
	}
}
