C		= clang
NAME	= fractol
FLAGS	= -Wall -Wextra -Werror -O3
LIBFT	= libft
SDIR	= src
ODIR	= tmp
MLX		= libmlx
HEADERS	= includes
SOURCES	= main.c error.c check_func.c init_func.c \
			expose.c put_fractol.c color.c hook.c \
			fractol_src.c

SRCS	= $(addprefix $(SDIR)/,$(SOURCES))
OBJS	= $(addprefix $(ODIR)/,$(SOURCES:.c=.o))

all: tmp $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MLX)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $^ -framework OpenGL -framework AppKit -L $(MLX) -lmlx

tmp:
	@mkdir -p tmp

$(ODIR)/%.o: $(SDIR)/%.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(MLX)

re: fclean all

.PHONY: all, tmp, clean, fclean, re
