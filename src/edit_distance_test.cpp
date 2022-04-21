#include <gtest.h>

#include "edit_distance.h"

namespace grammarly {

namespace {

TEST_F(DistanceEstimatorTest, Simple) {
    DistanceEstimator estimator(std::string_view("TestString"));
    ASSERT_EQ(estimator.calculate_(std::string_view("TestString")), 0);
    ASSERT_EQ(estimator.calculate_(std::string_view()), 9);
}

}  // namespace

} // namespace grammarly