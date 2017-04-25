##
## Makefile for  in /home/januar_m/delivery/graphical/raytracer1
## 
## Made by Martin Januario
## Login   <martin.januario@epitech.eu>
## 
## Started on  Wed Mar  8 09:04:32 2017 
## Last update Sun Mar 19 23:01:10 2017 
##

SRC_DIS	=	src_dis/main.c			\
		src_dis/create_window.c		\
		src_dis/creator_loop.c		\
		src_dis/raytrace_scene.c	\
		src_dis/my_put_pixel.c		\
		src_dis/find_nearest_point.c	\
		src_dis/create_vector.c		\
		src_dis/pos_object.c		\
		src_dis/check_env.c		\
		src_dis/put_mode.c		\
		src_dis/match.c			\
		src_dis/create_color.c		\
		src_dis/eye_light_pos.c		\
		src_dis/disp_shadow.c		\
		src_dis/my_framebuffer_create.c

SRC	=	src/sphere.c			\
		src/cone.c			\
		src/cylinder.c			\
		src/plane.c			\
		src/calc_dir_vector.c		\
		src/light.c			\
		src/rotate.c			\
		src/translate.c

OBJ	=	$(SRC_DIS:.c=.o)		\
		$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror -I include/

NAME	=	raytracer1

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lc_graph_prog -lm

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
