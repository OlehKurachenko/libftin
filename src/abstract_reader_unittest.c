/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_reader_unittest.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okurache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 05:23:41 by okurache          #+#    #+#             */
/*   Updated: 2018/06/09 05:23:41 by okurache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "exports/libftin.h"

int main() {
	t_abstract_reader *cin = (t_abstract_reader *)new_fd_reader(0, 128);

//	printf("Print number>\n");
//	fflush(stdin);
//
//	printf("Number: %d\n", (int)cin->vt->read_llint(cin));
//	fflush(stdin);
//
//	cin->vt->pass_line(cin);
//
//	printf("Print string>\n");
//	fflush(stdin);
//
//	printf("Char lookuped: %c\n", cin->vt->lookup_char(cin));
//	printf("Line: %s\n", cin->vt->read_line(cin));
//	fflush(stdin);

	// Lookup explained

	printf("Print number>\n");
	fflush(stdin);

	if (ft_isdigit(cin->vt->lookup_char(cin)))
		printf("Your number is: %d\n", (int)cin->vt->read_llint(cin));
	else
		printf("Bad number entered: %s\n", cin->vt->read_line(cin));

	cin->vt->del(&cin);
}