#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "vendors/GLFW/glfw3.h"


GLFWwindow* window;

int main(void) {

  /* Initialize the library */
  if (!glfwInit()) {
    fprintf(stderr, "Unable to Initialize glfw library\n");
    return EXIT_FAILURE;
  }

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
      glfwTerminate();
      return EXIT_FAILURE;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
      /* Render here */
      glClear(GL_COLOR_BUFFER_BIT);

      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
