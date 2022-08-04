# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnottle <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 13:03:09 by jnottle           #+#    #+#              #
#    Updated: 2022/08/04 14:59:31 by jnottle          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = sources/if_character.c \
	   sources/if_string.c \
	   sources/if_pointer.c \
	   sources/if_hex.c \
	   sources/if_int.c \
	   sources/if_unsignedint.c \
	   sources/ft_printf.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(NAME) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
