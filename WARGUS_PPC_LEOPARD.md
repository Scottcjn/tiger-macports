# Build Warcraft II on PowerPC Mac OS X Leopard (Wargus + Stratagus)

Prebuilt PowerPC binaries and the build recipe for running **Warcraft II**
via the open-source **Stratagus** engine and **Wargus** data importer on
**Mac OS X 10.5 Leopard, PowerPC (G4/G5)**. Built and verified on a Power
Mac G5.

This is, as far as we can tell, the only PowerPC-Leopard build of the
Wargus/Stratagus stack in existence: modern Wargus needs SDL2 + CMake 3.25,
neither of which works on Leopard PPC, so this uses the legacy SDL 1.2
stack (Stratagus V2.3.0 / Wargus 2015) rebuilt with a modern toolchain.

You supply your own legally owned Warcraft II: Tides of Darkness (or
Battle.net Edition); `wartool` extracts it into the engine format. No game
assets are included here.

## Binaries (in `binaries/`)

Each tarball extracts over a `/usr/local` prefix.

| Tarball | What |
|---|---|
| `sdl-1.2.15-tiger-ppc.tar.gz` | SDL 1.2.15 (Quartz/Cocoa video) |
| `lua-5.1.5-tiger-ppc.tar.gz` | Lua 5.1.5 |
| `kit-toluapp-1.0.92-tiger-ppc.tar.gz` | tolua++ 1.0.92 (Lua binding generator) |
| `kit-pkgconfig-0.29.2-tiger-ppc.tar.gz` | pkg-config 0.29.2 (internal glib) |
| `kit-cmake-3.16.9-tiger-ppc.tar.gz` | CMake 3.16.9 |
| `kit-stormlib-be-tiger-ppc.tar.gz` | StormLib (MPQ reader) with the big-endian build fix |
| `kit-stratagus-2.3.0-tiger-ppc.tar.gz` | Stratagus V2.3.0 engine |
| `kit-wargus-tools-tiger-ppc.tar.gz` | Wargus `wartool` / `wargus` / `pudconvert` |

## Toolchain

- **GCC 10.5** for Tiger/Leopard PPC (see `ppc-compilers` / `ppc-tiger-tools`) for everything C++.
- **Apple system gcc-4.2** (`/usr/bin/gcc-4.2`) for **SDL 1.2** and **Lua** (SDL's Darwin path uses Objective-C and `-fpascal-strings`, which mainline GCC rejects).

## Build notes (the walls, and the fixes)

- **gcc-10 ABI vs Leopard's system libstdc++:** gcc-10 C++ binaries crash under the old system libstdc++. Fix: `export DYLD_LIBRARY_PATH=/usr/local/gcc-10/lib` (set it in `~/.bash_profile`), and note that `sudo` strips `DYLD_*`, so installs need `sudo env DYLD_LIBRARY_PATH=... make install`.
- **CMake:** missing `#include <memory>` in `cmMachO.h` (gcc-10 is strict); add it.
- **Stratagus:** gcc-10 reads `"fmt"_C_` (the `#define _C_ ,` vararg idiom) as a C++11 user-defined literal. Fix: insert a space (`"fmt" _C_`) tree-wide. SDL 1.2 needs the full macOS framework set at link: `-DCMAKE_EXE_LINKER_FLAGS="-framework OpenGL -framework Cocoa -framework ApplicationServices -framework Carbon -framework AudioToolbox -framework AudioUnit -framework IOKit -framework CoreFoundation"`. Copy `gameheaders/*.h` to `/usr/local/include`.
- **Wargus:** make GTK2 optional (`find_package(GTK2)` with no `REQUIRED`/component, then `-DNOGTK`) to skip the GUI wizard. `ranlib` the installed StormLib (it is built `ar rcS`, with no symbol table).
- **Display over SSH:** an SSH-launched SDL app cannot reach the console WindowServer. Run it inside the Aqua session with `launchctl bsexec <Finder-pid> ...`.

## Running

1. Extract all tarballs over `/usr/local`.
2. `export DYLD_LIBRARY_PATH=/usr/local/gcc-10/lib`
3. `wartool /path/to/warcraft2/DATA /usr/local/share/games/stratagus/wargus`
4. `wargus` (or `stratagus -d /usr/local/share/games/stratagus/wargus`)

Built by Elyan Labs on real PowerPC hardware.
