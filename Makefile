NAME			= lem_in
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
LIBFT_DIRECTORY = ./libft
SRC_DIR 		= ./srcs/
ROOMS_DIR		= $(SRC_DIR)rooms/
TRAVEL_DIR		= $(SRC_DIR)travel/
PATH_DIR		= $(SRC_DIR)paths/
VAL_DIR			= $(SRC_DIR)validation/
DEBUG_DIR		= $(SRC_DIR)debug/
LIBRARIES 		= -lft -Llibft
LIBFT			= ./libft/*
INCLUDES 		= -I./libft/includes -I./includes

# ----- Colors -----
BLACK			:="\033[1;30m"
RED				:="\033[1;31m"
GREEN			:="\033[1;32m"
CYAN			:="\033[1;35m"
PURPLE			:="\033[1;36m"
WHITE			:="\033[1;37m"
EOC				:="\033[0;0m"
# ==================

SRCS		= main.c $(VAL_DIR)f_val.c $(ROOMS_DIR)room_manip.c $(ROOMS_DIR)link_manip.c $(TRAVEL_DIR)traversal.c 
SRCS		+= $(PATH_DIR)path_manip.c $(PATH_DIR)queue_manip.c $(DEBUG_DIR)display.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS) $(LIBFT)
		@cd ./libft && make
		@echo $(GREEN)Built libft.$(EOC);
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)
		@echo $(GREEN)"Compiled lem_in." $(EOC)

clean:
		@/bin/rm -f $(OBJS)
		@cd ./libft && make clean
		@echo $(RED)"Removed all .o files from lem_in" $(EOC)

fclean: clean
		@/bin/rm -f $(NAME)
		@cd ./libft && make fclean
		@echo $(RED)"Removed all .o files and .a files from lem_in" $(EOC)

re: fclean all