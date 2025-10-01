# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#              #
#    Updated: 2025/10/01 11:39:52 by tbezerra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-=-=- COLORS -=-=-=-=-=-=- #
RESET			=	\033[0m
BLACK 			=	\033[1;30m
RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
BLUE			=	\033[1;34m
PURPLE 			=	\033[1;35m
CYAN 			=	\033[1;36m
WHITE 			=	\033[1;37m
SBLINK			=	\033[5m
FBLINK			=	\033[6m

# -=-=-=-=-=-=- VARIABLES -=-=-=-=-=-=- #
NAME			=	ex02
OBJSDIR    		=	objs
OBJS			=	${SRC:%.cpp=${OBJSDIR}/%.o}
INCLUDES		=	-I .
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f
SRC				=	main.cpp

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

all:			${NAME}

${OBJSDIR}/%.o: %.cpp
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
				@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

clean:
				@${RM} -rf ${OBJSDIR}
				@echo "[${WHITE}${RED}Clean${WHITE}] ${GREEN}--> done${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@echo "[${WHITE}${RED}FClean${WHITE}] ${GREEN}--> done${RESET}"

re:				fclean all

.PHONY:			all clean fclean re