/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_pass_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:38:33 by okurache          #+#    #+#             */
/*   Updated: 2018/06/13 21:38:33 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

void	buffered_fd_reader_pass_line(t_buffered_fd_reader *const self)
{
	self->exception = false;
	while (self->vt->is_readable(self)
			&& (self->vt->lookup_char(self) != '\n'))
		self->vt->read_char(self);
	if (self->vt->is_readable(self) && (self->vt->lookup_char(self) != '\n'))
		self->vt->read_char(self);
}
