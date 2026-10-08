#ifndef TIMER_H
#define TIMER_H

// function declaration
void start_timer(int fps);
int is_time_out(void);
void reset_time_out(void);
unsigned int get_clock_cycle(void);

#endif
