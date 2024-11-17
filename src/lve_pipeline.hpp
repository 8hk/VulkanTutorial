#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
#include <fstream>
namespace lve {
class LvePipeline {
 private:
  static std::vector<char> readFile(const std::string &filePath);
  void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath);
 public:
  LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath);
  ~LvePipeline();

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