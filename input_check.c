/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:50:45 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 15:15:40 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(t_node **stack)
{
	t_node	*pos;
	t_node	*temp;

	pos = *stack;
	if (pos == NULL)
		exit (0);
	while (pos != NULL && pos->next != NULL)
	{
		temp = pos->next;
		while (temp != NULL)
		{
			if (pos->data == temp->data)
			{
				free_linked_list(*stack);
				ft_printf("Error\n");
				exit (1);
			}
			temp = temp->next;
		}
		pos = pos->next;
	}
	return (1);
}

void	push_swap(t_node **head_a, t_node **head_b, int size)
{
	if (size == 2)
		swap_a(*head_a);
	else if (size == 3)
		sort_3(head_a);
	else if (size == 5)
		sort_5(head_a, head_b);
	else
	{
		min_pusher(head_a, head_b, min_finder(head_a));
		if ((*head_a)->data > (*head_a)->next->data)
			swap_a(*head_a);
		if (last_value(*head_a) < (*head_a)->data)
			rrev_a(head_a);
		push_b(head_b, head_a);
		push_swap_first(head_a, head_b);
		min_to_bottom(head_b, min_finder(head_b));
		push_back(head_a, head_b);
	}
}

int	parse_number(char *str, int *i, t_node **head_a)
{
	int			sign;
	long long	val;

	sign = 1;
	val = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		val = val * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.' || val >= 2147483648)
	{
		free_linked_list(*head_a);
		ft_printf("Error\n");
		exit (1);
	}
	return (sign * val);
}

void	splitter(char *str, t_node **head_a)
{
	int	i;
	int	number;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = parse_number(str, &i, head_a);
			insert_node_bottom(head_a, number);
		}
		else if (str[i] == ' ')
			i++;
		else 
		{
			free_linked_list(*head_a);
			ft_printf("Error\n");
			exit (1);
		}
	}
}
