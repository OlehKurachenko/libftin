/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffered_fd_reader.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 23:24:29 by okurache          #+#    #+#             */
/*   Updated: 2018/06/09 23:24:29 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  class buffered_fd_reader : abstract class abstract_reader
**
**  Buffered reader which reads from opened (using "open") stream by its
**	fd using "read"
**
**	Buffer size have to be at least 1.
**
**	Written in accordance to 42_c_oop standard
**	https://github.com/OlehKurachenko/42_c_oop-standard
*/

#ifndef BUFFERED_FD_READER_H
# define BUFFERED_FD_READER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "../../../imports/okurache_libft/libft.h"

# include "abstract_reader.h"

typedef struct s_buffered_fd_reader	t_buffered_fd_reader;

struct								s_buffered_fd_reader {
	t_abstract_reader						super;

	const struct s_buffered_fd_reader_vtbl	*vt;

	bool									exception;

	int										fd;
	size_t									buffer_size;
	char									*buffer;
	size_t									buffer_actual_size;
	size_t									buffer_i;
	bool									pass_spaces_in_has;
	bool									pass_spaces_to_read;
};

/*
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: ok, okurache 13 june 2018
*/

typedef struct						s_buffered_fd_reader_vtbl {
	void				(*const dinit)(t_buffered_fd_reader *const self);

	void				(*const del)(t_buffered_fd_reader **const self_ptr);

	bool				(*const is_opened)(t_buffered_fd_reader *const self);

	bool				(*const is_readable)(t_buffered_fd_reader *const self);

	bool				(*const has_line)(t_buffered_fd_reader *const self);

	bool				(*const has_char)(t_buffered_fd_reader *const self);

	bool				(*const has_str)(t_buffered_fd_reader *const self);

	bool				(*const has_llint)(t_buffered_fd_reader *const self);

	bool				(*const has_lluint)(t_buffered_fd_reader *const self);

	bool				(*const has_ldouble)(t_buffered_fd_reader *const self);

	char				(*const read_char)(t_buffered_fd_reader *const self);

	char				*(*const read_line)(t_buffered_fd_reader *const self);

	void				(*const read_line_to_array)(
		t_buffered_fd_reader *const self,
		char *const array, const size_t limit);

	char				*(*const read_str)(t_buffered_fd_reader *const self);

	void				(*const read_str_to_array)(
		t_buffered_fd_reader *const self,
		char *const array, const size_t limit);

	long long			(*const read_llint)(t_buffered_fd_reader *const self);

	long long unsigned	(*const read_lluint)(t_buffered_fd_reader *const self);

	long double			(*const read_ldouble)(t_buffered_fd_reader *const self);

	char				(*const lookup_char)(t_buffered_fd_reader *const self);

	void				(*const pass_spaces)(t_buffered_fd_reader *const self);

	char				*(*const read_line_delim)(
		t_buffered_fd_reader *const self, bool (*const is_delim)(const char));

	void				(*const read_line_delim_to_array)(
		t_buffered_fd_reader *const self, char *const array, const size_t limit,
		bool (*const is_delim)(const char));

	void				(*const pass_line)(t_buffered_fd_reader *const self);

	void				(*const read_buffer)(t_buffered_fd_reader *const self);
}									t_buffered_fd_reader_vtbl;

/*
**  public:
*/

t_buffered_fd_reader				*new_buffered_fd_reader(
	const int fd, const size_t buffer_size, const bool pass_spaces_in_has);

void								buffered_fd_reader_init(
	t_buffered_fd_reader *const self,
	const int fd, const size_t buffer_size, const bool pass_spaces_in_has);

void								del_buffered_fd_reader(
	t_buffered_fd_reader **const self_ptr);

void								buffered_fd_reader_dinit(
	t_buffered_fd_reader *const self);

bool								buffered_fd_reader_is_opened(
	t_buffered_fd_reader *const self);

bool								buffered_fd_reader_is_readable(
	t_buffered_fd_reader *const self);

bool								buffered_fd_reader_has_str(
	t_buffered_fd_reader *const self);

bool								buffered_fd_reader_has_llint(
	t_buffered_fd_reader *const self);

bool								buffered_fd_reader_has_lluint(
	t_buffered_fd_reader *const self);

char								buffered_fd_reader_read_char(
	t_buffered_fd_reader *const self);

char								*buffered_fd_reader_read_line(
	t_buffered_fd_reader *const self);

void								buffered_fd_reader_read_line_to_array(
	t_buffered_fd_reader *const self,
	char *const array, const size_t limit);

char								*buffered_fd_reader_read_str(
	t_buffered_fd_reader *const self);

void								buffered_fd_reader_read_str_to_array(
	t_buffered_fd_reader *const self, char *const array, const size_t limit);

long long							buffered_fd_reader_read_llint(
	t_buffered_fd_reader *const self);

long long unsigned					buffered_fd_reader_read_lluint(
	t_buffered_fd_reader *const self);

long double							buffered_fd_reader_read_ldouble(
	t_buffered_fd_reader *const self);

char								buffered_fd_reader_lookup_char(
	t_buffered_fd_reader *const self);

void								buffered_fd_reader_pass_spaces(
	t_buffered_fd_reader *const self);

char								*buffered_fd_reader_read_line_delim(
	t_buffered_fd_reader *const self, bool (*const is_delim)(const char));

void								buffered_fd_reader_read_line_delim_to_array(
	t_buffered_fd_reader *const self, char *const array, const size_t limit,
	bool (*const is_delim)(const char));

void								buffered_fd_reader_pass_line(
	t_buffered_fd_reader *const self);

/*
**  private:
*/

void								buffered_fd_reader_read_buffer(
	t_buffered_fd_reader *const self);

/*
**  virtual table
**
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: ckecked, okurache june 13 2018
*/

static
const t_buffered_fd_reader_vtbl		g_buffered_fd_reader_vt = {
	&buffered_fd_reader_dinit,
	&del_buffered_fd_reader,
	&buffered_fd_reader_is_opened,
	&buffered_fd_reader_is_readable,
	&buffered_fd_reader_is_readable,
	&buffered_fd_reader_is_readable,
	&buffered_fd_reader_has_str,
	&buffered_fd_reader_has_llint,
	&buffered_fd_reader_has_lluint,
	&buffered_fd_reader_has_llint,
	&buffered_fd_reader_read_char,
	&buffered_fd_reader_read_line,
	&buffered_fd_reader_read_line_to_array,
	&buffered_fd_reader_read_str,
	&buffered_fd_reader_read_str_to_array,
	&buffered_fd_reader_read_llint,
	&buffered_fd_reader_read_lluint,
	&buffered_fd_reader_read_ldouble,
	&buffered_fd_reader_lookup_char,
	&buffered_fd_reader_pass_spaces,
	&buffered_fd_reader_read_line_delim,
	&buffered_fd_reader_read_line_delim_to_array,
	&buffered_fd_reader_pass_line,
	&buffered_fd_reader_read_buffer
};

#endif
