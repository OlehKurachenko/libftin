/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_read_line_to_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:29:33 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 21:29:33 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

void	fd_reader_read_line_to_array(t_fd_reader *const self,
		char *const array, const size_t limit)
{
	size_t array_itr;

	array_itr = 0;
	while (self->vt->is_readable(self) && (self->buffer[self->buffer_i] != '\n')
		&& array_itr < (limit - 1))
	{
		array[array_itr] = self->buffer[self->buffer_i];
		++array_itr;
		++(self->buffer_i);
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
	if (self->vt->is_readable(self) && (self->buffer[self->buffer_i] == '\n'))
		++(self->buffer_i);
	if (limit)
		array[array_itr] = 0;
}
