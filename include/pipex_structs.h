/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:08:42 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/14 17:17:58 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCTS_H
# define PIPEX_STRUCTS_H

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	char				*command;
	char				*pathname;
	char				**arguments;
	int					is_pathname;
}						t_cmd;

typedef struct s_pipex
{
	char				**envp;
	char				**argv;
	char				**path_array;
	int					pipefd[2];
	char				*infile;
	int					infile_fd;
	char				*outfile;
	int					outfile_fd;
	int					pid[2];
	int					exit_status;
	t_cmd				cmds[2];
}						t_pipex;

#endif