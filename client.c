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

	struct sigaction *sa_client;
	struct sigaction *sa_old_client;

	sa_client = &data.sa_client;	
	sa_old_client = &data.sa_old_client;
	

	sa_client->sa_handler = &client_handler;
	sa_client->sa_mask = 0xFFFFFFFF;

	sigaction(SIGUSR1, sa_client, sa_old_client);
	sigaction(SIGUSR2, sa_client, sa_old_client);


	while (1) ;
	return (0);
}

/* ************************************************************************** */
void client_handler(int sig_c)
{
	struct sigaction *sa_client;
	struct sigaction *sa_old_client;

	sa_client = &data.sa_client;	
	sa_old_client = &data.sa_old_client;

	sigaction(SIGUSR1, sa_client, sa_old_client);
	if (sig_c == SIGUSR1) printf("pomme reçu\n");
	if (sig_c == SIGUSR2) printf("biscuit reçu\n");


}
/* ************************************************************************** */
