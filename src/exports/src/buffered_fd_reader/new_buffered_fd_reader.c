/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffered_fd_reader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 02:29:42 by okurache          #+#    #+#             */
/*   Updated: 2018/06/10 02:29:42 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffered_fd_reader.h"

t_buffered_fd_reader	*new_buffered_fd_reader(const int fd,
	const size_t buffer_size)
{
	t_buffered_fd_reader *this_ptr;

	this_ptr = (t_buffered_fd_reader *)malloc(sizeof(t_buffered_fd_reader));
	if (!this_ptr)
		return (NULL);
	buffered_fd_reader_init(this_ptr, fd, buffer_size);
	if (this_ptr->exception == true)
	{
		free(this_ptr);
		return (NULL);
	}
	return (this_ptr);
}
