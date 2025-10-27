/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiglesia <eiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:41:15 by eniglesi          #+#    #+#             */
/*   Updated: 2025/10/27 17:06:43 by eiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "../includes/printf/ft_printf.h"

void	btoa(int signal)
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
}

int	main(void)
{
	pid_t	pid_server;

	pid_server = getpid();
	ft_printf("Pid del servidor = %d\n", pid_server);
	signal(30, btoa);
	signal(31, btoa);
	while (1)
		pause();
	return (0);
}
