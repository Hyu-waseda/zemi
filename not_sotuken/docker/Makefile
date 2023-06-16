NAME 	=	fractol
SRCS	=	main.c \
			ft_atof.c \
			hook.c \
			draw_fractol.c \
			complex_utils.c \
			cal.c \
			validate.c \
			init_fractol.c \
			my_mlx_pixel_put.c
HEADER	=	./
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
SRC_DIR	:=	./srcs
OBJ_DIR	:=	./objs
VPATH	:=	srcs:\
			srcs/complex
DEPS	:= $(OBJS:.o=.d)
LIBFT_DIR := ./libft
LIBFT := libft.a

ifeq ($(shell uname), Darwin)
	MLX_DIR		=	minilibx-mac
	LXFLAGS		=	-framework OpenGL -framework AppKit
else
	MLX_DIR		=	minilibx-linux
	LXFLAGS		=	-lXext -lX11 -lm
endif

LIBMLX			=	$(MLX_DIR)/libmlx.a

$(NAME): $(OBJ_DIR) $(OBJS)
	make bonus -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAG) $(OBJS) $(LIBFT_DIR)/$(LIBFT) $(LIBMLX) -o $@ -I/usr/X11/include -Lminilibx-linux -L/usr/X11/include/../lib -lXext -lX11 -lm

$(OBJ_DIR)/%.o: %.c
	$(CC) -g -c $< -o $@ -I $(HEADER)

$(OBJ_DIR):
	mkdir -p $@
	
all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR) 
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT)
	make clean -C $(MLX_DIR)

re:			fclean all


.PHONY:     all clean fclean re
