# Practice enterprises - Chess project

Made by placeholder & Gilles Van pellicom

## Build requirements
- Linux environement
- Qt 6
- CMake 3.27 or higher

### Compile project
```bash
cmake -Wall -Werror -B build -S . -G "Unix Makefiles"
cmake --build ./build --config Debug --target all -j256
```

### Run project
```bash
./cmake-build-debug/chess
```

### Generate documentation
**Run this from inside the `doc` directory**

```bash
doxygen ./Doxyfile
```
