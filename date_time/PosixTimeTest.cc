#include "gtest/gtest.h"

#include "boost/date_time.hpp"

namespace trial
{

class PosixTimeTest : public ::testing::Test
{
 public:
  PosixTimeTest()
  {
  }
  
  void SetUp()
  {
  }

  void TearDown()
  {

  }

 protected:

};

TEST_F(PosixTimeTest, nowTest)
{
  using namespace boost::posix_time;
  
  ptime now = microsec_clock::local_time();

  std::cout <<now <<std::endl;
      
  ASSERT_TRUE( true );
}

TEST_F(PosixTimeTest, diffTest)
{
  using namespace boost::posix_time;
  
  ptime t1 = microsec_clock::local_time();

  ptime t2 = t1 + microsec(2);

  std::cout <<t1 <<std::endl;

  std::cout <<t2 <<std::endl;

  time_duration d = t2 - t1;

  std::cout <<d <<std::endl
            <<d.hours() <<std::endl
            <<d.minutes() <<std::endl
            <<d.seconds() <<std::endl
            <<d.total_seconds() <<std::endl
            <<d.total_milliseconds() <<std::endl
            <<d.total_microseconds() <<std::endl
            <<d.total_nanoseconds() <<std::endl;
  
      
  ASSERT_TRUE( true );
}

};  
