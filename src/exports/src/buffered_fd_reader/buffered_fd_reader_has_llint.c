/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_has_llint.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:11:47 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 11:11:47 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static void	pull_buffer(t_buffered_fd_reader *const self)
{
	if (self->buffer_i + 1 < self->buffer_actual_size)
		return ;
	if (self->buffer_actual_size >= self->buffer_size)
	{
		self->buffer[0] = self->buffer[self->buffer_i];
		self->buffer_actual_size = 1;
		self->buffer_i = 0;
	}
	if (read(self->fd, self->buffer + self->buffer_actual_size, 1) == 1)
		++self->buffer_actual_size;
}

bool		buffered_fd_reader_has_llint(t_buffered_fd_reader *const self)
{
	self->exception = false;
	if (self->pass_spaces_in_has)
		self->vt->pass_spaces(self);
	if (!self->vt->is_readable(self))
		return (false);
	if (ft_isdigit(self->vt->lookup_char(self)))
		return (true);
	if (self->vt->lookup_char(self) == '+'
		|| self->vt->lookup_char(self) == '-')
	{
		pull_buffer(self);
		if (self->buffer_i + 1 < self->buffer_actual_size)
			return ft_isdigit(self->buffer[self->buffer_i + 1]);
	}
	return (false);
}
