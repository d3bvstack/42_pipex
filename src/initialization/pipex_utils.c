/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:50:50 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/14 17:17:32 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*retrieve_pathname(t_pipex *pipex, t_cmd *cmd)
{
	char	*pathname;
	int		i;

	if (strchr(cmd->command, '/'))
	{
		cmd->is_pathname = 1;
		return (ft_strdup(cmd->command));
	}
	cmd->is_pathname = 0;
	if (!pipex->path_array)
		return (NULL);
	i = 0;
	while (pipex->path_array[i])
	{
		pathname = ft_strjoin_three(pipex->path_array[i], "/", cmd->command);
		if (access(pathname, F_OK) == 0)
			return (pathname);
		free(pathname);
		i++;
	}
	return (NULL);
}

static char	*get_arguments(t_pipex *pipex, int i)
{
	char	**array;
	char 	*tmp;
	char	*arguments_string;
	int		j;

	array = ft_split(pipex->argv[i], ' ');
	if (!array)
		malloc_error(pipex);
	arguments_string = NULL;
	if (array[1])
	{
		arguments_string = ft_strdup(array[1]);
		j = 2;
		while (array[j])
		{
			tmp = arguments_string;
			arguments_string = ft_strjoin_three(arguments_string, " ", array[j]);
			free(tmp);
			j++;
		}
	}
	ft_free_array((void **)array);
	return (arguments_string);
}

char	**retrieve_arguments(t_pipex *pipex, int i)
{
	char	**arguments_array;

	arguments_array = ft_calloc(3, sizeof(char *));
	if (!arguments_array)
		malloc_error(pipex);
	arguments_array[0] = retrieve_command(pipex, i);
	arguments_array[1] = get_arguments(pipex, i);
	arguments_array[2] = 0;
	return (arguments_array);
}

char	*retrieve_command(t_pipex *pipex, int i)
{
	int	start;
	int	length;

	start = 0;
	length = 0;
	while (pipex->argv[i][start] == ' ')
	{
		start++;
	}
	while (pipex->argv[i][start + length] && pipex->argv[i][start
		+ length] != ' ')
	{
		length++;
	}
	return (ft_substr(pipex->argv[i], start, length));
}

char	**retrieve_path_array(char **envp)
{
	int i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}