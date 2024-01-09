/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:53:42 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 15:22:59 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **arg)
{
	int		i;
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	i = 1;
	while (ac > 2 && i < ac)
	{
		insert_node_bottom(&head_a, ft_atoi(arg[i], &head_a));
		i++;
	}
	if (ac == 2)
		splitter(arg[1], &head_a);
	if (input_check(&head_a) == 1 && sort_check(&head_a) == 0)
		push_swap(&head_a, &head_b, list_size(head_a));
	free_linked_list(head_a);
	free_linked_list(head_b);
	return (0);
}
