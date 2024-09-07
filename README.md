# RAYCASTER

A simple raycaster to practice some C programming.

### Components
* OpenGL
* GLFW
* GLAD 
* GLEW (No longer using. Replaced with GLAD)

<hr>


#### GLFW
GLFW is used to create windows. Each OS has different method of accomplishing this,
and GLFW provides a standardized API allowing you to write cross-platform compatible code.

#### GLAD
The graphics card must implement OpenGL functionality. To work cross-platform, regardless
of driver version or graphics card vendor, we use a library. This is similar to GLFW, but 
instead of dealing with OS specific windows, it works with specific graphics drivers.

<hr>

### Running the application
Build the binary by running `make`

Start the application with `./bin/raycaster` or `make run`

