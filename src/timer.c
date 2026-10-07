#include "../include/timer.h"

volatile int* TIME_ADDRESS = (volatile int*)0x04000020;
// initialize and start the Dtek-V timer
// fps translates to number of time outs per second
void start_timer(int fps) {
  int timeout_period = 30000000 / fps - 1;          // convert fps to time between timeouts
  int tp_ls = timeout_period & 0xFFFF;              // least significant 16 bits
  int tp_ms = (timeout_period & 0xFFFF0000) >> 16;  // most significant 16 bits

  // Timer addresses (four byte offsets from each other)
  volatile int* timer_control = (volatile int*)0x04000024;
  volatile int* timer_period_l = (volatile int*)0x04000028;
  volatile int* timer_period_h = (volatile int*)0x0400002C;

  // Set the period values
  *timer_period_l = tp_ls;
  *timer_period_h = tp_ms;

  // 0110 is CONT & START
  *timer_control = 0x6;
}

// returns true if timer is timed out
int is_time_out(void) {
  return (*TIME_ADDRESS & 1);
}

// resets the time out bit (to 0)
void reset_time_out(void) {
  *TIME_ADDRESS = 0;
}

// returns current clock cycle (32 bits)
unsigned int get_clock_cycle(void) {
  unsigned int cycle;
  __asm__ volatile("csrr %0, mycycle" : "=r"(cycle));
  return cycle;
}
