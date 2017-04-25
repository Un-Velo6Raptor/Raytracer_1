/*
** cylinder.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:24:28 2017 
** Last update Fri Mar 17 10:00:50 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	tmp;

  tmp.x = intersection_point.x;
  tmp.y = intersection_point.y;
  tmp.z = 0;
  return (tmp);
}

float		discrim_cylinder(float a, float b, float c)
{
  float		k1;
  float		k2;
  float		dis;

  k1 = 0;
  k2 = 0;
  if (a == 0)
    {
      if (b == 0)
	return (-1);
      k1 = -c / b;
      return ((k1 < 0) ? -1 : k1);
    }
  dis = powf(b, 2) - (4 * a * c);
  if (dis <= 0.0f)
    return ((dis < 0) ? -1.0f : ((b * -1) / (2.0f * a)));
  k1 = ((b * -1) + sqrtf(dis)) / (2 * a);
  k2 = ((b * -1) - sqrtf(dis)) / (2 * a);
  if (k1 < 0 && k2 < 0)
    return (-1.0f);
  if (k1 < 0.0f)
    return (k2);
  if (k2 < 0.0f)
    return (k1);
  return ((k1 > k2) ? k2 : k1);
}

float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
                                   float radius)
{
  sfVector3f	tmp;

  tmp.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2);
  tmp.y = 2 * ((dir_vector.x * eye_pos.x) + (dir_vector.y * eye_pos.y));
  tmp.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2) - powf(radius, 2);
  return (discrim_cylinder(tmp.x, tmp.y, tmp.z));
}
