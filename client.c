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
		printf("Wrong ARGUMENT\n");
		return (1);
	}
	data.pid_server = atoi(argv[1]);
	if (!data.pid_server)
	{
		printf("It is not a PID number\n");
		return (1);
	}
	/* INITIALISATION -------------------------------- */
	init_data(&data);
	data.size_stream = ft_strlen(argv[2]);

	/* ENVOI DE DONNEES ------------------------------ */
	printf("PID client: %u\n", data.pid_client);
	// printf("PID client: %#010x\n", data.pid_client);
	printf("Size Stream: %u\n", data.size_stream);
	// printf("Size Stream: %#010x\n", data.size_stream);

	stream_out_int(data.pid_client, &data);
	stream_out_int(data.size_stream, &data);

	/* ----------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	if (sig_c == SIGUSR1) printf("pomme reçu\n");
	if (sig_c == SIGUSR2) printf("biscuit reçu\n");
}

/* ************************************************************************** */