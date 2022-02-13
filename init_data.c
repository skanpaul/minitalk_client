/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:14:42 by ski               #+#    #+#             */
/*   Updated: 2022/02/11 18:14:44 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "client.h"

/* ************************************************************************** */
// static void reset_str_int(char *str_int);

/* ************************************************************************** */
void init_data(t_data *data)
{
	/* Configuration STRUCT SIGACTION ---------------- */
	data->sa.sa_handler = &handler_sig_usr;
	// data->sa.sa_flags = SA_RESTART;
    sigaddset(&data->sa.sa_mask, SIGUSR1);
    sigaddset(&data->sa.sa_mask, SIGUSR2);
	
	data->pid_client = getpid();


    data->us = 50;
    return ;
}

/* ************************************************************************** */

