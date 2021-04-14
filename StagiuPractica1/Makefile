FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./src

SRC = main.c \
		$(wildcard $(PATH_SRC)/util/*.c) \
		$(wildcard $(PATH_SRC)/data/*.c) \
		$(wildcard $(PATH_SRC)/menues/*.c)


NAME = main

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

run: main
	./main

rerun: re run

.PHONY: all clean re run rerun