#include <stdbool.h>
#include <stdio.h>

#include "include/glad/glad.h"
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

GLFWwindow* window;

void processInput(GLFWwindow *window) {
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

// Callback function being called everytime the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

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

  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL", NULL, NULL);
  if (!window) {
      fprintf(stderr, "Unable to create glfw window\n");
      glfwTerminate();
      return false;
  }

  glfwMakeContextCurrent(window);

  // GLAD Initializes function pointers for OpenGL so we must
  // initialize GLAD before we call any OpenGL function.
  // GLFW returns the function addresses (which is OS specific),
  // and then these addresses are loaded into GLAD.
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      fprintf(stderr, "Unable to create glfw window\n");
      return false;
  }

  // Create our viewport and register our resize callback function
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  while (!glfwWindowShouldClose(window)) {

    // Handle any user input
    processInput(window);

    /* Render here */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); // clear the screen to avoid seeing the previous frame

    // Check and call events and swap the buffers
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwTerminate();
  return true;
}

int main(void) {

  return present_window();
}
