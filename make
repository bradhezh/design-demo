mkdir -p build
gcc `pkg-config --cflags raylib` -o build/demo src/*.c `pkg-config --libs raylib`
