/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:28:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/24 06:32:36 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
		if ((result > INT_MAX && sign == 1) || (result > (2147483648)
				&& sign == -1))
			return (2147483648);
	}
	if (str[i])
		return (2147483648);
	return (result * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_atoi("  	-480wff"));
	return (0);
}
*/
