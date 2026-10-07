#include "../platform/dtekv-lib.h"
#include "../include/render.h"
#include "../include/player.h"

void handle_interrupt(void) {
}

int main(void) {
    Framebuffer frame_buffer = default_framebuffer();
    Player player = default_player();

    while (1) {
        draw_player(frame_buffer, player);
        clear_screen(frame_buffer);
    }
}
