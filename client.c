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
// int main(void)
int main(int argc, char **argv)
{
	char byte_c;
	int byte;
	int pid;

	if(argc != 2)
	{
		ft_printf("Wrong ARGUMENT\n");
		return (1);
	}

	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("It is not a PID number\n");
		// perror("It is not a PID number\n");
		return (1);
	}

	byte_c = 'A';
	byte = (int)byte_c;

	do_bit_from_char(byte, pid);

	// data.sa.sa_handler = &handler_sig_usr;
	// data.sa.sa_flags = SA_RESTART;
	// data.sa.sa_mask = 0xFFFFFFFF;  // A VERIFIER LE COMPORTEMENT CORRECTE OU PAS
	// sigaction(SIGUSR1, &data.sa, 0);
	// sigaction(SIGUSR2, &data.sa, 0);
	// while (1) ;
	return (0);
}

/* ************************************************************************** */
void handler_sig_usr(int sig_c)
{
	if (sig_c == SIGUSR1) printf("pomme reçu\n");
	if (sig_c == SIGUSR2) printf("biscuit reçu\n");
}

/* ************************************************************************** */