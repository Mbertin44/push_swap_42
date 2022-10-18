# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2022/10/13 12:37:02 by mbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFT_PATH	=	libft
LIBFT		=	libft/libft.a

CC		=	gcc
CFLAGS		=	-g -Wall -Werror -Wextra
RM		=	rm -f

SRCS		=	push_swap.c				\
				explore_and_find.c		\
				check_params.c			\
				do_switch.c				\
				do_reverse_rotate.c		\
				do_rotate.c				\
				do_push.c				\
				end_of_program.c		\
				find_last_node.c		\
				first_sorting.c			\
				sorting.c				\
				indexing.c				\
				cost_and_cheapest_move.c\
				sorting_of_five.c		\

OBJS		= 	${SRCS:.c=.o}

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@$(MAKE) -C $(LIBFT_PATH)
				@echo "libft compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -o $(NAME)
				@echo "Done !"

all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@make clean -C $(LIBFT_PATH)
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

exe:			$(NAME)
#				valgrind --leak-check=full --show-leak-kinds=all ./push_swap -
#				valgrind --leak-check=full --show-leak-kinds=all ./push_swap -89364982739487293874293874
				valgrind --leak-check=full --show-leak-kinds=all ./push_swap 432 21 21
#				valgrind --leak-check=full --show-leak-kinds=all ./push_swap "0 298374928374982739482739847239874239"

# Removes objects and executable then remakes all
re: 			fclean all

.PHONY:			all clean fclean bonus re
