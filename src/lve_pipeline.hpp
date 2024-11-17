#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "CustomFileOperation/FileReader.h"
#include <memory>
namespace lve {
class LvePipeline {
 private:
  void createGraphicsPipeline();
  std::unique_ptr<FileReader>vertFileReader;
  std::unique_ptr<FileReader>fragFileReader;
 public:
  LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath);
  virtual ~LvePipeline();

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