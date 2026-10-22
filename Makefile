.PHONY: all configure build run

all: build

configure:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

build: configure
	cmake --build build

run: build
	./build/game