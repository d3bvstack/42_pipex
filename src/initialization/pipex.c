/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:17:46 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/14 17:17:27 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	fill_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->envp = envp;
	pipex->argv = argv;
	pipex->path_array = retrieve_path_array(envp);
	if (pipe(pipex->pipefd) == -1)
		error_generalist("pipe", NULL, pipex);
	pipex->infile = argv[1];
	pipex->infile_fd = -1;
	pipex->outfile = argv[argc - 1];
	pipex->outfile_fd = -1;
	pipex->exit_status = 0;
	//
	pipex->cmds[0].command = retrieve_command(pipex, 2);
	pipex->cmds[0].arguments = retrieve_arguments(pipex, 2);
	pipex->cmds[0].pathname = retrieve_pathname(pipex, &(pipex->cmds[0]));
	
	pipex->cmds[1].command = retrieve_command(pipex, 3);
	pipex->cmds[1].arguments = retrieve_arguments(pipex, 3); 
	pipex->cmds[1].pathname = retrieve_pathname(pipex, &(pipex->cmds[1]));
}
