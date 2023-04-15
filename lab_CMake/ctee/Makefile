TARGET=ctee

build: CMakeLists.txt
	mkdir -p build && cd build && cmake ..

$(TARGET): build
	$(MAKE) -C build

clean:
	-rm -r build .cache

.PHONY: all clean $(TARGET) build