#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "first_app.hpp"
int main() try {
  lve::FirstApp app{};
  app.run();

  return EXIT_SUCCESS;
} catch (const std::exception &e) {
  std::cerr << e.what() << '\n';
  return EXIT_FAILURE;
}
