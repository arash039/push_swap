/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashojach <ashojach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:00:02 by ashojach          #+#    #+#             */
/*   Updated: 2023/07/04 15:22:14 by ashojach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct t_node{
	int				data;
	int				match;
	int				moves;
	int				side;
	struct t_node	*next;
}	t_node;

//input check
int		input_check(t_node **stack);
void	free_linked_list(t_node *head);
void	splitter(char *arg, t_node **head_a);
int		parse_number(char *str, int *i, t_node **head_a);
int		ft_atoi(const char *str, t_node **head_a);

//list utility
t_node	*create_node(int num);
void	insert_node_bottom(t_node **head, int num);
void	print_list(t_node *head);
void	insert_node_up(t_node **head, int num);
int		list_size(t_node *head);
int		last_value(t_node *head);

//instructions
void	push_a(t_node **head, t_node **to_add);
void	swap_a(t_node *head);
void	rrev_a(t_node **head);
void	rev_a(t_node **head);
void	swap_b(t_node *head);
void	rrev_b(t_node **head);
void	rev_b(t_node **head);
void	push_b(t_node **head, t_node **to_add);
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);

//calculator functions
int		match_finder(t_node **head_a, t_node **head_b);
int		move_counter(t_node **head, int val);
void	updater(t_node **head_a, t_node **head_b);
int		node_selector(t_node	**head);
int		side_finder(t_node **head, int data);
int		match_extractor(t_node **head, int data);

//rotators
void	rotator_a(t_node **head, int data, int side);
void	rotator_b(t_node **head, int match, int side);
void	mutual_rotate_rr(t_node **head_a, t_node **head_b,
			int data_a, int data_b);
void	mutual_rotate_rrr(t_node **head_a, t_node **head_b,
			int data_a, int data_b);

//push_swap main functions
void	push_swap_first(t_node **head_a, t_node **head_b);
void	min_pusher(t_node **head_a, t_node **head_b, int min);
int		min_finder(t_node **head);
void	min_to_bottom(t_node **head, int min);
void	push_back(t_node **head_a, t_node **head_b);
void	push_swap(t_node **head_a, t_node **head_b, int size);

//sort
void	sort_3(t_node **head_a);
void	sort_5(t_node **head_a, t_node **head_b);
int		sort_check(t_node **head);

//ft_printf
int		ft_printf(const char *c, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);

#endif