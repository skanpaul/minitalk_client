/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:56:34 by ski               #+#    #+#             */
/*   Updated: 2022/02/09 09:56:36 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

/* ************************************************************************** */
t_data data;
/* ************************************************************************** */
void handler_sig_usr(int sig_c);

/* ************************************************************************** */
int main(int argc, char **argv)
{
	if(argc != 3)
	{
		ft_printf("Wrong ARGUMENT\n");
		return (1);
	}
	data.pid_server = atoi(argv[1]);
	if (!data.pid_server)
	{
		ft_printf("It is not a PID number\n");
		return (1);
	}
	/* INITIALISATION -------------------------------- */
	init_data(&data);
	data.size_stream = ft_strlen(argv[2]);

	/* ENVOI DE DONNEES ------------------------------ */
	ft_printf("PID client:\t[%u]\n", data.pid_client);
	// printf("PID client: %#010x\n", data.pid_client);
	ft_printf("Size Stream:\t[%u]\n", data.size_stream);
	// printf("Size Stream: %#010x\n", data.size_stream);

	stream_out_int(data.pid_client, &data);
	stream_out_int(data.size_stream, &data);
	stream_out_string(argv[2], data.pid_server, &data);
	// stream_out_char(0, data.pid_server, &data);

	/* Link SIGNAL with HANDLER ---------------------- */
	sigaction(SIGUSR1, &data.sa, 0);
	/* ----------------------------------------------- */
	ft_printf("Attentre réponse du Server [%d]\n", data.pid_server);
	while (1)
		pause();
	/* ----------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	if (sig_c == SIGUSR1)
	{
		ft_printf("Message reçu du SERVER [%d]\n", data.pid_server);
		exit(1);
	}
}

/* ************************************************************************** */