/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:18:02 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/16 11:34:53 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include "./pipex_structs.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// Validate argument count
void	validate_argument_count(int argc);

// Initialization and Initialization Utils
void	fill_pipex(t_pipex *pipex, int argc, char **argv, char **envp);
char	**retrieve_path_array(char **envp);
char	*retrieve_command(t_pipex *pipex, int i);
char	**retrieve_arguments(t_pipex *pipex, int i);
char	*retrieve_pathname(t_pipex *pipex, t_cmd *cmd);

// Execution
void	execute_launch(t_pipex *pipex);
void	execute_cmd(t_cmd *cmd, t_pipex *pipex);

// Free
void	free_pipex_members(t_pipex *pipex);
void	free_cmd_members(t_cmd *cmd);

// Errors
void	syntax_error(void);
void	malloc_error(t_pipex *pipex);
void	error_generalist(char *origin, t_pipex *pipex);
void	error_cmd_not_found(t_cmd *cmd, t_pipex *pipex);

#endif