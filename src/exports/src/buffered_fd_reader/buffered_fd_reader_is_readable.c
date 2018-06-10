/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_is_readable.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:30:25 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 05:30:25 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

bool	buffered_fd_reader_is_readable(t_buffered_fd_reader *const self)
{
	self->exception = false;
	if (self->buffer_i >= self->buffer_actual_size)
		self->vt->read_buffer(self);
	return (self->buffer_i < self->buffer_actual_size);
}
