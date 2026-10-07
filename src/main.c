#include "game_loop.h"

// VGA Buffer is on this address
volatile int* framebuffer = (volatile int*)0x08000000;

int main(void) {
  // start Infinite game loop
  start_game_loop();
}
