# Tiger MacPorts - Pre-Built Binaries & Guide

**Modern software for Mac OS X Tiger (10.4) PowerPC**

Pre-built binaries and installation guide for running modern tools on Tiger.

## What's Here

| Package | Version | Status | Our Contribution |
|---------|---------|--------|------------------|
| Python | 3.10.18 | ✅ Working | Testing, packaging, documentation |
| curl | 7.88.1 | ✅ Working | Testing, packaging, documentation |
| OpenSSL | 3.5.1 | ✅ Working | Testing, packaging, documentation |
| Node.js | 14.x | 🔄 Building | Testing, packaging, documentation |
| wget | custom | ✅ Working | **Original code** (TLS 1.2 for Tiger) |
| PocketFox | custom | ✅ Working | **Original code** (Cocoa browser) |

## Credits

**Sergey Fedorov ([barracuda156](https://github.com/barracuda156))** - The legend keeping PowerPC MacPorts alive! His [powerpc-ports](https://github.com/barracuda156/powerpc-ports) repo has 1000+ fixes for PowerPC. Without his work, none of this would be possible.

**MacPorts Team** - The core MacPorts infrastructure and Portfiles.

**Other PowerPC Heroes:**
- [kencu](https://github.com/kencu) - Core MacPorts contributor
- [glebm](https://github.com/glebm) - GCC updates for Tiger
- [macos-powerpc](https://github.com/macos-powerpc) - Community PowerPC ports

**Scott (Scottcjn)** - Testing on real G4/G5 hardware, packaging binaries, documentation, and original Tiger tools (wget, PocketFox).

**Claude (Opus 4.1/4.5)** - Implementation assistance.

*barracuda156 does the porting. We do the testing, packaging, and original tools.*

## Pre-Built Binaries

Download ready-to-use binaries - no compiling needed!

### curl 7.88.1 with TLS 1.2

```bash
# Download
curl -LO https://github.com/Scottcjn/tiger-macports/releases/download/v1.0/curl-7.88.1-tiger-ppc.tar.gz

# Extract to /usr/local
cd /usr/local
sudo tar xzf ~/curl-7.88.1-tiger-ppc.tar.gz

# Test
/usr/local/bin/curl --version
/usr/local/bin/curl https://github.com
```

### Python 3.10.18

```bash
# Download
curl -LO https://github.com/Scottcjn/tiger-macports/releases/download/v1.0/python310-tiger-ppc.tar.gz

# Extract
cd /usr/local
sudo tar xzf ~/python310-tiger-ppc.tar.gz

# Test
/usr/local/bin/python3.10 --version
/usr/local/bin/python3.10 -c "import ssl; print(ssl.OPENSSL_VERSION)"
```

## Installing MacPorts (Build From Source)

If you prefer to compile yourself:

### 1. Get MacPorts

Download from: https://www.macports.org/install.php

For Tiger, you need the **legacy** installer or build from source.

### 2. Install Base Ports

```bash
# Update ports tree
sudo port selfupdate

# Install essentials (will take HOURS on G4)
sudo port install python310
sudo port install curl +ssl
sudo port install openssl
```

### 3. Build Times (Dual G4 1.25 GHz)

| Package | Approximate Time |
|---------|------------------|
| Python 3.10 | 4-6 hours |
| curl | 30-60 minutes |
| OpenSSL 3.x | 2-3 hours |
| Node.js 14 | 8-12 hours |
| GCC 7 | 12-24 hours |

*This is why we provide pre-built binaries!*

## Tested Hardware

| Model | OS | Status |
|-------|-----|--------|
| Power Mac G4 Dual 1.25 GHz | Tiger 10.4.11 | ✅ All working |
| Power Mac G5 Dual | Tiger 10.4.11 | ✅ All working |
| PowerBook G4 | Tiger 10.4.11 | ✅ All working |

## What Works on Tiger via MacPorts

### Fully Working
- Python 3.10 with SSL
- curl 8.x with TLS 1.2
- OpenSSL 3.x
- GCC 7.x
- CMake
- autoconf/automake
- Git (with our curl)

### Compiling (In Progress)
- Node.js 14

### Not MacPorts (Our Custom Code)
- **Rust compiler** - See [rust-ppc-tiger](https://github.com/Scottcjn/rust-ppc-tiger)
- **PocketFox browser** - See [pocketfox](https://github.com/Scottcjn/pocketfox)
- **wget with TLS** - See [pocketfox](https://github.com/Scottcjn/pocketfox)

### Not Working / Not Tested
- Node.js 18+ (V8 too new)
- Go (runtime issues)
- Docker (requires newer kernel)

## Original Tiger Tools

These are **our original code**, not MacPorts:

### wget with TLS 1.2
Built-in HTTPS using mbedTLS. See [pocketfox](https://github.com/Scottcjn/pocketfox)

### PocketFox Browser
Native Cocoa browser with embedded TLS. See [pocketfox](https://github.com/Scottcjn/pocketfox)

### OpenSSH Build Script
Build OpenSSH 9.6 with LibreSSL. See [rust-ppc-tiger](https://github.com/Scottcjn/rust-ppc-tiger)

## Related Projects

- [rust-ppc-tiger](https://github.com/Scottcjn/rust-ppc-tiger) - Rust compiler for PowerPC
- [pocketfox](https://github.com/Scottcjn/pocketfox) - Native browser with TLS
- [ppc-tiger-tools](https://github.com/Scottcjn/ppc-tiger-tools) - Various Tiger tools
- [macosx-security-patches](https://github.com/Scottcjn/macosx-security-patches) - CVE patches

## License

- **Pre-built binaries**: Subject to original package licenses (Python PSF, curl MIT, etc.)
- **Our original code**: MIT License
- **Documentation**: MIT License

---

## Traffic Note

**600+ clones across 14 repos in under 48 hours. Zero stars.**

This work is being actively scraped by someone — government HPC labs, AI research groups, defense contractors? If you're mirroring for research purposes, feel free to reach out. Otherwise, a star would be nice.

The clone-to-star ratio is the purest form of underground validation. We see you. 👁️

---

*"Modern software on your 2005 Power Mac."*
