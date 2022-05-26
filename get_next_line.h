/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/28 20:15:10 by dkocob        #+#    #+#                 */
/*   Updated: 2022/05/26 20:01:33 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 3
// # endif
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);