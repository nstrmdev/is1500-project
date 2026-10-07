#include "../platform/dtekv-lib.h"
#include "../include/render.h"
#include "../include/player.h"

// Returns the default framebuffer.
Framebuffer default_framebuffer() {
    Framebuffer f;

    // Setup buffers
    f.front_buffer = FRONT_BUFFER_ADDR;
    f.back_buffer = BACK_BUFFER_ADDR;

    // Setup resolution
    f.width = VGA_WIDTH;
    f.height = VGA_HEIGHT;
    f.stride = VGA_WIDTH; // 320 bytes per row

    print("[INFO] Framebuffer created...\n");
    return f;
}

// Sets the values in the DMA controller.
void setup_dma(Framebuffer *f) {
    f->front_buffer = (volatile unsigned char*)DMA_BUFFER;
    f->back_buffer = (volatile unsigned char*)DMA_BACK_BUFFER;

    if (f->front_buffer == FRONT_BUFFER_ADDR) {
        f->back_buffer = BACK_BUFFER_ADDR;
    } else {
        f->back_buffer = FRONT_BUFFER_ADDR;
    }

    DMA_BACK_BUFFER = (unsigned int)f->back_buffer;
    print("[INFO] DMA initialized...\n");
}

// Swaps the current buffer.
void swap_buffer(Framebuffer* f) {
    DMA_BACK_BUFFER = (unsigned int)f->back_buffer;
    DMA_BUFFER = 0; // request swap

    while ((DMA_STATUS & 0x1) != 0) {
        // wait until hardware is ready to swap
    }

    // swap the adresses
    volatile unsigned char* temp = f->front_buffer;
    f->front_buffer = f->back_buffer;
    f->back_buffer = temp;
}

// Clears the screen to black.
void clear_screen(Framebuffer* f) {
    for (int y = 0; y < f->height; y++) {
        for (int x = 0; x < f->width; x++) {
            f->back_buffer[y * f->stride + x] = 0x0; // black
        }
    }
}

// Draws the player onto the screen.
// TODO: Change to sprite data.
void draw_player(Framebuffer *f, Player *p) {
    int player_width = 16;
    int player_height = 16;

    for (int p_x = 0; p_x < player_width; p_x++) {
        for (int p_y = 0; p_y < player_height; p_y++) {
            int screen_x = p->position.x + p_x;
            int screen_y = p->position.y + p_y;
            f->back_buffer[screen_y * f->stride + screen_x] = 0xFF; // white
        }
    }
}
