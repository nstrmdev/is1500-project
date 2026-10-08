#include "../include/entities/player.h"
#include "../include/io/timer.h"
#include "../include/rendering/render.h"
#include "../include/rendering/vga.h"
#include "../platform/dtekv-lib.h"

/*void start_game_loop(void) {
  const int fps = 60;
  int is_running = 1;
  start_timer(fps);

  while (is_running) {
    if (is_time_out()) {
      // Update game and render stuff goes here
      reset_time_out();
    }

  }
}*/

void handle_interrupt() {
  // Handle interrupts
}

int main(void) {
  print("Started");
  int running = 1;

  Framebuffer frame_buffer = default_framebuffer();
  Player player = default_player();
  PlayerConfig player_cfg = default_player_config();

  setup_dma(&frame_buffer);

  // Delta time
  const unsigned int TICK_RATE = 60;
  const unsigned int CLOCK_SPEED = 30000000;
  const unsigned int DELTA_CYCLES = CLOCK_SPEED / TICK_RATE;
  // TODO: Measure if this does anything bad for performance
  const float DELTA_TIME = 1.0f / 60.0f;

  unsigned int accumalator = 0;
  unsigned int previous_cycles = get_clock_cycle();

  while (running) {
    unsigned int current_cycles = get_clock_cycle();
    unsigned int elapsed_cycles = current_cycles - previous_cycles;
    previous_cycles = current_cycles;

    accumalator += elapsed_cycles;

    while (accumalator >= DELTA_CYCLES) {
      Vec2 input_dir = (Vec2){1.0, 0.0};
      player_move(&player, &player_cfg, input_dir, DELTA_TIME);

      accumalator -= DELTA_CYCLES;
    }

    // Draw
    clear_screen(&frame_buffer);
    draw_player(&frame_buffer, &player);
    swap_buffer(&frame_buffer);
  }
}
