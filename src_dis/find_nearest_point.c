/*
** find_nearest_point.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 16:03:36 2017 
** Last update Tue Mar 21 14:28:58 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Color.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

sfVector2f	set_mode_vector(float x, float y)
{
  sfVector2f	tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}

void		find_nearest_point(t_my_framebuffer *buffer, sfVector2i pos,
				   sfVector3f dir_vector, sfVector3f eye)
{
  void		(*put_mode[5])(t_my_framebuffer *, float,
			       sfVector2i, sfVector3f) =
    {put_nothing, put_sphere, put_plane, put_cylinder, put_cone};
  sfVector2f	mode;
  float		tmp;

  mode.x = 0.0f;
  mode.y = 0.0f;
  tmp = 0.0f;
  if ((tmp = intersect_sphere(reverse_translate(eye, pos_sphere()),
			      dir_vector, 50)) > 0)
    mode = set_mode_vector(tmp, 1.0f);
  if ((tmp = intersect_plane(reverse_translate(eye, pos_plane()),
			     dir_vector)) > 0 &&
      (tmp < mode.x || mode.y == 0))
    mode = set_mode_vector(tmp, 2.0f);
  if ((tmp = intersect_cylinder(reverse_translate(eye, pos_cylinder()),
				dir_vector, 40)) > 0 &&
      (tmp < mode.x || mode.y == 0))
    mode = set_mode_vector(tmp, 3.0f);
  if ((tmp = intersect_cone(reverse_translate(eye, pos_cone()),
			    dir_vector, 20)) > 0 &&
      (tmp < mode.x || mode.y == 0))
    mode = set_mode_vector(tmp, 4.0f);
  put_mode[(int) mode.y](buffer, mode.x, pos, dir_vector);
}
