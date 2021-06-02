FLAGS = -Wall -Werror -Wextra

PATH_SRC = ./src

SRC = main.cpp \
		$(wildcard $(PATH_SRC)/util/*.cpp) \
		$(wildcard $(PATH_SRC)/data/*.cpp) \
		$(wildcard $(PATH_SRC)/menues/*.cpp) \
		$(wildcard $(PATH_SRC)/fileDb/*.cpp) \

NAME = main

all: $(NAME)

$(NAME):
	g++ $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

re: clean all

run: main
	./main

rerun: re run

.PHONY: all clean re run rerun