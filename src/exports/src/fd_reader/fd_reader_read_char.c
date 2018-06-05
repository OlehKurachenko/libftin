/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_read_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:08:17 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 19:08:17 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

char			fd_reader_read_char(t_fd_reader *const self)
{
	if (self->buffer_i >= self->buffer_actual_size)
		self->vt->read_buffer(self);
	if (self->buffer_i >= self->buffer_actual_size)
		return (0);
	return self->buffer[self->buffer_i++];
}