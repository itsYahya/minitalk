# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 22:07:55 by yel-mrab          #+#    #+#              #
#    Updated: 2022/01/09 22:29:30 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_C_M = Mandatory/client.c
SRC_S_M = Mandatory/server.c
OBJ_C_M = Mandatory/client.o
OBJ_S_M = Mandatory/server.o

SRC_C_B = Bonus/client_bonus.c
SRC_S_B = Bonus/server_bonus.c
OBJ_C_B = Bonus/client_bonus.o
OBJ_S_B = Bonus/server_bonus.o

NAME_C_M = client
NAME_S_M = server

NAME_C_B = client_bonus
NAME_S_B = server_bonus

GCC = gcc -Wall -Wextra -Werror

all: mandatory

%.o: %.c
	$(GCC) -c $< -o $@

mandatory: $(OBJ_C_M) $(OBJ_S_M)
	$(GCC) $(OBJ_C_M) -o $(NAME_C_M)
	$(GCC) $(OBJ_S_M) -o $(NAME_S_M)

bonus: $(OBJ_C_B) $(OBJ_S_B)
	$(GCC) $(OBJ_C_B) -o $(NAME_C_B)
	$(GCC) $(OBJ_S_B) -o $(NAME_S_B)

clean:
	rm -rf $(OBJ_C_B) $(OBJ_S_B)
	rm -rf $(OBJ_C_M) $(OBJ_S_M)
	
fclean: clean
	rm -rf $(NAME_C_B) $(NAME_S_B)
	rm -rf $(NAME_C_M) $(NAME_S_M)