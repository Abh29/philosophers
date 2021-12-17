#first parts 
SRC :=	main.c 	src/ft_atoi.c src/ft_check_end.c src/ft_create_threads.c \
		src/ft_init.c src/ft_lock.c src/ft_philo_eat.c src/ft_philo_sleep.c \
		src/tools.c src/tools_2.c src/ft_free_struct.c

#bonnus 
BSRC :=	main_bonus.c src/ft_atoi.c src/ft_check_end2.c src/ft_create_processes.c \
		src/ft_init_bonus.c src/ft_eat_bonus.c src/ft_sleep_bonus.c \
		src/tools.c src/tools_2.c src/ft_free_struct.c

CC = gcc

##FLGS = -Wall -Werror -Wextra -Imlx  -g -pthread -lrt
FLGS = -Wall -Werror -Wextra -Imlx  -g -pthread
VALGFLGS = --vgdb=full -s -q
TARGS = 5 1500 100 1400 10

HEADER = philo.h

NAME = philo


all :$(NAME)
	
$(NAME): $(SRC) $(HEADER)
	@echo "compiling ..."
	@$(CC) $(FLGS)  $(SRC) -o $(NAME)

bonus: $(BSRC) $(HEADER)
	@echo "compiling bonus ..."
	@$(CC) $(FLGS) $(BSRC) -o $(NAME)

fclean: clean
	@echo "cleaning every thing ..."
	@rm -f $(NAME)

re: fclean all


valgrind: $(NAME)
	@valgrind $(VALGFLGS) ./$(NAME) $(TARGS)

.PHONY: all clean fclean bonus so re test

#&.c : &.o libft.a 
