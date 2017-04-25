/*
** pos_object.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 16:15:29 2017 
** Last update Fri Mar 17 09:54:19 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

sfVector3f	pos_sphere(void)
{
  sfVector3f	tmp;

  tmp.x = 200;
  tmp.y = 0;
  tmp.z = 0;
  return (tmp);
}

sfVector3f	pos_plane(void)
{
  sfVector3f	tmp;

  tmp.x = 0;
  tmp.y = 0;
  tmp.z = 0;
  return (tmp);
}

sfVector3f	pos_cylinder(void)
{
  sfVector3f	tmp;

  tmp.x = 350;
  tmp.y = -100;
  tmp.z = 10;
  return (tmp);
}

sfVector3f	pos_cone(void)
{
  sfVector3f	tmp;

  tmp.x = 350;
  tmp.y = 100;
  tmp.z = 100;
  return (tmp);
}
