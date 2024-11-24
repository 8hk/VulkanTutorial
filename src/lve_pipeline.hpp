#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "CustomFileOperation/FileReader.h"
#include "lve_device.hpp"
#include <memory>
#include <vulkan/vulkan_core.h>
namespace lve {
struct PipelineConfigInfo {
  VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
};

class LvePipeline {
 private:
  void createGraphicsPipeline();
  void createShaderModule(const std::vector<char> &code, VkShaderModule * shaderModule);

  std::unique_ptr<FileReader>vertFileReader;
  std::unique_ptr<FileReader>fragFileReader;
  std::unique_ptr<PipelineConfigInfo> configInfo;
  std::unique_ptr<LveDevice> lveDevice;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;

 public:
  LvePipeline(const LveDevice &device,const std::string &vertFilePath, const std::string &fragFilePath, const PipelineConfigInfo& configInfo_);
  virtual ~LvePipeline();

  static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

  //copy ctor delete
  LvePipeline(const LvePipeline &pipeline) = delete;

  //copy assignment delete
  LvePipeline &operator=(const LvePipeline &pipeline) = delete;

  //move constructor delete
  LvePipeline(LvePipeline &&pipeline) = delete;

  //move assignment delete
  LvePipeline &operator=(LvePipeline &&pipeline) = delete;

};

}