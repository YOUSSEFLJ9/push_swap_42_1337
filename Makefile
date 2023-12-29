CC =cc
CFLAGS =-Wall -Wextra -Werror
SRC =main.c commands_rev_rotate.c commands_swap.c commands_push.c commands_rotate.c ft_isdigit.c ft_strchr.c sort.c sort_stack_algo_2.c sort_stack_algo.c LIS.c stack_func.c stack_func2.c ft_atoi.c ft_split.c   
OBJ =$(SRC:.c =.o)
SRC_BNS =
OBJ_B =
NAME =push_swap
BNS_NAME =checker
HEADER =push_swap.h
HEADERB = 
RM =rm -f
# LIB = ar -rcs

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY : clean all 