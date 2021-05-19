/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/18 21:46:46 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  make_stack(int ac, char **av, my_stack **start)
{
    my_stack    *new = NULL;
    my_stack    *end = NULL;
    int         i;

    new = new_node(ft_atoi(av[1]));
    *start = end = new;
    i = 2;
    while (i < ac)
    {
        new = new_node(ft_atoi(av[1]));
        end = append(end, new);
        i++;
    }
}