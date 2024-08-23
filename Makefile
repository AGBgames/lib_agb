compile_standard = -std=c++20
compile_options = -Wall -Werror -Wextra -Wpedantic -fpic $(compile_standard)

all: agb

agb: files winutils info
	clang++ out/files.o out/winutils.o out/info.o -o bin/agb.dll -shared $(compile_options)

info: src/info.cpp
	clang++ -c src/info.cpp -o out/info.o $(compile_options)

winutils: src/windows/winutils.cpp
	clang++ -c src/windows/winutils.cpp -o out/winutils.o $(compile_options)

files: src/files/files.cpp
	clang++ -c src/files/files.cpp -o out/files.o