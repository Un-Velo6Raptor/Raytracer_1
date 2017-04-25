/*
** plane.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:23:03 2017 
** Last update Fri Mar 17 09:59:56 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	tmp;

  tmp.x = 0;
  tmp.y = 0;
  if (upward == 1)
    tmp.z = 1;
  else if (upward == 0)
    tmp.z = -1;
  return (tmp);
}

float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float		result;

  result = 0;
  if (dir_vector.z == 0)
    return (-1);
  result = (eye_pos.z * -1) / dir_vector.z;
  if (result < 0)
    return (-1);
  return (result);
}
