CC =cc
CFLAGS =-Wall -Wextra -Werror
SRC =main.c commands_rev_rotate.c commands_swap.c commands_push.c commands_rotate.c ft_isdigit.c ft_strchr.c sort.c sort_stack_algo_2.c sort_stack_algo.c LIS.c stack_func.c stack_func2.c ft_atoi.c ft_split.c   
OBJ =$(SRC:.c=.o)
SRC_BNS = bonus/trate_check_bonus.c bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c commands_rev_rotate.c commands_swap.c commands_push.c commands_rotate.c ft_isdigit.c ft_strchr.c stack_func.c stack_func2.c ft_atoi.c ft_split.c
OBJ_B = $(SRC_BNS:.c=.o)
NAME =push_swap
BNS_NAME =checker
HEADER = push_swap.h
HEADERB = bonus/checker_bonus.h
RM =rm -f

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(OBJ_B) $(HEADERB)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(BNS_NAME)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(BNS_NAME)

re: fclean all
.PHONY : clean all 