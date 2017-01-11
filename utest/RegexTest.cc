// Copyright (c) 2010
// All rights reserved.

#include "gtest/gtest.h"
#include "boost/regex.hpp"

namespace trial {

class RegexTest : public ::testing::Test {
 public:
  RegexTest() {
  }

  void SetUp() {
  }

  void TearDown() {
  }

 protected:
};

TEST_F(RegexTest, prodTest) {
  std::string instru = "cu1702";
  std::string prod;
  boost::regex re_prod("^(\\D+)\\d+$");
  // boost::regex re_prod("^([a-z|A-Z]+)\\d+$");
  boost::smatch mat;
  if (boost::regex_match(instru, mat, re_prod)) {
    prod = mat[1];
  }

  std::cout <<instru <<" - " <<prod <<std::endl;

  ASSERT_EQ(prod, "cu");
}

};  // namespace trial
