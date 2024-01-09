/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:49:04 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:28:56 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	match_finder(t_node **head_a, t_node **head_b)
{
	int		temp;
	int		temp_diff;
	t_node	*pos_a;
	t_node	*pos_b;

	pos_a = *head_a;
	pos_b = *head_b;
	temp = min_finder(head_b);
	temp_diff = pos_a->data - min_finder(head_b);
	while (pos_b != NULL)
	{
		if (pos_a->data > pos_b->data && 
			((pos_a->data - pos_b->data) < temp_diff))
		{
			temp_diff = pos_a->data - pos_b->data;
			temp = pos_b->data;
		}
		pos_b = pos_b->next;
	}
	return (temp);
}

int	move_counter(t_node **head, int val)
{
	int		size;
	int		i;
	t_node	*pos;

	pos = *head;
	i = 0;
	if (pos->data == val)
		return (0);
	size = list_size(*head);
	while (pos->data != val && pos->next != NULL)
	{
		pos = pos->next;
		i++;
	}
	if (i > size / 2)
		i = size - i;
	return (i);
}

int	node_selector(t_node	**head)
{
	t_node	*pos;
	int		temp;
	int		t_node_select;

	pos = *head;
	temp = pos->moves;
	t_node_select = pos->data;
	while (pos != NULL)
	{
		if (pos->moves < temp)
		{
			temp = pos->moves;
			t_node_select = pos->data;
		}
		pos = pos->next;
	}
	return (t_node_select);
}

int	side_finder(t_node **head, int data)
{
	t_node	*pos;
	int		size;
	int		i;

	pos = *head;
	i = 1;
	size = list_size(*head);
	while (pos->next != NULL)
	{
		if (pos->data != data)
			i++;
		else 
			break ;
		pos = pos->next;
	}
	if (i > (size / 2))
		return (1);
	else if (i <= (size / 2))
		return (0);
	return (0);
}

int	match_extractor(t_node **head, int data)
{
	t_node	*pos;

	pos = *head;
	while (pos->data != data)
		pos = pos->next;
	return (pos->match);
}
