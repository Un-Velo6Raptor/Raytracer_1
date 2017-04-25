/*
** eye_light_pos.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 10 18:46:39 2017 
** Last update Wed Mar 15 21:14:10 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

sfVector3f      ini_eye(void)
{
  sfVector3f    tmp;

  tmp.x = 0;
  tmp.y = 0;
  tmp.z = 50;
  return (tmp);
}

sfVector3f      ini_light(void)
{
  sfVector3f    tmp;

  tmp.x = 300;
  tmp.y = -200;
  tmp.z = -200;
  return (tmp);
}
