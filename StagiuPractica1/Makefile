FLAGS = -Wall -Werror -Wextra

PATH_SRC = .\src

SRC = main.c \
		$(PATH_SRC)\menues\menues.c \
		$(PATH_SRC)\menues\incidentMenu.c \
		$(PATH_SRC)\menues\infoMenu.c \
		$(PATH_SRC)\menues\mainMenu.c \
		$(PATH_SRC)\menues\reportMenu.c \

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