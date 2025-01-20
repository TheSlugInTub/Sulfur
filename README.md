# Sulfur

Sulfur is a C-like programming language, which lets you get very low-level

This compiler is written in C++, and hopefully it gets to a point where the compiler can be written in itself.

# Getting started

To compile the project:

```bash
git clone https://github.com/TheSlugInTub/Sulfur.git
cd Sulfur
mkdir build
cmake -S . -B build
cmake --build build
```
This will generate an executable in the 'build' directory.
The compiler uses `nasm` and `ld` to assemble and link executables.
You must be on a unix-based system.
It doesn't work for Windows as of now, but hopefully it will in the future.

# Contributing

I will gladly, merge any pull requests if you make them, as long as they contribute something meaningful or fix an issue.
