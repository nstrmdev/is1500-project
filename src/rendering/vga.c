#include "../../include/rendering/vga.h"
#include "../../include/rendering/render.h"
#include "../../platform/dtekv-lib.h"

// Sets the values in the DMA controller.
void setup_dma(Framebuffer* f) {
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
  DMA_BUFFER = 0;  // request swap

  while ((DMA_STATUS & 0x1) != 0) {
    // wait until hardware is ready to swap
  }

  // swap the adresses
  volatile unsigned char* temp = f->front_buffer;
  f->front_buffer = f->back_buffer;
  f->back_buffer = temp;
}
