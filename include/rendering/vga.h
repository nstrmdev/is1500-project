#ifndef VGA_H
#define VGA_H

#include "render.h"

// VGA constants.
#define VGA_WIDTH 320
#define VGA_HEIGHT 240

// Screen buffer addresses.
#define FRONT_BUFFER_ADDR (volatile unsigned char*)0x08000000
#define BACK_BUFFER_ADDR (volatile unsigned char*)0x08012C00

// Holds DMA addresses.
#define DMA_BUFFER (*(volatile unsigned int*)0x04000100)       // buffer data
#define DMA_BACK_BUFFER (*(volatile unsigned int*)0x04000104)  // back buffer data
#define DMA_STATUS (*(volatile unsigned int*)0x0400010C)       // holds status data

// Function declarations
void setup_dma(Framebuffer* f);
void swap_buffer(Framebuffer* f);

#endif
