/*
** put_mode.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Fri Mar 10 18:19:41 2017 
** Last update Fri Mar 17 10:08:40 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"framefuffer.h"
#include	"my.h"

void		put_nothing(t_my_framebuffer *buffer, float dist,
			    sfVector2i pos, sfVector3f dir_vector)
{
  (void) buffer;
  (void) dist;
  (void) pos;
  (void) dir_vector;
}

void		put_sphere(t_my_framebuffer *buffer, float dist,
			   sfVector2i pos, sfVector3f dir_vector)
{
  sfVector3f	light;
  sfVector3f	intersection_point;
  sfVector3f	light_vector;
  sfVector3f	eye;
  sfColor	color;

  light = reverse_translate(ini_eye(), ini_light());
  eye = reverse_translate(ini_eye(), pos_sphere());
  color = sfRed;
  intersection_point.x = eye.x + (dist * dir_vector.x);
  intersection_point.y = eye.y + (dist * dir_vector.y);
  intersection_point.z = eye.z + (dist * dir_vector.z);
  light_vector.x = light.x - intersection_point.x;
  light_vector.y = light.y - intersection_point.y;
  light_vector.z = light.z - intersection_point.z;
  color.a *= get_light_coef(light_vector, intersection_point);
  my_put_pixel(buffer, pos.x, pos.y, color);
}

void		put_cylinder(t_my_framebuffer *buffer, float dist,
			     sfVector2i pos, sfVector3f dir_vector)
{
  sfVector3f	light;
  sfVector3f	intersection_point;
  sfVector3f	light_vector;
  sfVector3f	eye;
  sfColor	color;

  light = reverse_translate(ini_eye(), ini_light());
  eye = reverse_translate(ini_eye(), pos_cylinder());
  color = create_color(230, 100, 57);
  intersection_point.x = eye.x + (dist * dir_vector.x);
  intersection_point.y = eye.y + (dist * dir_vector.y);
  intersection_point.z = eye.z + (dist * dir_vector.z);
  light_vector.x = light.x - intersection_point.x;
  light_vector.y = light.y - intersection_point.y;
  light_vector.z = light.z - intersection_point.z;
  color.a *= get_light_coef(light_vector,
			    get_normal_cylinder(intersection_point));
  my_put_pixel(buffer, pos.x, pos.y, color);
}

void		put_plane(t_my_framebuffer *buffer, float dist,
			  sfVector2i pos, sfVector3f dir_vector)
{
  sfVector3f	light;
  sfVector3f	intersection_point;
  sfVector3f	light_vector;
  sfVector3f	eye;
  sfColor	color;

  light = reverse_translate(ini_eye(), ini_light());
  eye = reverse_translate(ini_eye(), pos_plane());
  color = sfBlue;
  intersection_point.x = eye.x + (dist * dir_vector.x);
  intersection_point.y = eye.y + (dist * dir_vector.y);
  intersection_point.z = eye.z + (dist * dir_vector.z);
  light_vector.x = light.x - intersection_point.x;
  light_vector.y = light.y - intersection_point.y;
  light_vector.z = light.z - intersection_point.z;
  color.a *= get_light_coef(light_vector,
			    get_normal_plane((eye.z > light.z) ? 0 : 1));
  color.a *= disp_shadow(2, intersection_point, light_vector, eye);
  my_put_pixel(buffer, pos.x, pos.y, color);
}

void		put_cone(t_my_framebuffer *buffer, float dist,
			 sfVector2i pos, sfVector3f dir_vector)
{
  sfVector3f	light;
  sfVector3f	intersection_point;
  sfVector3f	light_vector;
  sfVector3f	eye;
  sfColor	color;

  light = reverse_translate(ini_eye(), ini_light());
  eye = reverse_translate(ini_eye(), pos_cone());
  color = create_color(113, 89, 200);
  intersection_point.x = eye.x + (dist * dir_vector.x);
  intersection_point.y = eye.y + (dist * dir_vector.y);
  intersection_point.z = eye.z + (dist * dir_vector.z);
  light_vector.x = light.x - intersection_point.x;
  light_vector.y = light.y - intersection_point.y;
  light_vector.z = light.z - intersection_point.z;
  color.a *= get_light_coef(light_vector,
			    get_normal_cone(intersection_point, 20));
  my_put_pixel(buffer, pos.x, pos.y, color);
}
