/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_line_delim_to_array.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:27:19 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 14:27:19 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

void	buffered_fd_reader_read_line_delim_to_array(
	t_buffered_fd_reader *const self, char *const array, const size_t limit,
	bool (*const is_delim)(const char))
{
	size_t array_itr;

	self->exception = false;
	array_itr = 0;
	while (self->vt->is_readable(self) && !is_delim(self->vt->lookup_char(self))
			&& array_itr < limit)
	{
		array[array_itr] = self->vt->read_char(self);
		++array_itr;
	}
	if (limit && array_itr != limit)
		array[array_itr] = 0;
}
