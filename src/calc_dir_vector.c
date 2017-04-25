/*
** calc_dir_vector.c for  in /home/januar_m/delivery/graphical/bsraytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Feb 11 16:54:42 2017 
** Last update Fri Mar 17 09:58:16 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	calc_dir_vector(float dis_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dis_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}

sfVector3f	calc_dir_vector_bis(sfVector2i screen_size,
				sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = (screen_size.x / 2) / tanf(25.0f * M_PI / 180.0f);
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
