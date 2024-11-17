#include "lve_window.hpp"

namespace lve {
void LveWindow::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window =
      glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

LveWindow::LveWindow(int w, int h, string name)
    : width{w}, height{h}, windowName{name} {
  if (validateInputs()) {
    initWindow();
  }
}
LveWindow::~LveWindow() {
  glfwDestroyWindow(window);
  glfwTerminate();
}
bool LveWindow::shouldClose() { return glfwWindowShouldClose(window); }
bool LveWindow::validateInputs() {
  if (width < 1 || height < 1 || windowName.size() < 1) {
    throw std::invalid_argument(
        "received invalid values during creation of window");
    return false;
  }

  return true;
}
}  // namespace lve
