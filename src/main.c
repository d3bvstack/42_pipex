/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:14:41 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/06/16 10:46:30 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	validate_argument_count(argc);
	fill_pipex(&pipex, argc, argv, envp);
	execute_launch(&pipex);
	return (1);
}
