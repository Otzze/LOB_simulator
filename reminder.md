One-time setup:


cmake -S . -B build -G "Unix Makefiles"   # or "Ninja" if installed
Then your everyday loop is just:


cmake --build build           # equivalent to running `make` in build/
ctest --test-dir build        # runs all tests
Or literally cd build && make if you want pure Make. CMake only re-runs itself when a CMakeLists.txt changes — adding a new .cc file means editing the relevant CMakeLists.txt, then cmake --build build regenerates and compiles in one step.