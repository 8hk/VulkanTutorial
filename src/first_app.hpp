#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stdexcept>
#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
namespace lve {
class FirstApp {
 private:
  LveWindow lveWindow{WIDTH, HEIGHT, "Hoi Vulkan"};
  LveDevice lveDevice{lveWindow};
  void createPipelineLayout();
  void createPipeline();
  void createCommandBuffers();
  void drawFrame();
  std::unique_ptr<LvePipeline> lvePipeline;
  VkPipelineLayout  pipelineLayout;
  std::vector<VkCommandBuffer> commandBuffers;
  LveSwapChain lveSwapChain{lveDevice,lveWindow.getExtent()};
 public:
  FirstApp();
  ~FirstApp();

  FirstApp(const FirstApp &) = delete;
  FirstApp &operator=(const FirstApp &) = delete;

  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void run();
};
}  // namespace lve