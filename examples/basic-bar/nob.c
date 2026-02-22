#define NOB_IMPLEMENTATION
#include "nob.h"

Nob_Cmd cmd = {0};
int main(int argc, char *argv[]) {
    nob_cmd_append(&cmd, "gcc");
    nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb");
    nob_cmd_append(&cmd, "-lwayland-client", "-lwayland-egl", "-lEGL", "-lGLESv2");
    nob_cmd_append(&cmd, "./main.c", "./protocol/wlr-layer-shell-unstable-v1.c", "./protocol/xdg-shell.c");
    nob_cmd_append(&cmd, "-o", "basic-bar");

    if (!nob_cmd_run(&cmd)) return 1;
    return 0;
}
