#include "../platform/dtekv-lib.h"
#include "../include/render.h"

void handle_interrupt(void) {
}

int main(void) {
    Framebuffer frame_buffer = default_framebuffer();
    clear_screen(frame_buffer);
}
