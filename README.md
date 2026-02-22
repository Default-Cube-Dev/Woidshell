### woidshell - a single-header* layer SHELL library for Wayland that has vOID dependencies

### Why? 

wanna skip the yapping? [do it](#quickstart)!

Once upon a time... I woke up, it was a pecefull, sunny day. I checked reddit, everyone was really exited about that new kitty patch because it increased performance by quite a good amount. 
So I ran a quick little sudo pacman -Syu, but because I was using arch btw, my waybar broke because gtk updated.
When I saw the error I was curios about waybar's dependencies, so I checked it with ldd and oh boy, ts is so heavy:

```ldd
	linux-vdso.so.1 (0x00007fd98c879000)
	libwayland-client.so.0 => /usr/lib/libwayland-client.so.0 (0x00007fd98c835000)
	libfmt.so.12 => /usr/lib/libfmt.so.12 (0x00007fd98c5dc000)
	libspdlog.so.1.16 => /usr/lib/libspdlog.so.1.16 (0x00007fd98c587000)
	libsigc-2.0.so.0 => /usr/lib/libsigc-2.0.so.0 (0x00007fd98c57f000)
	libjsoncpp.so.26 => /usr/lib/libjsoncpp.so.26 (0x00007fd98c541000)
	libgtkmm-3.0.so.1 => /usr/lib/libgtkmm-3.0.so.1 (0x00007fd98c000000)
	libatkmm-1.6.so.1 => /usr/lib/libatkmm-1.6.so.1 (0x00007fd98c4ef000)
	libgdkmm-3.0.so.1 => /usr/lib/libgdkmm-3.0.so.1 (0x00007fd98c498000)
	libgiomm-2.4.so.1 => /usr/lib/libgiomm-2.4.so.1 (0x00007fd98be2c000)
	libgtk-3.so.0 => /usr/lib/libgtk-3.so.0 (0x00007fd98b600000)
	libgdk-3.so.0 => /usr/lib/libgdk-3.so.0 (0x00007fd98bd40000)
	libglibmm-2.4.so.1 => /usr/lib/libglibmm-2.4.so.1 (0x00007fd98b575000)
	libcairomm-1.0.so.1 => /usr/lib/libcairomm-1.0.so.1 (0x00007fd98c46f000)
	libgio-2.0.so.0 => /usr/lib/libgio-2.0.so.0 (0x00007fd98b3a3000)
	libgobject-2.0.so.0 => /usr/lib/libgobject-2.0.so.0 (0x00007fd98b344000)
	libglib-2.0.so.0 => /usr/lib/libglib-2.0.so.0 (0x00007fd98b1ec000)
	libdbusmenu-gtk3.so.4 => /usr/lib/libdbusmenu-gtk3.so.4 (0x00007fd98c45c000)
	libinput.so.10 => /usr/lib/libinput.so.10 (0x00007fd98b188000)
	libnl-3.so.200 => /usr/lib/libnl-3.so.200 (0x00007fd98bd1f000)
	libnl-genl-3.so.200 => /usr/lib/libnl-genl-3.so.200 (0x00007fd98c455000)
	libupower-glib.so.3 => /usr/lib/libupower-glib.so.3 (0x00007fd98b165000)
	libpipewire-0.3.so.0 => /usr/lib/libpipewire-0.3.so.0 (0x00007fd98b0a3000)
	libplayerctl.so.2 => /usr/lib/libplayerctl.so.2 (0x00007fd98bd07000)
	libpulse.so.0 => /usr/lib/libpulse.so.0 (0x00007fd98b053000)
	libjack.so.0 => /usr/lib/libjack.so.0 (0x00007fd98b019000)
	libwireplumber-0.5.so.0 => /usr/lib/libwireplumber-0.5.so.0 (0x00007fd98af8c000)
	libudev.so.1 => /usr/lib/libudev.so.1 (0x00007fd98af44000)
	libmpdclient.so.2 => /usr/lib/libmpdclient.so.2 (0x00007fd98af1b000)
	libevdev.so.2 => /usr/lib/libevdev.so.2 (0x00007fd98af06000)
	libgtk-layer-shell.so.0 => /usr/lib/libgtk-layer-shell.so.0 (0x00007fd98aec8000)
	libsndio.so.7 => /usr/lib/libsndio.so.7 (0x00007fd98aeb5000)
	libxkbregistry.so.0 => /usr/lib/libxkbregistry.so.0 (0x00007fd98aeaa000)
	libcava.so => /usr/lib/libcava.so (0x00007fd98ae7d000)
	libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0x00007fd98aa00000)
	libm.so.6 => /usr/lib/libm.so.6 (0x00007fd98ad6f000)
	libgcc_s.so.1 => /usr/lib/libgcc_s.so.1 (0x00007fd98ad42000)
	libc.so.6 => /usr/lib/libc.so.6 (0x00007fd98a600000)
	libffi.so.8 => /usr/lib/libffi.so.8 (0x00007fd98ad36000)
	/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007fd98c87b000)
	libpangomm-1.4.so.1 => /usr/lib/libpangomm-1.4.so.1 (0x00007fd98ad04000)
	libatk-1.0.so.0 => /usr/lib/libatk-1.0.so.0 (0x00007fd98acde000)
	libgdk_pixbuf-2.0.so.0 => /usr/lib/libgdk_pixbuf-2.0.so.0 (0x00007fd98aca6000)
	libgmodule-2.0.so.0 => /usr/lib/libgmodule-2.0.so.0 (0x00007fd98bd00000)
	libpangocairo-1.0.so.0 => /usr/lib/libpangocairo-1.0.so.0 (0x00007fd98ac96000)
	libpango-1.0.so.0 => /usr/lib/libpango-1.0.so.0 (0x00007fd98a995000)
	libcairo.so.2 => /usr/lib/libcairo.so.2 (0x00007fd98a858000)
	libharfbuzz.so.0 => /usr/lib/libharfbuzz.so.0 (0x00007fd98a4c8000)
	libpangoft2-1.0.so.0 => /usr/lib/libpangoft2-1.0.so.0 (0x00007fd98a83a000)
	libfontconfig.so.1 => /usr/lib/libfontconfig.so.1 (0x00007fd98a477000)
	libfribidi.so.0 => /usr/lib/libfribidi.so.0 (0x00007fd98a81a000)
	libcairo-gobject.so.2 => /usr/lib/libcairo-gobject.so.2 (0x00007fd98a46e000)
	libepoxy.so.0 => /usr/lib/libepoxy.so.0 (0x00007fd98a361000)
	libXi.so.6 => /usr/lib/libXi.so.6 (0x00007fd98a34e000)
	libX11.so.6 => /usr/lib/libX11.so.6 (0x00007fd98a20d000)
	libatk-bridge-2.0.so.0 => /usr/lib/libatk-bridge-2.0.so.0 (0x00007fd98a1d1000)
	libcloudproviders.so.0 => /usr/lib/libcloudproviders.so.0 (0x00007fd98a1b9000)
	libtinysparql-3.0.so.0 => /usr/lib/libtinysparql-3.0.so.0 (0x00007fd98a0e7000)
	libXfixes.so.3 => /usr/lib/libXfixes.so.3 (0x00007fd98a812000)
	libxkbcommon.so.0 => /usr/lib/libxkbcommon.so.0 (0x00007fd98a08a000)
	libwayland-cursor.so.0 => /usr/lib/libwayland-cursor.so.0 (0x00007fd98a07e000)
	libwayland-egl.so.1 => /usr/lib/libwayland-egl.so.1 (0x00007fd98a079000)
	libXext.so.6 => /usr/lib/libXext.so.6 (0x00007fd98a064000)
	libXcursor.so.1 => /usr/lib/libXcursor.so.1 (0x00007fd98a057000)
	libXdamage.so.1 => /usr/lib/libXdamage.so.1 (0x00007fd98a052000)
	libXcomposite.so.1 => /usr/lib/libXcomposite.so.1 (0x00007fd98a04d000)
	libXrandr.so.2 => /usr/lib/libXrandr.so.2 (0x00007fd98a03e000)
	libXinerama.so.1 => /usr/lib/libXinerama.so.1 (0x00007fd98a039000)
	libz.so.1 => /usr/lib/libz.so.1 (0x00007fd98a020000)
	libmount.so.1 => /usr/lib/libmount.so.1 (0x00007fd989fca000)
	libpcre2-8.so.0 => /usr/lib/libpcre2-8.so.0 (0x00007fd989f1c000)
	libdbusmenu-glib.so.4 => /usr/lib/libdbusmenu-glib.so.4 (0x00007fd989efd000)
	libmtdev.so.1 => /usr/lib/libmtdev.so.1 (0x00007fd989ef6000)
	libwacom.so.9 => /usr/lib/libwacom.so.9 (0x00007fd989ee5000)
	libpulsecommon-17.0.so => /usr/lib/pulseaudio/libpulsecommon-17.0.so (0x00007fd989e65000)
	libdbus-1.so.3 => /usr/lib/libdbus-1.so.3 (0x00007fd989e12000)
	libcap.so.2 => /usr/lib/libcap.so.2 (0x00007fd989e04000)
	libasound.so.2 => /usr/lib/libasound.so.2 (0x00007fd989d1c000)
	libbsd.so.0 => /usr/lib/libbsd.so.0 (0x00007fd989d07000)
	libxml2.so.16 => /usr/lib/libxml2.so.16 (0x00007fd989bd2000)
	libiniparser.so.4 => /usr/lib/libiniparser.so.4 (0x00007fd989bcb000)
	libfftw3.so.3 => /usr/lib/libfftw3.so.3 (0x00007fd989800000)
	libncursesw.so.6 => /usr/lib/libncursesw.so.6 (0x00007fd989b5a000)
	libportaudio.so.2 => /usr/lib/libportaudio.so.2 (0x00007fd989b2c000)
	libpulse-simple.so.0 => /usr/lib/libpulse-simple.so.0 (0x00007fd989b25000)
	libSDL2-2.0.so.0 => /usr/lib/libSDL2-2.0.so.0 (0x00007fd989ac2000)
	libGL.so.1 => /usr/lib/libGL.so.1 (0x00007fd989a50000)
	libglycin-2.so.0 => /usr/lib/libglycin-2.so.0 (0x00007fd989200000)
	libthai.so.0 => /usr/lib/libthai.so.0 (0x00007fd989a43000)
	libpng16.so.16 => /usr/lib/libpng16.so.16 (0x00007fd9897c6000)
	libfreetype.so.6 => /usr/lib/libfreetype.so.6 (0x00007fd9896f6000)
	libXrender.so.1 => /usr/lib/libXrender.so.1 (0x00007fd989a37000)
	libxcb.so.1 => /usr/lib/libxcb.so.1 (0x00007fd9896cb000)
	libxcb-render.so.0 => /usr/lib/libxcb-render.so.0 (0x00007fd9896bc000)
	libxcb-shm.so.0 => /usr/lib/libxcb-shm.so.0 (0x00007fd989a30000)
	libpixman-1.so.0 => /usr/lib/libpixman-1.so.0 (0x00007fd989151000)
	libgraphite2.so.3 => /usr/lib/libgraphite2.so.3 (0x00007fd989699000)
	libexpat.so.1 => /usr/lib/libexpat.so.1 (0x00007fd98966e000)
	libatspi.so.0 => /usr/lib/libatspi.so.0 (0x00007fd989635000)
	libjson-glib-1.0.so.0 => /usr/lib/libjson-glib-1.0.so.0 (0x00007fd989127000)
	libsqlite3.so.0 => /usr/lib/libsqlite3.so.0 (0x00007fd988fb2000)
	libblkid.so.1 => /usr/lib/libblkid.so.1 (0x00007fd988f78000)
	libgudev-1.0.so.0 => /usr/lib/libgudev-1.0.so.0 (0x00007fd988f6c000)
	libsndfile.so.1 => /usr/lib/libsndfile.so.1 (0x00007fd988ee2000)
	libsystemd.so.0 => /usr/lib/libsystemd.so.0 (0x00007fd988dbc000)
	libasyncns.so.0 => /usr/lib/libasyncns.so.0 (0x00007fd98962b000)
	libmd.so.0 => /usr/lib/libmd.so.0 (0x00007fd988dab000)
	libicuuc.so.78 => /usr/lib/libicuuc.so.78 (0x00007fd988a00000)
	libGLdispatch.so.0 => /usr/lib/libGLdispatch.so.0 (0x00007fd988d32000)
	libGLX.so.0 => /usr/lib/libGLX.so.0 (0x00007fd988d01000)
	liblcms2.so.2 => /usr/lib/liblcms2.so.2 (0x00007fd988c9b000)
	libseccomp.so.2 => /usr/lib/libseccomp.so.2 (0x00007fd988c78000)
	libdatrie.so.1 => /usr/lib/libdatrie.so.1 (0x00007fd988c6f000)
	libbz2.so.1.0 => /usr/lib/libbz2.so.1.0 (0x00007fd988c5c000)
	libbrotlidec.so.1 => /usr/lib/libbrotlidec.so.1 (0x00007fd988c4d000)
	libXau.so.6 => /usr/lib/libXau.so.6 (0x00007fd988c48000)
	libXdmcp.so.6 => /usr/lib/libXdmcp.so.6 (0x00007fd988c3e000)
	libogg.so.0 => /usr/lib/libogg.so.0 (0x00007fd988c34000)
	libvorbisenc.so.2 => /usr/lib/libvorbisenc.so.2 (0x00007fd988968000)
	libFLAC.so.14 => /usr/lib/libFLAC.so.14 (0x00007fd98891f000)
	libopus.so.0 => /usr/lib/libopus.so.0 (0x00007fd988200000)
	libmpg123.so.0 => /usr/lib/libmpg123.so.0 (0x00007fd9888c1000)
	libmp3lame.so.0 => /usr/lib/libmp3lame.so.0 (0x00007fd988849000)
	libvorbis.so.0 => /usr/lib/libvorbis.so.0 (0x00007fd98881b000)
	libicudata.so.78 => /usr/lib/libicudata.so.78 (0x00007fd986200000)
	libbrotlicommon.so.1 => /usr/lib/libbrotlicommon.so.1 (0x00007fd988c0f000)
```

So I tought: "I need to make my own!"

I didn't like all the existing options because they're ither bloated or have very limited capabilities 
because they use some cursedass markup language or ui toolkit instead of real code, so I tought: "I need to make my own!" and so I did. just look how clean the ldd is:

```ldd
linux-vdso.so.1 (0x00007f2ab60ac000)
	libwayland-client.so.0 => /usr/lib/libwayland-client.so.0 (0x00007f2ab605f000)
	libwayland-egl.so.1 => /usr/lib/libwayland-egl.so.1 (0x00007f2ab605a000)
	libEGL.so.1 => /usr/lib/libEGL.so.1 (0x00007f2ab6048000)
	libGLESv2.so.2 => /usr/lib/libGLESv2.so.2 (0x00007f2ab6038000)
	libc.so.6 => /usr/lib/libc.so.6 (0x00007f2ab5e00000)
	libffi.so.8 => /usr/lib/libffi.so.8 (0x00007f2ab602c000)
	libGLdispatch.so.0 => /usr/lib/libGLdispatch.so.0 (0x00007f2ab5d87000)
	/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f2ab60ae000)
```

compare to all the other shells mine uses good old OpenGL (OpenGLES 2 specificlly because that's what was in the [wlr-clients](https://gitlab.freedesktop.org/wlroots/wlr-clients) 
example but in the future I will try to add support for more backends like regular OpenGL 3.3 core, Vulkan, etc. 
(OpenGLES kinda feels like a cheatcode dough because you don't need glad to load it and it can even run on your fridge if it has a gpu))
this gives you more room for creative ideas and increases performance. Wanna try it out? what are you waiting for?! [do it!](#quickstart)


### <a name="quickstart"></a> Quickstart

1. check if your wayland compositor has wlroots support, get the `woidshell` and `woidshell-egl` headers and put them somwhere next-to each other.
   It's not like egl is optional, it's just nice to split things up :)

2. because this library is so low-level you first have to get the the wlroots boilerplate to interact with the API,
   this can be done by parsing the protocol xmls usually located somwhere in `/usr/share/wayland-protocols/` with a tool called `wayland-scanner` like this:

   ```shell    
    wayland-scanner client-header /usr/share/wayland-protocols/unstable/wlr-layer-shell-unstable-v1.xml ./protocol/wlr-layer-shell-unstable-v1.h # header
    wayland-scanner private-code /usr/share/wayland-protocols/unstable/wlr-layer-shell-unstable-v1.xml ./protocol/wlr-layer-shell-unstable-v1.c # c file
   ```

   and get xdg-shell as well:

   ```shell
    wayland-scanner client-header /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml ./protocol/xdg-shell.h
    wayland-scanner private-code /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml ./protocol/xdg-shell.c
   ```

3. enjoy :D it's a plain old stb-style single-header so checkout the examples! (don't forget to link with all the necessary libraries)


