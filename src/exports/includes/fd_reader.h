/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:53:25 by okurache          #+#    #+#             */
/*   Updated: 2018/06/05 15:53:25 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTIN_FD_READER_H
# define LIBFTIN_FD_READER_H

# include <stdlib.h>
# include <unistd.h>
# include "../../../imports/okurache_libft/libft.h"

typedef struct s_fd_reader		t_fd_reader;

typedef struct s_fd_reader_vtbl	t_fd_reader_vtbl;

struct							s_fd_reader {
	const t_fd_reader_vtbl	*vt;

	int						fd;
	long long				buffer_size;
	char					*buffer;
	long long				buffer_actual_size;
	long long				buffer_i;
};

struct							s_fd_reader_vtbl {
	void						(*const dinit)(t_fd_reader *const self);
	void						(*const del)(t_fd_reader **const self_ptr);
	unsigned char				(*const is_opened)(t_fd_reader *const self);
	unsigned char				(*const is_readable)(t_fd_reader *const self);
	char						*(*const read_line)(t_fd_reader *const self);
	void						(*const read_line_to_array)(
		t_fd_reader *const self, char *const array, const size_t limit);
	char						(*const read_char)(t_fd_reader *const self);
	long long					(*const read_llint)(t_fd_reader
		*const self);

	void						(*const read_buffer)(t_fd_reader *const self);
};

/*
**	public:
*/

t_fd_reader						*new_fd_reader(const int fd,
	const size_t buffer_size);

void							del_fd_reader(t_fd_reader **const self_ptr);

/*
**	fd_reader initializer. Allocates memory, in case of failure buffer_size is
**	being set to 0.
*/

void							fd_reader_init(t_fd_reader *const self,
	const int fd, const size_t buffer_size);

void							fd_reader_dinit(t_fd_reader *const self);

unsigned char					fd_reader_is_opened(t_fd_reader *const self);

unsigned char					fd_reader_is_readable(t_fd_reader *const self);

char							*fd_reader_read_line(t_fd_reader *const self);

void							fd_reader_read_line_to_array(
	t_fd_reader *const self, char *const array, const size_t limit);

char							fd_reader_read_char(t_fd_reader *const self);

long long						fd_reader_read_llint(t_fd_reader *const self);

/*
**	private:
*/

void							fd_reader_read_buffer(t_fd_reader *const self);

static const t_fd_reader_vtbl	g_fd_reader_vt = {
	&fd_reader_dinit,
	&del_fd_reader,
	&fd_reader_is_opened,
	&fd_reader_is_readable,
	&fd_reader_read_line,
	&fd_reader_read_line_to_array,
	&fd_reader_read_char,
	&fd_reader_read_llint,
	&fd_reader_read_buffer
};

#endif
