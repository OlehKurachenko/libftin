/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_ldouble.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 21:18:18 by okurache          #+#    #+#             */
/*   Updated: 2018/06/13 21:18:18 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

long double		buffered_fd_reader_read_ldouble(
	t_buffered_fd_reader *const self)
{
	long double	result;
	long double	multiplier;
	bool		is_positive;

	if (self->pass_spaces_to_read)
		self->vt->pass_spaces(self);
	if ((self->exception = !self->vt->is_readable(self)))
		return (0);
	is_positive = true;
	if (self->vt->lookup_char(self) == '+')
		self->vt->read_char(self);
	else if (self->vt->lookup_char(self) == '-')
		is_positive = (self->vt->read_char(self) && false);
	if (self->pass_spaces_to_read)
		self->vt->pass_spaces(self);
	result = 0;
	while (self->vt->has_char(self) && ft_isdigit(self->vt->lookup_char(self)))
		result = 10 * result + (self->vt->read_char(self) - '0');
	if (!(self->vt->has_char(self) && self->vt->lookup_char(self) == '.'))
		return (result);
	multiplier = 1 + 0 * (self->vt->read_char(self));
	while ((multiplier *= 0.1) && self->vt->has_char(self)
			&& ft_isdigit(self->vt->lookup_char(self)))
		result += multiplier * (self->vt->read_char(self) - '0');
	return ((is_positive) ? result : -result);
}
