/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 11:59:48 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *list)
{
	int	value_temp;
	int	pol_temp;

	if (list == NULL || ft_count(list) < 2)
		return ;
	value_temp = list->value;
	pol_temp = list->pol;
	list->value = list->next->value;
	list->pol = list->next->pol;
	list->next->value = value_temp;
	list->next->pol = pol_temp;
}

void	push_other(t_stack **from, t_stack **to)
{
	t_stack	*move;

	if (*from == NULL)
		return ;
	move = *from;
	*from = (*from)->next;
	move->next = *to;
	*to = move;
}

void	rotate_up(t_stack **list)
{
	t_stack	*curr;
	t_stack	*move_down;

	if (*list == NULL || ft_count(*list) < 2)
		return ;
	move_down = *list;
	curr = *list;
	while (curr->next != NULL)
		curr = curr->next;
	*list = move_down->next;
	curr->next = move_down;
	move_down->next = NULL;
}

void	rotate_down(t_stack **list)
{
	t_stack	*curr;

	if (*list == NULL || ft_count(*list) < 2)
		return ;
	curr = *list;
	while (curr->next->next != NULL)
		curr = curr->next;
	curr->next->next = *list;
	*list = curr->next;
	curr->next = NULL;
}

void	rrr_rotate_down(t_stack **a, t_stack **b, int print, int sg)
{
	rotate_down(a);
	rotate_down(b);
	if (print)
		write(1, "rrr\n", 4);
	if (sg)
		print_stacks(*a, *b);
}