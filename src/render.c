#include "../include/render.h"
#include "../include/player.h""

// Returns the default framebuffer.
Framebuffer default_framebuffer() {
    Framebuffer f;
    f.width = VGA_WIDTH;
    f.height = VGA_HEIGHT;
    f.pixels = (volatile unsigned char*)0x08000000;
    f.stride = VGA_WIDTH; // 320 bytes per row

    return f;
}

// Clears the screen to black.
void clear_screen(Framebuffer f) {
    for (int y = 0; y < f.height; y++) {
        for (int x = 0; x < f.width; x++) {
            f.pixels[y * f.stride + x] = 0x0; // black
        }
    }
}

void draw_player(Framebuffer f, Player p) {

}
