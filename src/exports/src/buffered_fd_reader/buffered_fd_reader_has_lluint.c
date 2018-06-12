/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_has_lluint.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:00:19 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 12:00:19 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/buffered_fd_reader.h"

bool	buffered_fd_reader_has_lluint(t_buffered_fd_reader *const self) {
	self->exception = false;
	return (ft_isdigit(self->vt->lookup_char(self)));
}
