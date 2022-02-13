/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:31:56 by ski               #+#    #+#             */
/*   Updated: 2022/02/10 19:31:59 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLIENT_H
# define CLIENT_H
/* ************************************************************************** */
# include "libft.h"
/* ************************************************************************** */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
/* ************************************************************************** */
# define MASK_BIT_0		1
# define MASK_BIT_1		2
# define MASK_BIT_2		4
# define MASK_BIT_3		8
# define MASK_BIT_4		16
# define MASK_BIT_5		32
# define MASK_BIT_6		64
# define MASK_BIT_7		128
/* ************************************************************************** */
typedef struct s_data
{
	struct sigaction	sa;
	unsigned int		pid_server;

	unsigned int		pid_client;
	char 				str_pid_client[5];

	unsigned int		size_stream;
	char 				str_size_stream[5];

	unsigned int		us;
}	t_data;
/* ************************************************************************** */
void	init_data(t_data *data);

void	send_pid_client(int pid_client, t_data *data);
void	send_size_stream(unsigned int size_stream, t_data *data);

void	send_string(char *str, int pid, t_data *data);
void	send_char(int byte, int pid_server, t_data *data);

/* ************************************************************************** */
#endif

