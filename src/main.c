#include "../include/game_loop.h"
         "
#include "../include/player.h"
#include "../include/render.h"

void handle_interrupt(void) {
  // Handle interrupts here
}

int main(void) {
  Framebuffer frame_buffer = default_framebuffer();
  Player player = default_player();

  setup_dma(&frame_buffer);

  while (1) {
    // Get input

    // Update game state
    start_game_loop();

    // Render
    clear_screen(&frame_buffer);
    draw_player(&frame_buffer, &player);
    swap_buffer(&frame_buffer);
  }
}
