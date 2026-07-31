#include <EGL/egl.h>
#define WOIDSHELL_IMPLEMENTATION
#define WOIDSHELL_OPENGL33
#include "../../protocol/wlr-layer-shell-unstable-v1.h"
#include "../../woidshell.h"
#include "./glad/glad.h"

void drawfunc(void* data) {
    WS_Shell* shell = (WS_Shell*)data;
    
    eglMakeCurrent(shell->egl->display, shell->egl->surface, shell->egl->surface, shell->egl->context);
    glViewport(0, 0, shell->settings->width, shell->settings->height);
    glClearColor(0.5, 0.6, 0.7, 1.0); 
    glClear(GL_COLOR_BUFFER_BIT);

    WS_ExecFrameCallback(shell); 
}

WS_Shell shell = {0};
int main(void) {
    
    WS_ShellSettings settings = {
        .layer = ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND, 
        .width = 1920,
        .height = 1080,
        .anchor = 0,
        .exclusive_zone = 0, 
        .margin_l = 0,
        .margin_b = 0,
        .margin_t = 0,
        .margin_r = 0,

        .drawfunc = drawfunc, 
    };
    shell.settings = &settings;

    WS_ShellInit(&shell);

    eglMakeCurrent(shell.egl->display, shell.egl->surface, shell.egl->surface, shell.egl->context); // load opengl
    if (!gladLoadGLLoader((GLADloadproc)eglGetProcAddress)) {
        printf("Failed to load opengl extentions\n");
        exit(1);
    }
    drawfunc((void*)&shell); 

    while (!WS_ShellShouldClose(&shell)) {} 
    WS_ShellDestroy(&shell);
    return 0;
}
