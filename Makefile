# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchadili <hchadili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 01:11:28 by hchadili          #+#    #+#              #
#    Updated: 2024/06/04 12:25:20 by hchadili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = Mandatory/so_long.c Mandatory/ft_putnbr.c Mandatory/key_press.c Mandatory/ft_start.c Mandatory/ft_split.c \
		Mandatory/ft_show.c Mandatory/check_map.c Mandatory/check_map_helper.c Mandatory/get_next_line/get_next_line.c \
		Mandatory/get_next_line/get_next_line_utils.c Mandatory/ft_free_arr.c

SRC_B = Bonus/so_long_bonus.c Bonus/ft_split_bonus.c Bonus/ft_itoa_bonus.c Bonus/key_press_bonus.c Bonus/ft_start_bonus.c \
		Bonus/ft_show_bonus.c Bonus/check_map_bonus.c Bonus/check_map_helper_bonus.c Bonus/get_next_line/get_next_line_bonus.c \
		Bonus/get_next_line/get_next_line_utils_bonus.c Bonus/ft_free_arr_bonus.c Bonus/move_enmy_even_bonus.c Bonus/move_enmy_odd_bonus.c


OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
$(NAME_B): $(OBJS_B)
	$(CC) $(OBJS_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	
Mandatory/%.o : Mandatory/%.c Mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o : Bonus/%.c Bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all