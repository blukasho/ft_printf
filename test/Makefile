# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/07 14:40:14 by blukasho          #+#    #+#              #
#*   Updated: 2019/03/17 13:02:42 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = test.c

all:
	make -C ../
	gcc -Wall -Wextra -g3 $(SRCS) ../libftprintf.a
	./a.out
#	lldb a.out

fclean:
	rm -rf a.out
	rm -rf a.out.dSYM 

re: fclean all
