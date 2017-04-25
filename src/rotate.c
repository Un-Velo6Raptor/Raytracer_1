/*
** rotate.c for  in /home/januar_m/delivery/graphical/raytracer1/src
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 14:19:18 2017 
** Last update Fri Mar 17 09:59:16 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<math.h>
#include	"my.h"

sfVector3f	rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;
  float		save;

  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  tmp.x = to_rotate.x;
  tmp.y = (to_rotate.y * cosf(angles.x)) + (to_rotate.z * -sinf(angles.x));
  tmp.z = (to_rotate.y * sinf(angles.x)) + (to_rotate.z * cosf(angles.x));
  save = tmp.x;
  tmp.x = (tmp.z * sinf(angles.y)) + (tmp.x * cosf(angles.y));
  tmp.y = tmp.y;
  tmp.z = (tmp.z * cosf(angles.y)) + (save * -sinf(angles.y));
  save = tmp.x;
  tmp.x = (tmp.x * cosf(angles.z)) + (tmp.y * -sinf(angles.z));
  tmp.y = (save * sinf(angles.z)) + (tmp.y * cosf(angles.z));
  tmp.z = tmp.z;
  return (tmp);
}

sfVector3f	rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  sfVector3f	tmp;
  float		save;

  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  save = to_rotate.x;
  tmp.x = (to_rotate.x * cosf(angles.z)) + (to_rotate.y * -sinf(angles.z));
  tmp.y = (save * sinf(angles.z)) + (to_rotate.y * cosf(angles.z));
  tmp.z = to_rotate.z;
  save = tmp.x;
  tmp.x = (tmp.z * sinf(angles.y)) + (tmp.x * cosf(angles.y));
  tmp.y = tmp.y;
  tmp.z = (tmp.z * cosf(angles.y)) + (save * -sinf(angles.y));
  tmp.x = tmp.x;
  save = tmp.y;
  tmp.y = (tmp.y * cosf(angles.x)) + (tmp.z * -sinf(angles.x));
  tmp.z = (save * sinf(angles.x)) + (tmp.z * cosf(angles.x));
  return (tmp);
}
