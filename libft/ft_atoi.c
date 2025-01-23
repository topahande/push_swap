/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:41:21 by htopa             #+#    #+#             */
/*   Updated: 2024/11/16 17:34:00 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && (10 * (int)nbr + (*str - '0')) / 10 != (int)nbr)
			return (0);
		else if (sign == -1 && (10 * (int)(sign * nbr)
			- (*str - '0')) / 10 != (int)(sign * nbr))
			return (0);
		nbr = 10 * nbr + (*str - '0');
		str++;
	}
	return (sign * nbr);
}
