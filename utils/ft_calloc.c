/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorouger <jorouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:14:21 by jorouger          #+#    #+#             */
/*   Updated: 2025/03/26 13:40:02 by jorouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (!nmemb || !size)
		return (malloc(0));
	str = (void *)malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, (nmemb * size));
	return (str);
}
