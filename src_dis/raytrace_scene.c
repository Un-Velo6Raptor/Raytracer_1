/*
** raytrace_scene.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 13:17:19 2017 
** Last update Sat Mar 11 00:41:28 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdlib.h>
#include	"framefuffer.h"
#include	"my.h"

int		raytrace_scene(t_my_framebuffer *buffer)
{
  sfVector3f	eye;
  sfVector2i	tmp;
  sfVector2i	size;
  int		x;
  int		y;

  y = 0;
  eye = ini_eye();
  size = create_vector2i(buffer->width, buffer->height);
  while (y < buffer->height)
    {
      x = 0;
      while (x < buffer->width)
	{
	  tmp = create_vector2i(x, y);
	  find_nearest_point(buffer, tmp, calc_dir_vector_bis(size, tmp), eye);
	  x++;
	}
      y++;
    }
  return (0);
}
