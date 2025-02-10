CC=gcc
CFLAGS=$(shell sdl2-config --cflags)
LDFLAGS=$(shell sdl2-config --libs)

build: 
	rm bin/life
	@echo "Building app..."
	$(CC) -o ./bin/life -I includes/... src/*.c  $(CFLAGS) $(LDFLAGS)
	@echo "App build."

run: build
	./bin/life

