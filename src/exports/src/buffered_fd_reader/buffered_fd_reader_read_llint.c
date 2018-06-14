/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_llint.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 22:16:40 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 22:16:40 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

long long	buffered_fd_reader_read_llint(t_buffered_fd_reader *const self)
{
	unsigned long long	result;
	long long			signed_result;
	bool				is_positive;

	if ((self->exception = !self->vt->is_readable(self)))
		return (0);
	is_positive = true;
	if (self->pass_spaces_to_read)
		self->vt->pass_spaces(self);
	if (self->vt->lookup_char(self) == '+')
		self->vt->read_char(self);
	else if (self->vt->lookup_char(self) == '-')
		is_positive = (self->vt->read_char(self) && false);
	result = self->vt->read_lluint(self);
	if (self->exception)
		return (0);
	signed_result = (is_positive) ? result : -result;
	if ((signed_result < 0 && is_positive)
		|| (signed_result > 0 && !is_positive))
	{
		self->exception = true;
		return (0);
	}
	return (signed_result);
}
