/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/10 13:12:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*side_a;
	t_list	*side_b;

	side_a = NULL;
	side_b = NULL;
	if (argc < 2)
		return (0);
	if (argv >= 2)
		parse_argv(argv[1], &side_a, NULL);
	if (argc > 2)
		add_argv(argc, argv, &side_a);
	ft_sort_set(&side_a, &side_b);
	ft_clear_stack(&side_a, &side_b);
	return (0);
}