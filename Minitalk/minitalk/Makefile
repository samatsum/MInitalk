NAME		=	server
NAMECL		=	client

BONUS_NAME		=	server_bonus
BONUS_NAMECL		=	client_bonus

SRCCL		=	src/client.c \
				libft/ft_atoi.c \
				$(shell find ./ft_printf/ -name '*.c') \

SRCSE		=	src/server.c \
				$(shell find ./ft_printf/ -name '*.c') \

BONUS_SRCCL		=	bonus/client_bonus.c \
				libft/ft_atoi.c \
				$(shell find ./ft_printf/ -name '*.c') \

BONUS_SRCSE		=	bonus/server_bonus.c \
				$(shell find ./ft_printf/ -name '*.c') \

OBJCL				=	$(SRCCL:.c=.o)

OBJSE				=	$(SRCSE:.c=.o)

BONUS_OBJCL				=	$(BONUS_SRCCL:.c=.o)

BONUS_OBJSE				=	$(BONUS_SRCSE:.c=.o)

CC					=	cc
MANDATORYFLAGS		=	-Wall -Wextra -Werror
FSANITIZEFLAGS		=	-fsanitize=address -g3
OPTIMIZEFLAGS 		=	-O3 -march=native -funroll-loops
RM					=	rm -f

.c.o:
	$(CC) $(MANDATORYFLAGS) $(OPTIMIZEFLAGS) -c $< -o $@

$(NAME): $(OBJSE)
	$(CC) $(MANDATORYFLAGS) -o $(NAME) $(OBJSE)

$(NAMECL): $(OBJCL)
	$(CC) $(MANDATORYFLAGS) -o $(NAMECL) $(OBJCL)

$(BONUS_NAME): $(BONUS_OBJSE)
	$(CC) $(MANDATORYFLAGS) -o $(BONUS_NAME) $(BONUS_OBJSE)

$(BONUS_NAMECL): $(BONUS_OBJCL)
	$(CC) $(MANDATORYFLAGS) -o $(BONUS_NAMECL) $(BONUS_OBJCL)

all:	$(NAME) $(NAMECL)

bonus:	$(BONUS_NAME) $(BONUS_NAMECL)

clean:		
	$(RM) $(OBJCL) $(OBJSE) $(BONUS_OBJCL) $(BONUS_OBJSE)

fclean:		clean
	$(RM) $(NAME) $(NAMECL) $(BONUS_NAME) $(BONUS_NAMECL)

re:			fclean all    

.PHONY:			all clean fclean re bonus
