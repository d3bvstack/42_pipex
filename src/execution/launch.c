/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:14:14 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/14 17:28:55 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static void	child_infile_to_pipe(t_pipex *pipex)
{
	pipex->infile_fd = open(pipex->infile, O_RDONLY);
	if (pipex->infile_fd == -1)
		error_generalist(pipex->infile, NULL, pipex);
	dup2(pipex->infile_fd, STDIN_FILENO);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	close(pipex->infile_fd);
	pipex->infile_fd = -1;
	close(pipex->pipefd[0]);
	pipex->pipefd[0] = -1;
	close(pipex->pipefd[1]);
	pipex->pipefd[1] = -1;
	execute_cmd(&(pipex->cmds[0]), pipex);
}

static void	child_pipe_to_outfile(t_pipex *pipex)
{
	pipex->outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (pipex->outfile_fd == -1)
		error_generalist(pipex->outfile, NULL, pipex);
	dup2(pipex->pipefd[0], STDIN_FILENO);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	close(pipex->outfile_fd);
	pipex->outfile_fd = -1;
	close(pipex->pipefd[0]);
	pipex->pipefd[0] = -1;
	close(pipex->pipefd[1]);
	pipex->pipefd[1] = -1;
	execute_cmd(&(pipex->cmds[1]), pipex);
}

static void	parent_process(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	pipex->pipefd[0] = -1;
	close(pipex->pipefd[1]);
	pipex->pipefd[1] = -1;
	waitpid(pipex->pid[0], NULL, 0);
	waitpid(pipex->pid[1], &(pipex->exit_status), 0);
	free_pipex_members(pipex);
	if (WIFEXITED(pipex->exit_status))
		exit(WEXITSTATUS(pipex->exit_status));
	else
		exit(EXIT_SUCCESS);
}

void	execute_launch(t_pipex *pipex)
{
	pipex->pid[0] = fork();
	if (pipex->pid[0] == -1)
		error_generalist("fork", NULL, pipex);
	if (pipex->pid[0] == 0)
		child_infile_to_pipe(pipex);
	pipex->pid[1] = fork();
	if (pipex->pid[1] == -1)
		error_generalist("fork", NULL, pipex);
	if (pipex->pid[1] == 0)
		child_pipe_to_outfile(pipex);
	parent_process(pipex);
}
