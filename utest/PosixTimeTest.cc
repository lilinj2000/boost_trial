// Copyright (c) 2010
// All rights reserved.

#include "gtest/gtest.h"
#include "boost/date_time.hpp"

namespace trial {

class PosixTimeTest : public ::testing::Test {
 public:
  PosixTimeTest() {
  }

  void SetUp() {
  }

  void TearDown() {
  }

 protected:
};

TEST_F(PosixTimeTest, nowTest) {
  namespace pt = boost::posix_time;

  pt::ptime now = pt::microsec_clock::local_time();
  std::cout <<now <<std::endl;

  GTEST_SUCCEED();
}

TEST_F(PosixTimeTest, diffTest) {
  namespace pt = boost::posix_time;

  pt::ptime t1 = pt::microsec_clock::local_time();
  pt::ptime t2 = t1 +pt::microsec(2);

  std::cout <<t1 <<std::endl;
  std::cout <<t2 <<std::endl;

  pt::time_duration d = t2 - t1;

  std::cout <<d <<std::endl
            <<d.hours() <<std::endl
            <<d.minutes() <<std::endl
            <<d.seconds() <<std::endl
            <<d.total_seconds() <<std::endl
            <<d.total_milliseconds() <<std::endl
            <<d.total_microseconds() <<std::endl
            <<d.total_nanoseconds() <<std::endl;

  GTEST_SUCCEED();
}

TEST_F(PosixTimeTest, fromStringTest) {
  namespace pt = boost::posix_time;
  namespace gre = boost::gregorian;

  std::string str_date = "20150818";
  std::string str_time = "11:29:59";
  int ms = 900;

  gre::date d(gre::from_undelimited_string(str_date));
  std::cout <<d <<std::endl;

  pt::ptime cur(d, pt::duration_from_string(str_time));
  std::cout <<cur <<std::endl;

  cur = cur + pt::milliseconds(ms);
  std::cout <<cur <<std::endl;

  GTEST_SUCCEED();
}

};  // namespace trial
