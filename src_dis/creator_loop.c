/*
** creator_loop.c for  in /home/januar_m/delivery/graphical/raytracer1
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Mar  8 10:05:27 2017 
** Last update Wed Mar  8 13:12:23 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	"framefuffer.h"
#include	"my.h"

void		creator_loop(t_my_framebuffer *buffer,
			    t_core_window *needs)
{
  sfEvent	event;

  raytrace_scene(buffer);
  sfTexture_updateFromPixels(needs->texture, buffer->pixels,
			     buffer->width, buffer->height, 0, 0);
  while (sfRenderWindow_isOpen(needs->window))
    {
      sfRenderWindow_clear(needs->window, sfBlack);
      while (sfRenderWindow_pollEvent(needs->window, &event))
	{
	  if (event.type == sfEvtClosed ||
	      sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
	    sfRenderWindow_close(needs->window);
	}
      sfRenderWindow_drawSprite(needs->window, needs->sprite, NULL);
      sfRenderWindow_display(needs->window);
    }
  sfRenderWindow_destroy(needs->window);
}
