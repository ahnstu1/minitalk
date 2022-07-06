/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:34:54 by hahn              #+#    #+#             */
/*   Updated: 2022/07/06 10:40:12 by hahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*make_str(char *str, char c)
{
	char	*ret;
	int		idx;

	idx = 0;
	ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[idx])
	{
		ret[idx] = str[idx];
		idx++;
	}
	free(str);
	ret[idx++] = c;
	ret[idx] = '\0';
	return (ret);
}

void	handler(int signum)
{
	static int	count = 7;
	static int	num = 0;
	static char	*str;

	num += signum == SIGUSR1;
	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (--count == -1)
	{
		if (num != 127)
			str = make_str(str, num);
		else
		{
			write(1, str, ft_strlen(str));
			free(str);
			str = NULL;
		}
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
