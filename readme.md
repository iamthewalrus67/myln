# Lab work _: myln
- Authors (team):
    - [Bohdan Ruban](https://github.com/iamthewalrus67)
- Variant: _nullptr_
## Prerequisites

- gcc/clang
- cmake
- Not Windows

### Compilation

```
Usage: ./compile.sh [options]
  Options:
    -h      --help                  Show help message.
    -O      --optimize-build        Compile with optimization before executing.
    -o      --no-optimize-build     Compile without optimization before executing.
    -D      --debug-build           Compile with debug options.
    -d      --no-debug-build        Compile without debug options.
    -I      --install_prefix        Installation path.
    -R      --remove-build-dirs     Remove build dirs after the install.
```

### Usage


```
./myln [-h|--help] [-s|--soft] <source> <dest>
```

By default the program will create a hard link if `-s|--soft` was not specified.

### Results

An implementation of the `ln` utility.
