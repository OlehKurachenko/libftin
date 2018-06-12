/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader_unittest.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:43:55 by okurache          #+#    #+#             */
/*   Updated: 2018/06/12 11:43:55 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include "../exports/includes/buffered_fd_reader.h"

static int print_error_at(const unsigned at)
{
	printf("\033[1;31mError at test section %u.\033[0;0m\n", at);
	return (0);
}

int main() {
	const int fd = open("data/1.txt", O_RDONLY);
	t_buffered_fd_reader *cin = new_buffered_fd_reader(fd, 128, true);

	// test 1
	if (!cin->vt->is_opened(cin))
		return print_error_at(1);
	// test 2
	if (!cin->vt->is_readable(cin))
		return print_error_at(2);
	// test 3
	if (cin->vt->read_char(cin) != 'h' || cin->vt->read_char(cin) != 'i')
		return print_error_at(3);

	cin->vt->del(&cin);
	printf("\033[1;32mAll ok!\033[0;0m\n");
	return (0);
}