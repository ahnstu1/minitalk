/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:49 by hahn              #+#    #+#             */
/*   Updated: 2022/07/06 10:40:07 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(char c, pid_t pid)
{
	int	div;

	div = 128;
	while (div)
	{
		if (c & div)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		div /= 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		idx;
	int		cnt;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	idx = 0;
	cnt = 0;
	while (argv[2][idx])
	{
		send(argv[2][idx++], pid);
		if (cnt++ % 101 == 100)
			send(127, pid);
	}
	send(127, pid);
	return (0);
}
