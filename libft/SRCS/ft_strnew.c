/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:24:17 by llonger           #+#    #+#             */
/*   Updated: 2017/11/08 14:24:17 by llonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	return (str);
}
