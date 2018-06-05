/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_read_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:18:39 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 18:18:39 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

static char 	*resize_new_line(char **const new_line_ptr, size_t *const
new_line_size_ptr)
{
	char 	*temp_new_line;

	temp_new_line = (char *)malloc(sizeof(char) * (*new_line_size_ptr * 2));
	if (temp_new_line == NULL)
	{
		free(*new_line_ptr);
		return (NULL);
	}
	ft_strncpy(temp_new_line, *new_line_ptr, *new_line_size_ptr);
	*new_line_size_ptr *= 2;
	free(*new_line_ptr);
	*new_line_ptr = temp_new_line;
	return temp_new_line;
}

static char		*reshape_new_line(char **const new_line_ptr, const size_t
new_line_size)
{
	char 	*temp_new_line;

	temp_new_line = (char *)malloc(sizeof(char) * (new_line_size + 1));
	temp_new_line[new_line_size] = 0;
	ft_strncpy(temp_new_line, *new_line_ptr, new_line_size);
	free(*new_line_ptr);
	*new_line_ptr = temp_new_line;
	return temp_new_line;
}

char			*fd_reader_read_line(t_fd_reader *const self)
{
	char 	*new_line;
	size_t	new_line_i;
	size_t	new_line_size;

	new_line_i = 0;
	new_line_size = self->buffer_size;
	new_line = (char *)malloc(sizeof(char) * new_line_size);
	if (!new_line)
		return (NULL);
	if (self->buffer_i >= self->buffer_actual_size)
		self->vt->read_buffer(self);
	while (self->buffer_i < self->buffer_actual_size
			&& self->buffer[self->buffer_i] != '\n')
	{
		if (new_line_i == new_line_size)
			if (!resize_new_line(&new_line, &new_line_size))
				return (NULL);
		new_line[new_line_i++] = self->buffer[self->buffer_i++];
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
	if (self->buffer_i < self->buffer_actual_size
			&& self->buffer[self->buffer_i] == '\n')
		++self->buffer_i;
	return (reshape_new_line(&new_line, new_line_i));
}