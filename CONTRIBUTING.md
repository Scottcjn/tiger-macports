# Contributing to Tiger MacPorts

Thank you for helping improve Tiger MacPorts. This repository documents modern
software that has been tested for Mac OS X Tiger 10.4 on PowerPC hardware and
hosts selected pre-built binary packages. Contributions should keep the setup
instructions accurate, preserve package provenance, and make the binaries easy
for vintage Mac users to evaluate before installing.

## Project Scope

This repository is a guide and binary distribution point. It tracks:

- tested MacPorts packages for Tiger on PowerPC
- pre-built package archives under `binaries/`
- installation and verification commands in `README.md`
- links to related Elyan Labs and PowerPC projects
- license notes for redistributed binaries and project documentation

Good contributions include:

- documentation fixes for package names, versions, install paths, or commands
- new hardware test notes for Tiger 10.4 PowerPC systems
- improved binary provenance notes, checksums, or package source references
- updates to the package status table when a build has been verified
- small corrections to related-project links or license wording

Avoid unrelated rewrites or broad style changes. Keep pull requests focused on
one package, one documentation section, or one binary update at a time.

## Local Setup

Clone the repository and create a working branch:

```bash
git clone https://github.com/Scottcjn/tiger-macports.git
cd tiger-macports
git switch -c <your-branch-name>
```

Most documentation changes can be edited and reviewed locally with a Markdown
previewer. Binary changes should also be tested on a Tiger PowerPC system when
possible.

## Updating Documentation

When editing `README.md`, keep commands copy-pasteable for Tiger users. Prefer
absolute install paths such as `/usr/local/bin/curl` when the installed binary
may differ from Apple's system-provided tools.

For package table changes, include:

- package name and version
- current status
- what was tested
- which hardware and Tiger version were used
- whether a binary archive is available in this repository

Do not change links to related projects unless you have verified the new target
exists and points to the intended project.

## Updating Binary Archives

Binary archive updates need extra care because users may install them directly
on older systems.

Before adding or replacing a file in `binaries/`:

1. Record the package name, version, build host, and target OS.
2. Confirm the archive extracts into the documented prefix.
3. Run the documented version or smoke-test command after extraction.
4. Add or update checksums or provenance notes in the pull request.
5. Confirm the license terms allow redistribution.

Keep archive names descriptive, for example
`curl-7.88.1-tiger-ppc.tar.gz`. Avoid replacing an existing archive without
explaining why the new build supersedes it.

## Validation

Run the checks that match your change before opening a pull request.

For documentation-only changes:

```bash
git diff --check
```

Review the rendered Markdown and confirm every changed command, path, and link
is still correct.

For binary archive changes, also test on the target system when possible:

```bash
/usr/local/bin/curl --version
/usr/local/bin/ssh -V
/usr/local/bin/python3.10 --version
```

Only run commands for packages affected by your change. If you cannot test on
PowerPC Tiger hardware, state that clearly in the pull request.

## Pull Request Guidelines

Use a concise pull request description that includes:

- the package or documentation section changed
- the validation you performed
- any hardware and OS details used for testing
- whether any files under `binaries/` changed
- any license or provenance notes for redistributed packages

Keep generated archives and documentation updates in the same pull request only
when they describe the same package release. Separate unrelated package updates
into separate pull requests.

## Review Notes

Reviewers should be able to answer three questions from the pull request:

- What changed for Tiger PowerPC users?
- How was it tested?
- Are the binary source, license, and install path clear?

If any of those answers are unclear, update the documentation before requesting
review.
