NAME_C   =   client
NAME_S   =   server

SRC_C    =   client.c utils.c
SRC_S    =   server.c utils.c

FLAGS   =   -Wall -Wextra -Werror
NAME = clientserver
OBJ_S	=	$(SRC_S:c=o)
OBJ_C	=	$(SRC_C:c=o)

all:	$(NAME)

$(NAME): $(NAME_S) $(NAME_C)

.c.o:       %.c
			gcc $(FLAGS) -c $< -o $@

$(NAME_C):	$(OBJ_C)
			gcc $(OBJ_C) -o $(NAME_C)
$(NAME_S):	$(OBJ_S)
			gcc $(OBJ_S) -o $(NAME_S)

clean:
			rm -f $(OBJ_C)
			rm -f $(OBJ_S)

fclean:     clean
			rm -f $(NAME_C)
			rm -f $(NAME_S)

re:         fclean all

.PHONY:     all clean fclean re
