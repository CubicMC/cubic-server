#include "TimeFormatter.hpp"
#include <gtest/gtest.h>

namespace logging {
TEST(TimeFormatterClass, get_time_without_format) { EXPECT_EQ(TimeFormatter::getTime().size(), std::string("YYYY/MM/DD HH:MM:SS.sss").size()); }

TEST(TimeFormatterClass, get_time_with_format)
{
    EXPECT_EQ(TimeFormatter::getTime("YYYY/MM/DD HH:MM:SS.sss").size(), std::string("YYYY/MM/DD HH:MM:SS.sss").size());
    EXPECT_EQ(TimeFormatter::getTime("YYYY").size(), 4);
    EXPECT_EQ(TimeFormatter::getTime("MM").size(), std::string("MM").size());
    EXPECT_EQ(TimeFormatter::getTime("DD").size(), std::string("DD").size());
    EXPECT_EQ(TimeFormatter::getTime("HH").size(), std::string("HH").size());
    EXPECT_EQ(TimeFormatter::getTime("MM").size(), std::string("MM").size());
    EXPECT_EQ(TimeFormatter::getTime("SS").size(), std::string("SS").size());
    EXPECT_EQ(TimeFormatter::getTime("sss").size(), std::string("sss").size());
    EXPECT_EQ(TimeFormatter::getTime("YYY").size(), std::string("YYY").size());
    EXPECT_EQ(TimeFormatter::getTime("YYY"), "YYY");
    EXPECT_EQ(TimeFormatter::getTime("The month is MM").size(), std::string("The month is MM").size());
}
}
