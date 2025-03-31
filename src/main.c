/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorouger <jorouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:23:19 by jorouger          #+#    #+#             */
/*   Updated: 2025/03/27 14:30:31 by jorouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_command(t_command *command)
{
	command->command = NULL;
	command->args = NULL;
	command->redirect = 0;
	command->files = 0;
}

static void	init_quoted(t_quoted *command)
{
	command->q_count = 0;
	command->start = 0;
	command->end = 0;
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int		ft_str_isequal(char *base, char *to_find)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] != to_find[i])
			return (0);
		else
			i++;
	}
	return (1);
}

size_t	commands_number(char **splitted_command)
{
	size_t	i;

	i = 0;
	while (splitted_command[i])
		i++;
	return (i);
}

char	**pipe_split_command(char *entry)
{
	char	**splitted;
	size_t	split_len;
	size_t	split_height;
	size_t	y;

	split_len = 0;
	y = 0;
	split_height = 0;
	splitted = ft_calloc(sizeof(char **), 1);
	if (!splitted)
		return (NULL);
	split_height = commands_number(ft_split(entry, '|'));
	while (y < split_height)
	{
		split_len = ft_strlen(ft_split(entry, '|')[y]);
		splitted[y] = (char *)ft_calloc(sizeof(char *), split_len);
		if (!splitted[y])
			return (NULL);
		// write(1, "test", 4);
		splitted[y] = ft_strdup(ft_split(entry, '|')[y]);
		// write(1, "test", 4);
		// printf("------------------%s------------------%zu\n", ft_split(entry,
				//'|')[y], split_len);
		y++;
	}
	// printf("%s\n", splitted[y]);
	// splitted[y] = ft_strdup("");
	return (splitted);
}

char	*commands_handler(char **commands)
{
	t_command	command;
	size_t		splitted_height;

	init_command(&command);
	splitted_height = commands_number(commands);
}

int		ft_contain(char *entry, char to_find)
{
	int	i;

	i = 0;
	while (entry[i])
	{
		if (entry[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int		*is_valid_quote(t_quoted *quoted, char *command)
{
	int	i;

	quoted->start = ft_contain(command, '"');
	if ((quoted->start < 0))
		return (0);
	i = quoted->start;
	while (command[i])
	{
		if (command[i] == '"')
		{
			quoted->end = i;
			quoted->q_count++;
		}
		i++;
	}
	if ((quoted->q_count % 2) != 0)
		printf("Invalid quote count\n");
	else if ((quoted->end - (quoted->q_count - 1)) == quoted->start)
		printf("Empty quote\n");
	return (0);
}

int		*is_valid_command(char *command);

int		get_next_redirect(char *command);

char	*command_preparsing(char *entry)
{
	t_quoted	quote;
	char	**commands;
	int		command_id;

	command_id = 0;
	commands = pipe_split_command(entry);
	while (commands[command_id])
	{

	}
	init_quoted(&quote);
}

void	commands_test(char *command)
{
	char	*result;
	pid_t	pid;

	if (ft_str_isequal("path", command))
	{
		result = getenv("PATH");
		printf("PATH = %s\n", result);
	}
	if (ft_str_isequal("pwd", command))
	{
		result = getcwd(NULL, 0);
		printf("pwd = %s\n", result);
	}
	if (ft_str_isequal("npwd", command))
	{
		chdir("/nfs/homes/maricoua/Documents/Envies_de_crever/Projets/minishelAHAHAHAHAHAH/buildins");
		result = getcwd(NULL, 0);
		printf("actual pwd = %s\n", result);
	}
	if (ft_str_isequal("ls", command))
	{
		pid = fork();
		if (pid == 0)
		{ // Processus enfant
			execve("/bin/ls", NULL, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{ // Processus parent
			waitpid(pid, NULL, 0);
		}
		else
		{
			perror("fork");
		}
	}
}

int	main(void)
{
	char		*commands;
	char		**commands_list;
	t_quoted	quote;

	while (1)
	{
		init_quoted(&quote);
		commands = readline("\1\1\1\1\1\2\2\2\2\2\1\033[95m\2\1🌸\2 minishell \1🎀\2 > \1\033[0m\2");
		if (ft_strlen(commands) > 0)
		{
			add_history(commands);
			// commands_test(commands);
			commands_list = pipe_split_command(commands);
			is_valid_quote(&quote, commands_list[0]);
			// while (**commands_list)
			//{
			// printf("commande = %s\n", *commands_list);
			// commands_list++;
			//}
			// commands = commands_handler(commands);
		}
	}
	return (0);
}
