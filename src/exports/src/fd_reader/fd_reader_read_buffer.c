/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_read_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:58:42 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 17:58:42 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

void	fd_reader_read_buffer(t_fd_reader *const self)
{
	self->buffer_actual_size = read(self->fd, self->buffer, self->buffer_size);
	self->buffer_i = 0;
}