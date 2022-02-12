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
	// char byte_c;
	// int byte;
	int pid;

	if(argc != 3)
	{
		printf("Wrong ARGUMENT\n");
		return (1);
	}

	pid = atoi(argv[1]);
	if (!pid)
	{
		printf("It is not a PID number\n");
		return (1);
	}

	send_string(argv[2], pid, &data);

	// byte_c = 'A';
	// byte = (int)byte_c;
	// send_char(byte, pid, &data);

	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	if (sig_c == SIGUSR1) printf("pomme reçu\n");
	if (sig_c == SIGUSR2) printf("biscuit reçu\n");
}

/* ************************************************************************** */