/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_reader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:10:26 by okurache          #+#    #+#             */
/*   Updated: 2018/06/09 19:10:26 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Abstract class abstract_reader
**
**  This is an abstract class of reader - an object which can read data from
**	somewhere
**
**	Written in accordance to 42_c_oop standard
**	https://github.com/OlehKurachenko/42_c_oop-standard
*/

#ifndef ABSTRACT_READER_H
# define ABSTRACT_READER_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_abstract_reader		t_abstract_reader;

typedef struct s_abstract_reader_vtbl	t_abstract_reader_vtbl;

struct									s_abstract_reader {
	const t_abstract_reader_vtbl	*vt;

	bool							exception;
};

/*
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: no base class. okurache, june 9 2018
*/

struct									s_abstract_reader_vtbl {
	void				(*const dinit)(t_abstract_reader *const self);

	void				(*const del)(t_abstract_reader **const self_ptr);

	bool				(*const is_opened)(t_abstract_reader *const self);

	bool				(*const is_readable)(t_abstract_reader *const self);

	bool				(*const has_line)(t_abstract_reader *const self);

	bool				(*const has_char)(t_abstract_reader *const self);

	bool				(*const has_str)(t_abstract_reader *const self);

	bool				(*const has_llint)(t_abstract_reader *const self);

	bool				(*const has_lluint)(t_abstract_reader *const self);

	bool				(*const has_ldouble)(t_abstract_reader *const self);

	char				(*const read_char)(t_abstract_reader *const self);

	char				*(*const read_line)(t_abstract_reader *const self);

	void				(*const read_line_to_array)(
		t_abstract_reader *const self, char *const array, const size_t limit);

	char				*(*const read_str)(t_abstract_reader *const self);

	void				(*const read_str_to_array)(
		t_abstract_reader *const self, char *const array, const size_t limit);

	long long			(*const read_llint)(t_abstract_reader *const self);

	long long unsigned	(*const read_lluint)(t_abstract_reader *const self);

	long double			(*const read_ldouble)(t_abstract_reader *const self);
};

/*
**  virtual table
**
**  First member function pointers have to match member
**  functions list from base class
**  Mark of EO: abstract class - no virtual table. okurache, june 9 2018
*/

#endif
