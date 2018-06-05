/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fd_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:53:35 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 16:53:35 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fd_reader.h"

t_fd_reader						*new_fd_reader(const int fd,
		const size_t buffer_size) {
	t_fd_reader	*this_ptr;

	this_ptr = (t_fd_reader *)malloc(sizeof(t_fd_reader));
	if (!this_ptr)
		return (NULL);
	fd_reader_init(this_ptr);
	return (this_ptr);
}