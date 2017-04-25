/*
** create_vector.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 16:06:45 2017 
** Last update Wed Mar  8 16:07:56 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

sfVector2i	create_vector2i(int x, int y)
{
  sfVector2i	tmp;

  tmp.x = x;
  tmp.y = y;
  return (tmp);
}
