/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:59:31 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/14 17:29:00 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	error_cmd_not_found(t_cmd *cmd)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(cmd->command, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	free_cmd_members(cmd);
	exit(127);
}

void	malloc_error(t_pipex *pipex)
{
	perror("Error allocating memory");
	free_pipex_members(pipex);
	exit(EXIT_FAILURE);
}

void	error_generalist(char *origin, t_pipex *pipex)
{
	const char	*error_str = strerror(errno);

	ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (origin && *origin)
	{
		ft_putstr_fd(origin, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putendl_fd((char *)error_str, STDERR_FILENO);
	free_pipex_members(pipex);
	if (errno == ENOENT)
		exit(127);
	exit(EXIT_FAILURE);
}

void	syntax_error(void)
{
	ft_putendl_fd("Incorrect syntax", STDERR_FILENO);
	ft_putendl_fd("Use: ./pipex infile \"cmd1\" \"cmd2\" outfile",
		STDERR_FILENO);
	exit(EXIT_FAILURE);
}
