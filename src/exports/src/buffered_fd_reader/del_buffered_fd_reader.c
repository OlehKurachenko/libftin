/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_buffered_fd_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 03:05:57 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 03:05:57 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffered_fd_reader.h"

void	del_buffered_fd_reader(t_buffered_fd_reader **const self_ptr)
{
	(*self_ptr)->vt->dinit(*self_ptr);
	free(*self_ptr);
	*self_ptr = NULL;
}
