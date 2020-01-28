NAME			= lem_in
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
LIBFT_DIRECTORY = ./libft
SRC_DIR 		= ./srcs/
# ROOMS_DIR		= $(SRC_DIR)rooms/
# DEBUG_DIR		= $(SRC_DIR)debug/
# PATHS_DIR		= $(SRC_DIR)paths/
# TRAVEL_DIR		= $(SRC_DIR)travel/
# VAL_DIR			= $(SRC_DIR)validation/
LIBRARIES 		= -lft -Llibft
LIBFT			= ./libft/*
INCLUDES 		= -I./libft/includes -I./includes


SRCS		= $(SRC_DIR)main.c $(VAL_DIR)val_funcs.c $(VAL_DIR)validate.c $(DEBUG_DIR)display.c
SRCS		+= $(ROOMS_DIR)room_handler.c $(ROOMS_DIR)link_handler.c $(TRAVEL_DIR)traversal.c 
SRCS		+= $(PATHS_DIR)path_handler.c $(PATHS_DIR)bfs.c $(PATHS_DIR)queue_handler.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(SRCS) $(LIBFT)
		@cd ./libft && make
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS) $(LIBRARIES) -o $(NAME)

clean:
		@/bin/rm -f $(OBJS)
		@cd ./libft && make clean

fclean: clean
		@/bin/rm -f $(NAME)
		@cd ./libft && make fclean

re: fclean all