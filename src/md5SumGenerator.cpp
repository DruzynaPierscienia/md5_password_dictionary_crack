#include "md5SumGenerator.hpp"

std::string md5SumGenerator::createMd5Sum(std::string const& word) {
  unsigned char digest[16];
  char mdString[33];
  
  MD5_CTX ctx;
  MD5_Init(&ctx);
  MD5_Update(&ctx, word.c_str(), word.size());
  MD5_Final(digest, &ctx);

  for (int i = 0; i < 16; i++)
    sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
  
  return std::string(mdString);
}
