//
// Created by Kerem on 17-Nov-24.
//

#include "FileReader.h"

namespace lve {

FileReader::FileReader(const std::string &path)try :path(path) {
  validateFile();
}
catch (std::exception &ex) {
  std::cerr << ex.what() << '\n';
  throw std::invalid_argument("failed to open file: " + path);
}
FileReader::~FileReader() {
  if(file.is_open()){
    file.close();
  }
}
bool FileReader::validateFile()try {
  file = std::ifstream (path, std::ios::ate | std::ios::binary);
  // Check if the file exists using std::filesystem
  if (!std::filesystem::exists(path)) {
    std::cerr << "File not found: " << path << '\n';
    return false;
  }
  if (!file.is_open()) {
    return false;
  }
  return true;
} catch (std::exception &ex) {
  std::cerr << ex.what() << '\n';
  return EXIT_FAILURE;
}
std::vector<char> FileReader::read() {
  const auto fileSize = std::filesystem::file_size(path);
  std::vector<char> buffer(fileSize);
  file.seekg(0);
  file.read(buffer.data(), fileSize);
  file.close();
  return buffer;
}
} // lve