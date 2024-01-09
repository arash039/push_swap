/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:55:08 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 12:49:04 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_node **head, t_node **to_add)
{
	t_node	*pos;

	insert_node_up(head, (*to_add)->data);
	pos = *to_add;
	*to_add = (*to_add)->next;
	free(pos);
	pos = NULL;
	ft_printf("pb\n");
}

void	swap_b(t_node *head)
{
	int	temp;

	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	ft_printf("sb\n");
}

void	rrev_b(t_node **head)
{
	t_node	*pos;
	int		i;

	pos = *head;
	while (pos->next->next != NULL)
		pos = pos->next;
	i = pos->next->data;
	free(pos->next);
	pos->next = NULL;
	insert_node_up(head, i);
	ft_printf("rrb\n");
}

void	rev_b(t_node **head)
{
	t_node	*pos;
	int		i;

	if (head == NULL)
		return ;
	pos = *head;
	i = (*head)->data;
	*head = (*head)->next;
	free(pos);
	insert_node_bottom(head, i);
	ft_printf("rb\n");
}
