#include <algorithm>

#include "edit_distance.h"

namespace grammarly {
DistanceEstimator::DistanceEstimator(std::string_view matching_string):
        matching_string_(matching_string) {
            const size_t string_length = matching_string_.length()+1;
            distance_buffer_.resize(string_length);
        }

float DistanceEstimator::calculate_distance(std::string_view test_string) {
    const size_t string_length = matching_string_.length();    
    // Initialize weights.
    distance_buffer_[0] = 0.f;
    for (auto i = 1; i< distance_buffer_.size(); ++i) {
        distance_buffer_[i] = distance_buffer_[i-1] + kSkipWeight;
    }
    float prev_weight = 0.f;
    for(size_t i=1;i<distance_buffer_.size();++i) {
        for (size_t j = 1; j < test_string.length(); ++j) {
            // replace
            float weight = (matching_string_[i-1] == test_string[j-1] ?  0.f:kReplaceWeight) + distance_buffer_[i-1];
            // skip in the test string
            weight = std::min(weight, prev_weight + kSkipWeight);
            // skip in the match string
            weight = std::min(weight, distance_buffer_[i-1]+kSkipWeight);
            distance_buffer_[i-1] = prev_weight;
            prev_weight = weight;
        }
    }
    return prev_weight;
}
} // namespace grammarly