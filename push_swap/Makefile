NAME        = push_swap
AR            = ar rcs
CC            = cc 
CFLAGS        = -Werror -Wall -Wextra -I .

PATH_LIBFT = libft
LIBFT = ${PATH_LIBFT}/libft.a

SRCS	=	main.c \
        	stack_utils.c stack_utils_2.c stack_utils_3.c\
		stack_cmd_pp.c stack_cmd_ss.c stack_cmd_rrr.c stack_cmd_rr.c \
		stack_init.c \
		fst_n_lst_sort.c \
		empty_b.c \
		all_three.c \
		rch_stack.c \
		find_stack.c \
		cost_a_to_b.c cost_b_to_a.c \





OBJS_FILES = ${SRCS:.c=.o}


all: ${LIBFT} ${NAME} 

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS_FILES}
	$(CC) $(OBJS_FILES) -o $(NAME) -L ${PATH_LIBFT} -lft
    

${LIBFT}:
	${MAKE} -C ${PATH_LIBFT}

clean:
	rm -f ${OBJS_FILES}
	${MAKE} -C  ${PATH_LIBFT} clean


fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${PATH_LIBFT} fclean 

re: fclean all

.PHONY: all clean fclean re