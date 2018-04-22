NAME=ft_printf
SRCS=ft_printf.c
OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) libft.a
	make clean

%.o: %.c
	gcc -c $^ -o $@

clean:
	rm -f *.o
