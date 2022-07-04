/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:54 by hahn              #+#    #+#             */
/*   Updated: 2022/06/27 16:34:55 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
#include <stdio.h>

void	handler(int signum)
{
	static int	count = 7;
	static int	num = 0;

//	num += signum == SIGUSR1;
	if (signum == SIGUSR1)
		num |= 1;
	else if (signum == SIGUSR2)
		num |= 0;
	printf("\n num : %d \n", num);
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

int main(void)
{
    char	*pid;

	pid = ft_itoa(getpid());

	write(1, pid, ft_strlen(pid));
    signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}