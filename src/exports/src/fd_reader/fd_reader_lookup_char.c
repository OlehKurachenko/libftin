/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_lookup_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 04:04:46 by okurache          #+#    #+#             */
/*   Updated: 2018/06/09 04:04:46 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

char	fd_reader_lookup_char(t_fd_reader *const self)
{
	if (!self->vt->is_readable(self))
		return (0);
	return (self->buffer[self->buffer_i]);
}