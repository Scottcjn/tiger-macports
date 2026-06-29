# SDL2 on PowerPC Mac OS X Leopard (X11 backend)

Prebuilt **SDL2 2.0.0** for **Mac OS X 10.5 Leopard, PowerPC (G4/G5)**.

SDL2 officially requires a 10.6 SDK (there is a hardcoded `#error "must be
built with a 10.6 SDK or above"`), and 10.6 Snow Leopard is **Intel-only**
— so there is no 10.6 PowerPC SDK and SDL2's native Cocoa backend cannot
be built on PPC at all. This build sidesteps that by using SDL2's **X11
video backend** instead of Cocoa.

Built on a Power Mac G5 with Apple `gcc-4.2`. Verified: a tiny SDL2
program links and runs (`SDL2 2.0.0 linked and running on PowerPC G5`).

## What was done (build)
- Bypassed the 10.6-SDK guard in `include/SDL_platform.h`.
- Configured `--disable-video-cocoa --enable-video-x11 --disable-video-opengl`.
  OpenGL must be OFF: Leopard X11.app's GLX cannot supply a visual
  (`Couldn't find matching GLX visual`), so SDL2 uses software XImage instead.
- Disabled the X11 extensions Leopard's older Xorg lacks:
  `xrandr` (no `RROutput`/`RRMode`), `xinerama`, `xvidmode`, `scrnsaver`, `xinput`.
- X11 headers/libs from `/usr/X11`.

## Rendering (confirmed: a demo renders on a real G5)
With OpenGL off, two things matter at runtime:
1. Set `SDL_FRAMEBUFFER_ACCELERATION=0`. SDL2 tries a texture/renderer
   framebuffer first and fails with GL off (`No hardware accelerated
   renderers available`); this env var forces the native X11 framebuffer.
2. Draw with the surface API, not the renderer:
   `SDL_CreateWindow` (no GL flag) -> `SDL_GetWindowSurface` ->
   `SDL_FillRect` / blits -> `SDL_UpdateWindowSurface`.
See `sdl2-demo-ppc.c` for a minimal working example (animated rectangles).

## Use
- Needs X11 (X11.app) running; SDL2 apps open in **X11 windows**, not native Cocoa.
- `sdl2-config --cflags --libs`; static `libSDL2.a` + `libSDL2main.a`.
- Extract over a `/usr/local` prefix.
- Launching a GUI app from SSH cannot reach the console; run it inside the
  Aqua/X11 session (`launchctl bsexec <Finder-pid> ...`, `open -a X11`).

A native-Cocoa SDL2 on Leopard would mean backporting the 10.6-era Cocoa
APIs to 10.5 (a larger effort); this X11 build makes SDL2 usable on PPC
Leopard today.

Built by Elyan Labs on real PowerPC hardware.
