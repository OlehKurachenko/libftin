/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 00:55:10 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 00:55:10 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

static void	init_super_virtual_tables(t_buffered_fd_reader *const self)
{
	self->super.vt = (t_abstract_reader_vtbl *)&g_buffered_fd_reader_vt;
}

void		buffered_fd_reader_init(t_buffered_fd_reader *const self,
	const int fd, const size_t buffer_size, const bool pass_spaces_in_has)
{
	self->vt = &g_buffered_fd_reader_vt;
	init_super_virtual_tables(self);
	self->exception = false;
	if (!buffer_size)
	{
		self->exception = true;
		return ;
	}
	self->buffer_size = buffer_size;
	self->buffer = (char *)malloc(sizeof(char) * self->buffer_size);
	if (!self->buffer)
	{
		self->exception = true;
		return ;
	}
	self->fd = fd;
	self->pass_spaces_in_has = pass_spaces_in_has;
	self->buffer_actual_size = 0;
	self->buffer_i = 0;
	self->pass_spaces_to_read = true;
}
