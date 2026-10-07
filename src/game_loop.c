#include "timer.h"
int is_running;

void start_game_loop(void) {
  const int fps = 60;
  int is_running = 1;
  start_timer(fps);
  
  while (is_running) {
    if (is_time_out()) {
      // Update game and render stuff goes here
      reset_time_out();
    }
    
  }
}

void stop_game_loop(void){
    is_running = 0;
}

