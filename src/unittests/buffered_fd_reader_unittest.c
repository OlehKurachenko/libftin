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
#include <string.h>
#include "../exports/includes/buffered_fd_reader.h"

static int print_error_at(const unsigned at)
{
	printf("\033[1;31mError at test section %u.\033[0;0m\n", at);
	return (0);
}

int main() {
	const int fd = open("data/1.txt", O_RDONLY);
	t_buffered_fd_reader *cin = new_buffered_fd_reader(fd, 3, true);

	// test 1
	if (!cin->vt->is_opened(cin))
		return print_error_at(1);
	// test 2
	if (!cin->vt->is_readable(cin))
		return print_error_at(2);
	// test 3
	if (cin->vt->read_char(cin) != 'h' || cin->vt->read_char(cin) != 'i')
		return print_error_at(3);
	// test 4
	if (!cin->vt->has_line(cin))
		return print_error_at(4);
	// test 5
	if (!ft_strequ(cin->vt->read_line(cin), ", frankie"))
		return print_error_at(5);
	// test 6
	if (!ft_strequ(cin->vt->read_line(cin), "i love you)"))
		return print_error_at(6);

	const int arr_n = 20;
	char arr[arr_n];
	// test 7
	cin->vt->read_line_to_array(cin, arr, arr_n); // not safe, of course
	if (!ft_strequ(arr, "kek, lol!"))
		return print_error_at(7);
	// test 8
	cin->vt->read_str_to_array(cin, arr, arr_n); // not safe, of course
	if (!ft_strequ(arr, "sdfs"))
		return print_error_at(8);
	// test 9
	if (!ft_strequ(cin->vt->read_str(cin), "sdfsdf"))
		return print_error_at(9);
	// test 10
	if (!ft_strequ(cin->vt->read_str(cin), "fdsfd"))
		return print_error_at(10);
	// test 11
	if (!cin->vt->has_llint(cin))
		return print_error_at(11);
	// test 12
	//printf("%lld", cin->vt->read_llint(cin));
	if (cin->vt->read_llint(cin) != -3453453)
		return print_error_at(12);
	// test 13
	if (cin->vt->has_llint(cin))
		return print_error_at(13);
	// test 14
	//=printf("%lld", cin->vt->read_llint(cin));
	if (cin->vt->read_llint(cin) != 0)
		return print_error_at(14);
	// test 15
	if (!cin->exception)
		return print_error_at(15);
	// test 16
	cin->vt->read_char(cin);
	if (cin->exception || cin->vt->read_llint(cin) != 34)
		return print_error_at(16);
	// test 17
	if (cin->vt->read_lluint(cin) != 123456789)
		return print_error_at(17);
	// test 18
	if (cin->vt->read_lluint(cin) != 0)
		return print_error_at(18);
	// test 19
	if (!cin->exception)
		return print_error_at(19);

	cin->vt->del(&cin);
	printf("\033[1;32mAll ok!\033[0;0m\n");
	return (0);
}