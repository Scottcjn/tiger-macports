# Contributing to Tiger MacPorts

Thank you for your interest in contributing to Tiger MacPorts! This project preserves and maintains MacPorts packages for Mac OS X Tiger (10.4) on PowerPC systems. Your contributions help keep legacy systems alive and functional.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Development Environment](#development-environment)
- [How to Contribute](#how-to-contribute)
- [Portfile Guidelines](#portfile-guidelines)
- [Testing](#testing)
- [Submitting Changes](#submitting-changes)
- [Community](#community)

## Code of Conduct

This project is committed to providing a welcoming experience for everyone. We expect contributors to:

- Be respectful and constructive in all interactions
- Focus on what's best for the PowerPC community
- Accept constructive criticism gracefully
- Show empathy towards others

## Getting Started

### Prerequisites

To contribute to Tiger MacPorts, you'll need:

- **Hardware**: PowerPC Mac (G3, G4, or G5) or QEMU emulation setup
- **Operating System**: Mac OS X Tiger (10.4.11 recommended)
- **Xcode**: Xcode 2.5 with GCC 4.0
- **MacPorts**: Base installation from [macports.org](https://www.macports.org)

### Repository Structure

```
tiger-macports/
├── ports/              # Portfile recipes
├── binaries/           # Pre-built binaries
├── patches/            # Platform-specific patches
├── docs/               # Documentation
└── scripts/            # Build automation scripts
```

## Development Environment

### Setting Up MacPorts on Tiger

1. Install MacPorts base:
   ```bash
   curl -O https://distfiles.macports.org/MacPorts/MacPorts-1.8.2.tar.gz
   tar xzvf MacPorts-1.8.2.tar.gz
   cd MacPorts-1.8.2
   ./configure && make && sudo make install
   ```

2. Update Portfiles:
   ```bash
   sudo port selfupdate
   ```

3. Add this repository:
   ```bash
   git clone https://github.com/Scottcjn/tiger-macports.git
   cd tiger-macports
   sudo port install -d ./ports/<category>/<portname>
   ```

### Using QEMU for Development

If you don't have physical PowerPC hardware:

```bash
# Install qemu-system-ppc
brew install qemu  # on modern macOS

# Run Tiger in QEMU (see docs/qemu-setup.md for details)
qemu-system-ppc -M mac99 -m 512 -hda tiger.img -cdma tiger-install.iso
```

## How to Contribute

### Reporting Issues

When reporting issues with ports:

1. **Check existing issues** first
2. **Include system information**:
   - Mac model (e.g., PowerMac G4 MDD)
   - CPU type and speed
   - RAM amount
   - MacPorts version
3. **Provide build logs**: `cat /opt/local/var/macports/logs/*/main.log`
4. **Describe expected vs actual behavior**

### Suggesting New Ports

To suggest a new port:

1. Verify the software supports Tiger/PowerPC
2. Check if it's already in upstream MacPorts
3. Open an issue with:
   - Software name and version
   - Homepage URL
   - License type
   - Build dependencies
   - Why it's needed for Tiger

### Contributing Portfiles

1. **Fork** the repository
2. **Create a branch**: `git checkout -b port/<software-name>`
3. **Write your Portfile** following our guidelines
4. **Test locally**: `sudo port install -d ./ports/<category>/<portname>`
5. **Submit a Pull Request**

## Portfile Guidelines

### Basic Structure

```tcl
# -*- coding: utf-8; mode: tcl; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- vim:fenc=utf-8:ft=tcl:et:sw=4:ts=4:sts=4

PortSystem          1.0
PortGroup           tiger 1.0

name                example
version             1.0.0
categories          devel
maintainers         {@yourusername:your@email.com} openmaintainer
license             MIT
description         Short description
long_description    Longer description of the software.

homepage            https://example.com
master_sites        sourceforge:project/example

checksums           rmd160  abc123 \
                    sha256  def456 \
                    size    123456

depends_lib         port:libexample

configure.args      --disable-shared

tiger.variant       yes
tiger.patchfiles    patch-tiger-compat.diff
```

### Tiger-Specific Considerations

- **Compiler**: Most ports use GCC 4.0.1 (Tiger's default)
- **SDK**: Target Mac OS X 10.4u SDK
- **Architectures**: ppc7400 (G4), ppc970 (G5), or ppc (G3)
- **Dependencies**: Prefer static linking when shared libs cause issues

### Common Patches

Place patches in `patches/<portname>/`:

- `patch-Makefile.in.diff` - Build system fixes
- `patch-configure.diff` - Configuration detection
- `patch-tiger-compat.diff` - Tiger-specific compatibility

### Version Constraints

When upstream dropped Tiger support:

```tcl
# Use last version that supported Tiger
if {${os.major} < 9} {
    version     1.2.3
    revision    0
    checksums   ...
} else {
    version     2.0.0
    checksums   ...
}
```

## Testing

### Local Testing Checklist

Before submitting:

- [ ] Port installs cleanly: `sudo port install <portname>`
- [ ] Port uninstalls cleanly: `sudo port uninstall <portname>`
- [ ] Port activates: `sudo port activate <portname>`
- [ ] Binary runs on target hardware
- [ ] No Tiger-specific warnings (or documented)

### Test on Multiple Systems

If possible, test on:

- **G3** (PowerBook G3, iMac G3) - oldest supported
- **G4** (PowerMac G4, PowerBook G4) - most common
- **G5** (PowerMac G5, iMac G5) - most powerful

### Build Logs

Include relevant build log excerpts in PR description if build issues occur.

## Submitting Changes

### Pull Request Process

1. **Update your fork**:
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

2. **Commit your changes**:
   ```bash
   git add ports/<category>/<portname>/Portfile
   git commit -m "<category>/<portname>: Add version X.Y.Z"
   ```

3. **Push to your fork**:
   ```bash
   git push origin port/<portname>
   ```

4. **Open a Pull Request** with:
   - Clear title: `category/portname: description`
   - Description of what changed and why
   - Testing performed
   - Any known issues or limitations

### Commit Message Format

```
category/portname: Brief description

Longer explanation if needed. Include:
- Why this change was made
- What testing was done
- Any breaking changes
```

Examples:
```
devel/cmake: Update to 2.8.12.2

Last version supporting Tiger. Tested on PowerMac G4.
```

```
python/py27-pip: Fix SSL certificate verification

Backport certifi support for Tiger's outdated OpenSSL.
```

## Community

### Getting Help

- **GitHub Issues**: Bug reports and feature requests
- **Discussions**: General questions and community chat
- **Wiki**: Additional documentation and tutorials

### Resources

- [MacPorts Guide](https://guide.macports.org/)
- [Tiger Compatibility Notes](docs/tiger-compatibility.md)
- [PowerPC Optimization Guide](docs/powerpc-optimization.md)

### Recognition

Contributors will be:

- Listed in CONTRIBUTORS.md
- Credited in port descriptions
- Acknowledged in release notes

## License

By contributing, you agree that your contributions will be licensed under the same license as the project (BSD 3-Clause).

---

**Thank you for keeping PowerPC alive!** 🐯
