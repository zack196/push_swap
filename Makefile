NAME = push_swap
NAME_BONUS = checker

CC = cc

CFLAG = -Wall -Wextra -Werror 

RM = rm -f

INCLUDES = push_swap.h

SRCS = \
	./fill_in_stack.c	\
	./fill_in_stack_utils.c	\
	./sorting_utils.c	\
	./ft_split.c	\
	./ft_substr.c	\
	./linked_list_fct.c	\
	./main.c	\
	./moves_push.c	\
	./moves_reverse_rotate.c	\
	./moves_rotate.c	\
	./moves_swap.c	\
	./moves.c	\
	./sorting.c	\
	./stack.c	
	

SRCS_BONUS = \
	./bonus/fill_in_stack_bonus.c	\
	./bonus/fill_in_stack_utils_bonus.c	\
	./bonus/checking.c	\
	./bonus/ft_split_bonus.c	\
	./bonus/ft_substr_bonus.c	\
	./bonus/linked_list_fct_bonus.c	\
	./bonus/bonus_main.c	\
	./bonus/moves_push_bonus.c	\
	./bonus/moves_reverse_rotate_bonus.c	\
	./bonus/moves_rotate_bonus.c	\
	./bonus/moves_swap_bonus.c	\
	./bonus/get_next_line.c	\
	./bonus/get_next_line_utils.c


OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o: %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

bonus/%.o: bonus/%.c bonus/checker.h
	$(CC) $(FLAGC) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM)  $(NAME) $(NAME_BONUS)

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)


.PHONY : clean
