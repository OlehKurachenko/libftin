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

	fd_reader_init(&reader1, 0, 100);

	reader1.vt->dinit(&reader1);
}