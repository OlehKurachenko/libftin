/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_line_delim.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:57:07 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 13:57:07 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static char		*resize_new_line(char **const new_line_ptr,
		size_t *const new_line_size_ptr)
{
	char	*temp_new_line;

	temp_new_line = (char *)malloc(sizeof(char) * (*new_line_size_ptr * 2));
	if (temp_new_line == NULL)
		return (NULL);
	ft_strncpy(temp_new_line, *new_line_ptr, *new_line_size_ptr);
	*new_line_size_ptr *= 2;
	free(*new_line_ptr);
	*new_line_ptr = temp_new_line;
	return (temp_new_line);
}

static void		reshape_new_line(char **const new_line_ptr,
		const size_t new_line_size)
{
	char	*temp_new_line;

	temp_new_line = (char *)malloc(sizeof(char) * (new_line_size + 1));
	if (!temp_new_line)
		return ;
	temp_new_line[new_line_size] = 0;
	ft_strncpy(temp_new_line, *new_line_ptr, new_line_size);
	free(*new_line_ptr);
	*new_line_ptr = temp_new_line;
}

char	*buffered_fd_reader_read_line_delim(
		t_buffered_fd_reader *const self, bool (*const is_delim)(const char)) {
	char	*new_line;
	size_t	new_line_i;
	size_t	new_line_size;

	self->exception = false;
	new_line_i = 0;
	new_line_size = self->buffer_size;
	new_line = (char *)malloc(sizeof(char) * new_line_size);
	if (!new_line && (self->exception = true))
		return (NULL);
	while (self->vt->is_readable(self) &&
		!is_delim(self->vt->lookup_char(self)))
	{
		if (new_line_i == new_line_size)
			if (!resize_new_line(&new_line, &new_line_size)
					&& (self->exception = true))
			{
				free(new_line);
				return (NULL);
			}
		new_line[new_line_i++] = self->vt->read_char(self);
	}
	reshape_new_line(&new_line, new_line_i);
	return (new_line);
}
