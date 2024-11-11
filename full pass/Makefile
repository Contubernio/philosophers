# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albealva <albealva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 19:31:58 by albealva          #+#    #+#              #
#    Updated: 2024/11/10 21:32:27 by albealva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
ORANGE=\033[38;2;255;165;0m
NC=\033[0m 

NAME		= philo

HEADER = include/philosophers.h

SRC_DIR		= src/
OBJ_DIR		= obj/
INC_DIR		= include/

SRC 		= 	$(SRC_DIR)main.c       \
				$(SRC_DIR)args.c        \
				$(SRC_DIR)philosophers.c \
				$(SRC_DIR)monitor.c    \
				$(SRC_DIR)utiles.c          \
				$(SRC_DIR)tiktak.c            \
				$(SRC_DIR)exit.c

OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC			= gcc
RM			= rm -f
CFLAGS		= 	-Wall -Wextra -Werror -I$(INCLUDE) -fsanitize=thread
INCS 		= -I$(INC_DIR) -I.

TOTAL_FILES 	:= $(words $(SRC))
CURRENT_FILE 	:= 0

define progress_bar_philosophers
    @$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
    @printf "\r$(YELLOW)Compiling Philosophers... [%-$(TOTAL_FILES)s] %d/%d $(NC)" $$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then echo ""; fi
	@sleep 0.1
endef

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	$(call progress_bar_philosophers)

all: norm $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking objects to create executable...$(NC)"
	@$(CC) $(OBJ) -o $(NAME)
	@echo "$(BLUE)Executable $(NAME) created!$(NC)"

norm:
	@if [ ! -d "$(OBJ_DIR)" ]; then \
	echo "⢕⢕⢕⢕⠁⢜⠕⢁⣴⣿⡇⢓⢕⢵⢐⢕⢕⠕⢁⣾⢿⣧⠑⢕⢕⠄⢑⢕⠅⢕"; \
		echo "⢕⢕⠵⢁⠔⢁⣤⣤⣶⣶⣶⡐⣕⢽⠐⢕⠕⣡⣾⣶⣶⣶⣤⡁⢓⢕⠄⢑⢅⢑"; \
		echo "⠍⣧⠄⣶⣾⣿⣿⣿⣿⣿⣿⣷⣔⢕⢄⢡⣾⣿⣿⣿⣿⣿⣿⣿⣦⡑⢕⢤⠱⢐"; \
		echo "⢠⢕⠅⣾⣿⠋⢿⣿⣿⣿⠉⣿⣿⣷⣦⣶⣽⣿⣿⠈⣿⣿⣿⣿⠏⢹⣷⣷⡅⢐"; \
		echo "⣔⢕⢥⢻⣿⡀⠈⠛⠛⠁⢠⣿⣿⣿⣿⣿⣿⣿⣿⡀⠈⠛⠛⠁⠄⣼⣿⣿⡇⢔"; \
		echo "⢕⢕⢽⢸⢟⢟⢖⢖⢤⣶⡟⢻⣿⡿⠻⣿⣿⡟⢀⣿⣦⢤⢤⢔⢞⢿⢿⣿⠁⢕"; \
		echo "⢕⢕⠅⣐⢕⢕⢕⢕⢕⣿⣿⡄⠛⢀⣦⠈⠛⢁⣼⣿⢗⢕⢕⢕⢕⢕⢕⡏⣘⢕"; \
		echo "⢕⢕⠅⢓⣕⣕⣕⣕⣵⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣷⣕⢕⢕⢕⢕⡵⢀⢕⢕"; \
		echo "⢑⢕⠃⡈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⢕⢕⢕"; \
		echo "⣆⢕⠄⢱⣄⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢁⢕⢕⠕⢁"; \
		echo "$(GREEN)Running Norminette for Philosophers...$(NC)"; \
		norminette $(SRC) $(HEADER); \
	fi

clean:
	@echo "$(ORANGE)Cleaning objects for Philosophers...$(NC)"
	@$(RM) $(OBJ_DIR)*.o
	@echo "$(GREEN)Cleaned Philosophers objects!$(NC)"

fclean: clean
	@echo "$(ORANGE)Fully cleaning library for Philosophers...$(NC)"
	@$(RM) $(NAME)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BLUE)Fully cleaned Philosophers!$(NC)"

re: fclean all

.PHONY: all clean fclean re
