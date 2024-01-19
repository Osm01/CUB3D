/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaghoug <nbaghoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:40:04 by nbaghoug          #+#    #+#             */
/*   Updated: 2024/01/11 15:43:20 by nbaghoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	lookin_up(double angle)
{
	if (!(angle > 0 && angle < PI))
		return (TRUE);
	return (FALSE);
}

int	lookin_down(double angle)
{
	if ((angle > 0 && angle < PI))
		return (TRUE);
	return (FALSE);
}

int	lookin_left(double angle)
{
	if ((angle > PI * 0.5 && angle < PI * 1.5))
		return (TRUE);
	return (FALSE);
}

int	lookin_right(double angle)
{
	if (!lookin_left(angle))
		return (TRUE);
	return (FALSE);
}
