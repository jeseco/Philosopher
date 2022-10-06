# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 13:10:01 by jcourtem          #+#    #+#              #
#    Updated: 2022/10/06 16:37:18 by jcourtem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------- Solution name: -------------- #
NAME 			= philo

# ----------- Compiler and flags: ------------ #
CC				= gcc
CFLAGS			= -Wextra -Wall -Werror -pthread

## ------------------ Debug: ---------------- ##
DEBUG			= -g

# ------------------- Paths: ----------------- #
SRCS_PATH		= srcs/
OBJS_PATH		= objs/
INCS_PATH		= includes/
PARSING_PATH	= $(SRCS_PATH)parsing/
# PHILO_PATH	= $(SRCS_PATH)philo/

# ------------------- Files: ----------------- #
## ------------------- SRC: ----------------- ##
MAIN 			= 	main.c
PARSING_SRCS	=	ft_atoi.c 		\
					ft_isdigit.c	\
					parsing.c 		
# PHILO			=	philo.c 

## ------------------ INC: ------------------ ##
INC				=	ft_atoi.h 		\
					ft_isdigit.h	\
					parsing.h		\
					philosopher.h	
					#philo.h

# ---------------- Prefixs: ------------------ #
MAIN_FILES		= $(addprefix $(SRCS_PATH),$(MAIN))
PARSING_FILES	= $(addprefix $(PARSING_PATH),$(PARSING_SRCS))
INCS_FILES		= $(addprefix $(INCS_PATH),$(INC))
OBJS_FILES		= $(addprefix $(OBJS_PATH),$(OBJS))
# PHILO_FILES	= $(addprefix $(PHILO_PATH), $(PHILO_FILES))

# ----------------- variables: ---------------- #
V_PATH			= $(SRCS_PATH) $(PARSING_PATH)

## ----------------- OBJS: ------------------- ##
OBJS			= $(patsubst $(SRCS_PATH)/%.c,$(OBJS_PATH)/%.o, $(MAIN)) $(patsubst $(PARSING_PATH)/%.c,$(OBJS_PATH)%.o, $(PARSING_FILES))

## ----------- TOOLS AND COLORS ------------- ##
RM				= rm -Rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

# ---------------- Recipies: ----------------- #

all: $(NAME)

$(NAME): obj_dir $(OBJS_PATH) 
	$(CC) $(CFLAGS) $(OBJS) -L$(INC_PATH) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) $(MAIN_FILES) $(PARSING_FILES) -I$(INC_PATH) -c $< -o $@
	@printf $(GREEN) OBJECTS CREATED $(NORMAL)

obj_dir:
	@mkdir -p $(OBJS_PATH)
	@echo "\033[34;1mCreating Object Directory\n\033[0m"
	@printf "\033[32;1m\nCompiling with: \033[38;5;208m$(CFLAGS)\033[0m\\n\\n"

.PHONY: clean fclean re

clean:
	rm -rf *.o 
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all