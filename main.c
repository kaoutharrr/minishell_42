/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 04:05:37 by kkouaz            #+#    #+#             */
/*   Updated: 2023/06/17 04:14:30 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	fail_readline(char	*input)
{
	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
}

void	main2(t_cmd **lst, int fi, int fo)
{
	if ((*lst)->command)
		exec((*lst), ft_lst_size(*lst));
	signal(SIGINT, sighandle);
	dup2(fi, 0);
	dup2(fo, 1);
}

int	main1(t_cmd **lst, t_vars *vars, int fi, int fo)
{
	char	*input;

	while (1)
	{
		input = readline("$minishell>: ");
		fail_readline(input);
		add_history(input);
		if (ft_synstax(input, vars) == 1)
			continue ;
		if (empty_cmd(input))
		{
			if (input[0] == '\0' || !parssing(lst, vars, input))
			{
				if (input[0] == '\0')
					free(input);
				else
					ft_free_allocation(lst, vars, input);
				continue ;
			}
			main2(lst, fi, fo);
			ft_free_allocation2(lst, vars);
		}
		free(input);
	}
	return (0);
}

void	ft_free_allocation2(t_cmd **lst, t_vars *vars)
{
	if ((*lst))
		ft_free_lst(lst);
	if (vars->ar_2d)
		ft_free_2d_array(vars->ar_2d);
	if (vars->mask)
		free(vars->mask);
}

int	main(int ac, char **av, char **envp)
{
	t_vars	vars;
	int		fi;
	int		fo;
	t_cmd	*lst;

	lst = NULL;
	fi = 0;
	fo = 0;
	(void)ac;
	(void)av;
	g_llobal.global = my_env(envp);
	fi = dup(0);
	fo = dup(1);
	signal(SIGINT, sighandle);
	signal(SIGQUIT, SIG_IGN);
	main1(&lst, &vars, fi, fo);
	return (0);
}
