#include <gtest/gtest.h>

#include "edit_distance.h"

namespace grammarly {

namespace {

TEST(DistanceEstimatorTest, Simple) {
    DistanceEstimator estimator(std::string_view("TestString"));
    ASSERT_EQ(estimator.calculate_distance(std::string_view("TestString")), 0);
    ASSERT_EQ(estimator.calculate_distance(std::string_view()), 10);
    ASSERT_EQ(estimator.calculate_distance(std::string_view("TestString1")), 1);
    ASSERT_EQ(estimator.calculate_distance(std::string_view("1TestString1")), 2);
}

TEST(DistanceEstimatorTest, Delete) {
    DistanceEstimator estimator(std::string_view("TestString"));
    ASSERT_EQ(estimator.calculate_distance(std::string_view("TesString")), 1);
}

}  // namespace

} // namespace grammarly