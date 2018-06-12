/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_str_to_array.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:55:51 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 17:55:51 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static bool		is_delim(const char character)
{
	return (ft_iswhitespace(character));
}

void	buffered_fd_reader_read_str_to_array(t_buffered_fd_reader *const self,
		char *const array, const size_t limit)
{
	self->vt->pass_spaces(self);
	buffered_fd_reader_read_line_delim_to_array(self, array, limit, &is_delim);
	if (!self->exception && self->vt->is_readable(self) &&
			self->vt->lookup_char(self) == '\n')
		self->vt->read_char(self);
}
