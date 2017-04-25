/*
** create_color.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 10 18:27:53 2017 
** Last update Fri Mar 10 18:29:46 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Color.h>
#include	"my.h"

sfColor		create_color(int r, int g, int b)
{
  sfColor	tmp;

  tmp.r = r;
  tmp.g = g;
  tmp.b = b;
  tmp.a = 255;
  return (tmp);
}
