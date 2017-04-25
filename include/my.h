/*
** my.h for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 09:12:39 2017 
** Last update Sun Mar 19 23:01:27 2017 
*/

#ifndef MY_H_
# define MY_H_

# include		<SFML/Graphics/RenderWindow.h>
# include		<SFML/Graphics/Color.h>
# include		"framefuffer.h"

# define		MALLOC_FAILED 84

typedef struct		s_core_window
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
}			t_core_window;

/*
**			Prototypes of file's source to display.
*/
t_my_framebuffer	*my_framebuffer_create(int, int);
sfRenderWindow		*create_window(char *, int, int);
void			creator_loop(t_my_framebuffer *, t_core_window *);
int			raytrace_scene(t_my_framebuffer *);
void			my_put_pixel(t_my_framebuffer *, int, int, sfColor);
void			find_nearest_point(t_my_framebuffer *, sfVector2i,
					   sfVector3f, sfVector3f);
sfVector2i		create_vector2i(int, int);
sfVector3f		pos_sphere(void);
sfVector3f		pos_plane(void);
sfVector3f		pos_cylinder(void);
sfVector3f		pos_cone(void);
void			put_nothing(t_my_framebuffer *, float, sfVector2i,
				    sfVector3f);
void			put_sphere(t_my_framebuffer *, float, sfVector2i,
				   sfVector3f);
void			put_cylinder(t_my_framebuffer *, float, sfVector2i,
				     sfVector3f);
void			put_plane(t_my_framebuffer *, float, sfVector2i,
				  sfVector3f);
void			put_cone(t_my_framebuffer *, float, sfVector2i,
				 sfVector3f);
sfColor			create_color(int, int, int);
sfVector3f		ini_eye(void);
sfVector3f		ini_light(void);
int			disp_shadow(int, sfVector3f, sfVector3f, sfVector3f);
int			check_env(char **);
int			match(char *, char *);

/*
**			Prototypes of file's source.
*/
sfVector3f		calc_dir_vector(float, sfVector2i, sfVector2i);
sfVector3f		calc_dir_vector_bis(sfVector2i, sfVector2i);
float			intersect_cone(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_cone(sfVector3f, float);
float			intersect_cylinder(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_cylinder(sfVector3f);
float			intersect_sphere(sfVector3f, sfVector3f, float);
sfVector3f		get_normal_sphere(sfVector3f);
float			intersect_plane(sfVector3f, sfVector3f);
sfVector3f		get_normal_plane(int);
sfVector3f		rotate_zyx(sfVector3f, sfVector3f);
sfVector3f		rotate_xyz(sfVector3f, sfVector3f);
sfVector3f		translate(sfVector3f, sfVector3f);
sfVector3f		reverse_translate(sfVector3f, sfVector3f);
float			get_light_coef(sfVector3f, sfVector3f);

#endif /* !MY_H_ */
