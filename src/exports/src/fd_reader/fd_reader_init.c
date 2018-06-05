/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:47:59 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 16:47:59 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

void	fd_reader_init(t_fd_reader *const self, const int fd,
	const size_t buffer_size)
{
	self->vt = &g_fd_reader_vt;
	self->buffer_size = buffer_size;
	self->buffer = (char *)malloc(sizeof(char) * self->buffer_size);
	if (!(self->buffer))
		self->buffer_size = 0;
	self->fd = fd;
	self->buffer_actual_size = 0;
	self->buffer_i = 0;
}
