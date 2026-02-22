#include <EGL/egl.h>
#define WOIDSHELL_IMPLEMENTATION
#include "./protocol/wlr-layer-shell-unstable-v1.h"
#include "./woidshell.h"
#include <GLES2/gl2.h>

void drawfunc(void* data) {
    WS_Shell* shell = (WS_Shell*)data;
    eglMakeCurrent(shell->egl->display, shell->egl->surface, shell->egl->surface, shell->egl->context);
    glViewport(0, 0, shell->settings->width, shell->settings->height);
    glClearColor(0.6, 0.7, 0.5, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    WS_ExecFrameCallback(shell); 
}

WS_Shell shell = {0};
int main(void) {
    WS_ShellSettings settings = {
        .layer = ZWLR_LAYER_SHELL_V1_LAYER_TOP, 
        .width = 1900,
        .height = 30,
        .anchor = ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP+ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT+ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT,

        .exclusive_zone = 30,

        .margin_l = 10,
        .margin_b = 0,
        .margin_t = 10,
        .margin_r = 10,

        .drawfunc = drawfunc, 
    };
    shell.settings = &settings;

    WS_ShellInit(&shell);

    while (!WS_ShellShouldClose(&shell)) {} 
                                            
    WS_ShellDestroy(&shell);
    return 0;
}
