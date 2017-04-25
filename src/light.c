/*
** light.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:19:43 2017 
** Last update Mon Mar 13 16:59:42 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdio.h>
#include	<math.h>
#include	"my.h"

float		div_vec_light(sfVector3f vector)
{
  return (sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2)));
}

float		get_light_coef(sfVector3f light_vector,
			       sfVector3f normal_vector)
{
  float		result;
  float		idx1;
  float		idx2;

  result = 0.0f;
  idx1 = div_vec_light(light_vector);
  idx2 = div_vec_light(normal_vector);
  if (idx1 == 0 || idx2 == 0)
    return (0);
  light_vector.x /= idx1;
  light_vector.y /= idx1;
  light_vector.z /= idx1;
  normal_vector.x /= idx2;
  normal_vector.y /= idx2;
  normal_vector.z /= idx2;
  result = (normal_vector.x * light_vector.x) +
    (normal_vector.y * light_vector.y) +
    (normal_vector.z * light_vector.z);
  return ((result < 0) ? 0 : result);
}
