/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_pass_spaces.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 06:50:04 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 06:50:04 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

void	buffered_fd_reader_pass_spaces(t_buffered_fd_reader *const self)
{
	self->exception = false;
	while (self->vt->has_char(self)
		&& ft_iswhitespace(self->vt->lookup_char(self)))
		self->vt->read_char(self);
}
