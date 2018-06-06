/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_pass_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 01:26:18 by okurache          #+#    #+#             */
/*   Updated: 2018/06/07 01:26:18 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

void	fd_reader_pass_line(t_fd_reader *const self)
{
	while (self->vt->is_readable(self)
		&& (self->buffer[self->buffer_i] != '\n'))
	{
		++(self->buffer_i);
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
	if (self->vt->is_readable(self) && (self->buffer[self->buffer_i] == '\n'))
		++(self->buffer_i);
}