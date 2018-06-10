/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_buffer.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:24:44 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 05:24:44 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

void	buffered_fd_reader_read_buffer(t_buffered_fd_reader *const self)
{
	self->buffer_actual_size = read(self->fd, self->buffer, self->buffer_size);
	self->buffer_i = 0;
}
