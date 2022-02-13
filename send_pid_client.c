/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_pid_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:34:04 by ski               #+#    #+#             */
/*   Updated: 2022/02/13 10:34:11 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

/* ************************************************************************** */
void	send_pid_client(int pid_client, t_data *data)
{
		int temp;

	temp = pid_client;
	temp >>= 24;
	temp = temp & 0x000000FF;
	send_char(temp, data->pid_server, data);

	temp = pid_client;
	temp >>= 16;
	temp = temp & 0x000000FF;
	send_char(temp, data->pid_server, data);

	temp = pid_client;
	temp >>= 8;
	temp = temp & 0x000000FF;
	send_char(temp, data->pid_server, data);

	temp = pid_client;
	temp >>= 0;
	temp = temp & 0x000000FF;
	send_char(temp, data->pid_server, data);	

	return ;
}