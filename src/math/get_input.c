/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oavelar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:01:15 by oavelar           #+#    #+#             */
/*   Updated: 2021/05/10 13:12:19 by oavelar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	parse_argv(char *arg, t_list **a, int *bonus_opt)
{
	char	**args;
	char	**aux;
	int		*n;

	if (!ft_strcmp(arg, "-v"))
	{
		*bonus_opt = 1;
		return ;
	}
	args = ft_split(arg,' ');
	aux = args;
	while (*args)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi_error(*args);
		check_dup(*n, *a);
		ft_lstadd_back(a, ft_lstnew(n));
		free(*args);
		args++;
	}
	free(aux);
}

void	add_argv(int argc, char **argv, t_list **a)
{
	int	i;
	int	*num;

	i = 2;
	while (i < argc)
	{
		num = malloc(sizeof(int));
		*num = ft_atoi_error(argv[i]);
		check_dup(*num, *a);
		ft_lstadd_back(a, ft_lstnew(num));
		i++;	
	}
}

void	check_dup(int n, t_list *a)
{
	while (a)
	{
		if (*(int *)(a->content) == n)
			ft_exit("ERROR\n");
		a = a->next;
	}
}