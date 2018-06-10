/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_is_opened.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 05:03:50 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 05:03:50 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

bool	buffered_fd_reader_is_opened(t_buffered_fd_reader *const self)
{
	self->exception = 0;
	if (read(self->fd, NULL, 0) == -1)
		return (false);
	return (true);
}
