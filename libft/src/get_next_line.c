/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbarba-v <dbarba-v@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:55:35 by dbarba-v          #+#    #+#             */
/*   Updated: 2025/04/13 15:20:32 by dbarba-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/* Function declarations */
static char	*extract_line(char *newline, char **storage);
static int	fill_storage(int fd, char **storage);
static char	*handle_remaining(char **storage);
static char	*process_storage(int fd, char **storage);
char		*get_next_line(int fd);

/// @brief Extracts a line from storage up to and including newline character
/// @param newline Pointer to the newline character in storage
/// @param storage Pointer to the buffer containing read data
/// @return Line including newline character, or NULL on allocation failure
static char	*extract_line(char *newline, char **storage)
{
	char	*line;
	char	*new_storage;

	line = ft_substr(*storage, 0, (newline - *storage) + 1);
	if (!line)
	{
		ft_free((void *)storage, NULL);
		return (NULL);
	}
	if (*(newline + 1) == '\0')
		new_storage = NULL;
	else
	{
		new_storage = ft_strdup(newline + 1);
		if (!new_storage)
		{
			free(line);
			ft_free((void *)storage, NULL);
			return (NULL);
		}
	}
	ft_free((void *)storage, new_storage);
	return (line);
}

/// @brief Reads from file descriptor into a new buffer and updates storage
/// @param fd File descriptor to read from
/// @param storage Pointer to the string containing previously read characters
/// @return Number of bytes read or -1 on error
static int	fill_storage(int fd, char **storage)
{
	char	*new_storage;
	size_t	strg_len;
	long	read_bytes;

	strg_len = ft_strlen(*storage);
	new_storage = ft_calloc(sizeof(char), strg_len + BUFFER_SIZE + 1);
	if (!new_storage)
	{
		ft_free((void *)storage, NULL);
		return (-1);
	}
	if (*storage)
		ft_strlcpy(new_storage, *storage, strg_len + 1);
	read_bytes = read(fd, new_storage + strg_len, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(new_storage);
		new_storage = NULL;
	}
	ft_free((void *)storage, new_storage);
	return (read_bytes);
}

/// @brief Handles end of file or read error conditions
/// @param storage Pointer to buffer containing any remaining characters
/// @return The remaining content as a new string, or NULL if empty/error
static char	*handle_remaining(char **storage)
{
	char	*line;

	if (*storage && **storage)
	{
		line = ft_strdup(*storage);
		ft_free((void *)storage, NULL);
		return (line);
	}
	ft_free((void *)storage, NULL);
	return (NULL);
}

/// @brief Processes stored data to extract the next line
/// @param fd File descriptor to read from if newline not found in storage
/// @param storage Pointer to buffer containing previously read data
/// @return Next line if found, NULL if EOF reached or on error
static char	*process_storage(int fd, char **storage)
{
	char	*newline_ch;
	long	read_bytes;

	while (1)
	{
		newline_ch = ft_strchr(*storage, '\n');
		if (newline_ch)
			return (extract_line(newline_ch, storage));
		read_bytes = fill_storage(fd, storage);
		if (read_bytes <= 0)
			return (handle_remaining(storage));
	}
}

/// @brief Reads and returns the next line from a file descriptor
/// @param fd File descriptor to read from
/// @return Next line including newline character, or NULL on error/EOF
char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	return (process_storage(fd, &storage[fd]));
}
