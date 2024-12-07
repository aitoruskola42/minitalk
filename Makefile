# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auskola- <auskola-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 10:49:52 by auskola-          #+#    #+#              #
#    Updated: 2023/09/04 11:49:17 by auskola-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=client
NAME2=server
NAME3=client_bonus
NAME4=server_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC1 = client.c
SRC2 = server.c server2.c
SRC3 = client_bonus.c
SRC4 = server_bonus.c server2_bonus.c

INCLUDE = server.h

OBJS1 = $(SRC1:.c=.o)
OBJS2 = $(SRC2:.c=.o)
OBJS3 = $(SRC3:.c=.o)
OBJS4 = $(SRC4:.c=.o)

all: $(NAME1) $(NAME2) $(NAME3) $(NAME4) 

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJS1) 
$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJS2) 
$(NAME3): $(OBJS3)
	$(CC) $(CFLAGS) -o $(NAME3) $(OBJS3) 
$(NAME4): $(OBJS4)
	$(CC) $(CFLAGS) -o $(NAME4) $(OBJS4) 
#	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -> si fuera un ejecutable
##	ar rc $(NAME) $(OBJS) $(BONUS_OBJS) >  ar rc para hacer libreria
	@echo "\ngenerated: $(OBJS1)\n"
$(OBJS1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1)
	@echo "\ngenerated: $(OBJS2)\n"
$(OBJS2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2)
	@echo "\ngenerated: $(OBJS3)\n"
$(OBJS3): $(SRC3)
	$(CC) $(CFLAGS) -c $(SRC3)
	@echo "\ngenerated: $(OBJS4)\n"
$(OBJS4): $(SRC4)
	$(CC) $(CFLAGS) -c $(SRC4)

clean:
	rm -f $(OBJS1)   
	rm -f $(OBJS2)
	rm -f $(OBJS3)   
	rm -f $(OBJS4)   
fclean:
	rm -f *.o
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(NAME3)
	rm -f $(NAME4)

re: fclean all

bonus:all

.PHONY: all bonus clean fclean re  