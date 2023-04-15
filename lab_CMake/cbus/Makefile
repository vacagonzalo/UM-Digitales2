all: application

build: CMakeLists.txt
	mkdir -p build && cd build && cmake ..

application: build
	$(MAKE) -C build

clean:
	-rm -r build .cache

.PHONY: all clean application build