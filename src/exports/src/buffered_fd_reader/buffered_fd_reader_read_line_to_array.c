/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_line_to_array.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:38:31 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 13:38:31 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static bool	is_delim(const char character)
{
	return (character == '\n');
}

void	buffered_fd_reader_read_line_to_array(t_buffered_fd_reader *const self,
	char *const array, const size_t limit)
{
	buffered_fd_reader_read_line_delim_to_array(self, array, limit, &is_delim);
	if (!self->exception && self->vt->is_readable(self) &&
		self->vt->lookup_char(self) == '\n')
		self->vt->read_char(self);
}
