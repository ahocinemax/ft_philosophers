#------------------------------------#
#             COMPILATION            #
#------------------------------------#

NAME	= philo

FLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=thread
INCLUDE	= -I $(HEAD_DIR) -pthread
CC		= gcc

#------------------------------------#
#               SOURCES              #
#------------------------------------#

SRC_DIR = srcs/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILE))
SRC_FILE = ft_check.c ft_dead.c ft_fork.c ft_args.c \
			ft_philosophers.c ft_routine.c ft_run.c \
			ft_time.c ft_utils.c

#------------------------------------#
#               OBJECTS              #
#------------------------------------#

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_DIR = obj/
OBJ = $(SRC_FILE:.c=.o)

#------------------------------------#
#              INCLUDES              #
#------------------------------------#

HEADER = $(addprefix $(HEAD_DIR), $(HEAD_FILE))
HEAD_DIR = includes/
HEAD_FILE = ft_philosophers.h

#------------------------------------#
#               COLORS               #
#------------------------------------#

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

#------------------------------------------------------------------------------#
#                                   RULES                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	# @echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	$(CC) $(FLAGS) $(OBJS) $(INCLUDE) -I includes -o $(NAME)
	@echo $(YELLOW)"- Project compiled -"$(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@ -I includes

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -f $(NAME)

re: fclean all

.PHONY : clean fclean re