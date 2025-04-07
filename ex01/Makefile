# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qliso <qliso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 09:22:01 by qliso             #+#    #+#              #
#    Updated: 2025/04/08 00:13:09 by qliso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME	=	cpp08_ex01

SRCS	=	$(addsuffix .cpp, \
			main \
			Span \
			)

HEADERS		=	$(addsuffix .hpp, \
				Span \
				)

OBJS_PATH	=	.objs/
OBJS		=	$(SRCS:%.cpp=$(OBJS_PATH)%.o)
DEPS		=	$(OBJS:.o=.d)

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD -MP -I.
RM			=	rm -rf


#RULES
all:	$(OBJS_PATH) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "\033[1;32m$(NAME) compiled !\033[0m"

$(OBJS_PATH)%.o:	%.cpp | $(OBJS_PATH)
					$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJS_PATH):	
				@mkdir -p $(OBJS_PATH)

clean:
		$(RM) $(OBJS_PATH)
		@echo "\033[1;31mObject files deleted !\033[0m"

fclean:		clean
			$(RM) $(NAME)
			@echo "\033[1;31m$(NAME) deleted !\033[0m"

re:		fclean all

-include $(DEPS)

.PHONY:	all clean fclean re