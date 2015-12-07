#pragma once

#include <string>
#include <openssl/md5.h>

class md5SumGenerator {
 public:
  std::string createMd5Sum(std::string const& word);
};
