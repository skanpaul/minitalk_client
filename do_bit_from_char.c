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
void do_bit_from_char(int byte, int pid)
{
	int mask;
	int result;
	int ms;
	int us;
	int i;

	ms = 1;
	us = ms * 1000;

	mask = MASK_BIT_7;
	i = 7;
	while (i >= 0)
	{
		result = byte & mask;
		// if (!result)
		// 	printf("valeur 0\n");
		// else		 
		// 	printf("valeur 1\n");
		if (!result)
		{
			kill(pid, SIGUSR1);
			usleep(us);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(us);
		}		 
		mask >>= 1;
		i--;
	}

	return ;
}

