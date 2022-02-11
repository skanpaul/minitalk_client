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
void client_handler(int sig_c);

/* ************************************************************************** */
int main(void)
{

	data.sa.sa_handler = &client_handler;
	data.sa.sa_flags = SA_RESTART;
	data.sa.sa_mask = 0xFFFFFFFF;  // A VERIFIER LE COMPORTEMENT CORRECTE OU PAS

	sigaction(SIGUSR1, &data.sa, 0);
	sigaction(SIGUSR2, &data.sa, 0);

	while (1) ;
	return (0);
}

/* ************************************************************************** */
void client_handler(int sig_c)
{
	if (sig_c == SIGUSR1) printf("pomme reçu\n");
	if (sig_c == SIGUSR2) printf("biscuit reçu\n");
}

/* ************************************************************************** */