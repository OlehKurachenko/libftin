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
**	The buffer of buffer_size+1 is being allocated dynamically. Buffer size
**	have to be at least 1.
**
**	Extra size is used to lookup two chars when checking "has_llint"
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

typedef struct s_buffered_fd_reader			t_buffered_fd_reader;

typedef struct s_buffered_fd_reader_vtbl	t_buffered_fd_reader_vtbl;

struct										s_buffered_fd_reader {
	t_abstract_reader				super;

	const t_buffered_fd_reader_vtbl	*vt;

	bool							exception;

	int								fd;
	size_t							buffer_size;
	char 							*buffer;
	size_t							buffer_actual_size;
	size_t							buffer_i;
};

/*
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: TODO check
*/

struct										s_buffered_fd_reader_vtbl {
	void	(*const dinit)(t_buffered_fd_reader *const self);

	void	(*const del)(t_buffered_fd_reader **const self_ptr);

	bool	(*const is_opened)(t_buffered_fd_reader *const self);

	bool	(*const is_readable)(t_buffered_fd_reader *const self);

	// private

	void	(*const read_buffer)(t_buffered_fd_reader *const self);

	//  TODO here types of member function pointers goes
};

/*
**  public:
*/

t_buffered_fd_reader						*new_buffered_fd_reader(
	const int fd, const size_t buffer_size);

void										buffered_fd_reader_init(
	t_buffered_fd_reader *const self,
	const int fd, const size_t buffer_size);

void										del_buffered_fd_reader(
	t_buffered_fd_reader **const self_ptr);

void										buffered_fd_reader_dinit(
	t_buffered_fd_reader *const self);

bool										buffered_fd_reader_is_opened(
	t_buffered_fd_reader *const self);

bool										buffered_fd_reader_is_readable(
	t_buffered_fd_reader *const self);

// TODO public methods prototypes goes here

/*
**  private:
*/

void										buffered_fd_reader_read_buffer(
	t_buffered_fd_reader *const self);

/*
**  virtual table
**
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: TODO check
*/

static const t_buffered_fd_reader_vtbl g_buffered_fd_reader_vt = {
		&buffered_fd_reader_dinit,
		&del_buffered_fd_reader,
		&buffered_fd_reader_is_opened,
		&buffered_fd_reader_is_readable,
		// TODO member function addresses goes here
		&buffered_fd_reader_read_buffer
};

#endif