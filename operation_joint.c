/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_joint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:55:34 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 12:49:13 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_node **head_a, t_node **head_b)
{
	t_node	*pos;
	int		i;

	if (head_a == NULL || head_b == NULL)
		return ;
	pos = *head_a;
	i = (*head_a)->data;
	*head_a = (*head_a)->next;
	free(pos);
	insert_node_bottom(head_a, i);
	pos = *head_b;
	i = (*head_b)->data;
	*head_b = (*head_b)->next;
	free(pos);
	insert_node_bottom(head_b, i);
	ft_printf("rr\n");
}

void	rrr(t_node **head_a, t_node **head_b)
{
	t_node	*pos;
	int		i;

	pos = *head_a;
	while (pos->next->next != NULL)
		pos = pos->next;
	i = pos->next->data;
	free(pos->next);
	pos->next = NULL;
	insert_node_up(head_a, i);
	pos = *head_b;
	while (pos->next->next != NULL)
		pos = pos->next;
	i = pos->next->data;
	free(pos->next);
	pos->next = NULL;
	insert_node_up(head_b, i);
	ft_printf("rrr\n");
}
