#include <algorithm>

#include "edit_distance.h"

namespace grammarly {
DistanceEstimator::DistanceEstimator(std::string_view matching_string):
        matching_string_(matching_string) {
            const size_t string_length = matching_string_.length()+1;
            distance_buffer0_.resize(string_length);
            distance_buffer1_.resize(string_length);
        }

float DistanceEstimator::calculate_distance(std::string_view test_string) {
    const size_t string_length = matching_string_.length();    
    // Initialize weights.
    distance_buffer0_[0] = 0.f;
    for (auto i = 1; i< distance_buffer0_.size()+1; ++i) {
        distance_buffer0_[i] = distance_buffer0_[i-1] + kSkipWeight;
    }
    float delete_weight = 0.f;
    for(auto i=0;i<test_string.length();++i) {
        delete_weight += kSkipWeight;
        distance_buffer1_[0] = delete_weight;

        for (size_t j = 0; j < distance_buffer0_.size(); ++j) {
            // replace
            float weight = (matching_string_[j] == test_string[i] ?  0.f:kReplaceWeight) + distance_buffer0_[j];
            // skip in the test string
            weight = std::min(weight, distance_buffer0_[j+1] + kSkipWeight);
            // skip in the match string
            weight = std::min(weight, distance_buffer1_[j]+kSkipWeight);
            distance_buffer1_[j+1] = weight;
        }
        std::swap(distance_buffer0_, distance_buffer1_);
    }
    return distance_buffer0_.back();
}
} // namespace grammarly