SRC = main.c src/*.c
NAME = phylo

ALL :
	gcc $(SRC) -o $(NAME) -pthread
