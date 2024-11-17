#include "lve_pipeline.hpp"
namespace lve {

LvePipeline::LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath)try {
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
}  // namespace lve