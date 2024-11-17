//
// Created by Kerem on 17-Nov-24.
//

#ifndef LVEENGINE_SRC_CUSTOMFILEOPERATION_FILEREADER_H_
#define LVEENGINE_SRC_CUSTOMFILEOPERATION_FILEREADER_H_
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
namespace lve {

class FileReader {
 public:
  explicit FileReader(const std::string & path);
  virtual ~FileReader();

  FileReader() =delete;
  //copy ctor delete
  FileReader(const FileReader &pipeline) = delete;

  //copy assignment delete
  FileReader &operator=(const FileReader &pipeline) = delete;

  //move constructor delete
  FileReader(FileReader &&pipeline) = delete;

  //move assignment delete
  FileReader &operator=(FileReader &&pipeline) = delete;
  std::vector<char> read();
 private:
  bool validateFile();
  std::vector<char> fileData;
  std::string path;
  std::ifstream file;
};

} // lve

#endif //LVEENGINE_SRC_CUSTOMFILEOPERATION_FILEREADER_H_
