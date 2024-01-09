/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:57:54 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:19:26 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotator_a(t_node **head, int data, int side)
{
	while ((*head)->data != data && list_size(*head) != 1)
	{
		if (side == 1)
			rrev_a(head);
		else 
			rev_a(head);
	}
}

void	rotator_b(t_node **head, int match, int side)
{
	while ((*head)->data != match)
	{
		if (side == 1)
			rrev_b(head);
		else 
			rev_b(head);
	}
}

void	mutual_rotate_rr(t_node **head_a, t_node **head_b
		, int data_a, int data_b)
{
	while ((*head_a)->data != data_a && (*head_b)->data != data_b)
		rr(head_a, head_b);
	if ((*head_a)->data == data_a && (*head_b)->data != data_b)
	{
		while ((*head_b)->data != data_b)
			rev_b(head_b);
	}
	else if ((*head_b)->data == data_b && (*head_a)->data != data_a)
	{
		while ((*head_a)->data != data_a)
			rev_a(head_a);
	}
}

void	mutual_rotate_rrr(t_node **head_a, t_node **head_b
		, int data_a, int data_b)
{
	while ((*head_a)->data != data_a && (*head_b)->data != data_b)
		rrr(head_a, head_b);
	if ((*head_a)->data == data_a && (*head_b)->data != data_b)
	{
		while ((*head_b)->data != data_b)
			rrev_b(head_b);
	}
	else if ((*head_b)->data == data_b && (*head_a)->data != data_a)
	{
		while ((*head_a)->data != data_a)
			rrev_a(head_a);
	}
}
