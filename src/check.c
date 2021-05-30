/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/29 12:03:53 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *s)
{
	long	sign;
	double	result;

	sign = 1;
	result = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + *s - '0';
		if (sign == 1 && result < 0)
			return (-1);
		else if (sign == -1 && - result > 0)
			return (0);
		s++;
	}
	return ((long) sign * (long) result);
}

int	check_input(int ac, char **s)
{
	int		a;
	int		b;
	int		count;

	a = 0;
	while (a < ac)
	{
		b = 0;
		count = ft_strlen(s[a]);
		if (s[a][0] == '-')
			b++;
		while (ft_isdigit(s[a][b]))
			b++;
		if (b != count || count > 11 || count == 0
			|| ft_atol(s[a]) > 2147483647 || ft_atol(s[a]) < -2147483648)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
		a++;
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
			write(2, "ERROR\n", 6);
			return (1);
		}
		init = sort_list->value;
	}
	return (0);
}
