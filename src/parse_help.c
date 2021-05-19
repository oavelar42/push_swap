/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/19 13:50:38 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    parse_number(char **av, t_stack **a, int ac, int i)
{
    while (i < ac)
    {
        insert_end(a, ft_atoi(av[i]));
        i++;
    }
}

void    ft_on_off(int *i, int *sg, char **av)
{
    if (!ft_strncmp("-v", av[1], 3))
    {
        *i = 2;
        *sg = 1;
    }
    else
    {
        *i = 1;
        *sg = 0;
    }
}