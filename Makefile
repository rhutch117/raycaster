APP_NAME = raycaster
BUILD_DIR = ./bin
C_FILES = ./src/*.c

APP_DEFINES:=
APP_INCLUDES:= -I/opt/homebrew/opt/glfw/include -framework Cocoa -framework OpenGL -framework IOKit
APP_LINKERS:= -L/opt/homebrew/opt/glfw/lib -L./src/lib -lglad -lglfw3

build:
	clang $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)

run:
	./bin/raycaster

clean:
	rm ./bin/raycaster
