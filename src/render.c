#include "../include/render.h"
#include "../include/player.h"

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
    // Use the sprite data here later.
    int player_width = 16;
    int player_height = 16;

    for (int p_x = 0; p_x < player_width; p_x++) {
        for (int p_y = 0; p_y < player_height; p_y++) {
            int screen_x = p.position.x + p_x;
            int screen_y = p.position.y + p_y;
            f.pixels[screen_y * f.stride + screen_x] = 0xFF; // white
        }
    }
}
