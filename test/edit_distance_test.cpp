#include <gtest/gtest.h>

#include "edit_distance.h"

namespace grammarly {

namespace {

TEST(DistanceEstimatorTest, Simple) {
    DistanceEstimator estimator(std::string_view("TestString"));
    ASSERT_EQ(estimator.calculate_distance(std::string_view("TestString")), 0);
    ASSERT_EQ(estimator.calculate_distance(std::string_view()), 9);
}

}  // namespace

} // namespace grammarly