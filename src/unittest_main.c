/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest_main.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:14:26 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 17:14:26 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "exports/libftin.h"

int main() {
	t_fd_reader reader1;

	const int fd = 0;

	fd_reader_init(&reader1, fd, 100);
	printf("fd=%d: is opened=%d\n", fd, reader1.vt->is_opened(&reader1));
	printf("fd=%d: is readable=%d\n", fd, reader1.vt->is_readable(&reader1));

	printf("char 1 = %d\n", reader1.vt->read_char(&reader1));
	fflush(stdout);
	printf("char 2 = %d\n", reader1.vt->read_char(&reader1));
	fflush(stdout);
	printf("char 3 = %d\n", reader1.vt->read_char(&reader1));
	fflush(stdout);

	printf("line 1 = %s\n", reader1.vt->read_line(&reader1));
	fflush(stdout);
	printf("line 2 = %s\n", reader1.vt->read_line(&reader1));
	fflush(stdout);
	printf("line 3 = %s\n", reader1.vt->read_line(&reader1));
	fflush(stdout);

	printf("int 1 = %lld\n", reader1.vt->read_llint(&reader1));
	fflush(stdout);
	printf("int 2 = %lld\n", reader1.vt->read_llint(&reader1));
	fflush(stdout);
	printf("int 3 = %lld\n", reader1.vt->read_llint(&reader1));
	fflush(stdout);

	reader1.vt->dinit(&reader1);
}