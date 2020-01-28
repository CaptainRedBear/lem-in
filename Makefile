NAME			= lem_in
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
LIBFT_DIRECTORY = ./libft
SRC_DIR 		= ./srcs/
<<<<<<< HEAD
# ROOMS_DIR		= $(SRC_DIR)rooms/
# DEBUG_DIR		= $(SRC_DIR)debug/
# PATHS_DIR		= $(SRC_DIR)paths/
# TRAVEL_DIR		= $(SRC_DIR)travel/
# VAL_DIR			= $(SRC_DIR)validation/
=======
VAL_DIR			= ./validation/
>>>>>>> 4493d8106b6491559229f8fe97daf90eb6db7770
LIBRARIES 		= -lft -Llibft
LIBFT			= ./libft/*
INCLUDES 		= -I./libft/includes -I./includes

<<<<<<< HEAD

SRCS		= $(SRC_DIR)main.c $(VAL_DIR)val_funcs.c $(VAL_DIR)validate.c $(DEBUG_DIR)display.c
SRCS		+= $(ROOMS_DIR)room_handler.c $(ROOMS_DIR)link_handler.c $(TRAVEL_DIR)traversal.c 
SRCS		+= $(PATHS_DIR)path_handler.c $(PATHS_DIR)bfs.c $(PATHS_DIR)queue_handler.c
=======
# ----- Colors -----
BLACK			:="\033[1;30m"
RED				:="\033[1;31m"
GREEN			:="\033[1;32m"
CYAN			:="\033[1;35m"
PURPLE			:="\033[1;36m"
WHITE			:="\033[1;37m"
EOC				:="\033[0;0m"
# ==================

SRCS		= main.c $(VAL_DIR)f_val.c
>>>>>>> 4493d8106b6491559229f8fe97daf90eb6db7770
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS) $(LIBFT)
		@cd ./libft && make
<<<<<<< HEAD
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)
=======
		@echo $(GREEN)Built libft.$(EOC);
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)
		@echo $(GREEN)"Compiled lem_in." $(EOC)
>>>>>>> 4493d8106b6491559229f8fe97daf90eb6db7770

clean:
		@/bin/rm -f $(OBJS)
		@cd ./libft && make clean

fclean: clean
		@/bin/rm -f $(NAME)
		@cd ./libft && make fclean

re: fclean all