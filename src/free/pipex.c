/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:41:12 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/16 10:46:48 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	free_cmd_members(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->command)
			free(cmd->command);
		if (cmd->pathname)
			free(cmd->pathname);
		if (cmd->arguments)
			ft_free_array((void **)cmd->arguments);
	}
	cmd = NULL;
}

void	free_pipex_members(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->path_array)
			ft_free_array((void **)(pipex->path_array));
		if (pipex->infile_fd != -1)
			close(pipex->infile_fd);
		if (pipex->outfile_fd != -1)
			close(pipex->outfile_fd);
		if (pipex->pipefd[0] != -1)
			close(pipex->pipefd[0]);
		if (pipex->pipefd[1] != -1)
			close(pipex->pipefd[1]);
		free_cmd_members(&(pipex->cmds[0]));
		free_cmd_members(&(pipex->cmds[1]));
	}
}
