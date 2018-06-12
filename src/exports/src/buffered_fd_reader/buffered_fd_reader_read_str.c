/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_str.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:49:04 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 14:49:04 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static bool		is_delim(const char character)
{
	return (ft_iswhitespace(character));
}

char	*buffered_fd_reader_read_str(t_buffered_fd_reader *const self)
{
	char	*temp_ptr;

	self->exception = false;
	self->vt->pass_spaces(self);
	temp_ptr = self->vt->read_line_delim(self, &is_delim);
	if (!self->exception && self->vt->is_readable(self)
			&& self->vt->lookup_char(self) == '\n')
		self->vt->read_char(self);
	return (temp_ptr);
}
