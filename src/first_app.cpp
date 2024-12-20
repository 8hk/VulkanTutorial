#include <array>
#include "first_app.hpp"
namespace lve {

FirstApp::FirstApp() {
  createPipelineLayout();
  createPipeline();
  createCommandBuffers();
}

FirstApp::~FirstApp() {
  vkDestroyPipelineLayout(lveDevice.device(),pipelineLayout, nullptr);
}
void FirstApp::run() {
  while (!lveWindow.shouldClose()) {
    glfwPollEvents();
    drawFrame();
  }
  vkDeviceWaitIdle(lveDevice.device());
}
void FirstApp::createPipelineLayout() {
  VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
  pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
  pipelineLayoutInfo.setLayoutCount = 0;
  pipelineLayoutInfo.pSetLayouts = nullptr;
  pipelineLayoutInfo.pushConstantRangeCount = 0;
  pipelineLayoutInfo.pPushConstantRanges = nullptr;

  if (vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
    throw std::runtime_error("failed to create pipeline layout!");
  }

}
void FirstApp::createPipeline() {
  auto pipelineConfig = LvePipeline::defaultPipelineConfigInfo(lveSwapChain.width(), lveSwapChain.height());
  pipelineConfig.renderPass = lveSwapChain.getRenderPass();
  pipelineConfig.pipelineLayout = pipelineLayout;
  lvePipeline =
      std::make_unique<LvePipeline>(lveDevice,
                                    "D:/Projects/vulkan/VulkanTutorial/src/shaders/simple_shader.vert.spv",
                                    "D:/Projects/vulkan/VulkanTutorial/src/shaders/simple_shader.frag.spv",
                                    pipelineConfig);
}
void FirstApp::createCommandBuffers() {
  commandBuffers.resize(lveSwapChain.imageCount());

  VkCommandBufferAllocateInfo allocateInfo{};
  allocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
  allocateInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
  allocateInfo.commandPool = lveDevice.getCommandPool();
  allocateInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());

  if(vkAllocateCommandBuffers(lveDevice.device(), &allocateInfo,commandBuffers.data()) != VK_SUCCESS){
    throw std::runtime_error("failed to allocate command buffers");
  }


  for(int i = 0; i < commandBuffers.size(); i++){
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if(vkBeginCommandBuffer(commandBuffers[i], &beginInfo) != VK_SUCCESS){
      throw std::runtime_error("failed to begin recording command buffer");
    }

    VkRenderPassBeginInfo renderPassBeginInfo{};
    renderPassBeginInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassBeginInfo.renderPass = lveSwapChain.getRenderPass();
    renderPassBeginInfo.framebuffer = lveSwapChain.getFrameBuffer(i);

    renderPassBeginInfo.renderArea.offset = { 0,0};
    renderPassBeginInfo.renderArea.extent = lveSwapChain.getSwapChainExtent();

    std::array<VkClearValue, 2> clearValues{};
    clearValues[0].color = {0.5f,0.5f,0.1f,0.1f};
    clearValues[1].depthStencil = {1.0f,0};

    renderPassBeginInfo.clearValueCount = static_cast<uint32_t >(clearValues.size());
    renderPassBeginInfo.pClearValues = clearValues.data();

    vkCmdBeginRenderPass(commandBuffers[i],&renderPassBeginInfo,VK_SUBPASS_CONTENTS_INLINE);

    lvePipeline->bind(commandBuffers[i]);

    vkCmdDraw(commandBuffers[i],3,1,0,0);

    vkCmdEndRenderPass(commandBuffers[i]);
    if(vkEndCommandBuffer(commandBuffers[i]) != VK_SUCCESS){
      throw std::runtime_error("failed to record command buffer");
    }
  }
}
void FirstApp::drawFrame() {
  uint32_t  imageIndex;
  auto result = lveSwapChain.acquireNextImage(&imageIndex);
  if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR){
    throw std::runtime_error("failed to acquire swap chain image!");
  }

  result = lveSwapChain.submitCommandBuffers(&commandBuffers[imageIndex],&imageIndex);
  if(result != VK_SUCCESS){
    throw std::runtime_error("failed to present swap chain image!");
  }

}
}  // namespace lve
