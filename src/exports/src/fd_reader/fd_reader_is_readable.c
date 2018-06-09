/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_is_readable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:03:06 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 18:03:06 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

bool	fd_reader_is_readable(t_fd_reader *const self)
{
	if (self->buffer_i >= self->buffer_actual_size)
		self->vt->read_buffer(self);
	return (self->buffer_i < self->buffer_actual_size);
}
