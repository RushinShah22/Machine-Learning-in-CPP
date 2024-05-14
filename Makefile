all : prepare generate

prepare:
	rm -rf build
	mkdir build
	cmake build -S . -B ./build

generate:
	cmake --build ./build

start:
	./build/app/app
