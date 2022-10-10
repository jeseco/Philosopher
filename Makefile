# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 13:04:10 by jeseco            #+#    #+#              #
#    Updated: 2022/10/09 21:45:44 by jeseco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				=	philo

INC_PATH			=	includes/
OBJS_PATH 			=	objs/
SRCS_PATH 			=	srcs/
CC 					=	gcc	
CFLAGS				=	-Wall -Werror -Wextra -Wpedantic -pthread

RM					=	rm -rf

INC_FILES 			=	philo.h \
						philosopher.h

SRCS_FILES			=	main.c

PARSING_FILES		=	ft_atoi.c \
						parsing.c \
						ft_isdigit.c

PARSING_HDRS		=	ft_atoi.h \
						ft_isdigit.h \
						parsing.h

PARSING_PATH		= 	$(SRCS_PATH)parsing/

SRCS 				=	$(addprefix $(SRCS_PATH), $(SRCS_FILES))
PARSING_SRCS		= 	$(addprefix $(PARSING_PATH), $(PARSING_FILES))

OBJS_FILES			= 	$(SRCS_FILES:.c=.o) $(PARSING_FILES:.c=.o)

INCLUDES			=	$(addprefix $(INC_PATH), $(INC_FILES))	
OBJS 				=	$(addprefix $(OBJS_PATH), $(OBJS_FILES))

VPATH				=	$(SRCS_PATH) $(PARSING_PATH)

ALL_INCLUDES		= 	-I$(INC_PATH)\
						-I$(PARSING_PATH)

USAGE				=	#Program Usage Message

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

.PHONY: all clean fclean re linux debug redebug

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
