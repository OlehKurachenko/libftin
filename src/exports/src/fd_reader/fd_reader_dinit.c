/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_dinit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:08:05 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 17:08:05 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

void	fd_reader_dinit(t_fd_reader *const self)
{
	free(self->buffer);
	self->buffer = NULL;
}
