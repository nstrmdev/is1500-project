#include "../platform/dtekv-lib.h"

// VGA Buffer is on this address
volatile int* framebuffer = (volatile int*)0x08000000;

void handle_interrupt(void) {
}

int main(void) {
    print("Hello, World!");
}
