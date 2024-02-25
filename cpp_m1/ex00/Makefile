# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/02/25 12:29:23 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = Zombie

SRC = main.cpp zombie.cpp

CPPFLAGS := -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating..." $<
	CPP CPPFLAGS $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean clean