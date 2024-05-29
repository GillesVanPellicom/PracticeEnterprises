# Practice enterprise - Chess project

Chess game in OOP with a Qt GUI as final assignment for Thomas More practice enterprise course, year 2023-2024.

## Build requirements
- Linux or macOS build environement (windows was not tested, CMake config would require alterations)
- CMake 3.26 or higher
- Qt 6

## Compile project
```bash
cmake -B ./cmake-build-debug -S . -G "Unix Makefiles"
cmake --build ./cmake-build-debug --target all -j256
```

## Run project
```bash
./cmake-build-debug/chess
```

## Generate documentation
Run command inside `doc` directory. (doxygen required)

```bash
doxygen ./Doxyfile
```
This will generate documentation about the project. Entrypoint is `doc/index.html`.

## Tested on
- **macOS 14.4.1:** Apple clang-1500.3.9.4 (C++26), CMake 3.28, Qt 6.7.0_1 
- **Arch 2024.04.01:** GCC 13.3 (C++23), CMake 3.26, Qt 6.7.0_1
