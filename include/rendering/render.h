#ifndef RENDER_H
#define RENDER_H

#include "../entities/player.h"

// Represents our framebuffer.
typedef struct {
  volatile unsigned char* front_buffer;  // the buffer that gets displayed
  volatile unsigned char* back_buffer;   // the buffer that we change
  unsigned int width;
  unsigned int height;
  unsigned int stride;  // pixels per row
} Framebuffer;

// Function declarations.
Framebuffer default_framebuffer();
void clear_screen(Framebuffer* f);
void draw_player(Framebuffer* f, Player* p);

#endif
