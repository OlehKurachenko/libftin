/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_dinit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 02:08:14 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 02:08:14 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

void	buffered_fd_reader_dinit(t_buffered_fd_reader *const self)
{
	free(self->buffer);
	self->buffer = NULL;
}
