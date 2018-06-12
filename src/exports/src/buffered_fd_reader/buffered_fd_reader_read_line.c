/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:09:47 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 13:09:47 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static bool		is_delim(const char character)
{
	return character == '\n';
}

char 			*buffered_fd_reader_read_line(t_buffered_fd_reader *const self)
{
	char	*temp_ptr;

	self->exception = false;
	temp_ptr = self->vt->read_line_delim(self, &is_delim);
	if (!self->exception && self->vt->is_readable(self)
		&& self->vt->lookup_char(self) == '\n')
			self->vt->read_char(self);
	return (temp_ptr);
}
