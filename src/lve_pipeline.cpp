#include "lve_pipeline.hpp"
namespace lve {

LvePipeline::LvePipeline(const LveDevice &device,const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo& configInfo_)try {
  lveDevice = std::make_unique<LveDevice>(device);
  configInfo = std::make_unique<PipelineConfigInfo>(configInfo_);
  vertFileReader = std::make_unique<FileReader>(vertFilePath);
  fragFileReader = std::make_unique<FileReader>(fragFilePath);
  createGraphicsPipeline();
}
catch (std::exception &ex) {
  std::cerr << ex.what() << '\n';
  throw std::invalid_argument("pipeline operation failed");
}
LvePipeline::~LvePipeline() {
  if(vertFileReader){
    vertFileReader.reset();
  }
  if(fragFileReader){
    fragFileReader.reset();
  }
};

void LvePipeline::createGraphicsPipeline() {
  auto vertCode = vertFileReader->read();
  auto fragCode =fragFileReader->read();
  std::cout << "Vertex shader code size: " << vertCode.size() << "\n";
  std::cout << "Frag shader code size: " << fragCode.size() << "\n";
}
void LvePipeline::createShaderModule(const vector<char> &code, VkShaderModule *shaderModule) {
  VkShaderModuleCreateInfo createInfo{};
  createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  createInfo.codeSize = code.size();
  createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

  if(vkCreateShaderModule(lveDevice->device(),&createInfo, nullptr,shaderModule)!= VK_SUCCESS){
    throw std::runtime_error("failed to create shader module");
  }

}
PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
  PipelineConfigInfo configInfo {};

  return configInfo;
}
}  // namespace lve