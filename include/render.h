// Represents our framebuffer.
typedef struct {
    volatile unsigned char* pixels;
    unsigned int width;
    unsigned int height;
    unsigned int stride;
} Framebuffer;

// VGA constants.
enum {
    VGA_WIDTH = 320,
    VGA_HEIGHT = 240,
};

// Function declarations.
Framebuffer default_framebuffer();
void clear_screen(Framebuffer f);
