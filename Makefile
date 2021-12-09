#first parts 
SRC :=	main.c 	src/*.c

#bonnus 
BSRC :=	main_bonus.c src/*.c

CC = gcc

FLGS = -Wall -Werror -Wextra -Imlx  -g -pthread -lrt
VALGFLGS = --vgdb=full --leak-check=full -s -q
TARGS = 5 1500 200 200 25

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
