/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_read_llint.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:28:17 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 19:28:17 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

static void		pass_spaces(t_fd_reader *const self)
{
	while (self->buffer_i < self->buffer_actual_size &&
		ft_iswhitespace(self->buffer[self->buffer_i]))
	{
		++self->buffer_i;
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
}

long long		fd_reader_read_llint(t_fd_reader *const self)
{
	long long		res;
	unsigned char	sign;

	res = 0;
	sign = 0;
	if (self->buffer_i >= self->buffer_actual_size)
		self->vt->read_buffer(self);
	pass_spaces(self);
	if (self->buffer_i < self->buffer_actual_size
			&& self->buffer[self->buffer_i] == '-')
	{
		self->buffer_i += (sign = 1);
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
	pass_spaces(self);
	while (self->buffer_i < self->buffer_actual_size
			&& self->buffer[self->buffer_i] >= '0'
			&& self->buffer[self->buffer_i] <= '9')
	{
		res = res * 10 + self->buffer[self->buffer_i++] - '0';
		if (self->buffer_i >= self->buffer_actual_size)
			self->vt->read_buffer(self);
	}
	return ((sign) ? -res : res);
}