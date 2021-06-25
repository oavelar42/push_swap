/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/21 21:33:25 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_init(t_stack **all, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_the_end("Memory Error\n");
	new->value = value;
	new->pol = -1;
	new->next = *all;
	*all = new;
}

void	insert_then(t_stack *node, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_the_end("Memory Error\n");
	new->value = value;
	new->pol = 9;
	new->next = node->next;
	node->next = new;
}

void	insert_sort(t_stack **all, int value)
{
	t_stack	*curr;

	curr = *all;
	if (*all == NULL || (*all)->value >= value)
	{
		insert_init(all, value);
		return ;
	}
	while (curr->next != NULL)
	{
		if (curr->next->value >= value)
			break ;
		curr = curr->next;
	}
	insert_then(curr, value);
}

void	insert_end(t_stack **all, int value)
{
	t_stack	*new;
	t_stack	*curr;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_the_end("Memory Error\n");
	new->next = NULL;
	new->value = value;
	new->pol = -1;
	if (*all == NULL)
	{
		*all = new;
		return ;
	}
	curr = *all;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

int	ft_count(t_stack *list)
{
	if (list == NULL)
		return (0);
	return (1 + ft_count(list->next));
}
