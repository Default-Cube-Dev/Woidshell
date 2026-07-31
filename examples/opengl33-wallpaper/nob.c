#define NOB_IMPLEMENTATION
#include "./../nob.h"

int main(int argc, char *argv[]) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};

    nob_cmd_append(&cmd, "gcc");
    nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb");
    nob_cmd_append(&cmd, "-lwayland-client", "-lwayland-egl", "-lEGL", "-lGL");
    nob_cmd_append(&cmd, "./main.c", ".../../protocol/wlr-layer-shell-unstable-v1.c", "../../protocol/xdg-shell.c", "./glad.c");
    nob_cmd_append(&cmd, "-o", "opengl33-wallpaper");

    if (!nob_cmd_run(&cmd)) return 1;
    return 0;
}
