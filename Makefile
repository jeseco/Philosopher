# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 14:14:28 by jcourtem          #+#    #+#              #
#    Updated: 2022/11/08 11:39:42 by jeseco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				=	philo

INC_PATH			=	includes/
OBJS_PATH 			=	objs/
SRCS_PATH 			=	srcs/
CC 					=	gcc
CFLAGS				=	-Wall -Werror -Wextra -pthread -g
RM					=	rm -rf

INC_FILES 			=	parsign.h		\
						ft_atol.h 		\
						ft_isdigit.h 


SRCS_FILES			=	main.c

PARSING_FILES		=	ft_atol.c		\
						ft_isdigit.c	\
						parsing.c
PARSING_HDRS		=	parsign.h		\
						ft_atol.h		\
						ft_isdigit.h 

SIMULATION_FILES	=	simulation.c	\
						life.c
SIMULATION_HDRS		=	simulation.h	\
						life.h

PHILOSOPHERS_FILES	= 	philosophers.c	\
						philosopher_routine.c \
						philo_routine_utils.c
PHILOSOPHERS_HDRS	= 	philsophers.h	\
						philosopher_routine.h \
						philosopher_utils.h

UTILS_FILES			=	utils.c			\
						ft_bzero.c		\
						ft_calloc.c
UTILS_HDRS			=	utils.h			\
						ft_bzero.h		\
						ft_calloc.c	
						
WAITOR_FILES		=	waitor.c
WAITOR_HDRS			=	waitor.h

PARSING_PATH		= 	$(SRCS_PATH)parsing/
SIMULATION_PATH		=	$(SRCS_PATH)simulation/
PHILOSOPHERS_PATH	=	$(SRCS_PATH)philosophers/
UTILS_PATH			=	$(SRCS_PATH)utils/
WAITOR_PATH			=	$(SRCS_PATH)waitor/

SRCS 				=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
PARSING_SRCS		= 	$(addprefix $(PARSING_PATH), $(PARSING_FILES))
SIMULATION_SRCS		=	$(addprefix $(SIMULATION_PATH), $(SIMULATION_FILES))
PHILOSOPHERS_SRCS	=	$(addprefix $(PHILOSOPHERS_PATH), $(PHILOSOPHERS_FILES))
UTILS_SRCS			=	$(addprefix $(UTILS_PATH), $(UTILS_FILES))

INCLUDES			=	$(addprefix $(INC_PATH), $(INC_FILES))	

OBJS_FILES			= 	$(SRCS_FILES:.c=.o) $(PARSING_FILES:.c=.o) $(SIMULATION_FILES:.c=.o) $(PHILOSOPHERS_FILES:.c=.o) $(UTILS_FILES:.c=.o) $(WAITOR_FILES:.c=.o)
OBJS 				=	$(addprefix $(OBJS_PATH), $(OBJS_FILES))

VPATH				=	$(SRCS_PATH) $(PARSING_PATH) $(SIMULATION_PATH) $(UTILS_PATH) $(PHILOSOPHERS_PATH) $(WAITOR_PATH)

ALL_INCLUDES		= 	-I$(INC_PATH)						\
						-I$(INC_PATH)$(PARSING_PATH)		\
						-I$(INC_PATH)$(SIMULATION_PATH)		\
						-I$(INC_PATH)$(PHILOSOPHERS_PATH)	\
						-I$(INC_PATH)$(WAITOR_PATH)			\
						-I$(INC_PATH)$(UTILS_PATH)

USAGE				=	"USAGE: ./philosopher [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] | OPTIONAL: [number_of_meal]"

$(OBJS_PATH)%.o: %.c
	@$(CC) $(CFLAGS) $(ALL_INCLUDES) -c $< -o $@
	@printf "\033[93m▓▓▓\033[0m"

all:	$(NAME)

$(NAME):	$(OBJS_PATH) $(OBJS) 
	@$(CC) $(OBJS) -o $(NAME)
	@echo "\\n\033[32;1mProgram Ready\033[0m \\n"
	@echo $(USAGE)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@echo "\033[34;1mCreating Object Directory\n \033[0m"
	@printf "\033[32;1m\nCompiling with: \033[38;5;208m$(CFLAGS)\033[0m\\n\\n"


# linux :	$(OBJS_PATH) $(OBJS)
# 	@echo "\033[95mCompiling Program \033[0m"
# 	$(CC) $(OBJS) -o $(NAME)
# 	@echo "\\n\033[32;1mProgram IS READY \033[0m \\n"
# 	@echo $(USAGE)

# linux_debug: CFLAGS += -g -fstandalone-debug -DDEBUG=1 -fno-limit-debug-info
# linux_debug: linux

# linux_redebug : fclean linux_debug


debug:	CFLAGS += -g -fstandalone-debug -fno-limit-debug-info
debug:	$(NAME)

redebug : fclean debug

# Optimization flag for a small performance boost to your programm
# If you have errors compiling with this flag reduce to -O1 or just compile using make
release: CFLAGS += -O2
release: all

clean:
	@$(RM) $(OBJS_FILES) $(OBJS_PATH) 
	@echo "\033[34;1mCLEAN DONE\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[34;1mFCLEAN DONE\033[0m"

re: fclean all

redebug: fclean debug

github: fclean
	git add *; git commit -m "auto commit from makefile"; git push github

.PHONY: all clean fclean re linux debug redebug github