/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 05:01:23 by okurache          #+#    #+#             */
/*   Updated: 2018/06/09 05:01:23 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTIN_READER_H
#define LIBFTIN_READER_H

#include <stdbool.h>

typedef struct s_abstract_reader		t_abstract_reader;

typedef struct s_abstract_reader_vtbl	t_abstract_reader_vtbl;

struct									s_abstract_reader {
	const t_abstract_reader_vtbl	*vt;
};

struct									s_abstract_reader_vtbl {
	void						(*const dinit)(
		t_abstract_reader *const self);
	void						(*const del)(
		t_abstract_reader **const self_ptr);
	bool						(*const is_opened)(
		t_abstract_reader *const self);
	bool						(*const is_readable)(
		t_abstract_reader *const self);
	char						*(*const read_line)(
		t_abstract_reader *const self);
	void						(*const read_line_to_array)(
		t_abstract_reader *const self, char *const array,
		const size_t limit);
	char						(*const read_char)(
		t_abstract_reader *const self);
	long long					(*const read_llint)(
		t_abstract_reader *const self);
	void						(*const pass_line)(
		t_abstract_reader *const self);
	char						(*const lookup_char)(
		t_abstract_reader *const self);
};

#endif
