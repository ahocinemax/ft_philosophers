<<<<<<< HEAD
#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME		= philo

FLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=thread
INCLUDE		= -I $(HEAD_DIR) -pthread
CC			= gcc

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRC_DIR 	= srcs/
SRCS 		= $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_FILE 	= ft_check.c ft_dead.c ft_fork.c ft_args.c \
				ft_philosophers.c ft_routine.c ft_run.c \
				ft_time.c ft_utils.c

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJS 		= $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_DIR 	= obj/
OBJ 		= $(SRC_FILE:.c=.o)

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEADER 		= $(addprefix $(HEAD_DIR), $(HEAD_FILE))
HEAD_DIR 	= includes/
HEAD_FILE 	= ft_philosophers.h
=======
NAME = philo

HEAD_DIR = includes/
SRC_DIR = srcs/
OBJ_DIR = obj/

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_FILE = ft_check.c ft_dead.c ft_fork.c ft_args.c \
			ft_philosophers.c ft_routine.c ft_run.c \
			ft_time.c ft_utils.c

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = ft_check.o ft_dead.o ft_fork.o ft_args.o \
	ft_philosophers.o ft_routine.o ft_run.o \
	ft_time.o ft_utils.o

HEADER = $(addprefix $(HEAD_DIR), $(HEAD_FILE))
HEAD_FILE = ft_philosophers.h
>>>>>>> parent of f035007... A

FLAGS = -Wall -Wextra -Werror -g3
INCLUDE = -I $(HEADER) -pthread

NONE		= '\033[0m'
GREEN		= '\033[32m'
YELLOW		= '\033[33m'
GRAY		= '\033[2;37m'
CURSIVE		= '\033[3m'

all: $(NAME)

<<<<<<< HEAD
$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@$(CC) $(FLAGS) $(OBJS) $(INCLUDE) -I includes -o $(NAME)
	@echo $(GREEN)"- Project compiled -"$(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@ -I includes
=======
$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - Moving object files..." $(NONE)
	@rm -rf $(OBJ_DIR)
	@mkdir $(OBJ_DIR)
	@mv $(OBJ) $(OBJ_DIR)
	@echo $(YELLOW)"- Project compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRCS)
>>>>>>> parent of f035007... A

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -f $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME)
	@echo $(YELLOW)"- Project removed -"$(NONE)

re: fclean all

.PHONY : clean fclean re