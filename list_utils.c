/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:51:05 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 00:28:00 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (0);
	new_node->data = num;
	new_node->next = NULL;
	return (new_node);
}

void	insert_node_bottom(t_node **head, int num)
{
	t_node	*new_node;
	t_node	*pos;

	new_node = create_node(num);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		pos = *head;
		while (pos->next != NULL)
			pos = pos->next;
		pos->next = new_node;
	}
}

void	insert_node_up(t_node **head, int num)
{
	t_node	*new_t_node;

	new_t_node = create_node(num);
	if (new_t_node == NULL)
		return ;
	new_t_node->next = *head;
	*head = new_t_node;
}

int	list_size(t_node *head)
{
	int		i;
	t_node	*temp;

	temp = head;
	i = 1;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	last_value(t_node *head)
{
	t_node	*pos;

	pos = head;
	while (pos->next != NULL)
		pos = pos->next;
	return (pos->data);
}
