# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:29:25 by hahn              #+#    #+#              #
#    Updated: 2022/06/27 16:24:06 by hahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft

NAME = client
NAME1 = server

OBJS = client.o
OBJS1 = server.o

all: $(NAME)

$(NAME): $(OBJS) $(OBJS1)
	make all -C $(LIBFT)
	cc -Llibft -lft $(OBJS) -o $(NAME)
	cc -Llibft -lft $(OBJS1) -o $(NAME1)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJS) $(OBJS1)

fclean: clean
	rm -f $(NAME) $(NAME1)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re