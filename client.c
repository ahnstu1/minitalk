/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:49 by hahn              #+#    #+#             */
/*   Updated: 2022/07/04 15:38:50 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		div = 128;
		while (div)
		{
			if (argv[2][idx] & div)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			div /= 2;
			usleep(100);
		}
		idx++;
	}
	return (0);
}