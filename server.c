/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:54 by hahn              #+#    #+#             */
/*   Updated: 2022/07/06 13:51:13 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	static int	count = 7;
	static int	num = 0;

	num += signum == SIGUSR1;
	count--;
	if (count == -1)
	{
		write(1, &num, 1);
		count = 7;
		num = 0;
	}
	else
		num *= 2;
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putendl_fd(pid, 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_putendl_fd(pid, 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
