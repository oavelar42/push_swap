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

int   main(int ac, char **av)
{
   if (ac < 3)
        return (0);
  if(validate_input(ac, av))
  {
	  my_stack *stack_a = NULL;
	  my_stack *stack_b = NULL;
	  make_stack(ac, av, &stack_a);
	  sort(&stack_a, &stack_b, ac - 1);
	  free_stack(stack_a);
	  free_stack(stack_b);
  } 
  return (1);
}
