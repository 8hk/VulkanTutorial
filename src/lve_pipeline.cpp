#include "lve_pipeline.hpp"
namespace lve {

LvePipeline::LvePipeline(const std::string &vertFilePath, const std::string &fragFilePath) {
  createGraphicsPipeline(vertFilePath, fragFilePath);
}

LvePipeline::~LvePipeline() {
}

std::vector<char> LvePipeline::readFile(const std::string &filePath) {
  // req 1 = std::ios::ate = seek the end immideately when the file opens
  // req 2 = std::ios::binary = read the file binary format to avoid unnecesary text transformations
  std::ifstream file(filePath, std::ios::ate | std::ios::binary);
  // Check if the file exists using std::filesystem
  if (!std::filesystem::exists(filePath)) {
    std::cerr << "File not found: " << filePath << '\n';
  }
  if (!file.is_open()) {
    throw std::runtime_error("failed to open file: " + filePath);
  }
  const auto fileSize = std::filesystem::file_size(filePath);
  std::vector<char> buffer(fileSize);
  file.seekg(0);
  file.read(buffer.data(), fileSize);
  file.close();
  return buffer;
}

void LvePipeline::createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath) {
  auto vertCode = readFile(vertFilePath);
  auto fragCode = readFile(fragFilePath);

  std::cout << "Vertex shader code size: " << vertCode.size() << "\n";
  std::cout << "Frag shader code size: " << fragCode.size() << "\n";
}
}  // namespace lve