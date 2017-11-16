/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:14:06 by llonger           #+#    #+#             */
/*   Updated: 2017/11/16 11:14:06 by llonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./Libft/INCLUDES/libft.h"
# define BUFF_SIZE 500
# define VERIF(x) if (!x) return (-1)

int		get_next_line(const int fd, char **line);

#endif
