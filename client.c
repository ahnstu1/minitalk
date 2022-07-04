/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:49 by hahn              #+#    #+#             */
/*   Updated: 2022/06/27 17:11:18 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	pid_t 	pid;
	int		idx;
	int		div;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	idx = 0;
	while (argv[2][idx])
	{
		printf("\n argv : %c \n", argv[2][idx]);
		printf("\n test : %d \n", 1 << 7);
		div = 128;
		while (1)
		{
			printf("\nif : %d \n", argv[2][idx] & div);
			if (argv[2][idx] & div)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (!div)
				break;
			div /= 2;
			usleep(100);
		}
		idx++;
	}
	return (0);
}