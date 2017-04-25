/*
** sphere.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:21:47 2017 
** Last update Fri Mar 17 10:02:36 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}

float		discrim_sphere(float a, float b, float c)
{
  float		k1;
  float		k2;
  float		dis;

  k1 = 0;
  k2 = 0;
  dis = powf(b, 2.0f) - (4.0f * a * c);
  if (a == 0)
    {
      if (b == 0)
	return (-1);
      k1 = -c / b;
      return ((k1 < 0) ? -1 : k1);
    }
  if (dis <= 0.0f)
    return ((dis < 0) ? -1.0f : ((b * -1) / (2.0f * a)));
  k1 = ((b * -1.0f) + sqrtf(dis)) / (2.0f * a);
  k2 = ((b * -1.0f) - sqrtf(dis)) / (2.0f * a);
  if (k1 < 0 && k2 < 0)
    return (-1.0f);
  if (k1 < 0.0f)
    return (k2);
  if (k2 < 0.0f)
    return (k1);
  return ((k1 > k2) ? k2 : k1);
}

float		intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius)
{
  sfVector3f	tmp;

  tmp.x = powf(dir_vector.x, 2.0f) + powf(dir_vector.y, 2.0f) +
    powf(dir_vector.z, 2.0f);
  tmp.y = 2.0f * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y +
		  eye_pos.z * dir_vector.z);
  tmp.z = powf(eye_pos.x, 2.0f) + powf(eye_pos.y, 2.0f) +
    powf(eye_pos.z, 2.0f) - powf(radius, 2.0f);
  return (discrim_sphere(tmp.x, tmp.y, tmp.z));
}
