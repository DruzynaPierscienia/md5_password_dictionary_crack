#include "gtest/gtest.h"
#include "md5SumGenerator.cpp"

TEST (md5SumGeneratorTest, simpleSum) { 
  md5SumGenerator md5Generator;
  auto stringToCalculateMd5 {"something_here"};
  auto calculatedMd5 {"c7a9c5d384ba4a4402af133dd749b994"};
  
  auto calculatedSum = md5Generator.createMd5Sum(stringToCalculateMd5);
  
  EXPECT_TRUE (calculatedSum == calculatedMd5);
}
