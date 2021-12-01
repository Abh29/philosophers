#first parts 
SRC :=	main.c 	src/*.c

#bonnus 
BSRC :=	$(SRC)

CC = gcc

FLGS = -Wall -Werror -Wextra -Imlx  -g -pthread
VALGFLGS = --vgdb=full --leak-check=full -s -q

HEADER = philo.h

NAME = philo


all :$(NAME)
	
$(NAME): $(SRC) $(HEADER) $(LIBFT)
	@echo "compiling ..."
	@$(CC) $(FLGS)  $(SRC) -o $(NAME)

bonus: $(BSRC) $(HEADER) $(LIBFT)
	@echo "compiling bonus ..."
	@rm -f $(NAME)
	@$(CC) $(FLGS) $(BSRC) -o $(NAME)

$(LIBFT):
	@make -C libft/
	@make bonus -C libft/

so:
	@echo "clreating .so file ..."
	@$(CC) -fPIC $(CFLAGS) -c $(SRC)
	@gcc -shared -o $(NAMESO) $(OBJ)

fclean: clean
	@echo "cleaning every thing ..."
	@rm -f $(NAME)

re: fclean all

test:
	@make -C libft/
	@$(CC) $(BSRC) $(LIBFT)  -o tst -lm

debug: $(SRC) $(HEADER) $(LIBFT)
	@make debug -C libft/
	@echo "compiling with -g ..."
	@$(CC) -g $(SRC) $(LIBFT) -o $(NAME) -lm

valgrind: $(NAME)
	@valgrind $(VALGFLGS) ./$(NAME) $(TARGS)


.PHONY: all clean fclean bonus so re test

#&.c : &.o libft.a 
