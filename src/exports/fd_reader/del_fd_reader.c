/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_fd_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:10:37 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 17:10:37 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_reader.h"

void	del_fd_reader(t_fd_reader **const self_ptr)
{
	(*self_ptr)->vt->dinit(*self_ptr);
	free(*self_ptr);
	(self_ptr) = NULL;
}