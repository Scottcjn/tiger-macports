# SDL2 on PowerPC Mac OS X Leopard (X11 backend)

Prebuilt **SDL2 2.0.0** for **Mac OS X 10.5 Leopard, PowerPC (G4/G5)**.

SDL2 officially requires a 10.6 SDK (there is a hardcoded `#error "must be
built with a 10.6 SDK or above"`), and 10.6 Snow Leopard is **Intel-only**
— so there is no 10.6 PowerPC SDK and SDL2's native Cocoa backend cannot
be built on PPC at all. This build sidesteps that by using SDL2's **X11
video backend** instead of Cocoa.

Built on a Power Mac G5 with Apple `gcc-4.2`. Verified: a tiny SDL2
program links and runs (`SDL2 2.0.0 linked and running on PowerPC G5`).

## What was done
- Bypassed the 10.6-SDK guard in `include/SDL_platform.h`.
- Configured `--disable-video-cocoa --enable-video-x11`.
- Disabled the X11 extensions that Leopard's older Xorg lacks:
  `xrandr` (no `RROutput`/`RRMode`), `xinerama`, `xvidmode`, `scrnsaver`, `xinput`.
- X11 headers/libs from `/usr/X11`.

## Use
- Needs X11 (X11.app) running; SDL2 apps open in **X11 windows**, not native Cocoa.
- `sdl2-config --cflags --libs`; static `libSDL2.a` + `libSDL2main.a`.
- Extract over a `/usr/local` prefix.

A native-Cocoa SDL2 on Leopard would mean backporting the 10.6-era Cocoa
APIs to 10.5 (a larger effort); this X11 build makes SDL2 usable on PPC
Leopard today.

Built by Elyan Labs on real PowerPC hardware.
