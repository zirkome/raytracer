##
## Makefile for Makefile in /home/bridou_n//minishell1
##
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
##
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Sun Jun  9 16:30:40 2013 nicolas bridoux
##

CC	= 	gcc

RM	=	rm -f

DEBUG	=	false

NAME	= 	rt

SRCDIR	=	src/

VPATH	=	$(SRCDIR):$(SRCDIR)objects:$(SRCDIR)vector:$(SRCDIR)utils:$(SRCDIR)parsing:$(SRCDIR)effects

SRC	=	main.c			\
		mlx.c			\
		bmp.c			\
		msaa.c			\
		cone.c			\
		tore.c			\
		cube.c			\
		spot.c			\
		limit.c			\
		light.c			\
		color.c			\
		plane.c			\
		noise.c			\
		vector.c		\
		object.c		\
		sphere.c		\
		solveur.c		\
		read_fd.c		\
		get_eye.c		\
		texture.c		\
		my_itoa.c		\
		filters.c		\
		contrast.c		\
		rotation.c		\
		color_op.c		\
		cylinder.c		\
		my_error.c		\
		vector_op.c		\
		get_spots.c		\
		pixel_put.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_strdup.c		\
		my_strcat.c		\
		raytracer.c		\
		movements.c		\
		vector_op2.c		\
		my_strncmp.c		\
		arithmetic.c		\
		copy_scene.c		\
		save_scene.c		\
		get_objects.c		\
		parse_scene.c		\
		solve_cubic.c		\
		paraboloide.c		\
		hyperboloide.c		\
		perturbation.c		\
		perlin_noise.c		\
		checkerboard.c		\
		solve_square.c		\
		parse_object.c		\
		infos_objects.c		\
		apply_effects.c		\
		parse_balises.c		\
		fill_infos_obj.c	\
		gamma_correction.c	\

OBJDIR	=	obj/

OBJ	=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

ifeq		($(DEBUG),true)
CFLAGS		+= -ggdb3
endif

CFLAGS	+= 	-Wall -Wextra -Wfloat-equal
CFLAGS	+=	-I include
CFLAGS	+=	-O3 -ffast-math -march=native -mtune=native

LDFLAGS	+=	-L/usr/lib64 -lmlx_x86_64-linux -L/usr/lib64/X11 -lXext -lX11
LDFLAGS +=	-lm -lpthread

$(OBJDIR)%.o: %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo -e "Compilation de\033[32;1m" $(notdir $<) "\033[0m => \033[31;1m" $(notdir $@) "\033[0m" "[" $(CFLAGS) "]"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@echo -e "Compilation de {\033[31;1m" $(notdir $(OBJ)) "\033[0m} en \033[32;1m" $(notdir $(NAME)) "\033[0m" "[" $(LDFLAGS) "]"

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
