/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:39 by sojammal          #+#    #+#             */
/*   Updated: 2025/02/26 14:19:16 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_extension(char *file)
{
    int i;
    
    if (file == NULL)
        return (0);
    i = ft_strlen(file);
    if (i < 4)
        return (0);
    if (ft_strcmp(&file[i - 4], ".ber") != 0)
        return (0);
    return (1);
}
