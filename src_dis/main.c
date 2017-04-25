/*
** main.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 09:43:27 2017 
** Last update Sun Mar 19 22:58:56 2017 
*/

#include	<stdlib.h>
#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	"framefuffer.h"
#include	"my.h"

int			main(int argc, char **argv, char **env)
{
  t_my_framebuffer	*buffer;
  t_core_window		needs;

  (void) argc;
  (void) argv;
  if (check_env(env) == 1)
    return (84);
  if ((buffer = my_framebuffer_create(1000, 1000)) == NULL ||
      (needs.window = create_window("Ray Teacher", buffer->width,
				    buffer->height)) == NULL)
    return (MALLOC_FAILED);
  needs.sprite = sfSprite_create();
  needs.texture = sfTexture_create(buffer->width, buffer->height);
  sfSprite_setTexture(needs.sprite, needs.texture, sfTrue);
  creator_loop(buffer, &needs);
  return (0);
}
