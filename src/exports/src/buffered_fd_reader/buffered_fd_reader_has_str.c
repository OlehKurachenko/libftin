/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_has_str.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 06:11:51 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 06:11:51 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

bool	buffered_fd_reader_has_str(t_buffered_fd_reader *const self)
{
	self->exception = false;
	if (self->pass_spaces_in_has)
	{
		self->vt->pass_spaces(self);
		return (self->vt->has_char(self));
	}
	return (self->vt->has_char(self)
		&& !ft_iswhitespace(self->vt->lookup_char(self)));
}
