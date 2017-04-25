/*
** cone.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:36:19 2017 
** Last update Sat Mar 18 15:29:28 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	get_normal_cone(sfVector3f intersection_point,
				float semiangle)
{
  float		rad;

  rad = semiangle * M_PI / 180;
  if (intersection_point.z <= 0)
    intersection_point.z = -tanf(rad) * intersection_point.z;
  else
    intersection_point.z = tanf(rad) * intersection_point.z;
  return (intersection_point);
}

float		discrim_cone(float a, float b, float c)
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
  dis = pow(b, 2) - (4 * a * c);
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

float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
                               float semiangle)
{
  sfVector3f	tmp;

  semiangle = (semiangle) * (M_PI / 180);
  tmp.x = powf(dir_vector.x, 2) + powf(dir_vector.y, 2) -
    (powf(dir_vector.z, 2) * (powf(tanf(semiangle), 2)));
  tmp.y = 2 * (eye_pos.x * dir_vector.x + eye_pos.y * dir_vector.y -
                 ((eye_pos.z * dir_vector.z) * powf(tanf(semiangle), 2)));
  tmp.z = powf(eye_pos.x, 2) + powf(eye_pos.y, 2) -
    (powf(eye_pos.z, 2) * powf(tanf(semiangle), 2));
  return (discrim_cone(tmp.x, tmp.y, tmp.z));
}
