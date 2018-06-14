/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_read_lluint.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:03:25 by okurache          #+#    #+#             */
/*   Updated: 2018/06/13 18:03:25 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

long long unsigned	buffered_fd_reader_read_lluint(
	t_buffered_fd_reader *const self)
{
	unsigned long long	result;
	unsigned long long	prev_result;
	bool				is_positive;

	if (self->pass_spaces_to_read)
		self->vt->pass_spaces(self);
	self->exception = false;
	if ((!self->vt->is_readable(self)
		|| !ft_isdigit(self->vt->lookup_char(self)))
		&& (self->exception = true))
		return (0);
	is_positive = true;
	result = 0;
	while (self->vt->has_char(self) && ft_isdigit(self->vt->lookup_char(self)))
	{
		prev_result = result;
		result = 10 * result + (self->vt->read_char(self) - '0');
		if (result / 10 != prev_result && (self->exception = true))
			return (0);
	}
	return (result);
}
