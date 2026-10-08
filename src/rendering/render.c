#include "../../include/rendering/render.h"
#include "../../include/entities/player.h"
#include "../../include/rendering/vga.h"
#include "../../platform/dtekv-lib.h"

// Returns the default framebuffer.
Framebuffer default_framebuffer() {
  Framebuffer f;

  // Setup buffers
  f.front_buffer = FRONT_BUFFER_ADDR;
  f.back_buffer = BACK_BUFFER_ADDR;

  // Setup resolution
  f.width = VGA_WIDTH;
  f.height = VGA_HEIGHT;
  f.stride = VGA_WIDTH;  // 320 bytes per row

  print("[INFO] Framebuffer created...\n");
  return f;
}

// Clears the screen to black.
void clear_screen(Framebuffer* f) {
  const unsigned int count = f->height * f->width;
  volatile unsigned char* pixels = f->back_buffer;

  for (int p = 0; p < count; p++) {
    pixels[p] = 0x0;
  }
}

// Draws the player onto the screen.
// TODO: Change to sprite data.
void draw_player(Framebuffer* f, Player* p) {
  int player_width = 16;
  int player_height = 16;

  int pos_x = (int)p->position.x;
  int pos_y = (int)p->position.y;

  for (int p_x = 0; p_x < player_width; p_x++) {
    for (int p_y = 0; p_y < player_height; p_y++) {
      int screen_x = pos_x + p_x;
      int screen_y = pos_y + p_y;

      // TODO: Add bounds checking to make sure we're not
      // outside the resolution bounds.

      f->back_buffer[screen_y * f->stride + screen_x] = 0xFF;  // white
    }
  }
}
