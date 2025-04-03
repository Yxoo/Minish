/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorouger <jorouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:26:09 by jorouger          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/03/31 13:14:43 by jorouger         ###   ########.fr       */
=======
/*   Updated: 2025/03/27 12:54:05 by jorouger         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
typedef struct s_command
{
	char	*command;
	char	**args;
	char	redirect;
	int		*files;
}	t_command;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

#include <stdio.h>

static	t_bool	is_n_flag(char *arg)
{
	t_bool	n_flag;
	int		i;

	n_flag = FALSE;
	i = 0;
	if (arg[i] != '-')
		return (n_flag);
	i++;
	while (arg && arg[i] == 'n')
		i++;
	if (arg[i] == '\0')
		n_flag = TRUE;
	return (n_flag);
}

static void	echo_print(char **arg, t_bool n_flag, int i)
{
	if (!arg[i])
	{
		if (!n_flag)
			printf("\n");
		return ;
	}
	while (arg[i])
	{
		printf("%s", arg[i]);
		if (arg[i + 1])
			printf(" ");
		else if (!arg[i + 1] && !n_flag)
			printf("\n");
		i++;
	}
}

int	echo_builtin(t_command *command, char **arg)
{
	int		i;
	t_bool	n_flag;

	i = 2;
	(void) command;
	n_flag = FALSE;
	while (arg[i] && is_n_flag(arg[i]))
	{
		n_flag = TRUE;
		i++;
	}
	echo_print(arg, n_flag, i);
	return (1);
}

int main(int argc, char **argv)
{
	(void) argc;
	t_command	*command;
	echo_builtin(command, argv);
	
}
