#include <EGL/egl.h>
#define WOIDSHELL_IMPLEMENTATION
#include "./protocol/wlr-layer-shell-unstable-v1.h"
#include "./woidshell.h"
#include <GLES2/gl2.h>

void drawfunc(void* data) {
    WS_Shell* shell = (WS_Shell*)data;
    // draw here
    eglMakeCurrent(shell->egl->display, shell->egl->surface, shell->egl->surface, shell->egl->context);
    glViewport(0, 0, shell->settings->width, shell->settings->height);
    glClearColor(0.5, 0.6, 0.7, 1.0); // six seven???? o_O?
    glClear(GL_COLOR_BUFFER_BIT);

    WS_ExecFrameCallback(shell); // DON'T FORGET TO CALL THIS FUNCTION AT THE END!!!
}

WS_Shell shell = {0};
int main(void) {
    // shell configuration
    WS_ShellSettings settings = {
        .layer = ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND, // TOP OVERLAY BOTTOM
        .width = 1920,
        .height = 1080,
        .anchor = 0,

        .exclusive_zone = 0, // idk why they named it exclusive_zone in the protocol but it's kinda like a gap:
                            // for example if you want to make a bar, 
                            // you'd set this value to the height of the bar so the windows doesn't overlap with it
                            // (see the basic-bar example)
        .margin_l = 0,
        .margin_b = 0,
        .margin_t = 0,
        .margin_r = 0,

        .drawfunc = drawfunc, // executes every frame
    };
    shell.settings = &settings;

    WS_ShellInit(&shell);

    while (!WS_ShellShouldClose(&shell)) {} // don't draw here, it's not gonna work. 
                                            // This is due to how wayland handles frames as callbacks,
                                            // intrested? read about it here in the wayland book:
                                            // https://wayland-book.com/surfaces-in-depth/frame-callbacks.html

    WS_ShellDestroy(&shell);
    return 0;
}
