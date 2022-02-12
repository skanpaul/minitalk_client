/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_bit_from_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:14:42 by ski               #+#    #+#             */
/*   Updated: 2022/02/11 18:14:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

/* ************************************************************************** */
void send_char(int byte, int pid, t_data *data)
{
	int mask;
	int result;
	int i;
	int us;

	us = data->us;

	mask = MASK_BIT_7;
	i = 7;
	while (i >= 0)
	{
		result = byte & mask;
		if (!result)
		{
			kill(pid, SIGUSR1);
			printf("0");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("1");
		}	
		usleep(5000); 
		mask >>= 1;
		i--;
	}

	return ;
}
