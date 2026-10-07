#include "../include/timer.h"

int is_running;

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

void start_game_loop(void) {
  // Acumulative delta time
  const unsigned int FPS = 60;
  const unsigned int CLOCK_SPEED = 30000000;
  const unsigned int DELTA_CYCLES = CLOCK_SPEED / FPS;
  unsigned int accumalator = 0;
  unsigned int previous_cycles = get_clock_cycle();  // TODO: implement get_clock_cycle in asm

  int is_running = 1;

  while (is_running) {
    unsigned int current_cycles = get_clock_cycle();
    unsigned int elapsed_cycles = current_cycles - previous_cycles;
    previous_cycles = current_cycles;

    accumalator += elapsed_cycles;

    while (accumalator >= DELTA_CYCLES) {
      // UPDATE GAME
      accumalator -= DELTA_CYCLES;
    }

    // RENDER GAME
  }
}

void stop_game_loop(void) {
  is_running = 0;
}
