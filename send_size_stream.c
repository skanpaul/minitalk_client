/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_size_stream.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:56:24 by ski               #+#    #+#             */
/*   Updated: 2022/02/13 13:56:26 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

/* ************************************************************************** */
void	send_size_stream(unsigned int size_stream, t_data *data)
{

	char	*str_size_stream;	
	str_size_stream = ft_itoa(size_stream);	
	send_string(str_size_stream, data->pid_server, data);	
	return ;
}



