NAME	=	philo

HEADER = philosophers.h

CC		=	gcc
INCLUDE	=	includes
CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE) -fsanitize=thread
RM		=	rm -f

SRCS	=		main.c        \
			checks.c       \
			dead.c          \
			eat.c            \
			initialize.c      \
			print.c            \
			tasks.c             \
			util_itoa.c          \
			utils.c	      	      \

OBJS	=	$(SRCS:%.c=%.o)

# Regla para compilar archivos objeto
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<."

# Regla para recompilar si Makefile o HEADER cambian
.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Linked into executable \033[0;32mphilo\033[0m."

clean:
	@$(RM) $(OBJS)
	@echo "Removed object files."

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed executable."

re: fclean all

# Reglas para que el compilador sepa que necesita recompilar
$(OBJS): $(HEADER) Makefile


