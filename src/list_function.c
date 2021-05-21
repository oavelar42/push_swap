/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/21 16:17:01 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_sort(t_stack **all, int value)
{
	//after _because today , day of beer !!!;
}

void	insert_end(t_stack **all, int value)
{
	t_stack	*new;
	t_stack	*curr;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		ft_the_end("MEMORY ERROR\n");
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

int		ft_count(t_stack *list)
{
	if (list == NULL)
		return (0);
	return (1 + ft_count(list->next));
}