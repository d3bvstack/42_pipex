/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:45:53 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/16 11:34:06 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	execute_cmd(t_cmd *cmd, t_pipex *pipex)
{
	char	*pathname;

	pathname = cmd->pathname;
	if (pathname == NULL)
		pathname = cmd->command;
	if (pipex->path_array == NULL || cmd->is_pathname == 1)
	{
		if (execve(pathname, cmd->arguments, pipex->envp) == -1)
			error_generalist(cmd->command, pipex);
	}
	if (execve(pathname, cmd->arguments, pipex->envp) == -1)
	{
		if (errno == ENOENT)
			error_cmd_not_found(cmd, pipex);
		else
			error_generalist(cmd->command, pipex);
	}
}
