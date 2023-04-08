#include "TimeFormatter.hpp"
#include <gtest/gtest.h>

namespace logging {
TEST(TimeFormatterClass, get_time_without_format) { EXPECT_EQ(TimeFormatter::get_time().size(), std::string("YYYY/MM/DD HH:MM:SS.sss").size()); }

TEST(TimeFormatterClass, get_time_with_format)
{
    EXPECT_EQ(TimeFormatter::get_time("YYYY/MM/DD HH:MM:SS.sss").size(), std::string("YYYY/MM/DD HH:MM:SS.sss").size());
    EXPECT_EQ(TimeFormatter::get_time("YYYY").size(), 4);
    EXPECT_EQ(TimeFormatter::get_time("MM").size(), std::string("MM").size());
    EXPECT_EQ(TimeFormatter::get_time("DD").size(), std::string("DD").size());
    EXPECT_EQ(TimeFormatter::get_time("HH").size(), std::string("HH").size());
    EXPECT_EQ(TimeFormatter::get_time("MM").size(), std::string("MM").size());
    EXPECT_EQ(TimeFormatter::get_time("SS").size(), std::string("SS").size());
    EXPECT_EQ(TimeFormatter::get_time("sss").size(), std::string("sss").size());
    EXPECT_EQ(TimeFormatter::get_time("YYY").size(), std::string("YYY").size());
    EXPECT_EQ(TimeFormatter::get_time("YYY"), "YYY");
    EXPECT_EQ(TimeFormatter::get_time("The month is MM").size(), std::string("The month is MM").size());
}
}
