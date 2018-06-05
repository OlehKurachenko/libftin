/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader_is_opened.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:42:26 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 17:42:26 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fd_reader.h"

unsigned char	fd_reader_is_opened(t_fd_reader *const self)
{
	if (read(self->fd, NULL, 0) == -1)
		return (0);
	return (1);
}
