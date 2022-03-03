HEADER = fract.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

OBJ = mandelbrot.o\
		julia.o\
		main.o\
		event.o\
		mlx.o\

NAME = fractol


all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(RM) $(OBJ) ${OBJ_BONUS}

fclean: clean
		$(RM) $(NAME) 

re: fclean all
