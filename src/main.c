#include <stdbool.h>
#include <stdio.h>

#include <GLFW/glfw3.h>

GLFWwindow* window;

bool configure_glfw(void) {
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  if (!glfwInit()) {
    fprintf(stderr, "Unable to Initialize glfw library\n");
    return false;
  }
  
  return true;
}

bool present_window(void) {

  if(!configure_glfw()) {
    fprintf(stderr, "Unable to configure glfw library\n");
    return false;
  }

  window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
  if (!window) {
      glfwTerminate();
      return false;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
      /* Render here */
      glClear(GL_COLOR_BUFFER_BIT);

      /* Swap front and back buffers */
      glfwSwapBuffers(window);

      /* Poll for and process events */
      glfwPollEvents();
  }

  glfwTerminate();
  return true;
}

int main(void) {

  return present_window();
}
