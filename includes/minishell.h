/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorouger <jorouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:21:29 by jorouger          #+#    #+#             */
/*   Updated: 2025/03/27 14:11:57 by jorouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

/*------------------------------------Struct----------------------------------*/

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

typedef struct s_quoted
{
	int		q_count;
	int 	start;
	int		end;
}	t_quoted;

/*------------------------------------Utils-----------------------------------*/

int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *src);

/*-----------------------------------Bultins----------------------------------*/

int		echo_builtin(t_command *command, char **arg);



#endif