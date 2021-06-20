FLAGS = 

LIBNAME = libft.a

PS_NAME = push_swap
PS_EXEC = push_swap

BONUS_NAME = checker
BONUS_EXEC = checker

GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

PS_SRC = push_swap.c \
srcs/subroutines/StackConstructor.c srcs/subroutines/StackSetter.c srcs/subroutines/stackDesctructor.c \
srcs/methods/__swap__.c srcs/methods/__rotation__.c srcs/methods/__push__.c \
srcs/__sort3__.c srcs/__sort4__.c srcs/__sort5__.c srcs/__sortAll__.c \
utils/checkForDups.c utils/syntaxChecker.c utils/isSorted.c utils/execActions.c \
utils/isEvenOrOdd.c utils/findSmallestNode.c utils/findLargestNode.c utils/findPosition.c utils/pushMinToB.c utils/pushMaxToA.c \

BONUS_SRC = checker.c \
srcs/subroutines/StackConstructor.c srcs/subroutines/StackSetter.c srcs/subroutines/stackDesctructor.c \
srcs/methods/__swap__.c srcs/methods/__rotation__.c srcs/methods/__push__.c \
srcs/__sort3__.c srcs/__sort4__.c srcs/__sort5__.c srcs/__sortAll__.c \
utils/checkForDups.c utils/syntaxChecker.c utils/isSorted.c utils/execActions.c \
utils/isEvenOrOdd.c utils/findSmallestNode.c utils/findLargestNode.c utils/findPosition.c utils/pushMinToB.c utils/pushMaxToA.c \

all: $(PS_NAME) $(BONUS_NAME)

$(LIBNAME): $(SRC)
	@echo "\033[0;35mCompiling libft."
	make -C libft/
	cp libft/$(LIBNAME) ./

$(PS_NAME): $(LIBNAME)
	@echo "\033[0;32mCompilation in progress!"
	gcc $(FLAGS) $(PS_SRC) libft.a $(GNL) -D BUFFER_SIZE=1024 -o $(PS_EXEC)
	@echo "\033[0;34mCompilation done."
	rm -rf $(PS_EXEC).dSYM

$(BONUS_NAME): $(LIBNAME)
	@echo "\033[0;32mCompilation in progress!"
	gcc $(FLAGS) $(BONUS_SRC) libft.a $(GNL) -D BUFFER_SIZE=1024 -o $(BONUS_EXEC)
	@echo "\033[0;34mCompilation done."
	rm -rf $(BONUS_EXEC).dSYM

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