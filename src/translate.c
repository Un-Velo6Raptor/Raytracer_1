/*
** translate.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Thu Feb 23 13:31:43 2017 
** Last update Fri Mar 17 09:57:48 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

sfVector3f	translate(sfVector3f to_translate,
			  sfVector3f translations)
{
  sfVector3f	tmp;

  tmp.x = to_translate.x + translations.x;
  tmp.y = to_translate.y + translations.y;
  tmp.z = to_translate.z + translations.z;
  return (tmp);
}

sfVector3f	reverse_translate(sfVector3f to_translate,
				  sfVector3f translations)
{
  sfVector3f	tmp;

  tmp.x = to_translate.x - translations.x;
  tmp.y = to_translate.y - translations.y;
  tmp.z = to_translate.z - translations.z;
  return (tmp);
}
