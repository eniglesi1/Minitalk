/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:15 by eniglesi          #+#    #+#             */
/*   Updated: 2025/10/28 13:32:05 by eiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "../includes/printf/ft_printf.h"

static void	btoa(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	num;

	if (!num)
		num = 8;
	if (!c)
		c = 0;
	num--;
	if (signal == 30)
		c += 0 << num;
	if (signal == 31)
		c += 1 << num;
	if (num == 0)
	{
		write(1, &c, 1);
		num = 8;
		c = 0;
	}
	if (context == NULL)
		write(1, "", 0);
	kill(info->si_pid, 31);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Pid del servidor = %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = btoa;
	sigaction(30, &sa, NULL);
	sigaction(31, &sa, NULL);
	while (1)
		usleep(50);
	return (0);
}
