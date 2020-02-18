/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:06:28 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 15:19:19 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int error(char c, int error_id)
{
	if (!error_id)
		ft_printf_error("Error\nTexture not found (%c)\n", c);
	else if (error_id == 1)
		ft_printf_error("Error\nSpawnpoint not found\n");
	return (1);
}

int check_map(t_info info)
{
	return (1);
}