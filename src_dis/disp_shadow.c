/*
** disp_shadow.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Sat Mar 11 04:50:13 2017 
** Last update Tue Mar 21 14:28:52 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	"my.h"

int		disp_shadow(int mode, sfVector3f intersection_point,
			    sfVector3f light_vector, sfVector3f eye)
{
  float		tmp;

  tmp = 0;
  (void) eye;
  if (mode != 1 &&
      (tmp = intersect_sphere(reverse_translate(intersection_point,
						pos_sphere()),
			      light_vector, 50)) < 0.999f && tmp > 0)
    return (0);
  if (mode != 3 &&
      (tmp = intersect_cylinder(reverse_translate(intersection_point,
						  pos_cylinder()),
				light_vector, 40)) < 0.999f && tmp > 0)
    return (0);
  if (mode != 4 &&
      (tmp = intersect_cone(reverse_translate(intersection_point,
					      pos_cone()),
			    light_vector, 20)) < 0.999f && tmp > 0)
    return (0);
  return (1);
}
