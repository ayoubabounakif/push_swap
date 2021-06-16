FLAGS = 

LIBNAME = libft.a

NAME = push_swap

EXEC = push_swap

SRC = main.c \
srcs/subroutines/StackConstructor.c srcs/subroutines/StackSetter.c srcs/subroutines/stackDesctructor.c \
srcs/methods/__swap__.c srcs/methods/__rotation__.c srcs/methods/__push__.c \
srcs/__sort3__.c srcs/__sort5__.c srcs/__sortAll__.c \
utils/checkForDups.c utils/syntaxChecker.c utils/isSorted.c utils/execActions.c \
utils/isEvenOrOdd.c utils/findSmallestNode.c utils/findLargestNode.c utils/findPosition.c utils/pushMinToB.c utils/pushMaxToA.c \

all: $(NAME)

$(LIBNAME): $(SRC)
	@echo "\033[0;35mCompiling libft."
	make -C libft/
	cp libft/$(LIBNAME) ./

$(NAME): $(LIBNAME)
	@echo "\033[0;32mCompilation in progress!"
	gcc -g3 -fsanitize=address $(FLAGS) $(SRC) libft.a -D BUFFER_SIZE=1024 -o $(EXEC)
	@echo "\033[0;34mCompilation done."
	rm -rf $(EXEC).dSYM

clean:
	make clean -C libft/
	rm -f *.o
	@echo "\033[0;3mCleaned"

fclean: clean
	make fclean -C libft/
	rm -f *.a
	rm -f $(EXEC)
	@echo "\033[0;31mEverything cleaned"

re: fclean all