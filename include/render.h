#ifndef RENDER_H
#define RENDER_H

#include "player.h"

// Represents our framebuffer.
typedef struct {
    volatile unsigned char* front_buffer;  // the buffer that gets displayed
    volatile unsigned char* back_buffer;   // the buffer that we change
    unsigned int width;
    unsigned int height;
    unsigned int stride; // pixels per row
} Framebuffer;

// VGA constants.
#define VGA_WIDTH  320
#define VGA_HEIGHT 240

// Screen buffer addresses.
#define FRONT_BUFFER_ADDR (volatile unsigned char*)0x08000000
#define BACK_BUFFER_ADDR (volatile unsigned char*)0x08012C00

// Holds DMA addresses.
#define DMA_BUFFER (*(volatile unsigned int*)0x04000100)      // buffer data
#define DMA_BACK_BUFFER (*(volatile unsigned int*)0x04000104) // back buffer data
#define DMA_STATUS (*(volatile unsigned int*)0x0400010C)      // holds status data

// Function declarations.
Framebuffer default_framebuffer();
void clear_screen(Framebuffer* f);
void draw_player(Framebuffer* f, Player* p);
void setup_dma(Framebuffer *f);
void swap_buffer(Framebuffer* f);

#endif
