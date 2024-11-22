/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:12:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/22 09:12:31 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft.h"

int ft_str_isdigit(char *str)
{
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}