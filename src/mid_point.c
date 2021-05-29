/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 11:58:30 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_stack *list, t_stack **sort_point, int pol)
{
	*sort_point = NULL;
	insert_sort(sort_point, list->value);
	while (list->next != NULL && list->pol == pol)
	{
		list = list->next;
		if (list->pol == pol)
			insert_sort(sort_point, list->value);
		else
			break ;
	}
}

int	count_not_sort(t_stack *list)
{
	if (list == NULL)
		return (0);
	while (list != NULL && list->pol == 0)
		list = list->next;
	if (list == NULL)
		return (0);
	return (1 + count_not_sort(list->next));
}

int	find_med(t_stack *list)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*pre_slow;

	slow = list;
	fast = list;
	pre_slow = list;
	if (list != NULL)
	{
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			pre_slow = slow;
			slow = slow->next;
		}
		if (fast != NULL)
			return (slow->value);
		else
			return (pre_slow->value);
	}
	return (-1);
}

int	find_med_part(t_stack *list)
{
	t_stack	*part_sort;
	int		med;

	if (ft_count(list) == 0)
		return (0);
	sort_list(list, &part_sort, list->pol);
	med = find_med(part_sort);
	ft_unallocate(&part_sort);
	return (med);
}