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

<hr>

### Graphics Programming Concepts

#### Graphics Pipeline
A set of 3d coordinates is sent through the graphics pipeline where they are transformed 
into 2d pixels on the screen. The pipeline involves several steps that can easily be 
executed in parallel. Modern graphics cards processing cores run these "shaders" for
each step of the pipeline. 

Steps may include:
* Vertex shader
* Geometry shader
* Shape assembly
* Rasterization
* Fragment Shader (Fragment is all the data required for OpenGL to render a single pixel)
* Tests & blending

***Almost all use cases can be handled using the vertex and fragment shader.***
