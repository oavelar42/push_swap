/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:45:28 by oavelar           #+#    #+#             */
/*   Updated: 2021/06/21 21:33:02 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_unallocate(t_stack **a, t_stack **b, int sg)
{
	sort(a, b, sg);
	ft_unallocate(a);
	ft_unallocate(b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	int		sg;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !ft_strncmp(av[1], "-v", 3)))
		return (0);
	ft_on_off(&i, &sg, av);
	if (check_input(ac - i, av + i))
		return (1);
	parse_number(av, &a, ac, i);
	if (check_dual(&a))
		return (1);
	if (!ft_okay(a, b, ft_count(a)))
	{
		ft_unallocate(&a);
		return (0);
	}
	return (sort_unallocate(&a, &b, sg));
}
