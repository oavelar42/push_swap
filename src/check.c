/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/30 10:39:49 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(int sg, char **str)
{
	int	a;

	a = 0;
	if (ft_strlen(str[a]) < 10)
		return (0);
	if (ft_strlen(str[a]) > 10)
		return (1);
	if (sg == 1 && ft_strcmp(str[a], "2147483647") > 0)
		return (1);
	if (sg == -1 && ft_strcmp(str[a], "2147483648") > 0)
		return (1);
	return (0);
}

int	ft_atol(char *str)
{
	int	i;
	int	sg;

	i = 0;
	sg = 1 - 2 * (str[i] == '-');
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || check_input(sg, &str))
			return (1);
		i++;
	}
	return (0);
}

int	check_dual(t_stack **a)
{
	t_stack	*sort;

	sort_list(*a, &sort, (*a)->pol);
	if (check_list_dual(sort))
	{
		ft_unallocate(&sort);
		ft_unallocate(a);
		return (1);
	}
	else
	{
		ft_unallocate(&sort);
		return (0);
	}
}

int	check_list_dual(t_stack *sort_list)
{
	int		init;

	if (ft_count(sort_list) == 0)
		exit(0);
	init = sort_list->value;
	while (sort_list->next != NULL)
	{
		sort_list = sort_list->next;
		if (init == sort_list->value)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		init = sort_list->value;
	}
	return (0);
}
