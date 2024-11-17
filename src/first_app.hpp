#pragma once
#include <string>
#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve {
class FirstApp {
 private:
  LveWindow lveWindow{WIDTH, HEIGHT, "Hoi Vulkan"};
  LvePipeline lvePipeline{"D:/Projects/vulkan/VulkanTutorial/src/shaders/simple_shader.vert.spv",
                          "D:/Projects/vulkan/VulkanTutorial/src/shaders/simple_shader.frag.spv"};
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void run();
};
}  // namespace lve